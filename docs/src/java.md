# Java

## Array

- 复制整数数组，例如int[] a, 如何快速复制出一个一样的，不用去遍历?
```java
int[] a = {1, 2, 3};
int[] b = a.clone();
```

- list to array
```java
list.toArray(new String[0]);
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
- subString
- 将字符串转为字符数组
```java
String str = "hello";
char[] chars = str.toCharArray();
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


ThreadLocal
- 提供线程内的局部变量


- 线程并发：多线程并发的场景下，单线程是用不到这个的
- 传递数据：在同一线程内，不同组件间传递公共变量
- 线程隔离：每个线程内的变量相互独立，不会互相影响。

![](img/img.png)

## Constant
- Integer.MAX_VALUE