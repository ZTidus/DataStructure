# Array

- 对于矩阵的遍历，索引变量不要用`i`, `j`表示，使用`row`, `col`表示。

## 排序

- 二维数组排序
```java

public class Demo {
    public static void main(String[] args) {
        int[][] arr;
        Arrays.sort(arr, (a, b) -> b[1] - a[1]);
    }
}
```

- 对二维数组的遍历
```java
public class Demo {
    public static void main(String[] args) {
        int[][] boxTypes = new int[][];

        for (int[] boxType: boxTypes) {

        }
    }
}
```

- 数组反转
```java
Collections.reverse(list);
```
注意这个reverse没有返回值。

- List -> array

- Arrays.sort()默认正向排序，如何反向排序呢，对于一维数组来说。
