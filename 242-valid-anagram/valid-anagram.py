## IP: Two strings
## OP: True or False (based on whether string is anagram or not)

## Brute force:
## Check each character from first string present in 2nd string or not
## TC: O(n^2)
## SC: O(n) - as we are generating one list

## Better approach:
## Sort both the strings and check equality
## If both same then anagram otherwise not
## TC: O(n logn)

## Optimal approach:
# 1. array approach
## Can use array having 26 letters - O(1) space as length of array doesn't increase with the size of the array
## Define one array having 26 letters;
## If character found in S; Increment by 1
## If character found in T; Decrement by 1
## At the end check if array has any value other than 0, then string NOT anagram, if all 0s, then anagram
## TC: O(n) - as iterating through single pass, as length of string same, if not same exiting from start only
## SC: O(1) - as only 26 character length array

#2. Hashmap approach:
## Iterate through string and store frequency of the character as a value
## same like array, increment and decrement and get the result
## TC: O(n) - as iterating through single pass, as length of string same, if not same exiting from start only
## SC: O(1) - as only 26 character length array
from collections import Counter

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        ## Optimal: Hashmap one
        if len(s) != len(t):
            return False
        return Counter(s) == Counter(t)

        # # Better approach: Sorting one
        # if len(s) != len(t):
        #     return False
        # return sorted(s) == sorted(t)

        ## BruteForce:
        # if len(s) != len(t):
        #     return False
        
        # t = list(t)
        # for char in s:
        #     if char in t:
        #         t.remove(char)
        #     else:
        #         return False
        
        # return True
