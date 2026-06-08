class Solution {
public:
    string removeDigit(string number, char digit) {
        // string ans;
        int lastOccur, n = number.size();

        for (int i=0; i<number.size(); i++){
            if (i!= n-1 && number[i] == digit && number[i] < number[i+1]){
                number.erase(i,1);
                return number;
            }
            else if (number[i] == digit){
                lastOccur = i;
            }
        }

        number.erase(lastOccur,1);
        return number;
    }
};