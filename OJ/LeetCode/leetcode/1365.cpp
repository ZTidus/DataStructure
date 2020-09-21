// 1365. How Many Numbers Are Smaller Than the Current Number
// 
// Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
// 
// Return the answer in an array.
// 
// 
// 
// Example 1:
// 
// Input: nums = [8,1,2,2,3]
// Output: [4,0,1,1,3]
// Explanation:
// For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3).
// For nums[1]=1 does not exist any smaller number than it.
// For nums[2]=2 there exist one smaller number than it (1).
// For nums[3]=2 there exist one smaller number than it (1).
// For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
// Example 2:
// 
// Input: nums = [6,5,4,8]
// Output: [2,1,0,3]
// Example 3:
// 
// Input: nums = [7,7,7,7]
// Output: [0,0,0,0]
// 
// 
// Constraints:
// 
// 2 <= nums.length <= 500
// 0 <= nums[i] <= 100

// better 
// map ✓
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> mp;
        vector<int> res;
        
        // find out the number's frequence
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            int cnt = 0;
            for (auto e: mp)
            {
                if (e.first != nums[i] && e.first < nums[i])
                    cnt += e.second;
            }
            res.push_back(cnt);
        }
        
        return res;
    }
};

// 先计算每个值的频数，然后数组进行遍历，在遍历的过程中，将每个数和map中的数进行对比,如果当前值大于map中元素的值，则加上这个元素的频数
