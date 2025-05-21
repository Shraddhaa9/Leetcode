class Solution {
struct cmp {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first > b.first;
    }
};

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n+1);
        for(auto edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adjList[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        pq.push({0, k});
        set<int> visited;
        int time = 0;

        while(!pq.empty()) {
            auto [w1, n1] = pq.top();
            pq.pop();
            if(visited.count(n1)) {
                continue;
            }

            visited.insert(n1);
            time = max(time, w1);

            for(auto& [v2, w2] : adjList[n1]) {
                if(!visited.count(v2)) {
                    pq.push({ w1 + w2, v2});
                }
            }
        }

        return visited.size() == n ? time : -1;
    }
};