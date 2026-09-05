class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>pSmall=nums;
        vector<int>sGreat=nums;
        
        for(int i=1; i<n; i++){
            if(pSmall[i-1]<pSmall[i]){
                pSmall[i]=pSmall[i-1];
            }
        }

        for(int i=n-2; i>=0; i--){
            if(sGreat[i]<sGreat[i+1]){
                sGreat[i]=sGreat[i+1];
            }
        }

        int ans=-1;
        for(int i=0; i<n; i++){
            ans=max(ans, sGreat[i]-pSmall[i]);
        }

        if (ans==0) return -1;
        return ans;
    }
};