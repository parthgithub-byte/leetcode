class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN, n=nums.size(), prefixSum=0;
        for(int i=0; i<n; i++){
            prefixSum+=nums[i];
            ans=max(ans, prefixSum);
            if(prefixSum<0) prefixSum=0;
        }
        return ans;
    }
};