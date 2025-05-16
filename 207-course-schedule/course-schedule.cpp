#if 1
class Solution {
    // BFS topological
private:
    vector<int> computeInDegrees(vector<vector<int>>& adjList) {
        vector<int> result(adjList.size(), 0);
        for( auto adj : adjList) {
            for (auto v : adj) {
                result[v]++;
            }
        }
        return result;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        for(auto preReq : prerequisites) {
            int a = preReq[0];
            int b = preReq[1];
            adjList[b].push_back(a);
        }

        vector<int> inDegrees = computeInDegrees(adjList);
        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if (inDegrees[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto node = q.front();
                q.pop();
                count++;

                for(auto neighbour : adjList[node]) {
                    inDegrees[neighbour]--;
                    if(inDegrees[neighbour] == 0) {
                        q.push(neighbour);
                    }
                }
            }
        }

        return count == numCourses;
    }
};
#else
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