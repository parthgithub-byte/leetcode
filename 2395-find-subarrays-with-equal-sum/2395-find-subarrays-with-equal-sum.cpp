class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        set<int>sums;
        int n=nums.size();
        for(int i=0; i<n-1; i++){
            int sum = nums[i]+nums[i+1];
            if (sums.contains(sum)){
                return true;
            }
            sums.insert(sum);
        }

        return false;
    }
};