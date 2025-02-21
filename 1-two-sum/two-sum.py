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
        for i in range(len(nums)):
            complement = target - nums[i]
            for j in range(i+1, len(nums)):
                if complement == nums[j]:
                    return [i, j]