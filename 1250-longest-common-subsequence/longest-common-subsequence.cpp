class Solution {
private:
    int dp[1001][1001];

    int helper(string& text1, string& text2, int len1, int len2) {
        if (len1 == 0 || len2 == 0) {
            return 0;
        }

        if (dp[len1][len2] != -1) {
            return dp[len1][len2];
        }

        if (text1[len1 - 1] == text2[len2 - 1]) {
            return dp[len1][len2] = 1 + helper(text1, text2, len1 -1 , len2 - 1);
        }

        return dp[len1][len2] = max(helper(text1, text2, len1- 1, len2),
                   helper(text1, text2, len1, len2 - 1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();

        memset(&dp, -1, sizeof(dp));
        helper(text1, text2, len1, len2);

        return dp[len1][len2];
    }
};