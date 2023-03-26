# HashMap

- 统计词频：使用map.getOrDefault(关键字，默认值)函数
```java
for (int i = 0; i < words1.length; i++) {
    String str = words1[i];
    words1Map.put(str, words1Map.getOrDefault(str, 0) + 1);
}
```
- 找到map中频次最高和频次次高的
- 多值排序


- 遍历值：`map.values()`


## Set

- `boolean add()`
集合中不存在，添加返回true;
集合中存在，添加返回false.
