class Solution {
public:
    
    string addStrings(string num1, string num2) {
        string ans;

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        if (num1.size()<num2.size()){
            swap(num1, num2);
        }

        int n1=num1.size();
        int n2=num2.size();

        int carry=0, i=0;
        while(i<n2){
            int sum=(num1[i]-'0')+(num2[i]-'0')+carry;
            char c=(sum%10 +'0');
            carry=sum/10;
            ans.push_back(c);
            i++;
        }

        while(i<n1){
            int sum=(num1[i]-'0')+carry;
            char c=sum%10 + '0';
            carry=sum/10;
            ans.push_back(c);
            i++;
        }
        if (carry!=0){
            char c=carry+'0';
            ans.push_back(c);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};