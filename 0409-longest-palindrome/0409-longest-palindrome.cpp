class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>charFreq(256,0);
        
        for (auto c : s){
            charFreq[c]++;
        }
        
        bool odd = false;
        int count = 0;
        
        for (auto f : charFreq){
            count += (f/2)*2;
            if (f%2 == 1)   odd = true;
        }
        
        if (odd)
            count += 1;
            
        return count;
    }
};