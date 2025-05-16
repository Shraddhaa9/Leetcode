class Solution {
private:
    // vector<int> computeInDegrees(vector<vector<int>>& adjList) {
    //     vector<int> result(adjList.size(), 0);
    //     for( auto adj : adjList) {
    //         for (auto v : adj) {
    //             result[v]++;
    //         }
    //     }
    //     return result;
    // }
    bool dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& onPath, stack<int>& s) {
        visited[node] = true;
        onPath[node] = true;

        for(auto neighbour : adjList[node]) {
            if(!visited[neighbour]) {
                if (!dfs(neighbour, adjList, visited, onPath, s)) {
                    return false;
                }
            } else if (onPath[neighbour]) {
                return false; // there is a cycle
            }
        }

        onPath[node] = false;
        s.push(node);
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto preReq : prerequisites) {
            int u = preReq[0];
            int v = preReq[1];
            adjList[u].push_back(v);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> onPath(numCourses, false);
        stack<int> s;

        for(int i = 0; i <numCourses; i++) {
            if(!visited[i]) {
                if(!dfs(i, adjList, visited, onPath, s)) {
                    return false;
                }
            }
        }

        return true;
    }
};