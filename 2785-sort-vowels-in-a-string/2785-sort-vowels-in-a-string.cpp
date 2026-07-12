class Solution {
public:
    string sortVowels(string s) {
        string vowels;
        for (auto &c: s){
            if (c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u' ||c=='A' ||c=='E' ||c=='I' ||c=='O' ||c=='U'){
                vowels+=c;
                c = '0';
            }
        }

        sort(vowels.begin(), vowels.end());

        int curr = 0;
        for (auto &c : s){
            if (c == '0'){
                c = vowels[curr];
                curr++;
            }
        }

        return s;
    }
};