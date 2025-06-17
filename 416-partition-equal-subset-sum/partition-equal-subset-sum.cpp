class Solution {
private:
    bool subsetSum(vector<int> &nums, int sum) {
        int m = nums.size();
        int n = sum;
        vector<vector<bool>> res(m+1, vector<bool>(n+1, false));

        res[0][0] = true;
        for(int i = 1; i <= m; i++) {
            res[i][0] = true;
        }

        for(int j = 1; j <= n; j++) {
            res[0][j] = false;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if (nums[i - 1] <= j) {
                    res[i][j] = res[i-1][j] || res[i-1][j - nums[i-1]];
                } else {
                    res[i][j] = res[i-1][j];
                }
            }
        }

        return res[m][n];
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) {
            sum = sum + num;
        }
        
        if (sum % 2 != 0) {
            return false;
        }

        return subsetSum(nums, sum/2);
    }
};