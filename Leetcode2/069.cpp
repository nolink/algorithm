class Solution {
public:
    int mySqrt(int x) {
        double x_0 = 1.0;
        while(abs(x_0 * x_0 - x) >= 0.000001){
            x_0 = (x_0 + x / x_0) / 2;
        }
        return (int)x_0;
    }
};
