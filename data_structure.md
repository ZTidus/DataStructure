# DATA STRUCTURE

## 线性结构

### 1. 线性表

由同类型`数据元素`构成`有序序列`的线性结构。

- 线性表`长度`：表中元素个数
- `空表`：线性表中无元素
- `表头`/`表尾`

### 2. 线性表的顺序存储

利用数组的`连续存储空间顺序存放`线性表的各元素。

```c++
typedef  struct LNode *List;
struct LNode{
    ElementType Data[MAXSIZE];
    int last;  // 指向数组最后一个元素
};
struct LNode L;
List PtrL;

// 访问下标为i的元素：L.Data[i], PtrL->Data[i]
// 线性表长度：L.last+1, PtrL->last+1
```

### 3. 主要操作的实现

- 初始化

```c++
List MakeEmpty(){
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));  // 申请结构
    PtrL->last = -1;  // 置空
    return PtrL;
}
```

- 查找

```c++
// 查找变量X位置
int Find(ElementType X, List PtrL){
    int i = 0;
    while(i <= PtrL->last && PtrL->Data[i] != X) // 两种退出情况
        i++;
    if(i > PtrL->last) return -1; // 未找到
    else return i;  // 找到，返回位置
}
```

查找平均次数为`(n+1)/2`，`O(n)`。  // 运气好，第一个就找到；运气不好，最后一个找到。

- 插入

  > 在第`i`（1<i<n+1)个位置上插入值为X的元素

  将`i-1`之后的元素（包含i-1)移动后一位，再进行插入

  从后往前挪动。

```c++
void Insert(ElementType X, int i, List PtrL){
    int j;
    if(PtrL->last == MAXSIZE-1){  // 表空间已满，不能插入
        printf("表满");
        return;
    }
    if(i < 1 || i > PtrL->last+2){
        printf("位置不合法");
        return;
    }
    for(j = PtrL->last; j >= i-1; j--)  // 移动元素
        PtrL->Data[j+1] = PtrL->Data[j];
    PtrL->Data[i-1] = X;  // 插入元素
    PtrL->last++;  // last仍指向最后元素
    return;
}
```

平均移动次数`n/2`，`O(n)`。

- 删除

  删除表第`i`(1<i<n)个位置上的元素。

```c++
void Delete(int i, List PtrL){
    int j;
    if(i < 1 || i > PtrL->last+1){  // 检查删除位置合法性
        printf("不存在第%d个元素", i);
        return;
    }
    for(j = i; j <= PtrL->last; j++)
        PtrL->Data[j-1] = PtrL->Data[j];
    PtrL->last--; 
    return;
}
```

平均移动次数`(n-1)/2`，`O(n)`。