class Solution {
public:
    int reverse(int x) {
        bool isNegative = false;
        long revNum = 0;
        while(x != 0) {
            revNum = revNum * 10 + x % 10;
            x = x / 10;
        }

        if (revNum > INT_MAX || revNum < INT_MIN) return 0;
        return revNum;
    }
};