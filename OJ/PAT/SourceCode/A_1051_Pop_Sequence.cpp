// A_1051_Pop_Sequence
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    // m: the maximum capacity of stack
    // n: the length of push sequence
    // k: the number of pop sequences to be checked
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    for(int i = 0; i < k; i++){
        bool flag = false;
        stack<int> s;
        vector<int> v(n+1);
        for(int j = 1; j <= n; j++)
            scanf("%d", &v[j]);
        int current = 1;
        for(int j = 1; j <= n; j++){
            s.push(j);
            if(s.size() > m) break;
            while(!s.empty() && s.top() == v[current]){
                s.pop();
                current++;
            } 
        }
        if(current == n + 1) flag = true;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}