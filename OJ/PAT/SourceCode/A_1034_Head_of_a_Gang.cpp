// A_1034
// pend
// 有点懵
#include <iostream>
#include <map>
using namespace std;

const int maxn = 2010;  // 最大总人数

map<int, string> intToString;  // 编号->姓名
map<string, int> stringToInt;  // 姓名->编号
map<string, int> Gang;         // head->人数

int G[maxn][maxn] = {0}, weight[maxn] = {0};  // 邻接矩阵，点权
int n, k, numPerson = 0;
bool vis[maxn] = {false};

// DFS
void DFS(int newVisit, int& head, int& numMember, int& totalValue) {
    numMember++;
    vis[nowVisit] = true;
    if(weight[nowVisit] > weight[head]) {
        head = nowVisit;
    }
    for(int i = 0; i < numPerson; i++) {
        if(G[nowVisit][i] > 0) {  // nowVisit 可以到达 i
            totalValue += G[nowVisit][i];
            G[nowVisit][i] = G[i][nowVisit] = 0;
            if(vis[i] == false) {
                DFS(i, head, numMember, totalValue);
            }
        }
    }
}
// DFSTrave
void DFSTrave() {
    for(int i = 0; i < numPerson; i++) {
        if(vis[i] == false) {
            int head = i, numMember = 0, totalValue = 0;
            DFS(i, head, numMember, totalValue);
            if(numMember > 2 && totalValue > k) {
                Gang[intToString[head]] = numMember;
            }
        }
    }
}

int main() {
    int w;
}
