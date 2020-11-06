#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/* Leetcode */
/* Type: string */
/* 题目信息 */
/*
 *1436. Destination City
You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

 

Example 1:

Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
Example 2:

Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".
Example 3:

Input: paths = [["A","Z"]]
Output: "Z"
 

Constraints:

1 <= paths.length <= 100
paths[i].length == 2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
All strings consist of lowercase and uppercase English letters and the space character.
 */

/* my solution */
// solution-1, 16ms, defeat 95.68%
class Solution {
public:
    string destCity(vector<vector<string> >& paths) {
        bool flag = true;
        map<string, pair<int, int> > mp;
        for (int i = 0; i < paths.size(); i++)
        {
            mp[paths[i][0]].first++;
            mp[paths[i][1]].second++;
        }
        
        for (auto e : mp)
        {
            if (e.second.first == 0 && e.second.second != 0)
                return e.first;
        }
        return "";
    }
};

/* better solution */
// solution-x, ms, defeat %


/* 一些总结 */
// 1. 题意: 给定一二维数组，每个元素是包含起始地和目的地的数组，找出终点地是哪一个（只有入，没有出的那个地方）
// 遍历整个元素，以pair<int, int>, first出度，second是入度,最终结果出度为0入度不为0的就是目的地。
// 需要注意的点: 
// 1. 
// 2. 
// 3. 

