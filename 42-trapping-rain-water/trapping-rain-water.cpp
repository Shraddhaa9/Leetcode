class Solution {
#if 0
public:
    int trap(vector<int>& height) {
        int res = 0;
        int l = 0;
        int r = height.size() - 1;
        int leftMax = height[l];
        int rightMax = height[r];

        while(l < r) {
            if (leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }

        return res;
    }
#else
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n, height[0]);
        vector<int> maxRight(n, height[n-1]);
        vector<int> minMaxLeftMaxRight(n, INT_MAX);
        int maxL = height[0];
        int maxR = height[n-1];
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
            int val = minMaxLeftMaxRight[i] - height[i];
            if (val >= 0) {
                res += val;
            }
        }

        return res;
    }
#endif
};