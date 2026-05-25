class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int>st;
        vector<int>sequence(n,0);

        for (int i=0; i<n; i++){
            if (!st.empty()){
                if (s[i] == ')'){
                    if (s[st.top()] == '('){
                        sequence[st.top()] = 1;
                        sequence[i] = 1;
                        st.pop();
                    }
                    else{
                        // unstisfied s[i]
                        st.push(i);
                    }
                }
                else{
                    // again, couldn't satisfy this one like in the ideal case
                    st.push(i);
                }
            }
            else{
                st.push(i);
            }
        }

        int maxi = 0, count = 0;
        for (int i=0; i<n; i++){
            if (sequence[i] == 0){
                count = 0;
            }
            else {
                count++;
                maxi = max(maxi, count);
            }
            // maxi += sequence[i];
        }

        return maxi;
    }
};