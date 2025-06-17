class Solution {
private:
    int subsetSum(vector<int> &nums, int sum) {
        int m = nums.size();
        int n = sum;
        vector<vector<int>> res(m+1, vector<int>(n+1, 0));

        for(int i = 0; i <= m; i++) {
            res[i][0] = 1;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if (nums[i - 1] <= j) {
                    res[i][j] = res[i-1][j] + res[i-1][j - nums[i-1]];
                } else {
                    res[i][j] = res[i-1][j];
                }
            }
        }

        return res[m][n];
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        if ((target + sum) % 2 != 0 || abs(target) > sum) {
            return 0;
        }

        int subSum = (target + sum) / 2;
        // int ways = subsetSum(nums, subSum);
        // return ways * (1 << zeroCount);

        return subsetSum(nums, subSum);
    }
};