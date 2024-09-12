class Solution:
    def isPalindrome(self, s: str) -> bool:
        s.lower()

        i, j = 0, len(s) - 1
        while i<j:
            while i<j and not s[i].isalnum() : i += 1
            while i<j and not s[j].isalnum() : j -= 1

            if s[i].lower() != s[j].lower(): return False
            i += 1
            j -= 1

        return True

# string to lower
# check for string length
# remove non-alphanumerics from the string
# two pointer, one increasing and one descreasing; till mid length of string
# when value - does not match, break and declare non-palindrome
# otherwise, when l and r crosses each other delcare it palindrome
