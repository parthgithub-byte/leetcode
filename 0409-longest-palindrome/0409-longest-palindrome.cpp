class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>letter(256, 0);
        for (auto c:s){
            letter[c-'A']++;
        }

        bool odd=false;
        int total=0;
        for (auto count: letter){
            if((count%2==1))    odd=true;
            total+=((count/2)*2);
        }
        if (odd) total++;

        return total;
    }
};