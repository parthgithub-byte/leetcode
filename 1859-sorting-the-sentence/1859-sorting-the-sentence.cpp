class Solution {
public:
    string sortSentence(string s) {
        vector<string>words(10);    

        int n = s.size(), count = 0;

        string temp = "";
        for (int i=0; i<n; i++){
            if (s[i ]== ' '){
                int index = temp[temp.size()-1] - '0';
                temp.pop_back();
                words[index] = temp;
                temp.clear();
                count++;
            }
            else{
                temp.push_back(s[i]);
            }
        }

        int index = temp[temp.size()-1] - '0';
        temp.pop_back();
        words[index] = temp;
        temp.clear();
        count++;


        for (int i=1; i<=count; i++){
            temp += words[i];
            temp += " ";
        }

        temp.pop_back();
        return temp;
    }
};