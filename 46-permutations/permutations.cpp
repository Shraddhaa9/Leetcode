class Solution {
private:
    void helper(vector<int>& nums, int start, vector<vector<int>> &result) {
        if (start == nums.size() - 1) {
            result.push_back(nums);
            return;
        }

        for(int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            helper(nums, start+1, result);
            swap(nums[start], nums[i]);
        }

        return;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helper(nums, 0, result);
        return result;
    }
};