class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int target = 0;
        set<vector<int>> s;
        vector<vector<int>> result;
        int threeSum, i, l, r;
        
        for(i = 0; i < size(nums); i++)
        {
            l = i+1;
            r = size(nums) - 1;
            while(l < r)
            {
                threeSum = nums[i] + nums[l] + nums[r];
                if (threeSum > 0) {
                    r = r -1;
                } else if (threeSum < 0) {
                    l = l + 1;
                } else {
                    s.insert({nums[i], nums[l], nums[r]});
                    l = l + 1;
                    r = r - 1;
                    while(nums[l] == nums[l - 1] && l < r ) {
                        l = l + 1;
                    }
                }
            }
        }

        for (auto triplets : s)
            result.push_back(triplets);
        return result;
    }
};