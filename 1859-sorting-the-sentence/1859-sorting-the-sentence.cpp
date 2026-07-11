class Solution {
public:
    string sortSentence(string s) {
        vector<string>words;

        int n = s.size();
        string temp = "";
        for (int i=0; i<n; i++){
            if (s[i ]== ' '){
                words.push_back(temp);
                temp.clear();
            }
            else{
                temp.push_back(s[i]);
            }
        }
        words.push_back(temp);

        vector<string>serialWords(words.size());

        for (auto it : words){
            string index = "";

            while (it[it.size() - 1] >= '0' && it[it.size() - 1] <= '9'){
                index = it[it.size() - 1] + index;
                it.pop_back();
            }
            // removing the trailing digit and storing the index from back

            int i = stoi(index);
            serialWords[i-1] = it;
        }

        string ans = "";
        for (auto it : serialWords){
            ans += it;
            ans += " ";
        }

        ans.pop_back();

        return ans;
    }
};