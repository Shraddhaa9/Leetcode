## IP: Array of nums and target
## OP: indexes of two numbers which results a sum
## Notes: 
## Each input has exactly one solution
## Can return answer in any order

## Bruteforce:
## Iterate through the array, take a complement of the current number
## and try to see if we have complement number present in the array
## TC: O(n^2)
## SC: O(1)

## Better version:
## Sort the array
## Iterate through the array, take a complement of the current number
## and try to see if we have complement number present in the array, not through
## LINEAR SEARCH but through BINARY SEARCH
## BUT HAVE TO BE CAREFUL, AS HAS TO STORE ORIGINAL INDICES AS WELL
## TC: O(n logn) + O(logn)
## SC: O(1)

## Optimal solution:
## Use a hashmap, key - number and value - index of the number 
## [needed this as we are returning index of the target sum numbers]
## Define one hashmap
## Iterate through the array, and check in the hashmap that complement number present
## If present return [current index, number_index[value]] from hashmap
## TC: O(n) - as we are iterating through entire array
## SC: O(n) - as we are defining new hashmap


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
    ## Optimal approach:
        nums_map = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in nums_map:
                return [nums_map[complement], i]
            nums_map[num] = i  # Store the number and its index
        return []

'''
    # Bruteforce - better:
    def BinaryS(self, nums, complement) -> int:
        start = 0
        end = len(nums) - 1
        while start <= end:
            mid = (start + end)//2
            if complement == nums[mid]:
                return mid
            if complement < nums[mid]:
                end = mid - 1
            if complement > nums[mid]:
                start = mid + 1
        return -1

    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_sorted = sorted((num, i) for i, num in enumerate(nums))  # Sort (value, original index)
        sorted_nums = [num for num, _ in nums_sorted]

        # Store multiple occurrences of indices
        original_indices = defaultdict(list)
        for num, idx in nums_sorted:
            original_indices[num].append(idx)

        for i in range(len(sorted_nums)):
            complement = target - sorted_nums[i]
            idx = self.BinaryS(sorted_nums, complement)
            if idx != -1 and idx != i:
                return [original_indices[sorted_nums[i]].pop(0), original_indices[sorted_nums[idx]].pop(0)]

        return []
'''
        ## Bruteforce:
        # for i in range(len(nums)):
        #     complement = target - nums[i]
        #     for j in range(i+1, len(nums)):
        #         if complement == nums[j]:
        #             return [i, j]