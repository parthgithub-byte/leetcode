class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int suffixMax=nums[n-1];
        int ans=-1;

        for(int i=n-2; i>=0; i--){
            suffixMax=max(suffixMax, nums[i+1]);
            if(nums[i]<suffixMax){
                ans=max(ans, suffixMax-nums[i]);
            }
        }

        return ans;
    }
};