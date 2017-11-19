#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
#define ok 1
#define error 0
typedef int Status; 
typedef struct 
{
	int *pBase;
	int front;
	int rear;
}Queue;
void initial(Queue *);
Status EnQueue(Queue *,int val);
Status DeQueue(Queue *,int *);
Status GetHead(Queue *,int *);
void YangHui(int N);                                                                                                                                                                                                                    
int main()
{   
   int N;
   printf("输入杨辉三角的行数\n");
   scanf("%d",&N); 
   YangHui(N);
   return 0;
}
void initial(Queue *queue) 
{
  queue->pBase=(int *)malloc(sizeof(int)*MaxSize);
  queue->front=queue->rear=0;
  printf("初始化成功\n"); 
} 
Status EnQueue(Queue *queue,int val)
{  
    if((queue->rear+1)%MaxSize==queue->front)
    {
       printf("队列已满，无法执行插入操作\n");
       return error;
    }
    else
    {
	queue->pBase[queue->rear]=val;
	queue->rear=(queue->rear+1)%MaxSize;
    }
    return ok;
}
Status DeQueue(Queue *queue,int *val)
{
	if(queue->front==queue->rear)
	{
		printf("队列为空,没有元素可以删除\n");
		return error;
	}
	else
	{
		*val=queue->pBase[queue->front];
		queue->front=(queue->front+1)%MaxSize;	
	}
	return ok; 
}
Status GetHead(Queue *queue,int *val)
{   if(queue->front==queue->rear)
	{
		printf("队列为空,没有队头元素\n");
		return error;
	}
	else
	{
	 *val=queue->pBase[queue->front];
    }
    return ok;
}
void YangHui(int N)//N为行数
{ 
  Queue q;
  int s,t,j; 
  initial(&q);
  printf("1\n");
  EnQueue(&q,0);
  EnQueue(&q,1);
  EnQueue(&q,1);
  for(j=2;j<=N;j++)
  { 
   
  	EnQueue(&q,0);
  	do
  	{
  		DeQueue(&q,&s);
  		GetHead(&q,&t);
		  if(t)
		  printf("%d\t",t);
		  else
		  printf("\n");
		EnQueue(&q,s+t); 
	}while(t!=0);
  }
  DeQueue(&q,&s);
}






  
