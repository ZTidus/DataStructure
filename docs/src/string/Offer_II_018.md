
# Offer_II_018
type: string

difficulty: easy

---

## [Problem Info][problem_link]

## Attention

## Answer - 1
双指针。将原字符串过滤掉非字母非数字。一个从左，一个从右，对比字符是否相同。

- java

```java
class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (Character.isLetterOrDigit(ch)) {
                sb.append(ch);
            }
        }
        String newStr = sb.toString();
        int left = 0;
        int right = sb.toString().length() - 1;
        boolean res = true;
        while (left < right) {
            if (AToa(newStr.charAt(left)) != AToa(newStr.charAt(right))) {
                res = false;
                break;
            }
            left++;
            right--;
        }
        return res;
    }
    private char AToa(char ch) {
        if (ch >= 97 && ch <= 122) {
            return (char)(ch - 32);
        }
        return ch;
    }
}
```
- time: 3ms
- beat 55.25%
- big O: O(n)

## Answer - 2

[problem_link]: https://leetcode-cn.com/problems/XltzEq/

