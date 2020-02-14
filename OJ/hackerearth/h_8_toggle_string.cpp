// h_8_toggle_string
#include <cstdio>
#include <string.h>
int main(){
    char str[100];
    scanf("%s", str);
    for(int i = 0; i < strlen(str); i++){
        if(str[i] >= 97) str[i] -= 32;
        else str[i] += 32;
    }
    printf("%s", str);
    return 0;
}