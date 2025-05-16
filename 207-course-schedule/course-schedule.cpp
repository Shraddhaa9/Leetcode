#if 1
class Solution {
    // DFS topological
private:
    bool dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& onPath) {
        visited[node] = true;
        onPath[node] = true;

        for(auto neighbour : adjList[node]) {
            if(!visited[neighbour]) {
                if (!dfs(neighbour, adjList, visited, onPath)) {
                    return false;
                }
            } else if (onPath[neighbour]) {
                return false; // there is a cycle
            }
        }

        onPath[node] = false;
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

        for(int i = 0; i <numCourses; i++) {
            if(!visited[i]) {
                if(!dfs(i, adjList, visited, onPath)) {
                    return false;
                }
            }
        }

        return true;
    }
};
#endif