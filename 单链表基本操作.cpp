         /*单链表的应用*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int Elemtype; 
typedef struct Node
{
    Elemtype data;
	struct Node *PNext;
}NODE,* PNODE;

PNODE Creat_List(void);
void Treval_List(PNODE PHead);
bool Empty_List(PNODE PHead);
int Length_List(PNODE PHead);
void Sort_List(PNODE PHead,int length);
void Insert_List(PNODE PHead,int pos,Elemtype data);
void Delete_List(PNODE PHead,int pos,Elemtype *data);
void Destroy(PNODE PHead);
PNODE Merge_List(PNODE La,PNODE Lb,PNODE Lc);

int main()
 {
    PNODE La=NULL;//表头 
    PNODE Lb=NULL;
    PNODE Lc=NULL;
    int  lengtha;//表长 
    int  lengthb;
    Elemtype  data; //插入的数据 
	int pos;//插入，删除的位置 
    Elemtype  val;//接收删除的结点数据 
    printf("创建链表La\n");
    La=Creat_List();
    if(Empty_List(La))
    {
    printf("链表为空\n");
    return 0;
    }
    else
	{
	lengtha=Length_List(La);
    printf("链表长度=%d\n",lengtha);
    Sort_List(La,lengtha);
    printf("排序后输出链表\n");
    Treval_List(La);
    }
    printf("创建链表Lb\n");
    Lb=Creat_List();
    if(Empty_List(Lb))
    {
    printf("链表为空\n");
    return 0;
    }
    else
	{
	lengthb=Length_List(Lb);
    printf("链表长度=%d\n",lengthb);
    Sort_List(Lb,lengthb);
    printf("排序后输出链表\n");
    Treval_List(Lb);
    }
    Lc=Merge_List(La,Lb,Lc);
    Treval_List(Lc);
    
    printf("输入插入的位置和数据");
	scanf("%d %d",&pos,&data);
	Insert_List(Lc,pos,data);
	Treval_List(Lc);
	printf("输入删除数据的位置\n");
	scanf("%d",&pos);
	Delete_List(Lc,pos,&val); 
	printf("删除的数据是 %d\n",val);
	Treval_List(Lc);
	Destroy(Lc);
	printf("空间释放\n");
    return 0;
 }
 
 PNODE Creat_List(void)
 {
 	int len;//数据个数
	int i;
	int data;
	PNODE PNew;
	PNODE PTail;
	PNODE PHead=NULL;
	PHead=(PNODE)malloc(sizeof(NODE));
    PTail=PHead;
    PTail->PNext=NULL;//头结点 
	if(PHead==NULL)
	{
	printf("空间分配失败！\n");
	exit(-1);//程序终止 
    }
	 
   
	printf("输入链表的长度len=");
	scanf("%d",&len);
	
	for(i=0;i<len;i++)
	{
		PNew=(PNODE)malloc(sizeof(NODE));
		if(PNew==NULL)
	    {
	      printf("空间分配失败！\n");
	      exit(-1);//程序终止 
        }
        PTail->PNext=PNew;
        PNew->PNext=NULL;
        PTail=PNew;//开辟节点并连接节点，空间分配成功 
	} 
	PNew=PHead->PNext;
	for(i=0;i<len;i++)
	{
	   	printf("输入第%d个结点数值\n",i+1);
		scanf("%d",&data);
		PNew->data=data;
		PNew=PNew->PNext;	
	}
	return PHead;		
} 
 void Treval_List(PNODE PHead)
 {
 	PNODE p=NULL;
 	p=PHead->PNext;
 	while(p!=NULL)
 	{
 		printf("%d\t",p->data);
 		p=p->PNext;//指针移动 
	}
	printf("\n");
 }
 bool Empty_List(PNODE PHead)
 {  
 	if(PHead->PNext==NULL)
 		return true;
	else
	    return false;	 
 }
 
 int Length_List(PNODE PHead)
 {
 	PNODE p;
 	int length=0;
 	p=PHead->PNext;
	while(p!=NULL)
	{
		length++;
		p=p->PNext;	
	} 
	return length;
 }
 void Sort_List(PNODE PHead,int length)
 {
 	int i,j,t;
 	PNODE p,q;
 	for(i=0,p=PHead->PNext;i<length-1;i++,p=p->PNext)
 	   for(j=i+1,q=p->PNext;j<length;j++,q=q->PNext)
 	   	if(p->data>q->data)
 	   	{
 	   		t=p->data;
 	   		p->data=q->data;
		    q->data=t;	
		}	   		
 }
 void Insert_List(PNODE PHead,int pos,Elemtype data)
 {  int length;
    int i=0;
    PNODE p=PHead;
    length=Length_List(PHead);
 	if(pos<1||pos>length+1)
 	{
 		printf("插入位置不合法\n");
 		exit(-1);	
	}
	while(i<pos-1&&p!=NULL)
	{
		i++;
		p=p->PNext;
	}       //判断插入位置 
	PNODE PNew=(PNODE)malloc(sizeof(NODE));
    if(PNew==NULL)
	{
	printf("空间分配失败！\n");
	exit(-1);//程序终止 
    }
	PNew->PNext=p->PNext;
	p->PNext=PNew;
	PNew->data=data;		
 }
 void Delete_List(PNODE PHead,int pos,Elemtype *data)
 {
 	int length;
    int i=0;
    PNODE p=PHead;
    PNODE q=NULL;
    length=Length_List(PHead);
 	if(pos<1||pos>length)
 	{
 		printf("删除位置不合法\n");
 		exit(-1);	
	}
	while(i<pos-1&&p->PNext!=NULL)//判断条件多余吗? 
	{
		p=p->PNext;
		i++;
	}
	q=p->PNext;
	p->PNext=q->PNext;
	*data=q->data;//保存删除的值 
	free(q);//删除节点 	
 }
 void Destroy(PNODE PHead)
 { 
     PNODE p=PHead;
     PNODE q=NULL;
	 while(p)
	 {  q=p;
	 	p=p->PNext;
	 	free(q);
	 } 
	 
 } 
PNODE Merge_List(PNODE La,PNODE Lb,PNODE Lc)
 {
 	PNODE pa=La->PNext;
 	PNODE pb=Lb->PNext;
 	PNODE pc=NULL; //参照Insert函数 
 	Lc=pc=La;//将La的头结点赋给Lc
 	while(pa&&pb)
 	{
 	    if(pa->data<=pb->data)
 	    {
		 pc->PNext=pa;
		 pc=pa;
		 pa=pa->PNext;	
 	    }
 	    else
 		 {
		 pc->PNext=pb;
		 pc=pb;
		 pb=pb->PNext;	
 	     }
 	 }
 	pc->PNext=pa?pa:pb;//剩余结点处理 
	 free(Lb);	
	 return Lc;//需要返回头指针，不然找不到链表的头 
 }
 
 
 
 
 
 
 
 
