class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (divisor == -1 && dividend == INT_MIN)) return INT_MAX;
        int ret = 0;
        bool negative = (dividend < 0) ^ (divisor < 0);
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        while(dvd >= dvs){
            long long aux = dvs, shift = 1;
            while(dvd >= (aux << 1)){
                aux <<= 1;
                shift <<= 1;
            }
            dvd -= aux;
            ret += shift; 
        }
        return negative ? -ret : ret;
    }
};
