class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] < 0) {
                result.push_back(abs(nums[i]));
            }
            nums[abs(nums[i]) - 1] = - nums[abs(nums[i]) - 1];
        }

        return result;

#if 0
        vector<int> res;
        map<int, int> m;

        for(int num : nums) {
            m[num]++;
        }

        for(auto [num, freq] : m) {
            if (freq == 2) {
                res.push_back(num);
            }
        }

        return res;
#endif
    }
};