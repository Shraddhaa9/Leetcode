class Solution {
private:
    int binarySearch(vector<int> &nums, int start, int end, int target) {
        while(start <= end) {
            int mid = start + (end - start)/2;
            if (nums[mid]==target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int minIndex = -1;
        int size = nums.size();
        int start = 0;
        int end = size - 1;

        while(start <= end) {
            if (nums[start] <= nums[end]) {
                minIndex = start;
                break;
            }
            int mid = start + (end - start)/2;
            int prev = (mid + size - 1) % size;
            int next = (mid + 1) % size;

            if(nums[mid] <= nums[prev] && nums[mid] <= nums[next]) {
                minIndex = mid;
                break;
            }
            if (nums[start] <= nums[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        if (nums[minIndex] == target) return minIndex;

        int part1 = binarySearch(nums, 0, minIndex - 1, target);
        int part2 = binarySearch(nums, minIndex+1, size - 1, target);

        if (part1 != -1) return part1;
        if (part2 != -1) return part2;

        return -1;
    }
};