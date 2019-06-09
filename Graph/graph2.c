#include <stdio.h>
#include <stdlib.h>
typedef char VertexType;  // 顶点类型
typedef int EdgeType;  // 边上权值类型
#define MAXVEX 100;  // 最大顶点数

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
