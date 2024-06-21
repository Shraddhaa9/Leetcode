class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size();
        int mid;

        // add this corner case:
        if (target > nums[high - 1]) {
            return high;
        }

        while (low <= high) {
            mid = (low+high)/2;
            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                high = mid - 1;
            } else if (target > nums[mid]) {
                low = mid + 1;
            }
        }
        return low;     
    }
};