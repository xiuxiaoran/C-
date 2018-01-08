/*
*******************完成图的创建，用邻接矩阵存储图，完成深度遍历和广度遍历
*******************简化版，图的顶点即为顶点序号，没有用字符当做图的顶点
********************只解决了无向图的邻接矩阵矩阵问题，还有邻接表没解决 
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 20          //边数和顶点数最大值 
typedef int VertexType;//顶点类型
typedef int Arc;        //边类型
typedef struct Graph
{
	VertexType vex[MAX+1];
	Arc arc[MAX+1][MAX+1]; 
	int vexnum;
	int arcnum; 
}MGraph;
bool flag[MAX+1];
//=======================创建无向图========================// 
void CreatGraph(MGraph *G)
{
     int i,j,k;
     int r1,r2; 
	 printf("请输入顶点的个数,顶点即为序数");
	 scanf("%d",&G->vexnum);
	 for(i=1;i<=G->vexnum;i++)
	 {
	   G->vex[i]=i;
	 }
	 printf("输入边的个数\n");
	 scanf("%d",&G->arcnum);
	    for(i=1;i<=G->vexnum;i++)
		   for(j=1;j<=G->vexnum;j++) 
		    G->arc[i][j]=0;//初始化二维数组 
	 printf("输入顶点间的边,如(1 2)\n");
	 for(k=0;k<G->arcnum;k++)
	 {
	    scanf("%d %d",&r1,&r2);
	    G->arc[r1][r2]=G->arc[r2][r1]=1;
	 }	
} 
//=====================输出图的邻接矩阵=================// 
void PrintGraph(MGraph *G)
{
	int i,j;
	for(i=1;i<=G->vexnum;i++) 
	{
	   for(j=1;j<=G->vexnum;j++)
	     printf("%3d",G->arc[i][j]);
	     printf("\n");
	}
	   
}
//=========================图的深度优先遍历算法==========================// 
void DFS(MGraph *G,int i)//从图的第i个节点开始递归遍历 
{
	int j;
	flag[i]=true;
	printf("%3d ",G->vex[i]);
	for(j=1;j<=G->vexnum;j++)
	    if(G->arc[i][j]==1&&!flag[j])
		DFS(G,j); 
}
void DFSTraver(MGraph *G)
{
    int i;
	for(i=1;i<=G->vexnum;i++)
	    flag[i]=false;//初始化标志数组,所有的点都是没有访问过的 
	for(i=1;i<=G->vexnum;i++)
	{
		if(!flag[i])//如果标志数组为true，这个点没有访问，执行DFS递归函数
		 DFS(G,i); 
	}
	printf("\n");	
} 
//=======================图的广度优先遍历算法===============================//
/*---广度优先遍历——循环队列的实现----*/
typedef struct{ 
 int vex[MAX]; 
 int front; 
 int rear; 
}Queue;
/*----初始化队列q---*/
void InitQueue(Queue *q) 
{ 
  q->front=0; 
  q->rear=0; 
}

/*----元素e入队列---*/
int EnQueue(Queue *q,int e) { 
  if((q->rear+1)%MAX==q->front) { 
      printf("队列已满\n"); 
      return 0; 
   } 
   else { 
    q->vex[q->rear]=e; 
    q->rear=(q->rear+1)%MAX; 
    return 1; 
   } 
} 

/*----出队列---*/
int DeQueue(Queue *q) { 
  int t; 
  if(q->front==q->rear) { 
     printf("队列为空!\n"); 
     return 0; 
   } 
   else { 
     t=q->vex[q->front]; 
     q->front=(q->front+1)%MAX; 
     return t; 
   } 
} 
 
void BFSTraver(MGraph *G)
{
	int i,j;
	Queue Q;
	for(i=1;i<=G->vexnum;i++)
	     flag[i]=false;
    InitQueue(&Q);
	for(i=1;i<=G->vexnum;i++)
	   if(!flag[i])
   {
	   	flag[i]=true;
	   	printf("%3d",G->vex[i]);
	   	EnQueue(&Q,i);
	   	while(Q.rear!=Q.front)
	   	{
	   	    DeQueue(&Q);
	   	    for(j=1;j<=G->vexnum;j++)
			   {
			   	if(G->arc[i][j]==1&&flag[j]==false) 
			   	    {
			   	    	flag[j]=true;
			   	    	printf("%3d",G->vex[j]);
			   	    	EnQueue(&Q,j);
					}
				} 
		 }
	   	
	} 
}
int main()
{   MGraph *graph=(MGraph *)malloc(sizeof(MGraph));
    printf("创建一个新图\n");
    CreatGraph(graph); 
    printf("输出图的邻接矩阵\n"); 
    PrintGraph(graph);
    printf("图的深度优先遍历为:\n");
    DFSTraver(graph); 
    printf("图的广度优先遍历为:\n");
    BFSTraver(graph);
	return 0;
}
