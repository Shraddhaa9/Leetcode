class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int stone : stones) {
            pq.push(stone);
        }

        while(pq.size() >= 2) {
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();

            if(x != y) {
                y = y - x;
                pq.push(y);
            }
        }

        if(pq.size()) return pq.top();

        return 0;
    }
};