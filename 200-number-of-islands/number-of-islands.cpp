class Solution {
private:
    bool explore(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited) {
        bool rowInbounds = r >= 0 && r < grid.size();
        bool colInbounds = c >= 0 && c < grid[0].size();

        if(!rowInbounds || !colInbounds) return false;

        if(grid[r][c] == '0') return false;

        if(visited[r][c]) return false;

        visited[r][c] = true;
        explore(grid, r-1, c, visited);
        explore(grid, r+1, c, visited);
        explore(grid, r, c-1, visited);
        explore(grid, r, c+1, visited);
        return true;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        for(int r = 0; r < grid.size(); r++) {
            for(int c = 0; c < grid[0].size(); c++) {
                if (explore(grid, r, c, visited) == true ) {
                    islands++;
                }
            }
        }

        return islands;
    }
};