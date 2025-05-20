class Solution {
public:
    struct compare {
        bool operator()(const vector<int>&a, const vector<int> &b) {
            return a[0] < b[0];
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;

        for(auto point : points) {
            int x = point[0];
            int y = point[1];
            int distance = (x * x) + (y * y);
            pq.push({distance, x, y});
            if (pq.size() > k) pq.pop(); // Keep heap size to k
        }

        vector<vector<int>> result;
        while (!pq.empty()) {
            auto& top = pq.top();
            result.push_back({top[1], top[2]});
            k--;
            pq.pop();
        }

        return result;
    }
};