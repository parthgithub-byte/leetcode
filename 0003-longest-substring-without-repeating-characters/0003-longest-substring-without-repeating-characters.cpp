class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        vector<int>count(256,0);
        int first=0, second=0, n=s.size();
        while (second<n){
            while(count[s[second]]){
                count[s[first]]=0;
                first++;
            }
            ans=max(ans, second-first+1);
            count[s[second]]++;
            second++;
        }

        return ans;

    }
};