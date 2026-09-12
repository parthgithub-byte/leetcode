class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string sortVowels(string s) {
        string vowels;
        for (auto &c: s){
            if (isVowel(c)){
                vowels.push_back(c);
                c='0';
            }
        }

        sort(vowels.begin(), vowels.end());

        int i=0;
        for (auto &c: s){
            if(c=='0'){
                c=vowels[i];
                i++;
            }
        }

        return s;
    }
};