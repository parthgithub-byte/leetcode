class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0, n=nums.size(), candidate;
        for(int i=0; i<n; i++){
            if (count==0){
                candidate=nums[i];
                count++;
            }
            else if(nums[i]==candidate){
                count++;
            }
            else{
                count--;
            }
        }

        count=0;
        for(int i=0; i<n; i++){
            if(nums[i]==candidate)  count++;
        }
        if(count<=(n/2)) return -1;

        return candidate;
    }
};