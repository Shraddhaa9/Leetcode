## IP: Array
## OP: True/False (based on duplicate number)

## take 1 number and iterate through the 2nd loop, if number matches
## TC: O(n^2)

## Sort the array
## Check two adjacent numbers
## TC: O(n logn)

## Use hashset
## Store the number in the set if it's not already there
## If found return true

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums.sort()
        hashset = set()
        for i in range(len(nums)):
            if nums[i] in hashset:
                return True
            else:
                hashset.add(nums[i])

        return False

        ## Sorting approach
        # for i in range(len(nums)-1):
        #     if nums[i] == nums[i+1]:
        #         return True
            
        # return False

        ## Brute force approach:
        # for i in range(len(nums)-1):
        #     for j in range(i+1, len(nums)):
        #         if nums[i] == nums[j]:
        #             return True
    
        # return False

