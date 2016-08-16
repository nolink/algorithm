class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        vector<int> aux(n1 + n2 + 1, 0);
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                aux[i+j] += (num1[n1 - i - 1] - '0') * (num2[n2 - j - 1] - '0');
                aux[i+j+1] += aux[i+j] / 10;
                aux[i+j] %= 10;
            }
        }
        string ret;
        int k = n1 + n2;
        while(k >= 0 && aux[k] == 0) k--;
        while(k >= 0) ret += aux[k--] + '0';
        return ret.empty() ? "0" : ret;
    }
};
