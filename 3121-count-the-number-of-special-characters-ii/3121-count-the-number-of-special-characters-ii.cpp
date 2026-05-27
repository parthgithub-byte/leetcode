class Solution {
public:
    int numberOfSpecialChars(string word) {

        unordered_set<char> letterSeen;
        unordered_set<char> letterSatisfied;
        unordered_set<char> letterInvalid;


        for (char letter : word) {
            if (letter < 'a'){
                // i.e. if the letter is of upper case already
                char lower = tolower(letter);

                if (!letterSeen.count(lower)){
                    // uppercase appeared before, thus make the letter invalid
                    letterInvalid.insert(lower);
                }
                else if(letterSeen.count(lower) && !letterSatisfied.count(lower)){
                    letterSatisfied.insert(lower);
                }
            }

            // lowercase letter
            else {
                // uppercase before lowercase
                if (letterSatisfied.count(letter)) {
                    letterInvalid.insert(letter);
                }

                // valid case
                else{
                    letterSeen.insert(letter);
                }
            }
        }

        int count = 0;

        for (auto element : letterSatisfied){
            if (!letterInvalid.count(element)){
                count++;
            }
        }

        return count;
    }
};