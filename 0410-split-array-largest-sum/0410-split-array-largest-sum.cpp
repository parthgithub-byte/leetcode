class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long n=nums.size();
        long long start=*max_element(nums.begin(), nums.end());
        long long end=accumulate(nums.begin(), nums.end(), 0LL);
        long long ans=end;
        while(start<=end){
            long long mid = start + (end-start)/2;
            long long group=0, count=1;
            for (long long i=0; i<n; i++){
                group+=nums[i];
                if(group>mid){
                    count++;
                    group=nums[i];
                }
            }

            if (count<=k){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }

        return ans;
    }
};