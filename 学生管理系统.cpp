#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SPACE ' '
#define STAR '*'
void space(void);//20���ո� 
void star(void);//40���Ǻ� 
struct student *remove(struct student*head,char *pstr);
struct student *add(struct student*head,char *pstr,int n);  
void amend(struct student*head,char *pstr);
void show(struct student*head);
void seek(struct student *head,char *pstr);

struct student
{
	char name[10];
    int number;
	struct student *next; 
};
int main()
{

   char input[10];
    int  n;
    int choice;
	struct student *head=NULL;
	struct student *prev,*current;
	puts("����ѧ�����������н�������");
	while(gets(input)!=NULL&&input[0]!='\0')
	{ 
		current=(struct student*)malloc(sizeof(struct student));
		if(head==NULL)
		head=current;
		else
		prev->next=current;
		current->next=NULL;
		strcpy(current->name,input);
		puts("����ѧ��ѧ��");
		scanf("%d",&current->number);
		getchar();
		prev=current;
		puts("����ѧ������,���н�������");	
	}
	if(head==NULL)
	{ 
	printf("������\n");
	return -1; //����������ų� 
    }
	space();
    space();
    printf("\b\b\b\b\b\b\b��ӭʹ�ñ�ϵͳ\n");
    space(); 
    star();
    printf("\n");
    space();
    printf("1.��Ϣ��ʾ\t\t\t2.��Ϣ�޸�\n");
    space();
    printf("3.��Ϣ���\t\t\t4.��Ϣɾ��\n");
    space();
    printf("5.��Ϣ��ѯ\t\t\t6.�˳�\n");
    space();
    star();
    printf("\n");
    printf("������ָ��\n");
    while(scanf("%d",&choice)==1)
    {   getchar();//�޳����з� 
    	switch(choice)
    	{
    		case 1:
    			{
    			    printf("ѧ����Ϣ����\n");
    				show(head);
    			}
    		        break;
    		case 2:
    			{
    			printf("�޸�ѧ����Ϣ������Ҫ�޸ĵ�ѧ������\n");
	            gets(input);
	            amend(head,input);
				}
    	    break;
    	    case 3:
    	    {
    	  	  printf("���ѧ����Ϣ������Ҫ��ӵ�������ѧ��\n");
              gets(input);
	          scanf("%d",&n);
	          getchar();
	          add(head,input,n);
			 }
    		break;
    		case 4:
    		{
    		printf("ɾ��ѧ����Ϣ������Ҫɾ��������\n");
	        gets(input);	
	        remove(head,input);
	        }
    		break;
    		case 5:
    		{
    		printf("����Ҫ����ѧ��������\n");
    		gets(input);	
    		seek(head,input);
    	    }
    		break;
    		case 6:
    		break;
    		default :
    		printf("��������ȷ��ָ��!\n");
    	    break;
        }
    	    if(choice==6)
    	    {
    	    printf("�ټ�\n");
    	    break;
         	}
      	printf("������ָ��\n");		    		
	}
   
		current=head;
		while(current!=NULL)
		{
			free(current);
			current=current->next;	
		}
		printf("�ͷſռ�\n");
		return 0;	
}
struct student *remove(struct student *head,char *pstr)
{    
	struct student *temp,*p;
     temp=head;
     while(strcmp(temp->name,pstr)!=0&&temp->next!=NULL)
     {
     	p=temp;
     	temp=temp->next;
	 }
	 if(strcmp(temp->name,pstr)==0)
	{
	 	if(temp==head)//ͷ�ڵ�
	   { 
	    
	 	printf("ɾ����ѧ����%s\n",temp->name);
	 	head=head->next;
	     //ͷ�ڵ�����
		free(temp);//ɾ��ͷ�ڵ�������� 
	    }
	    else
	    {
	    	p->next=temp->next;//���нڵ㣬����β�ڵ� 
	    	printf("ɾ����ѧ����%s\n",temp->name);
	    	free(temp);		
		}
	}
	else
		printf("û���ҵ�ѧ����Ϣ\n");	
	    return head;	
}
struct student *add(struct student *head,char *pstr,int n)//˳����� 
{
	struct student *p1,*p2,*p3;
	p1=(struct student *)malloc(sizeof(struct student));
	strcpy(p1->name,pstr);
	p1->number=n;
	p2=head;
	while(n>p2->number&&p2->next!=NULL)
	{
		p3=p2;
		p2=p2->next; 
	}
	if(n<=p2->number)//�ҵ�λ��
	if(head==p2)//�ڱ�ͷ���� 
	{
		head=p1;
		p1->next=p2;
		printf("����ɹ�\n");
	 } 
	 else //���в���
	 {
	   p3->next=p1;
	   p1->next=p2;
	   printf("����ɹ�\n");
	 }
	else//��β����
	{
	p2->next=p1;
	p1->next=NULL;
	printf("����ɹ�\n");
    }	 
    return head;	
}
void amend(struct student *head,char *pstr)
{ 
    char input[10];
    int  n;
	struct student *p1,*p2;
	p1=head;
	while(strcmp(p1->name,pstr)!=0&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(strcmp(p1->name,pstr)==0)
	{
		printf("��������ѧ����Ϣ\n");
		gets(input);
		scanf("%d",&n);
		getchar();
		strcpy(p1->name,input);
		p1->number=n;
		printf("��Ϣ�޸ĳɹ�\n");
	}
	else
	printf("ѧ����Ϣ������\n");
	} 
void space(void)
{    int i;
	 for(i=1;i<=20;i++)
    putchar(SPACE);
}
void star(void)
{
	int i;
	 for(i=1;i<=40;i++)
    putchar(STAR);	
}

void seek(struct student *head,char *pstr)
{
	struct student *p1,*p2;
	p1=head;//�ҵ�ͷָ�� 
	while(strcmp(p1->name,pstr)!=0&&p1->next!=NULL)
     {
     	p2=p1;
     	p1=p1->next;
	 }
	 if(strcmp(p1->name,pstr)==0)
	 {
	 printf("ѧ����Ϣ:\n");
	 printf("����:%s\tѧ��:%d\n",p1->name,p1->number);
     }
   printf("��ѯ�ɹ�\n");
	
}
void show(struct student*head)
{    
     struct student *current=head;
		while(current!=NULL)
	{
		printf("����%+10s   ѧ��%5d\n",current->name,current->number);
		current=current->next;
	}
	
}	




























