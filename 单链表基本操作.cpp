         /*�������Ӧ��*/

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
    PNODE La=NULL;//��ͷ 
    PNODE Lb=NULL;
    PNODE Lc=NULL;
    int  lengtha;//�� 
    int  lengthb;
    Elemtype  data; //��������� 
	int pos;//���룬ɾ����λ�� 
    Elemtype  val;//����ɾ���Ľ������ 
    printf("��������La\n");
    La=Creat_List();
    if(Empty_List(La))
    {
    printf("����Ϊ��\n");
    return 0;
    }
    else
	{
	lengtha=Length_List(La);
    printf("������=%d\n",lengtha);
    Sort_List(La,lengtha);
    printf("������������\n");
    Treval_List(La);
    }
    printf("��������Lb\n");
    Lb=Creat_List();
    if(Empty_List(Lb))
    {
    printf("����Ϊ��\n");
    return 0;
    }
    else
	{
	lengthb=Length_List(Lb);
    printf("������=%d\n",lengthb);
    Sort_List(Lb,lengthb);
    printf("������������\n");
    Treval_List(Lb);
    }
    Lc=Merge_List(La,Lb,Lc);
    Treval_List(Lc);
    
    printf("��������λ�ú�����");
	scanf("%d %d",&pos,&data);
	Insert_List(Lc,pos,data);
	Treval_List(Lc);
	printf("����ɾ�����ݵ�λ��\n");
	scanf("%d",&pos);
	Delete_List(Lc,pos,&val); 
	printf("ɾ���������� %d\n",val);
	Treval_List(Lc);
	Destroy(Lc);
	printf("�ռ��ͷ�\n");
    return 0;
 }
 
 PNODE Creat_List(void)
 {
 	int len;//���ݸ���
	int i;
	int data;
	PNODE PNew;
	PNODE PTail;
	PNODE PHead=NULL;
	PHead=(PNODE)malloc(sizeof(NODE));
    PTail=PHead;
    PTail->PNext=NULL;//ͷ��� 
	if(PHead==NULL)
	{
	printf("�ռ����ʧ�ܣ�\n");
	exit(-1);//������ֹ 
    }
	 
   
	printf("��������ĳ���len=");
	scanf("%d",&len);
	
	for(i=0;i<len;i++)
	{
		PNew=(PNODE)malloc(sizeof(NODE));
		if(PNew==NULL)
	    {
	      printf("�ռ����ʧ�ܣ�\n");
	      exit(-1);//������ֹ 
        }
        PTail->PNext=PNew;
        PNew->PNext=NULL;
        PTail=PNew;//���ٽڵ㲢���ӽڵ㣬�ռ����ɹ� 
	} 
	PNew=PHead->PNext;
	for(i=0;i<len;i++)
	{
	   	printf("�����%d�������ֵ\n",i+1);
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
 		p=p->PNext;//ָ���ƶ� 
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
 		printf("����λ�ò��Ϸ�\n");
 		exit(-1);	
	}
	while(i<pos-1&&p!=NULL)
	{
		i++;
		p=p->PNext;
	}       //�жϲ���λ�� 
	PNODE PNew=(PNODE)malloc(sizeof(NODE));
    if(PNew==NULL)
	{
	printf("�ռ����ʧ�ܣ�\n");
	exit(-1);//������ֹ 
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
 		printf("ɾ��λ�ò��Ϸ�\n");
 		exit(-1);	
	}
	while(i<pos-1&&p->PNext!=NULL)//�ж�����������? 
	{
		p=p->PNext;
		i++;
	}
	q=p->PNext;
	p->PNext=q->PNext;
	*data=q->data;//����ɾ����ֵ 
	free(q);//ɾ���ڵ� 	
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
 	PNODE pc=NULL; //����Insert���� 
 	Lc=pc=La;//��La��ͷ��㸳��Lc
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
 	pc->PNext=pa?pa:pb;//ʣ���㴦�� 
	 free(Lb);	
	 return Lc;//��Ҫ����ͷָ�룬��Ȼ�Ҳ��������ͷ 
 }
 
 
 
 
 
 
 
 
