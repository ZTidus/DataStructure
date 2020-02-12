// Cost of balloons
// 1. 在建立新变量，特别是需要累加的变量进行计算，检查是否进行了初始化操作。

#include <cstdio>
int main(){
	int T; // The number of test cases
	scanf("%d", &T);

	for(int i = 0; i < T; i++){
		int green_balloon_cost, purple_ballon_cost;
	    int n; // The number of participants
	    int min_cost;

		scanf("%d%d", &green_balloon_cost, &purple_ballon_cost);
		scanf("%d", &n);

		// 前边写下边这句代码时，未将f_num和s_num初始化，最后得到的是很大的数，但OJ也没把错误给出来。
		int f_num = 0, s_num = 0, operation_1_cost, operation_2_cost;
		for(int j = 0; j < n; j++){
			int f, s;
			scanf("%d%d", &f, &s);
			if(f == 1) f_num++;
			if(s == 1) s_num++;
		}
		// TEST
		// printf("%d %d\n\n", f_num, s_num);

		// operation 1
		operation_1_cost = f_num * green_balloon_cost + s_num * purple_ballon_cost;
		// operation 2
		operation_2_cost = f_num * purple_ballon_cost + s_num * green_balloon_cost;
		if(operation_1_cost >= operation_2_cost) min_cost = operation_2_cost;
		else min_cost = operation_1_cost;

		printf("%d\n", min_cost);
	}
	return 0;
}