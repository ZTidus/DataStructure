#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int a[5] = {1, 2, 3, 4, 5};
    fill(a, a+5, 23);
    for(int i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
