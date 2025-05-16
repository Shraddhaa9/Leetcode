#if 1
class Solution {
    // DFS topological
private:
    bool dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& onPath, stack<int>& s) {
        visited[node] = true;
        onPath[node] = true;

        for(auto neighbour : adjList[node]) {
            if(!visited[neighbour]) {
                if (!dfs(neighbour, adjList, visited, onPath, s)) {
                    return false;
                }
            } else if (onPath[neighbour]) {
                    return false; // found a cycle
            }
        }

        onPath[node] = false;
        s.push(node);
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto preReq : prerequisites) {
            int a = preReq[0];
            int b = preReq[1];
            adjList[b].push_back(a);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> onPath(numCourses, false);
        stack<int> s;

        for(int i = 0; i <numCourses; i++) {
            if(!visited[i]) {
                if(!dfs(i, adjList, visited, onPath, s)) {
                    return {};
                }
            }
        }

        vector<int> schedule;
        while(!s.empty()) {
            schedule.push_back(s.top());
            s.pop();
        }

        return schedule;
    }
};
#endif