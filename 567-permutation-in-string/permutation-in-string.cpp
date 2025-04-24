// IP: string1, string2
// OP: true - if string1's permutation is substring of string2 
// OP: false - if string1's permutation is NOT a substring of string2 

// find all the permutations of string1
// store it somewhere
// one by one check in string2, whether its present or not

/// same as ABOVE, but we are not storing and using string directly
// find all the permutations of string1
// check whether its present in string2 or not


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int str1Size = s1.length();
        int str2Size = s2.length();
        if(str1Size == 1 && str2Size == 1 && s1 != s2) {
            return false;
        }

        int windowSize = str1Size;
        vector<int> charSet1(26, 0);
        vector<int> charSet2(26, 0);
        for(char s : s1) {
            charSet1[s - 'a']++;
        }

        int i = 0;
        int j = 0;
        while (j < str2Size) {
            charSet2[s2[j] - 'a']++;
            if (j - i + 1 < windowSize) {
                j++;
            } else if (j - i + 1 == windowSize) {
                if (charSet2 == charSet1) {
                    return true;
                }
                charSet2[s2[i] - 'a']--;
                i++;
                j++;                
            }
        }

        return false;
    }
};