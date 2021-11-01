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
/* Type: sort */
/* 题目信息 */
/*
 *75. Sort Colors
 */

/* my solution */
// solution-x, ms, defeat %
// 自己使用快排
class Solution {
public:
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        
    }
private:
    void quickSort(vector<int>& nums, int low, int high)
    {
        int temp;
        int i = low, j = high;
        
        if (low < high)
        {
            temp = nums[low];
            while (i < j)
            {
                // find value that less than temp
                while (j > i && nums[j] >= temp) j--;
                if (i < j)
                {
                    nums[i] = nums[j];
                    i++;
                }
                while (i < j && nums[i] < temp) i++;
                if (i < j)
                {
                    nums[j] = nums[i];
                    j--;
                }
            }
            nums[i] = temp;
            quickSort(nums, low, i - 1);
            quickSort(nums, i + 1, high);
        }
    }
};

/* better solution */
// solution-2, 0ms, defeat 100%
// two pointers
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int pn = nums.size() - 1;
        int curr = 0;
        while (curr <= pn)
        {
            if (nums[curr] == 0)
            {
                swap(nums[p0], nums[curr]);
                p0++;
                curr++;
            }
            else if (nums[curr] == 2)
            {
                swap(nums[curr], nums[pn]);
                pn--;
            }
            else
                curr++;
        }
        
    }
};

/* 一些总结 */
// 1. 题意: 为给定数组排序, 不能使用函数sort, 只有3种数字：0, 1, 2
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

/*
 * main test
 */

int main(void)
{
    Solution solution;

    return 0;
}

