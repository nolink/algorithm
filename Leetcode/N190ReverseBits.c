uint32_t reverseBits(uint32_t n) {
    int bits[32];
    int result = 0;
    int i=0;
    for(;i<32;i++){
        bits[i]= (n >> i) & 1;
    }
    
    i = 0;
    for(;i<32;i++){
        result |= bits[i] << (31 - i);
    }
    
    return result;
}