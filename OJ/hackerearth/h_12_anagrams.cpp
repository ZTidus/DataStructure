// h_12_anagrams
// WRONG. 这道题还没搞明白

#include <cstdio>
#include <string.h>
int main(){
    int t;
    char a[10000], b[10000];
    scanf("%d\n%s\n%s", &t, &a, &b);
    int del_a = 0, del_b = 0;
    for(int i = 0; i < strlen(a); i++){
        if(a[i] != a[t]) del_a++;
    }
    for(int i = 0; i < strlen(b); i++){
        if(b[i] != a[t]) del_b++;
    }
    printf("%d", del_a+del_b);
    return 0;
}