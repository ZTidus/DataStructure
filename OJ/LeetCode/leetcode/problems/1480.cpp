// 1480. Running Sum of 1d Array
// 
// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
// 
// Return the running sum of nums.
// 
// 
// 
// Example 1:
// 
// Input: nums = [1,2,3,4]
// Output: [1,3,6,10]
// Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
// Example 2:
// 
// Input: nums = [1,1,1,1,1]
// Output: [1,2,3,4,5]
// Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
// Example 3:
// 
// Input: nums = [3,1,2,10,1]
// Output: [3,4,6,16,17]
// 
// 
// Constraints:
// 
// 1 <= nums.length <= 1000
// -10^6 <= nums[i] <= 10^6
//
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int len = nums.size();
        int sum[len];
        //sum[len] = {0};
        int whole = 0;
        for (int i = 0; i < len; i++) {
            sum[i] = nums[i] + whole;
            whole += nums[i];
        }
        for (int i = 0; i < len; i++) {
            nums[i] = sum[i];
        }
        return nums;
    }
};


// 1.
// 这是从新算了一个新的数组，将每次算的sum存入新数组中，再循环将对应的数字赋值给nums
//

// better choice

//class Solution {
//public:
//    vector<int> runningSum(vector<int>& nums) {
//        int i = 1;
//        while (i < nums.size()) {
//            nums[i] += nums[i-1];
//            i++;
//        }
//        return nums;
//    }
//};
