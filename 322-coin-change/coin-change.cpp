class Solution {
public:
    int dp[10000+1][12+1];
    int coinsHelper(vector<int>& coins, int amount, int len){
        if(len==0||amount==0){
            return amount==0?0:INT_MAX-1;
        }
        
        if(dp[amount][len]!=-1) return dp[amount][len];
        
        if(coins[len-1]>amount) return dp[amount][len]=coinsHelper(coins,amount ,len-1);
        else
            return dp[amount][len]=min(coinsHelper(coins,amount ,len-1),1+coinsHelper(coins,amount-coins[len-1],len));
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int minCoins=coinsHelper(coins,amount,coins.size());
        return minCoins==INT_MAX-1?-1:minCoins;
    }
};

#if 0
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> result(n+1, vector<int>(amount+1, 0));

        for (int j = 1; j <= amount; j++) {
            result[0][j] = INT_MAX - 1; // Cannot form amount with 0 coins
        }
        for (int i = 0; i <= n; i++) {
            result[i][0] = 0; // 0 amount requires 0 coins
        }

        for(int j = 1; j <= amount; j++) {
            if(j % coins[0] == 0) {
                result[1][j] = j / coins[0];
            } else {
                result[1][j] = INT_MAX -1;
            }
        }

        for (int i = 2; i <= n; i++) {
            for(int j = 1; j <= amount; j++) { 
                if (coins[i-1] <= j) {
                    result[i][j] = min(result[i-1][j], 1 + result[i][j - coins[i-1]]);
                } else {
                    result[i][j] = result[i-1][j];
                }
            }
        }

        return result[n][amount] == INT_MAX -1 ? -1 : result[n][amount] ;
    }
};
#endif