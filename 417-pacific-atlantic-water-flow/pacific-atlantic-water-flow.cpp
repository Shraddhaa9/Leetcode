class Solution {
private:
    vector<vector<bool>> bfs(queue<pair<int, int>>& q, vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> reachable(m, vector<bool>(n, false));

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            reachable[r][c] = true;

            for(auto [dr, dc]: dirs) {
                int nr = r + dr;
                int nc = c + dc;

                // if out of bound, skip
                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                
                // skip if already visited or can't flow uphill
                if(reachable[nr][nc] || matrix[nr][nc] < matrix[r][c]) continue;

                q.push({nr, nc});
            }
        }

        return reachable;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        if (heights.empty() || heights[0].empty()) return result;

        int Rows = heights.size();
        int Cols = heights[0].size();
        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;

        for(int i = 0; i < Rows; i++) {
            pacificQueue.push({i, 0});
            atlanticQueue.push({i, Cols - 1});
        }

        for(int i = 0; i < Cols; i++) {
            pacificQueue.push({0, i});
            atlanticQueue.push({Rows - 1, i});
        }

        auto pacificReachable = bfs(pacificQueue, heights);
        auto atlanticReachable = bfs(atlanticQueue, heights);

        for(int i = 0; i < Rows; i++) {
            for(int j = 0; j < Cols; j++) {
                if(pacificReachable[i][j] && atlanticReachable[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};