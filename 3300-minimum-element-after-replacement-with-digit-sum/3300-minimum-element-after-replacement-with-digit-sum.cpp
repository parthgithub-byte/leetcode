class Solution {
public:
    int digitSum (int num){
        int sum = 0;
        while(num){
            sum += (num%10);
            num /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for (auto num : nums){
            ans = min(ans, digitSum(num));
        }
        
        return ans;
    }
    
};