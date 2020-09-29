#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include "dbg.h"
using namespace std;

/* Offer */
/* Type: Stack */
/* 题目信息 */
/*
 *剑指 Offer 09. 用两个栈实现队列
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/* my solution */


/* better solution */
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        stk1.push(value);
    }
    
    int deleteHead() {
        if (stk2.empty())
        {
            while (!stk1.empty())
            {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        
        if (stk2.empty())
        {
            return -1;
        }
        else
        {
            int res = stk2.top();
            stk2.pop();
            return res;
        }
        

    }
private:
    stack<int> stk1;
    stack<int> stk2;
};


/* 一些总结 */
// 1. 题意: 
//
// 需要注意的点: 
// 1. 不必看上边输入输出样例，很懵。
// 2. 两个栈实现队列，一个实现入队操作，一个实现出队操作，剩下的就是一些控制语句。
// 3. 

