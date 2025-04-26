class Solution {
    int sumOfSquares(int n) {
        int result = 0;

        while(n != 0) {
            int digit = n % 10;
            digit = digit * digit;
            result = result + digit;
            n = n / 10;
        }

        return result;
    }

public:
    bool isHappy(int n) {
        unordered_set<int> visitedSet;

        while(visitedSet.find(n) == visitedSet.end()) {
            visitedSet.insert(n);

            n = sumOfSquares(n);

            if (n == 1) {
                return true;
            }
        }

        return false;
    }
};