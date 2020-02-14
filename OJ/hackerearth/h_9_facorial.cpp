// h_9_facorial
#include <cstdio>
int main(){
    int n;
    scanf("%d", &n);
    int product = 1;
    for(int i = 1; i <= n; i++){
        product *= i;
    }
    printf("%d\n", product);
    return 0;
}
