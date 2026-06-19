class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>actualHeight(1,0);
        for (int i=0; i<gain.size(); i++){
            actualHeight.push_back(actualHeight[i]+gain[i]);
        }

        auto max_it = max_element(actualHeight.begin(), actualHeight.end());

        int ans = *max_it;
        return ans;
    }
};