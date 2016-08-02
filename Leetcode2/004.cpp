class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        int imin = 0, imax = m, mid = (m+n+1)/2, i = 0, j = 0;
        int leftMax = 0, rightMin = 0;
        while(imin <= imax){
            i = (imin + imax) / 2;
            j = mid - i;
            if(j > 0 && i < m &&  nums2[j-1] > nums1[i]){
                imin = i+ 1;
            }else if(i > 0 && j < n && nums1[i-1] > nums2[j]){
                imax = i - 1;
            }else{
                if(i == 0) leftMax = nums2[j-1];
                else if(j == 0) leftMax = nums1[i-1];
                else leftMax = max(nums1[i-1], nums2[j-1]);
                if((m+n) % 2 == 1) return leftMax;
                if(i == m) rightMin = nums2[j];
                else if(j == n) rightMin = nums1[i];
                else rightMin = min(nums1[i], nums2[j]);
                return (leftMax + rightMin) / 2.0;
            }
        }
        return 0.0;
    }
};
