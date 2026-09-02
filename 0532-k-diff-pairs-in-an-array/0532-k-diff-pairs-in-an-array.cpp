class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans=0, n=nums.size();
        for(int i=0; i<n-1; i++){
            while(i!=0 && nums[i]==nums[i-1])  i++; // already covered cases

            int target=nums[i];   
            int start=i+1, end=n-1;
            while(start<=end){
                int mid=start+(end-start)/2;
                int diff=nums[mid]-target;
                if(diff==k){
                    ans++;
                    break;
                }
                else if(diff>k){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
        }
        return ans;
    }
};