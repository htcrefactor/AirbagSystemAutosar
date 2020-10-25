// Header File(s)
#include <stdio.h>

// Definition(s)
#define uint32  __UINT32_TYPE__

// Global Variable(s)
int unpacked_data[9] = {0};

// Function Prototype(s)
uint32_t uint32Packer(uint32_t speed, uint32_t ocs_fl, uint32_t ocs_fr, uint32_t ocs_rl, uint32_t ocs_rr, uint32_t belt_fl, uint32_t belt_fr, uint32_t belt_rl, uint32_t belt_rr);

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
    
    return 0;
}

int* uint32Unpacker(uint32 packed_data) {

}

// speed(0~2^8) | ocs_fl(0|1) | ocs_fr(0|1) | ocs_rl(0|1) | ocs_rr(0|1) | belt_fl(0|1) | belt_fr(0|1) | belt_rl(0|1) | belt_rr(0|1)
uint32_t uint32Packer(uint32_t speed, uint32_t ocs_fl, uint32_t ocs_fr, uint32_t ocs_rl, uint32_t ocs_rr, uint32_t belt_fl, uint32_t belt_fr, uint32_t belt_rl, uint32_t belt_rr) {
    uint32_t ret = speed << 24 | ocs_fl << 7 | ocs_fr << 6 | ocs_rl << 5 | ocs_rr << 4 | belt_fl << 3 | belt_fr << 2 | belt_rl << 1 | belt_rr << 0;
    return ret;
}
