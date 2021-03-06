// Header File(s)
#include <stdio.h>

// Definition(s)
#define uint32  __UINT32_TYPE__

// Global Variable(s)
int unpacked_data[9] = {0};

// Function Prototype(s)
uint32_t uint32Packer(uint32_t speed, uint32_t ocs_fl, uint32_t ocs_fr, uint32_t ocs_rl, uint32_t ocs_rr, uint32_t belt_fl, uint32_t belt_fr, uint32_t belt_rl, uint32_t belt_rr);
void uint32Unpacker(uint32_t packed_data);

int main() {
    uint32_t speed = 60;
    uint32_t ocs_fl = 0;
    uint32_t ocs_fr = 0;
    uint32_t ocs_rl = 0;
    uint32_t ocs_rr = 0;
    uint32_t belt_fl = 1;
    uint32_t belt_fr = 1;
    uint32_t belt_rl = 1;
    uint32_t belt_rr = 1;
    
    uint32_t result = uint32Packer(speed, ocs_fl, ocs_fr, ocs_rl, ocs_rr, belt_fl, belt_fr, belt_rl, belt_rr);
    printf("%x\n", result);

    uint32Unpacker(result);
    
    return 0;
}

/* uint32Unpacker() Specification */
// unpacked_data[0~3]: OCS_{FrontLeft | FrontRight | RearLeft | RearRight}
// unpacked_data[4~7]: BELT_{FrontLeft | FrontRight | RearLeft | RearRight}
// unpacked_data[9]: SPEED
void uint32Unpacker(uint32_t packed_data) {
    for(int i = 0 ; i < 8 ; i++) {
        uint32_t mask = 1 << i;
        unpacked_data[i] = (packed_data & mask) / (1 << i);
    }

    unpacked_data[8] = packed_data >> 24;
}

/* uint32Packer() Specifications */
// Data Domains
// 0 < speed < 2^8
// 0 < ocs, belt < 1

// Parameter Abbreviations
// {OCS | BELT} _ {FrontLeft | FrontRight | RearLeft | RearRight}

// Bit Composition
// |31 30 29 28 27 26 25 24 | 23 22 21 20 19 18 17 16 15 14 13 12 11 10 09 08 | 07 06 05 04 | 03 02 01 00 |
// |         SPEED          |                      NULL                       |     OCS     |     BELT    |
uint32_t uint32Packer(uint32_t speed, uint32_t ocs_fl, uint32_t ocs_fr, uint32_t ocs_rl, uint32_t ocs_rr, uint32_t belt_fl, uint32_t belt_fr, uint32_t belt_rl, uint32_t belt_rr) {
    uint32_t ret = speed << 24 | ocs_fl << 7 | ocs_fr << 6 | ocs_rl << 5 | ocs_rr << 4 | belt_fl << 3 | belt_fr << 2 | belt_rl << 1 | belt_rr << 0;
    return ret;
}
