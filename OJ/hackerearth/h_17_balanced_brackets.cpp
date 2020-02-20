// h_17_balanced_brackets
// 我觉得下面是对的，但是是错误的，错误我找不出来在哪里。
#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;  // Number of strings
    cin >> n;
    for(int i = 0; i < n; i++){
        bool flag = true;
        string str;
        cin >> str;
        int len = str.length();
        if(len % 2 != 0){
            cout << "NO\n";
            flag = false;
            continue;
        }
        for(int i = 0; i < (len/2); i++){
            if(str[i] != str[len-i-1]){
                cout << "NO\n";
                flag = false;
                break;
            }
        }
        if(flag == true) cout << "YES\n";
    }
    return 0;
}
