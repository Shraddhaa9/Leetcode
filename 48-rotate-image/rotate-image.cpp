class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // take the transpose
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = i+1; j < matrix[0].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // now reverse row wise
        for (auto &row : matrix) {
            reverse(row.begin(), row.end());
        }
    }
};