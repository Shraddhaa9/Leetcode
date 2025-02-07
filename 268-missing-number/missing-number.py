# i/p - nums
#     inclusive range
#     distinct (no duplicates)
#     no negative numbers given as only positive

# Corner case:
# empty array

class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return sum(range(len(nums)+1)) - sum(nums)
'''
        length = len(nums)
        if length == 0:
            return -1
        
        nums.sort()
        
        # enumerate gives index,value from the list
        for i, num in enumerate(nums):
            # return the missing number, since it's SORTED at somepoint, 
            # value of index would not match with value, so that we should be able
            # to get correct value after subtracting 
            if i != num:
                return num-1

            # handles the edge case - case 2; as it's inclusive
            if num == len(nums) - 1:
                return num+1
# TC: O(n logn) because of sorting
'''