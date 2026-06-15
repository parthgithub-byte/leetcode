class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>commands;

        int curr = 1;

        for (int x: target){
            while (curr<x){
                commands.push_back("Push");
                commands.push_back("Pop");
                curr++;
            }

            commands.push_back("Push");
            curr++;
        }

        return commands;
    }
};