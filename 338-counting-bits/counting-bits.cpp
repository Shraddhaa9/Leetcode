class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i = 0; i <= n; i++) {
            int counter = 0;
            for (int j = 0; j < 32; j++) {
                if ((i & (1 << j)) != 0) {
                    counter++;
                }
            }
            ans.push_back(counter);
        }

        return ans;
    }
};