// h_19_Reversed_Linked_List
// -------- mine --------
// submission 1: WA
// 1. stack中元素访问只能是st.top()!!!
// 2. stack中的操作没有输出功能。
// 3. 此题是链表题，算是取巧了
// -------- mine --------
#include <cstdio>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0)  // 若元素为偶数，推入栈中
            st.push(arr[i]);
        else {  // 不是偶数，先检查栈是否空，不空，将栈输出完毕
            while(!st.empty()) {
                printf("%d ", st.top());
                st.pop();  // 当前栈顶元素输出后立即出栈
            }
            printf("%d ", arr[i]);  // 偶数输出完毕后，输出奇数
        }
    }
    // 若全为偶数
    while(!st.empty()) {
        printf("%d ", st.top());
        st.pop();
    }
    return 0;
}