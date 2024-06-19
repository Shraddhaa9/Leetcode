class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        for(int i=1; i <= size(nums); i++) {
            if (!binary_search(begin(nums), end(nums), i))
                result.push_back(i);
        }
        return result;
    }
};


// traverse an array
// record max number - no need for this, right?
// based on the number of array members present 
// sorting an array takes - nlogn



// ----- TC -----
// Time Complexity : O(nlogn), we iterate over the range [1, n]
// which takes O(n) and for each iteration, we check if that element
// occurs in nums using binary search which takes another O(logn)
// giving a total time of O(nlogn)
// Space Complexity : O(sort), the only extra space required is
// the one used in internal sorting algorithm. Ignoring that space,
// we can say it to be O(1)