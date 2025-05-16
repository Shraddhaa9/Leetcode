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

class Solution {
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
        unordered_map<Node*, Node*> map;

        if (!node) return nullptr;

        return dfs(node, map);
    }
};