// IP: Array [with distinct numbers, so no duplicates]
// OP: number - missing in the range

// n = length of vector

// BRUTE FORCE:
// sort the array
// 3, 0, 1 -> (after sorting) 0, 1, 3
// 0, 1 -> (after sorting) 0, 1
// 9, 6, 4, 2, 3, 5, 7, 0, 1 -> (after sorting) 0, 1, 2, 3, 4, 5, 6, 7, 9

// We go from start to end and try to match all values with its particular indice
// So, if it doesn't match, then its clear that the missing value will be n,
// which is the last indice

// TC: O(nlogn) + O(n) === O(n logn)
// SC: O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // OPTIMAL SOLUTION:
        int n = nums.size();

        int TotalExpectedSum = n * (n + 1) / 2;

        int actualSum = accumulate(nums.begin(), nums.end(), 0);

        return TotalExpectedSum - actualSum;

#if 0
        // BRUTE FORCE:
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            cout << i << " " << nums[i] << endl;
            if (i != nums[i])
            {
                return i;
            }
        }

        return n;
#endif
    }
};