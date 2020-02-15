// 1. 关于回文数和回文字符的问题：理清前后两个字母的位置关系即可
// 2. 我竟然忘记写输入代码...
#include <cstdio>
#include <string.h>
int main(){
	char str[100];
	scanf("%s", str);
	int flag = 1;
	for(int i = 0; i < strlen(str); i++){
		if(str[i] != str[strlen(str)-i-1]){
			flag = 0;
			break;
		}
	}
	if(flag == 1) printf("YES");
	else printf("NO");

	return 0;
}