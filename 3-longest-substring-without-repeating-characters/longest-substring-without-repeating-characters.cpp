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


// OPTIMIZED APPROACH: SLIDING WINDOW
// We will have two pointers, one slow and 2nd fast pointer, fast pointer will traverse fast,
// increasing length of substring till we find repeating character, and slow pointer will
// move when we find repeated character, we will again use set, for storing unique characters
// we will keep storing maximum length of substring based on set size,
// so we will get maximum length at end

// TC: o(n)
// SC: o(k)


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        unordered_set<char> charSet;
        int i = 0;
        int j = 0;
        int maxLength = 0;

        while(j < size) {
            if (charSet.find(s[j]) == charSet.end()) {
                charSet.insert(s[j]);
                maxLength = max(maxLength, j - i + 1);
                j++;
            } else {
                while(charSet.find(s[j]) != charSet.end()) {
                    charSet.erase(s[i]);
                    i++;
                }
            }
        }

        return maxLength;
#if 0
        int size = s.size();
        unordered_set<char> charSet;
        int left = 0;
        int maxLength = 0;

        for(int right = 0; right < size; right++) {
            while(charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            maxLength = std::max(maxLength, right-left+1);
        }

        return maxLength;
#endif
#if 0        
        int maxLength = 0;
        int n = s.length();
        int slow = 0;

        unordered_set<char> usc;
        for (int fast = 0; fast < n; fast++)
        {
            while (usc.find(s[fast]) != usc.end()) {
                usc.erase(s[slow]);
                slow++;
            }
            usc.insert(s[fast]);
            maxLength = std::max(maxLength, (int)usc.size());
        }

    return maxLength;
#endif
#if 0
// Brute force:
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
#endif
    }
};