#include<stdio.h>

int main() {
    int m = 1;
    while(m != 0) {
        printf("Input m, m*m square, when input 0: exit\n");
        scanf("%d", &m);
        // 设定n*n方阵
        int move[8][2] = {
            {0, 1}, {1, 1}, {1, 0}, \
            {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}
        };

        // Posttion
        struct position {
            int x, y;
        }

        char maze[m+2][m+2];
        position stack[m*m + 1];

        int top; // stack top
        int i, x, y, ok;
        position p;


    }
}
