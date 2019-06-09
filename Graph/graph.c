/* 图的邻接矩阵存储结构 */
typedef char VertexType;  // 顶点类型
typedef int EdgeType;  // 边上权值类型
#define INFINITY 65535;  // 代表无穷大
#define MAXVEX 100;  // 最大顶点数
typedef struct
{
    VertexType vexs[MAXVEX];  // 顶点表
    EdgeType arc[MAXVEX][MAXVEX];  // 邻接矩阵
    int numVertexes, numEdges;  // 图中当前顶点数与边数
} MGraph;
