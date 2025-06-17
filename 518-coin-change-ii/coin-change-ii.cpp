class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> result(n+1, vector<unsigned long long>(amount+1, 0));

        for (int j = 1; j <= amount; j++) {
            result[0][j] = 0; // Cannot form amount with 0 coins
        }
        for (int i = 0; i <= n; i++) {
            result[i][0] = 1; // 0 amount requires 0 coins
        }

        for (int i = 1; i <= n; i++) {
            for(int j = 1; j <= amount; j++) { 
                if (coins[i-1] <= j) {
                    result[i][j] = result[i-1][j] + result[i][j - coins[i-1]];
                } else {
                    result[i][j] = result[i-1][j];
                }
            }
        }

        return static_cast<int>(result[n][amount]);
    }
};
