class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
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
    }
};