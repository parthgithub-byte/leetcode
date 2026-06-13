class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int>sequence(n, 0);
        stack<int>st;

        for (int i=0; i<n; i++){
            if (!st.empty() && s[st.top()] == '(' && s[i] == ')'){
                sequence[st.top()] = 1;
                sequence[i] = 1;
                st.pop();
            }
            else{
                // else if, st was empty or s[st.top()] was not '(' or s[i] was not ')'
                st.push(i);
            }
        }

/* Eg:
")(()))()" gives the sequence:
 01111011
*/
        int maxi=0, count=0;
        for (int i=0; i<n; i++){
            if (sequence[i]==0){
                count=0;
            }
            else{
                count++;
                maxi = max(maxi, count);
            }
        }

        return maxi;
    }
};