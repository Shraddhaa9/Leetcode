/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> map;
        Node *curr = head;
        while(curr != nullptr) {
            Node *new_node = new Node(curr->val);
            map[curr] = new_node;
            curr = curr->next;
        }

        curr = head;
        while(curr != nullptr) {
            Node *newNode = map[curr];
            newNode->next = map[curr->next];
            newNode->random = map[curr->random];
            curr = curr->next;
        }

        return map[head];
    }
};