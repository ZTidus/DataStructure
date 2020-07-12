/* 1502. Can Make Arithmetic Progression From Sequence
 * Given an array of numbers arr. A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Return true if the array can be rearranged to form an arithmetic progression, otherwise, return false.



Example 1:

Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.
Example 2:

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.


Constraints:

2 <= arr.length <= 1000
-10^6 <= arr[i] <= 10^6
*/

/* mine's solution */
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // 1. sort
        sort(arr.begin(), arr.end());
        // 2. 对比相邻两个元素的差值是否相同
        int compare_val = arr[1] - arr[0];
        printf("%d\n", compare_val);
        for (int i = 1; i < arr.size() - 1; i++) {
            //for (int j = i + 1; j < arr.size(); j++) {
            int j = i + 1;
            printf("i=%d, j=%d, 差值=%d\n", i, j, arr[j] - arr[i]);
            if (arr[j] - arr[i] != compare_val) return false;
            //}
        }
        return true;
    }
};

/* better solution */
// 下面这段可以改成这样的
        for (int i = 2; i < arr.size() - 1; i++) {
            if (arr[i] - arr[i-1] != compare_val) 
                return false;
        }
