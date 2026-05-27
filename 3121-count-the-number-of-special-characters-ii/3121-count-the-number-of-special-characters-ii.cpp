class Solution {
public:
    int numberOfSpecialChars(string word) {

        unordered_map<char, int> visitedLetters;

        // 0 -> lowercase seen
        // 1 -> valid special
        // -1 -> permanently invalid

        for (char letter : word) {

            // lowercase
            if (islower(letter)) {

                // uppercase appeared before
                if (visitedLetters[letter] == 1 ||
                    visitedLetters[letter] == -1) {

                    visitedLetters[letter] = -1;
                }
                else {
                    visitedLetters[letter] = 0;
                }
            }

            // uppercase
            else {

                char lower = tolower(letter);

                // uppercase before lowercase
                if (visitedLetters.count(lower) == 0) {
                    visitedLetters[lower] = -1;
                }

                // valid case
                else if (visitedLetters[lower] != -1) {
                    visitedLetters[lower] = 1;
                }
            }
        }

        int count = 0;

        for (auto &item : visitedLetters) {
            if (item.second == 1) {
                count++;
            }
        }

        return count;
    }
};