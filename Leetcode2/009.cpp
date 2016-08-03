class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long n = 0;
        for(int i=x;i>0;i/=10){
            n = (n * 10) + (i % 10);
            if(n > INT_MAX) return false;
        }
        return n == x;
    }
};
