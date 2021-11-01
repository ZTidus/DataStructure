/* 1299. Replace Elements with Greatest Element on Right Side
 * Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.



Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]


Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5
*/

/* my solution */
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int len = arr.size();
        for (int i = 0; i < len - 1; i++) {
            int max = -1;
            // 找出arr[i]右方最大的数
            for (int j = i + 1; j < len; j++) {
                if (arr[j] > max) max = arr[j];
            }
            arr[i] = max;
        }
        arr[len-1] = -1;
        return arr;
    }
};
/* better solution */
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxv = -1, temp;
        for (int i = arr.size() - 1; i >= 0; i--) {
            temp = arr[i];
            arr[i] = maxv;
            maxv = max(maxv, temp);
        }
        return arr;
    }
};
/* 一些总结 */
// 1. c++ max()函数掌握
// 2. 从右向左遍历，因为总是在找右边最大的。
