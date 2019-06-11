/* Prim算法生成最小生成树 */
void MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	ing adjvex[MAXVEX];  // 保存相关顶点下标
	int lowcost[MAXVEX];  // 保存相关顶点边的权值
	lowcost[0] = 0;       // 初始化第一个权值为0，表明 v0 已加入最小生成树
	                      //  lowcost为0，就是此下标的顶点已加入生成树
	adjvex[0] = 0;        
	// 初始化
	for(i=0; i<G.numVertexes; i++)
	{
		lowcost[i] = G.arc[0][i];  // 将邻接矩阵的第一行读入数组
		adjvex[i] = 0;             // 初始化都为 v0 的下标
	}
	for(i=0; i<G.numVertexes; i++)
	{
		min = INFINITY;  // 初始化最小权值为无穷大
		j = 1; k = 0;
		while(j < G.numVertexes)  // 循环全部顶点
		{
			if(lowcost[j] != 0 && lowcost[j] < min)
			// 如果权值不为0，此表明已经是生成树的结点，故不参与最小权值的比较
			{
				min = lowcost[j];
				k = j;
			} 
			j++; 
		}
		printf("(%d, %d)", adjvex[k], k);  // 打印当前顶点边中权值最小边
		lowcost[k] = 0;                    // 将当前顶点的权值设置为0，表明已经完成任务
		
		for(j=1; j<G.numVertexes; j++)
		{
			if(lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		} 
	} 
} 
