/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

#if 1
class Solution {
    // BFS
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> map;
        queue<Node*> q;

        Node *clone = new Node(node->val);
        map[node] = clone;
        q.push(node);

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            for(auto neighbour : curr->neighbors) {
                if(map.find(neighbour) == map.end()) {
                    map[neighbour] = new Node(neighbour->val);
                    q.push(neighbour);
                }

                map[curr]->neighbors.push_back(map[neighbour]);
            }

        }

        return clone;
    }
};
#else
class Solution {
    // DFS
private:
    Node* dfs(Node *node, unordered_map<Node*, Node*>& map) {
        if (map.find(node) != map.end()) return map[node];

        Node *newNode = new Node(node->val);
        map[node] = newNode;

        for(auto neighbour : node->neighbors) {
            newNode->neighbors.push_back(dfs(neighbour, map));
        }

        return newNode;
    }

public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> map;
        return dfs(node, map);
    }
};
#endif