// IP: Array of strings (str)
// OP: Array of Array of strings [ANY ORDER, so index/position doesn't matter]

// Anagram - uses same characters in different orders- [combinations of same characters]
// a, e, t ----> ate, eat, tea

// EMPTY string - return empty string as a group

// Single character - return single character as a group

// QUESTIONS:
// Do we get same character in a group of strings? i.e. BOON, NOOB, etc?
// ----> length of 100 characters in a string, and since we have 26 characters in a ABCD,
//       we can have repeating characters
// is it only character string? or we can have alphanumeric values as well?
// ----> it's only character string
// will single testcase contain always same letter strings? or it will be different?
// doesn't matter much though


// MY APPROACH - inefficient:
// 1. iterate through the array till end and keep repeating below steps
// 2. check whether string is valid - non-null
// ...if it's null, then add that to array of array of string's ith index
// 3. for non-null strings
// ...check iteratively for each array of arrya's ith index
// .......if length doesn't matches
// ...........continue to next member of array of array's ith
// .......hashmap - array of arrya's ith match?
// ...........if hashmap matches
// ..............we will append array of array's ith
// ...........if not
// ..............create new hashmap
// ..............append to array of array's i+1

// COMMENTS:
// It has many redundency operations going on, we have to recheck
// getFrequencyMap(s) runs in O(K), where K` is the string length.
// Nested loop leads to O(N^2 * K), making this approach inefficient for large inputs.



// 2nd approach - using sorted strings in hashmap:
// Iterate through the list of strings.
// For each string, compute a key (sorted string).
// Use a hashmap where the key is the sorted string, and the value is a list of anagrams.
// Finally, return the grouped anagrams.

// Sorting each word → O(K log K), where K is the average length of a word.
// Hashmap operations → O(1), since we use a string as a key.
// Final traversal → O(N), where N is the number of words.
// TC: O(N * K log K) (Better than O(N^2))




class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umsvs;

        for (auto istr : strs)
        {
            string sortedStr = istr;
            sort(sortedStr.begin(), sortedStr.end());
            umsvs[sortedStr].push_back(istr);
        }

        vector<vector<string>> result;
        for (auto group : umsvs)
        {
            result.push_back(group.second);
        }

        return result;

    }
#if 0
    unordered_map<char, int> getFrequencyMap(const string& s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        return freq;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        for (const string& str : strs) {
            if (str.empty()) { // Handle empty string case
                result.push_back({str});
                continue;
            }

            bool found = false;
            unordered_map<char, int> currentMap = getFrequencyMap(str);

            // Check if it belongs to an existing group
            for (auto& group : result) {
                if (group[0].length() != str.length()) continue; // Length must match

                unordered_map<char, int> existingMap = getFrequencyMap(group[0]);
                if (existingMap == currentMap) { // Compare frequency maps
                    group.push_back(str);
                    found = true;
                    break;
                }
            }

            // If no match, create a new group
            if (!found) {
                result.push_back({str});
            }
        }
        
        return result;  
    }
#endif
};