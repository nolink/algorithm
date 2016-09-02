class Solution {
public:
    string convertToTitle(int n) {
        n--;
        return n < 26 ? string(1, (char)(n + 'A')) : convertToTitle(n / 26) + convertToTitle(n % 26 + 1);
    }
};
