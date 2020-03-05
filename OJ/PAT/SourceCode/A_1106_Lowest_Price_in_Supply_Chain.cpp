// A_1106
// error: r /= 100忘记加上
// error: vector和数组是不同的，要使用push_back()方法进行添加元素，而不是
// 像数组那般下标赋值
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 100010;
const double INF = 1e12;  // 10^12
vector<int> Node[maxn];  // Node[i]存放i的孩子编号
int n, num = 0;  // num为价格最低的叶子结点个数，即为最终输出中的以最低价格卖出的卖家数目
double p, r, ans = INF;
void DFS(int index, int depth) {
    if(Node[index].size() == 0) {  // 抵达叶子结点
        double price = p * pow(1+r, depth);  // 当前价格
        if(price < ans) {  // 当期价格小于全局最低价格
            ans = price;
            num = 1;
        } else if(price == ans)
            num++;
        return;
    }
    for(int i = 0; i < Node[index].size(); i++) {
        DFS(Node[index][i], depth+1);
    }
}
int main() {
    int k, child;
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        if(k != 0) {
            for(int j = 0; j < k; j++) {
                // scanf("%d", &Node[i][j]); !!!vector是不能使用这种方法赋值的
                scanf("%d", &child);
                Node[i].push_back(child);
            }
        }
    }
    DFS(0, 0);  // DFS入口
    printf("%.4f %d", ans, num);
    return 0;
}

