class Solution {
public:
    void reverseString(string &s, int len){
        int f = 0, l = len-1;
        while (f<l){
            swap(s[f], s[l]);
            f++; l--;
        }
    }

    string addStrings(string num1, string num2) {
        string ans;

        string temp;
        if (num1.size() < num2.size()){ 
            // we are strictly assuming num1 to be of more length
            temp = num1;
            num1 = num2;
            num2 = temp;
        }

        reverseString(num1, num1.size());
        reverseString(num2, num2.size());

        int carry = 0, i=0;
        for (; i<num2.size(); i++){
            int sum = carry + (num1[i] - '0') + (num2[i] - '0');
            ans += ((sum%10) + '0');
            carry = sum / 10;
        }

        while (i<num1.size()){
            int sum = carry + (num1[i] - '0');
            ans += ((sum%10) + '0');
            carry = sum / 10;
            i++;
        }

        if (carry!=0)
            ans += (carry + '0');

        reverseString(ans, ans.size());

        return ans;
    }
};