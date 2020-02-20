// A_1074_Reversing_Linked_List@liuchuo
// result: AC
#include <iostream>
using namespace std;
int main(){
    int begin, k, n, count = 0;
    cin >> begin >> n >>k;
    int temp, data[100005], next[100005], list[100005], result[100005];
    for(int i = 0; i < n; i++){
        cin >> temp;
        cin >> data[temp] >> next[temp];
    }
    while(begin != -1){
        list[count++] = begin;
        begin = next[begin];
    }
    for(int i = 0; i < count; i++)
        result[i] = list[i];
    for(int i = 0; i < (count - count % k); i++)
        result[i] = list[i / k * k + k - 1 - i % k];
    for(int i = 0; i < count-1; i++)
        printf("%05d %d %05d\n", result[i], data[result[i]], result[i+1]);
    printf("%05d %d -1", result[count-1], data[result[count-1]]);
    return 0;
}
