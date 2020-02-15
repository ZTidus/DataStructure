#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <math.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100  // 最大顶点数
#define INFINITY 65535  // 代表无穷大

typedef int Status; // 函数类型 
typedef char VertexType;  // 顶点类型
typedef int EdgeType;  // 边上权值类型
typedef int Boolean;
Boolean visited[MAX];  // 访问标志数组，初值为0，访问过后为1

/* 图的邻接矩阵存储结构 */
typedef struct
{
    VertexType vexs[MAXVEX];  // 顶点表
    EdgeType arc[MAXVEX][MAXVEX];  // 邻接矩阵
    int numVertexes, numEdges;  // 图中当前顶点数与边数
} MGraph;

/* 建立无向网图的邻接矩阵表示 */
void CreateMGraph(MGraph *G)
{
    int i, j, k, w;
    printf("输入顶点数和边数:\n");
    scanf("%d, %d", &G->numVertexes, &G->numEdges);
    // 顶点表
    for(i=0; i<G->numVertexes; i++)
        scanf(&G->vexs[i]);
    // 邻接矩阵初始化
    for(i=0; i<G->numVertexes; i++)
        for(j=0; j<G->numVertexes; j++)
            G->arc[i][j] = INFINITY;
    for(k=0; k<G->numEdges; k++)
    {
        printf("输入边(vi, vj)的下标i, j和权值w:\n");
        scanf("%d, %d, %d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }
}

/* 邻接矩阵的深度优先递归算法 */
void DFS(MGraph G, int i)
{
    int j;
    visited[i]  = TRUE;
    printf("%c ", G.vexs[i]);  // 打印顶点
    for(j=0; j<G.numVertexes; j++)
        if(G.arc[i][j] == 1 && !visited[j])
            DFS(G, j);  // 递归调用邻接顶点
}

/* 邻接矩阵的深度遍历操作 */
void DFSTraverse(MGraph G)
{
    int i;
    for(i=0; i<G.numVertexes; i++)
        visited[i] = FALSE;  // 初始所有顶点状态为未访问状态
    for(i=0; i<G.numVertexes; i++)
        if(!visited[i])
            DFS(G, i);
}

/* 邻接矩阵的广度遍历算法 */
void BFSTraverse(MGraph M)
{
	int i, j;
	Queue Q;
	for(i=0; i<G.numVertexes; i++)
	    visited[i] = FALSE;
	InitQueue(&Q);  // 初始化辅助队列
	for(i=0; i<G.numVertexes; i++)  // 循环每一个顶点
	{
		if(!visited[i])
		{
			visited[i] = TRUE;
			printf("%c ", G.vexs[i]);  // 打印顶点
			EnQueue(&Q, i);            // 将此顶点入队列
			while(!QueueEmpty(Q))      // 若当前队列不为空
			{
				DeQueue(&Q, &i);       // 将队中元素出队列
				for(j=0; j<G.numVertexes; j++)
				{
					if(G.arc[i][j] == 1 && !visited[j])
					{
						visited[j] = TRUE;
						printf("%c ", G.vex[j]);    // 打印顶点
						EnQueue(&Q, j); 
					}
				} 
			} 
		}
	} 
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	return 0;
} 
