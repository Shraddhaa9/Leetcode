class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n, INT_MIN);
        vector<int> maxRight(n, INT_MIN);
        vector<int> minMaxLeftMaxRight(n, INT_MAX);
        int maxL = INT_MIN;
        int maxR = INT_MIN;
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            maxL = max(maxL, height[i]);
            maxLeft[i] = maxL;
        }

        for(int i = n - 1; i >= 0; i--) {
            maxR = max(maxR, height[i]);
            maxRight[i] = maxR;
        }

        for(int i = 0; i < n; i++) {
            minMaxLeftMaxRight[i] = min(maxLeft[i], maxRight[i]);
        }

        for(int i = 0; i < n; i++) {
            int val = minMaxLeftMaxRight[i] - height[i];
            if (val >= 0) {
                res += val;
            }
        }

        return res;
    }
};