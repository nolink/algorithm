int hammingWeight(uint32_t n) {
    int count = 0;
    int i=0;
    for(;i<32;i++){
        if(((n >> i) & 1) == 1){
            count++;
        }
    }
    return count;
}