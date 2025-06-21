class Solution {
private:
    bool isPalindrome(string s, int start, int end) {
        while(start < end) {
            if (s[start++] != s[end--]) return false;
        }

        return true;
    }

    void helper(string &s, int start, vector<string>& current, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(current);
        }

        for(int i = start; i < s.size(); i++) {
            if(isPalindrome(s, start, i)) {
                current.push_back(s.substr(start, i - start + 1));
                helper(s, i+1, current, result);
                current.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        helper(s, 0, current, result);
        return result;
    }
};