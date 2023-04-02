
# offer_069
type: array

和852题相同。

difficulty:

---

## [Problem Info][problem_link]

## Attention

## Answer - 1
因为题目中说“题目数据保证 arr
是一个山脉数组”，这样的话，一开始肯定的递增的，这样就只需要判断当前元素值大于后一个元素值就可以了。

- java
```java
class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int res = -1;
        for (int i = 1; i < arr.length-1; i++) {
            if (arr[i] > arr[i+1]) {
                res = i;
                break;
            }
        }
        return res;
    }
}
```

- time: ms
- beat %
- big O:

## Answer - 2

[problem_link]:

