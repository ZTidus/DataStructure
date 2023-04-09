
# offer_006
type:

difficulty:

---

## [Problem Info][problem_link]

有序数组，给定一目标值target，找到数组中和为目标值的两个元素的下标。

## Attention

## Answer - 1
暴力求解，双重循环。

- java
```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] res = new int[2];

        for (int i = 0; i < numbers.length-1; i++) {
            int part1 = numbers[i];
            int match = target - part1;

            for (int j = i+1; j < numbers.length; j++) {
                if (numbers[j] == match) {
                    res[0] = i;
                    res[1] = j;
                }
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
双指针。
先算和，大于target，right左移，反之left右移。

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int l = 0;
        int r = numbers.length-1;
        int[] res = new int[2];

        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                res[0] = l;
                res[1] = r;
                break;
            } else if (sum > target) {
                r--;
            } else {
                l++;
            }
        }
        return res;
    }
}
```

[problem_link]:

