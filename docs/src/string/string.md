# String

## Java

1. 遍历
- 遍历 
  - string, str.charAt(i)

2. 转换
- char -> int
```java
char b = 'b';
System.out.println(b - 'a'); 
```

- int -> char
```java
int a = 97;
sout((char)a);
```
- 'a' + 1 如何变成 'b'
```java
(char)('a' + 1);
```
 
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

关于StringBuffer:
1、添加进入 sb 中时 int 类型数字不用再转，会自动转。
2、sb.charAt()
3、sb.length()

- 字符串排序
1. 先将字符串->字符串数组
2. Arrays.sort(数组)
3. new String(数组)

- 倒序输出字符串
```java
System.out.println(new StringBuffer(s).reverse());
```

### 常量识记   
- [a, z] 范围是 [65, 90]
- [A, Z] 范围是 [97, 122]
