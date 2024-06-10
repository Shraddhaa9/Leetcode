class Solution {
public:
    bool isPalindrome(int x) {
        long long revNum = 0;
        long long original = x;
        int mod = 0;

        if (x < 0) return false;

        while(x != 0) {
            mod = x % 10;
            revNum = revNum * 10 + mod;
            x = x / 10;
        }

        if(revNum == original) return true;

        return false;
    }
};