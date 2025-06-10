class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> result(size, 0);
        stack<int> s;

        for(int i = size - 1; i >= 0; i--) {
            while(!s.empty() && temperatures[i] >= temperatures[s.top()]) {
                s.pop();
            }
            if(!s.empty()) {
                result[i] = s.top() - i;
            }

            s.push(i);
        }
        return result;
    }
};