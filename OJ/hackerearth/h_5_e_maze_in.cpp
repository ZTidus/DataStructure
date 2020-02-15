// h_5_e_maze_in
#include <cstdio>
#include <string.h>
int main(){
    int maze[2] = {0, 0};
    char str[200];
    scanf("%s", str);
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == 'L') maze[0]--;
        else if(str[i] == 'R') maze[0]++;
        else if(str[i] == 'U') maze[1]++;
        else if(str[i] == 'D') maze[1]--;
    }
    printf("%d %d\n", maze[0], maze[1]);

    return 0;
}