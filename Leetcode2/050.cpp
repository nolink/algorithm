class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        if(x == 0){
            return 0;
        }
        long ln = n;
        if(n < 0){
            ln = -ln;
            x = 1 / x;
        }
        return (ln % 2 == 0) ? myPow(x*x, ln / 2) : x * myPow(x*x, ln / 2);
    }
};
