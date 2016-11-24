class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ret;
        for(int i=0;i<nums.size();i++){
            while(!q.empty() && q.front() < i-k+1) q.pop_front();
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if(i + 1 >= k) ret.push_back(nums[q.front()]);
        }
        return ret;
    }
};
