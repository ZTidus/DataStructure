# String

## Java

1. 遍历
- 遍历 
  - string, str.charAt(i)

2. 转换
- char -> int
- int -> char
 
* string -> char[]: s.toCharArray()
* char[] -> string: new String(char[] values)

- string -> int: "32" -> 32
- int -> string: 32 -> "32"

- 判断字符是否是数字或字母
```java
Character.isLetterOrDigit(char ch);
Character.isDigit(char ch);
```

- 求字母的频次
使用数组。
```java
String str = "abc";
int[] charCounter = new int[26];
for (int i = 0; i < str.length(); i++) {
    char ch = str.charAt(i);
    charCounter[ch - 'a']++;
}
```

- 字符串反转: 利用StringBuffer
```java
StringBuffer sb = new StringBuffer();
return sb.reverse().toString();
```

### 常量识记   
- [a, z] 范围是 [65, 90]
- [A, Z] 范围是 [97, 122]
