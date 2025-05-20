class Solution {
public:
    struct compare {
        bool operator()(const pair<int, char>& a, const pair<int, char> &b) {
            return a.first < b.first;
        }
    };

    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char c : tasks) {
            freq[c - 'A']++;
        }

        priority_queue<pair<int, char>, vector<pair<int, char>>, compare> pq;

        for(int i = 0; i < 26; i++) {
            if (freq[i]) {
                pq.push({freq[i], i + 'A'});
            }
        }

        queue<pair<int, pair<int, char>>> cooldown; // availableTime, {freq, task}
        int time = 0;
        while(!pq.empty() || !cooldown.empty()) {
            time++;

            if(!cooldown.empty() && cooldown.front().first == time) {
                pq.push(cooldown.front().second);
                cooldown.pop();
            }

            if(!pq.empty()) {
                auto [freq, task] = pq.top();
                pq.pop();
                if(freq > 1) {
                    cooldown.push({time + n + 1, {--freq, task}});
                }
            }
        }

        return time;
    }
};