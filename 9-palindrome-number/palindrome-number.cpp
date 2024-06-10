class Solution {
public:
    bool isPalindrome(int x) {
        long long revNum = 0;
        long long original = x;
        int digit = 0;

        if (x < 0) return false;

        while(x != 0) {
            digit = x % 10;
            revNum = revNum * 10 + digit;
            x = x / 10;
        }

        if(revNum == original) return true;

        return false;
    }
};