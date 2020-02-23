// h_20_Remove_Friends
// -------- mine --------
// submission 1: 
// 1. prob pass.
// -------- mine --------
#include <cstdio>
struct Node {
    int popularity;
    int next;
}node[100000];
int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        int n, k;
        scanf("%d%d", &n, &k);
        int popularity[n]; // 朋友受欢迎程度
        for(int j = 0; j < n; j ++) {
            scanf("%d", &popularity[i]);
        }
        bool deleteFriend = false;
        for(int j = 0; j < n; j++) {
            if(popularity[i] < popularity[i+1]) {

            }
        }     
    }
}