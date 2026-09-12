class Solution {
public:
    string sortSentence(string s) {
       vector<string>words;
       string temp="";
       for(auto c:s){
        if (c==' '){
            words.push_back(temp);
            temp="";
            continue;
        }
        temp.push_back(c);
       }

       words.push_back(temp);
       int length=words.size();
       vector<string>sequence(length);
       
       for (auto it:words){
        int n=it.size();
        int i=it[n-1]-'0';
        it.pop_back();
        sequence[i-1]=it;
       }

       string ans="";
       for(auto it:sequence){
        ans+=it;
        ans+=" ";
       }
       ans.pop_back();

       return ans;
    }
};