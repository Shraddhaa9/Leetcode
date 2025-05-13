class Solution {
    int exploreSize(vector<vector<int>>& grid, int r, int c, set<pair<int, int>>& visited) {
        bool rowInbounds = r >= 0 && r < grid.size();
        bool colInbounds = c >= 0 && c < grid[0].size();

        if(!rowInbounds || !colInbounds) return 0;

        if(grid[r][c] == 0) return 0;

        if(visited.count({r, c})) return 0;

        visited.insert({r, c}); 
        int size = 1;       
        size += exploreSize(grid, r-1, c, visited);
        size += exploreSize(grid, r+1, c, visited);
        size += exploreSize(grid, r, c-1, visited);
        size += exploreSize(grid, r, c+1, visited);
        return size;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = INT_MIN;
        set<pair<int, int>> visited;

        for(int r = 0; r < grid.size(); r++) {
            for(int c = 0; c < grid[0].size(); c++) {
                int size = exploreSize(grid, r, c, visited);
                maxSize = max(size, maxSize);
            }
        }   

        return maxSize;     
    }
};