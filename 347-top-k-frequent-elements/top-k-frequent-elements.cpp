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
// 20 cases passed, but got TLE for one
// so need to have better approach

//------

// sort the array - O(n logn)
// once array is sorted - traverse through the array, store element with index, occurence
// 



// also we can use priority queue for max elements as well
// it will give top occurence elements 
// but that will be o(log n) - so i think this works

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
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
    }
};