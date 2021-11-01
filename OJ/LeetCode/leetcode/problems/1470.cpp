/* 1470. Shuffle the Array

Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

Return the array in the form [x1,y1,x2,y2,...,xn,yn].



Example 1:

Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7]
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].
Example 2:

Input: nums = [1,2,3,4,4,3,2,1], n = 4
Output: [1,4,2,3,3,2,4,1]
Example 3:

Input: nums = [1,1,2,2], n = 2
Output: [1,2,1,2]


Constraints:

1 <= n <= 500
nums.length == 2n
1 <= nums[i] <= 10^3
*/


//class Solution {
//public:
//    vector<int> shuffle(vector<int>& nums, int n) {
//        vector<int> a[n], b[n];
//        for (int i = 0; i < n; i++) {
//            a[i] = nums[i];
//            b[i] = nums[i+n];
//        }
//        int ai = 0, bi = 0
//        for (i = 0; i < 2n; i += 2) {
//            nums[i] = a[ai];
//            nums[i+1] = b[bi];
//            ai++;
//            bi++;
//        }
//        
//    }
//};

// 我的思路：将nums分成两个长度为n的ventor，然后就重新赋值，一个接一个，但是编译报错。
// 看了一个别人解析的，非常简单，使用了vector的push_back()方法
//
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(nums[i]);
            res.push_back(nums[i+n]);
        }
        return res;
    }
};
