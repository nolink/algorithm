class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = INT_MAX, maxSoFar = INT_MIN, profit = 0;
        for(auto p : prices){
            if(p < minSoFar){
                maxSoFar = minSoFar = p;
            }else if(p > maxSoFar){
                maxSoFar = p;
                profit = max(profit, maxSoFar - minSoFar);
            }
        }
        return profit;
    }
};
