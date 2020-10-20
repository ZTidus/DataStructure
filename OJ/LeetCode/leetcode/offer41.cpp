#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Offer */
/* Type: heap */
/* 题目信息 */
/*
 *剑指 Offer 41. 数据流中的中位数
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例 1：

输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]
示例 2：

输入：
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
输出：[null,null,2.00000,null,2.50000]
 

限制： 最多会对 addNum、findMedian 进行 50000 次调用。
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxHeap; // default is max heap
    priority_queue<int, vector<int>, greater<int> > minHeap;
    MedianFinder() {

    }
    
    void addNum(int num) {
        // 1. push element into maxHeap
        maxHeap.push(num);
        // 2. then pop the max value of maxHeap, push it into the minHeap
        int x = maxHeap.top(); maxHeap.pop();
        minHeap.push(x);
        if (maxHeap.size() < minHeap.size())
        {
            int y = minHeap.top(); minHeap.pop();
            maxHeap.push(y);
        }

    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) * 0.5;
        else
            return maxHeap.top();

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

