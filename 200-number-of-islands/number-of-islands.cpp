#if 1
class Solution {
private:
    void explore (int row, int col, vector<vector<char>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == '0') return;

        grid[row][col] = '0';

        explore(row - 1, col, grid);
        explore(row, col - 1, grid);
        explore(row + 1, col, grid);
        explore(row, col + 1, grid);

        return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    explore(i, j, grid);
                }
            }
        }
        return islands;
    }
};
#else

#endif
#if 0
class Solution {
private:
    bool explore(vector<vector<char>>& grid, int r, int c, set<pair<int, int>>& visited) {
        bool rowInbounds = r >= 0 && r < grid.size();
        bool colInbounds = c >= 0 && c < grid[0].size();

        if(!rowInbounds || !colInbounds) return false;

        if(grid[r][c] == '0') return false;

        if(visited.count({r, c})) return false;

        visited.insert({r, c});        
        explore(grid, r-1, c, visited);
        explore(grid, r+1, c, visited);
        explore(grid, r, c-1, visited);
        explore(grid, r, c+1, visited);
        return true;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        set<pair<int, int>> visited;

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
#endif