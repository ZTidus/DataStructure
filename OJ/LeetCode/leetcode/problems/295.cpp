#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/* Leetcode */
/* Type: heap */
/* 题目信息 */
/*
 *
295. Find Median from Data Stream
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
 */

/* my solution */
// solution-x, ms, defeat %


/* better solution */
// solution-x, ms, defeat %
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // 1. 先把数据插入maxHeap
        maxHeap.push(num);
        // 2. 把maxHeap的最大值拿出来插入minHeap
        // 保证minHeap最小的值都是maxHeap中最大的
        int x = maxHeap.top(); maxHeap.pop();
        minHeap.push(x);
        //
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
// 1. 题意: 在动态数据流中找到中位数。
// 使用两个堆，首先将数据流分成两部分，左边使用max heap存储，右边使用min
// heap存储，左边最大的值小于右边最小的值，保证两个堆的大小不超过1.
// 需要注意的点: 
// 1. 一个数据流，让找出中位数。对于数据流这种动态（流动）的数据，如果使用数组存储，那么每次新进来一个数据都进行排序的话，效率很低。处理动态数据来说一般使用的数据结构是栈、队列、二叉树、堆。
// 2. 
// 3. 

