class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if ((long long)m*k>n){
            return -1; // only edge case, also breaks the initialization of start below
        }
        vector<int>sorted=bloomDay;
        sort(sorted.begin(), sorted.end());
        int start=sorted[((long long)m*k)-1];  // minimum days for m*k flowers to bloom possible in favourable array
        int end=sorted[n-1];
        int ans=-1; //no amount of days passing can make the enough bouquets be made
        while(start<=end){
            int mid = start+(end-start)/2;
            int count=0, temp=0;
            for(int i=0; i<n; i++){
                if(mid>=bloomDay[i]){
                    temp++;
                }
                else{
                    temp=0; //reset
                    continue; // no need to check the next condition as adjacency broke
                }
                // required flower count in single bouquet
                if(temp==k){
                    count++;
                    temp=0; //reset
                }
            }

            if (count>=m){ //eligible no of days found, can found even smaller limit
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