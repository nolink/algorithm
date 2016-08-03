class Solution {
public:
    int reverse(int x) {
        long n = 0, ret = 0;
        for(long i=abs(x);i>0;i/=10){
            n = n == 0 ? 1 : n*10;
        }
        for(long i=abs(x);n>0;i/=10, n/=10){
            ret += (i % 10) * n;
        }
        return x < 0 ? (-ret < INT_MIN ? 0 : -ret) : (ret > INT_MAX ? 0 : ret);
    }
};
