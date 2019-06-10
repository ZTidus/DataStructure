#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <time.h>
#include <math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100  // 最大顶点数
#define INFINITY 65535  // 代表无穷大

typedef int Status;  // 函数类型 
typedef char VertexType;  // 顶点类型
typedef int EdgeType;  // 边上权值类型

typedef int Boolean;
Boolean visited[MAX];  // 访问标志数组，初值为0，访问过后为1

// 边表结点
typedef struct EdgeNode
{
    int adjvex;  // 邻接点域，存储该顶点对应下标
    EdgeType weight;  // 存储权值
    struct EdgeType *next;  // 链域，指向下一个邻接点
} EdgeNode;

// 顶点表结点
typedef struct VertexNode
{
    VertexType data;  // 顶点域，存储顶点信息
    EdgeNode *firstedge;  // 边表头指针
} VertexNode, AdjList[MAXVEX];

typedef struct 
{
    AdjList adjList;
    int numVertexes, numEdges;  // 图中当前顶点数和边数
} GraphAdjList;

/* 建立图的邻接表结构 */
void CreateALGraph(GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;
    printf("输入顶点数和边数:\n");
    scanf("%d, %d", &G->numVertexes, &G->numEdges);
    // 建立顶点表
    for(i=0; i<G->numVertexes; i++)
    {
        scanf(&G->adjList[i].data);  // 输入顶点信息
        G->adjList[i].firstedge = NULL;  // 将边表置为空
    }

    // 建立边表
    for(k=0; k<G->numEdges; k++)
    {
        printf("输入边(vi, vj)上的顶点序号:\n");
        scanf("%d, %d", &i, &j);
        e = (EdgeNode *)malloc(sizeof(EdgeNode)); // 申请空间生成边表结点
        // 头插法
        e->adjvex = j;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;

        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}

/* 邻接表的深度优先递归算法 */
void DFS(GraphAdjList GL, int i)
{
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c ", GL->adjList[i].data);  // 打印顶点
    p = GL->adjList[i].firstedge;
    while(p)
    {
        if(!visited[p->adjvex])
            DFS(GL, p->adjvex);  // 对邻接顶点递归调用
        p = p->next;
    }
}

/* 邻接表的深度遍历操作 */
void DFSTraverse(GraphAdjList GL)
{
    int i;
    for(i=0; i<GL.numVertexes; i++)
        visited[i] = FALSE;  // 初始化所有顶点状态为未访问
    for(i=0; i<GL.numVertexes; i++)
        if(!visited[i])
            DFS(GL, i);
}

/* 邻接表的广度优先遍历 */
void BFSTraverse(GraphAdjList GL) 
{
	int i;
	EdgeNode *p;
	Queue Q;
	for(i=0; i<GL->numVertexes; i++)
	    visited[i] = FALSE;    // 初始化所有顶点状态为未访问
	InitQueue(&Q);
	for(i=0; i<GL->numVertexes; i++)
	{
		if(!visited[i])
		{
			visited[i] = TRUE;
			printf("%c ", GL->adjList[i].data);  // 打印顶点
			EnQueue(&Q, i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q, &i);
				p = GL->adjList[i].firstedge;  // 找到当前顶点边表链表头指针
				while(p)
				{
					if(!visited[p->adjvex])
					{
						visited[p->adjvex] = TRUE;
						printf("%c ", GL->adjList[p->adjvex].data);
						EnQueue(&Q, p->adjvex);    // 将顶点入队列 
					}
					p = p->next;
				 } 
			 } 
		}
	 } 
}

int main(void) 
{
	GraphAdjList G;
	CreateALGraph(&G);
	return 0;
}
