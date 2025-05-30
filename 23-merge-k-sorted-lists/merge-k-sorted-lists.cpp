/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
#if 1
struct cmp {
    // this is for minheap
    bool operator()(const ListNode* l1, const ListNode* l2) const {
        return l1->val > l2->val;
    }
};

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for(auto node : lists) {
            if(node) pq.push(node);
        }

        ListNode dummy(0);
        ListNode *curr = &dummy;
        while(!pq.empty()) {
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
            if(curr->next) pq.push(curr->next);
        }

        return dummy.next;
    }
#else
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;

        while(l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if(l1) curr->next = l1;
        if(l2) curr->next = l2;

        return dummy->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int nodes = lists.size();
        if(!nodes) return nullptr;

        int interval = 1;
        while(interval < nodes) {
            for(int i = 0; i < nodes - interval; i += interval * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }

            interval *= 2;
        }

        return lists[0];
    }
#endif
};