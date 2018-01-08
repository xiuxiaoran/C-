/*
*******************���ͼ�Ĵ��������ڽӾ���洢ͼ�������ȱ����͹�ȱ���
*******************�򻯰棬ͼ�Ķ��㼴Ϊ������ţ�û�����ַ�����ͼ�Ķ���
********************ֻ���������ͼ���ڽӾ���������⣬�����ڽӱ�û��� 
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 20          //�����Ͷ��������ֵ 
typedef int VertexType;//��������
typedef int Arc;        //������
typedef struct Graph
{
	VertexType vex[MAX+1];
	Arc arc[MAX+1][MAX+1]; 
	int vexnum;
	int arcnum; 
}MGraph;
bool flag[MAX+1];
//=======================��������ͼ========================// 
void CreatGraph(MGraph *G)
{
     int i,j,k;
     int r1,r2; 
	 printf("�����붥��ĸ���,���㼴Ϊ����");
	 scanf("%d",&G->vexnum);
	 for(i=1;i<=G->vexnum;i++)
	 {
	   G->vex[i]=i;
	 }
	 printf("����ߵĸ���\n");
	 scanf("%d",&G->arcnum);
	    for(i=1;i<=G->vexnum;i++)
		   for(j=1;j<=G->vexnum;j++) 
		    G->arc[i][j]=0;//��ʼ����ά���� 
	 printf("���붥���ı�,��(1 2)\n");
	 for(k=0;k<G->arcnum;k++)
	 {
	    scanf("%d %d",&r1,&r2);
	    G->arc[r1][r2]=G->arc[r2][r1]=1;
	 }	
} 
//=====================���ͼ���ڽӾ���=================// 
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
//=========================ͼ��������ȱ����㷨==========================// 
void DFS(MGraph *G,int i)//��ͼ�ĵ�i���ڵ㿪ʼ�ݹ���� 
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
	    flag[i]=false;//��ʼ����־����,���еĵ㶼��û�з��ʹ��� 
	for(i=1;i<=G->vexnum;i++)
	{
		if(!flag[i])//�����־����Ϊtrue�������û�з��ʣ�ִ��DFS�ݹ麯��
		 DFS(G,i); 
	}
	printf("\n");	
} 
//=======================ͼ�Ĺ�����ȱ����㷨===============================//
/*---������ȱ�������ѭ�����е�ʵ��----*/
typedef struct{ 
 int vex[MAX]; 
 int front; 
 int rear; 
}Queue;
/*----��ʼ������q---*/
void InitQueue(Queue *q) 
{ 
  q->front=0; 
  q->rear=0; 
}

/*----Ԫ��e�����---*/
int EnQueue(Queue *q,int e) { 
  if((q->rear+1)%MAX==q->front) { 
      printf("��������\n"); 
      return 0; 
   } 
   else { 
    q->vex[q->rear]=e; 
    q->rear=(q->rear+1)%MAX; 
    return 1; 
   } 
} 

/*----������---*/
int DeQueue(Queue *q) { 
  int t; 
  if(q->front==q->rear) { 
     printf("����Ϊ��!\n"); 
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
    printf("����һ����ͼ\n");
    CreatGraph(graph); 
    printf("���ͼ���ڽӾ���\n"); 
    PrintGraph(graph);
    printf("ͼ��������ȱ���Ϊ:\n");
    DFSTraver(graph); 
    printf("ͼ�Ĺ�����ȱ���Ϊ:\n");
    BFSTraver(graph);
	return 0;
}
