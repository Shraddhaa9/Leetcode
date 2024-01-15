class Solution {
    public boolean isPalindrome(int x) {
        Integer var1 = x;
        String strX = var1.toString();

        int left = 0;
        int right = strX.length() -1;
        boolean isPalindrome = false;

        while (left <= right) {
            if (strX.charAt(left) != strX.charAt(right)) {
                return isPalindrome;
            }
            left++;
            right--;
        }

        isPalindrome = true;
        return isPalindrome;
    }
}