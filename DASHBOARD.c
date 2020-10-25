// Text 
#define uint32  __UINT32_TYPE__

int unpacked_data[9] = {0};

int* uint32Unpacker(uint32 packed_data) {

}

// speed(0~2^8) | ocs_fl(0|1) | ocs_fr(0|1) | ocs_rl(0|1) | ocs_rr(0|1) | belt_fl(0|1) | belt_fr(0|1) | belt_rl(0|1) | belt_rr(0|1)
uint32 uint32Packer(uint32 speed, uint32 ocs_fl, uint32 ocs_fr, uint32 ocs_rl, uint32 ocs_rr, uint32 belt_fl, uint32 belt_fr, uint32 belt_rl, uint32 belt_rr) {
    uint32 res = speed << 24 | ocs_fl << 7 | ocs_fr << 6 | ocs_rl << 5 | ocs_rr << 4 | belt_fl << 3 | belt_fr << 2 | belt_rl << 1 | belt_rr << 0;
    return res;
}