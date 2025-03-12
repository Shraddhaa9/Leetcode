// input: String
// op: integer, return length of substring without duplicate characters

// BruteForce:
// if we iterate through loop twice, once for starting position of the substring
// and 2nd for substring-generation(but not actual generation, it will be like
// we are traversing), so if we do that, then it's like we are iterating through
// string twice, and for checking uniqueness we will keep adding new characters
// to the set, if that character is not already present in the set, if it's 
// already there then we will skip that, for adding any element to the set, it's like
// O(1) operation, for lookup as well it's O(1), so basically we are traversing string twice
// so it's O(n^2), and for using set we are using extra space, for maxlength of string
// so let's suppose it's k, then space complexity will be O(k), and if entire string has a uniquq
// characters then basically that means, space complexity is O(n)

// time complexity: o(n^2)
// space complexity: O(k)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            std::unordered_set<char> usc;
            for (int j = i; j < n; j++) {
                if (usc.find(s[j]) != usc.end()) {
                    break;
                }
                usc.insert(s[j]);
                maxLength = std::max(maxLength, (int)usc.size());
            }
        }

        return maxLength;
    }
};