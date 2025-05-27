class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int sum = sum + nums[i];
            maxSum = max(maxSum, sum);
            if(sum < 0) {
                sum = 0;
            }
        }

        return maxSum;
    }
};


// generate all subarray of input array
// add the elements
// compare the summed result
// the subset which gave the larget sum is the answer

// corner case:
// 1 or 2 members in a array