class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start=1, end=*max_element(quantities.begin(), quantities.end());
        int ans=end, m=quantities.size();
        if(n==m) return ans;    // optimisation

        while(start<=end){
            int mid=start+(end-start)/2;
            int count=0;
            for (int i=0; i<m; i++){
                count+=(quantities[i]/mid);
                if(quantities[i]%mid) count++; // remaining slot for the same type of product
            }
            if(count<=n){
                // last mid which can actually fit the slotswhile being the maximum of all possibilites
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