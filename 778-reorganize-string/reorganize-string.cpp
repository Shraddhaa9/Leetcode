class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        int n = s.size();
        vector<int> freq(26, 0);
        for(char c : s) {
            freq[c - 'a']++;
        }

        for (int f : freq) {
            if (f > (n + 1) / 2) return "";
        }

        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < 26; i++) {
            if (freq[i] > 0)
                pq.push({freq[i], 'a' + i});
        }

        while(pq.size() > 1) {
            auto [cnt1, char1] = pq.top(); pq.pop();
            auto [cnt2, char2] = pq.top(); pq.pop();
            res += char1;
            res += char2;
            cnt1 -= 1;
            cnt2 -= 1;
            if (cnt1 > 0) pq.push({cnt1, char1});
            if (cnt2 > 0) pq.push({cnt2, char2});
        }

        if(!pq.empty()) {
            auto [freqLeft, chLeft] = pq.top();
            if (freqLeft > 1) return "";
            res += chLeft;
        }

        return res;
    }
};