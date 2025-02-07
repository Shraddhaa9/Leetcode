# nums
# true -> If atleast twice
# false -> No matching elements found

# Corner cases:
# empty array - return false
# Single element array - return false
# -Ve number - allowed
# Duplicate numbers - allowed [it's THE problem]

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        if len(nums) == 1 or len(nums) == 0:
            return False
        
        hs = set()
        for item in nums:
            if item not in hs:
                hs.add(item)
            else:
                return True
        
        return False  