// h_10_find_product
// 1. 将次方写成了^
#include <cstdio>
int main(){
    int n;
    scanf("%d", &n);
    long long int product = 1;
    for(int i = 0; i < n; i++){
        int element;
        scanf("%d", &element);
        product = ((product *element) % 1000000007);
    }
    printf("%d", product);
    return 0;
}