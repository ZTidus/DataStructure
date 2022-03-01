# Java

## Array

- 复制整数数组，例如int[] a, 如何快速复制出一个一样的，不用去遍历?
```java
int[] a = {1, 2, 3};
int[] b = a.clone();
```

- set -> list
```java
List<Integer> res = new ArrayList<>(set);
```
- list -> []

- int[] to string
```java
private String join(int[] nums) {
    StringBuilder res = new StringBuilder();
    for (int i = 0; i < nums.length; i++) {
        res.append(nums[i]);
    }
    return res.toString();
}
```

- 清空list
```java
list.clear();
```

## String
- 判断字符是否是字母
- 反转字符串
- 判断是否是元音字母
```java
public boolean isVowel(char ch) {
    return "aeiouAEIOU".indexOf(ch) >= 0;
}
```

### StringBuilder
- append(String s)
- reverse(String s)
- length()
- setChatAt(int index, char ch)

## set
- add(): 添加元素
- contains(): 是否包含某元素

## Map
### 值得注意的方法
- getOrDefault()