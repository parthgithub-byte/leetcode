class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start=*max_element(weights.begin(), weights.end());
        int end=accumulate(weights.begin(), weights.end(), 0);
        int ans=end;
        int n=weights.size();
        while(start<=end){
            int mid=start+(end-start)/2;
            int packages=0, count=1;
            for (int i=0; i<n; i++){
                packages+=weights[i];
                if(packages>mid){
                    count++;
                    packages=weights[i];
                }
            }
            if(count<=days){
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