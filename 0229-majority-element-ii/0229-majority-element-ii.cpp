class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0, count2=0, n=nums.size(), candidate1=INT_MIN, candidate2=INT_MIN;
        for (int i=0; i<n; i++){
            if(nums[i]==candidate1){
                count1++;
            }
            else if(nums[i]==candidate2){
                count2++;
            }
            else if(count1==0){
                candidate1=nums[i];
                count1++;
            }
            else if(count2==0){
                candidate2=nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        bool eligible1=false, eligible2=false;
        if(candidate1!=INT_MIN){
            eligible1 = true;
        }
        if(candidate2!=INT_MIN){
            eligible2 = true;
        }

        vector<int>ans;
        count1=0, count2=0;
        if(eligible1){
            for(int i=0; i<n; i++){
                if(nums[i]==candidate1){
                    count1++;
                }
            }

            if(count1>(n/3))    ans.push_back(candidate1);
        }

        if(eligible2){
            for(int i=0; i<n; i++){
                if(nums[i]==candidate2){
                    count2++;
                }
            }

            if(count2>(n/3))    ans.push_back(candidate2);
        }

        return ans;
    }
};