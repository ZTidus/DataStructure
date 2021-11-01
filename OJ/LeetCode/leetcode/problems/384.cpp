#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <cmath>
using namespace std;

/* Leetcode */
/* Type:  */
/* 题目信息 */
/*
 *384. Shuffle an Array
Given an integer array nums, design an algorithm to randomly shuffle the array.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the integer array nums.
int[] reset() Resets the array to its original configuration and returns it.
int[] shuffle() Returns a random shuffling of the array.
 

Example 1:

Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must be equally likely to be returned. Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

 

Constraints:

1 <= nums.length <= 200
-106 <= nums[i] <= 106
All the elements of nums are unique.
At most 5 * 104 calls will be made to reset and shuffle.
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-1, 152ms, defeat 35.70%
class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i : nums) {
            nums_first.push_back(i);
            nums_copy.push_back(i);
        }
        //return nums_first;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums_copy;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(nums_first.begin(), nums_first.end(), std::default_random_engine(seed));
        return nums_first;
    }
private:
    vector<int> nums_copy;
    vector<int> nums_first;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

/* 一些总结 */
// 1. 题意: 实现两个函数，一个重置数组函数，一个洗牌数组函数
//
// 需要注意的点: 
// 1. std::shuffle
// 2. std::array
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;

    return 0;
}

