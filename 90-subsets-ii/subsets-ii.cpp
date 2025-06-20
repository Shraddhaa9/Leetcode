class Solution {
private:
    set<vector<int>> seen;

    void helper(vector<int> &input, vector<int> &output, vector<vector<int>>& result) {
        if (input.size() == 0) {
            if(seen.count(output)) return;
            result.push_back(output);
            seen.insert(output);
            return;
        }

        // exclude the first element
        vector<int> ip1(input.begin()+1, input.end());
        helper(ip1, output, result);

        // include the first element
        output.push_back(input[0]);
        helper(ip1, output, result);
        output.pop_back();
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> input(nums);
        vector<int> output;
        helper(input, output, result);
        return result;
    }
};