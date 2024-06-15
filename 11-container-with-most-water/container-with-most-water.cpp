class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxArea = 0;
        while(l < r)
        {
            int area = (r - l) * min(height[l], height[r]);
            maxArea = max(maxArea, area);

            if (height[l] < height[r])
                l = l+1;
            else
                r = r-1;            
        }

        return maxArea;
    }
};


// first will keep the max height noted so far
// can i start from other end of array and check for max matching that end????