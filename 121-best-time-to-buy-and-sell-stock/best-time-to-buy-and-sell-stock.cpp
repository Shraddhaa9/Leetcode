class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int left = 0;
        int right = left + 1;

        while(right < prices.size()) {
            int profit = prices[right] - prices[left];
            if (profit < 0) {
                left = right;
            }
            right++;
            maxP = max(maxP, profit);
        }


        return maxP;

#if 0
        int maxP = 0;

        for(int i = 0; i < prices.size()-1; i++) {
            for(int j = i+1; j < prices.size(); j++) {
                int profit = prices[j] - prices[i];
                maxP = max(maxP, profit);
            }
        }
        return maxP;
#endif
    }
};