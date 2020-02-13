// 1. 字符串的输入问题
// 2. 字符书写，单引号与双引号

#include <cstdio>
#include <string.h>
int main(){
	char str[20];
	scanf("%s", str);
	int z_num = 0, o_num = 0;
	for(int i = 0; i < strlen(str); i++){
		if(str[i] == 'z') z_num++;
		else o_num++;
	}
	if(o_num == 2*z_num) printf("Yes");
	else printf("No");

	return 0;
}