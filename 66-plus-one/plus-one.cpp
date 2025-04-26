class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        for(int i = size - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }

        // we will generate new vector will +1 size to original and
        // will have first digit as 1 and rest of them as 0
        vector<int> result(size + 1, 0);
        result[0] = 1;
        return result;

#if 0
// brute force:
/* This brute force passes some cases only, as it digits-length can be 100
 so no integer or long long will be able to hold that big value
 integer can store upto 10 ^ 9 and long long upto 10 ^ 18
 so we need to perform this digit by digit only
*/
        int num = 0;
        int size = digits.size();
        for(int i = 0; i < size; i++) {
            int digit = digits[i];
            num = digit + num * 10;
        }

        // increment number by 1
        num++;

        vector<int> result;
        while(num) {
            int digit = num % 10;
            result.push_back(digit);
            num = num / 10;
        }

        reverse(result.begin(), result.end());
        return result;
#endif
    }
};