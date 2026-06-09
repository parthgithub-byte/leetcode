class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        int n=num.size();
        k = min(k, n);  // in case k number digits to remove is more than even the no. of digits in num

        for (int i=0; i<n; i++){
            while (!st.empty() && st[st.size()-1] > num[i] && k){
                st.pop_back();
                k--;
            }
            if (!st.empty() or num[i] != '0')
            st.push_back(num[i]);
        }

        while (k-- and !st.empty()){
            st.pop_back();
        }
        // removing the remaining of last k characters from the string, as by greedy approach, removing the last digits will always be better than removing the first characters if you want to minimize the number (greedy technique: similar but opposite problem, 2259).

        if (st.empty())
            return "0";

        return st;
    }
};