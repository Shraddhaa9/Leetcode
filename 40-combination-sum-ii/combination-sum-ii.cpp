class Solution {
private:
    void helper(vector<int> &candidates, int start, int target, vector<int>& current, vector<vector<int>> &result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        if(target < 0) {
            return;
        }

        for(int i = start; i < candidates.size(); i++) {
            // skip duplicates
            if(i>start && candidates[i] == candidates[i-1]) continue;

            current.push_back(candidates[i]);
            helper(candidates, i+1, target - candidates[i], current, result);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target, current, result);
        return result;        
    }
};