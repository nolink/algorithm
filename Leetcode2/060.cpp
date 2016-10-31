class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        int aux = 1;
        vector<int> nums;
        vector<int> factorial(n+1, 1);
        for(int i=1;i<=n;i++) nums.push_back(i);
        for(int i=1;i<=n;i++){
            aux *= i;
            factorial[i] = aux;
        }
        k--;
        for(int i=1;i<=n;i++){
            int idx = k / factorial[n-i];
            ret += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);;
            k -= idx * factorial[n-i];
        }
        return ret;
    }
};
