/*
1. 关于12倍数的考虑
*/
#include <cstdio>
int main(){
	int T; // number of test case
	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		int N; // seat number
		scanf("%d", &N);
		int divisor = N / 12;

		int temp = N % 12;  // 余数：0 - 11
		int opposite;
		// complex desicion
		if(temp == 1){
			opposite = 12;
			printf("%d WS\n", divisor*12+opposite);
		} else if(temp == 6){
			opposite = 7;
			printf("%d WS\n", divisor*12+opposite);
		} else if(temp == 7){
			opposite = 6;
			printf("%d WS\n", divisor*12+opposite);
		} else if(temp == 0){
			opposite = 1;
			printf("%d WS\n", (divisor-1)*12+opposite);
		} else if(temp == 2){
			opposite = 11;
			printf("%d MS\n", divisor*12+opposite);
		} else if(temp == 5){
			opposite = 8;
			printf("%d MS\n", divisor*12+opposite);
		} else if(temp == 8){
			opposite = 5;
			printf("%d MS\n", divisor*12+opposite);
		} else if(temp == 11){
			opposite = 2;
			printf("%d MS\n", divisor*12+opposite);
		} else if(temp == 3){
			opposite = 10;
			printf("%d AS\n", divisor*12+opposite);
		} else if(temp == 4){
		    opposite = 9;
			printf("%d AS\n", divisor*12+opposite);
		} else if(temp == 9){
			opposite = 4;
			printf("%d AS\n", divisor*12+opposite);
		} else if(temp == 10){
			opposite = 3;
			printf("%d AS\n", divisor*12+opposite);
		}
		/*
	    if(temp == 1 || temp == 6 || temp == 7 || temp == 12)
	    	printf("%d WS\n", 12*divisor+temp);
	    if(temp == 2 || temp == 5 || temp == 8 || temp == 11)
	    	printf("%d MS\n", 12*divisor+temp);
	    if(temp == 3 || temp == 4 || temp == 9 || temp == 10)
	    	printf("%d AS\n", 12*divisor+temp); 
	    	*/
	}
}