/* 1464. Maximum Product of Two Elements in an Array
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
Example 3:

Input: nums = [3,7]
Output: 12
 

Constraints:

2 <= nums.length <= 500
1 <= nums[i] <= 10^3
*/

/* mine's solution */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            // attention to the 'j = i + 1'
            // the i and j are two different indics
            // i and j is equal to j and i, switching them is meaningless.
            for (int j = i + 1;  j < nums.size(); j++) {
                int temp = (nums[i] - 1) * (nums[j] - 1);
                if (temp > max) max = temp;
            }
        }
        return max;
    }
};

// 题解: 在数组中任选两个不同的下标，找出其对应的数组值相乘后的最大值。
// 注: 两个下标是不同的，写循环时一定要注意。

/* better solution */
/*
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort() default ascending
        int len = nums.size();
        return (nums[len-1] - 1) * (nums[len-2] - 1);
    }
};
*/
// 先将数组中的数字排序，最高的两个数一定在数组的最后两位，再进行相乘，这样就不必使用循环了。
// 解法1是104ms, 解法2是12ms
