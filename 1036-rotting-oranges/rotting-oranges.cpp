class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0;
        if (q.empty()) return -1;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        while(!q.empty() && fresh > 0) {
            int size = q.size();

            while(size--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }

            time++;
        }

        if (fresh == 0) {
            return time;
        }

        return -1;
        
    }
};