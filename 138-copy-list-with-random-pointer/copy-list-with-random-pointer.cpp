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

// we use 2-passes here
// cannot copy directly as when random node points to not allocated/created map
// it can create issue as its pointing original node or null node maybe
// so we can keep copy of node pointers using hashmap
// in first pass we will create newNodes and will map it to original list's node
// once thats completed
// we will traverse through list again and LINK THE NEW LIST
// we will link, next link as well as random link using hashmap
// will return VALUE OF HEAD OF MAP, which will give us correct result

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