class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), s = needle.size();
        if (n < s)
            return -1;
        if (haystack == needle)
            return 0; // same in size and matching from the start
        int first = 0, second = 0;

        while (first <= n - s) {
            while (second < s &&
                   haystack[first + second] == needle[second]) {
                second++;
            }
            if (second == s) {
                return first;
            }
            second = 0;
            first++;
        }
        return -1;
    }
};