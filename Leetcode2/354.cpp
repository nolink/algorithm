class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if(n <= 1) return n;
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int>& a, pair<int, int>& b){
           if(a.first == b.first){
               return a.second > b.second;
           }
           return a.first < b.first;
        });
        // int ret = 1;
        // vector<int> dp(n, 1);
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second){
        //             dp[i] = max(dp[i], dp[j] + 1);
        //         }
        //         ret = max(ret, dp[i]);
        //     }
        // }
        // return ret;
        vector<int> dp;
        for(auto envelope : envelopes){
            auto it = lower_bound(dp.begin(), dp.end(), envelope.second);
            if(it == dp.end()){
                dp.push_back(envelope.second);
            }else{
                *it = envelope.second;
            }
        }
        return dp.size();
    }
};
