class Solution {
public:
    int compareVersion(string version1, string version2) {
        int num1 = 0, num2 = 0, i=0, j=0, m = version1.length(), n = version2.length();
        while(i<m || j<n){
            while(i<m && version1[i] != '.'){
                num1 = 10 * num1 + (version1[i] - '0');
                i++;
            }
            while(j<n && version2[j] != '.'){
                num2 = 10 * num2 + (version2[j] - '0');
                j++;
            }
            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
            num1 = num2 = 0;
            i++;
            j++;
        }
        return 0;
    }
};
