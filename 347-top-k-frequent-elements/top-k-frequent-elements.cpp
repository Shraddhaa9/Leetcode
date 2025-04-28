// Ip: nums
// OP: array having k elements which are most frequent

// IP: 1 to 10^5 -> so no null element array
// nums[i] -> can be negative or positive
// k -> 1 to unique elements
// ANSWER is unique only

// So currently if the input is like this -> 1, 1, 2, 4, 5, 6, 2, 3, 1 and k = 2
// answer should be [1, 2]

// Brute force:
// We can use hashmap with key, value -> where key is element and for value we will
// keep increasing occurences of elements
// once its done, we will get the maximum element from the hashmap, add it to
// result array and remove it from the hashmap
// once we get k elements, we will return


// Question:
// How from hashmap you get top k elements
// lambda function and also by pair, as map is key, value pair so when we traverse we get
// element as pair, we compare 2nd element each time and get the result
// time complexity:
// O(n) + O(N * k) === O(n * k)
// 20 cases passed, but got TLE for one; so need to have better approach
// MISTAKE: traversing hashmap iteratively, which was not needed to find largest element
// in the list

//------
// better approach:
// also we can use priority queue for min heap as well
// We can use hashmap with key, value -> where key is element and for value we will
// keep increasing occurences of elements
// once we have hashmap, we will generate min heap from hashmap - o(n)
// once we have heap, we will remove top k elements
// get the answer array


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
#if 1
        // Better approach:
        vector<int> result;
        unordered_map<int, int> mp;

        for(int num: nums) {
            mp[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto &[num, freq]: mp) {
            pq.push({freq, num});
            if (pq.size() > k) pq.pop();
        }

        while(!pq.empty()) {
            auto [freq, num] = pq.top();
            pq.pop();
            result.push_back(num);
        }

        return result;

#endif

#if 0
        // Brute force approach:
        
        unordered_map<int, int> mp;
        for(auto num : nums)
        {
            mp[num]++;
        }

        vector<int> res;
        int maxE = -1;
        while(k != 0) {
            // for(auto itr : mp)
            {
                auto maxElement = max_element(mp.begin(), mp.end(), [](auto &a, auto &b){
                    return a.second < b.second;
                });
                maxE = maxElement->first;
            }
            res.push_back(maxE);
            k--;
            mp.erase(maxE);
        }

        return res;
#endif
    }
};