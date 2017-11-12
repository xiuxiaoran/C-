#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SPACE ' '
#define STAR '*'
void space(void);//20个空格 
void star(void);//40个星号 
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
	puts("输入学生姓名，空行结束输入");
	while(gets(input)!=NULL&&input[0]!='\0')
	{ 
		current=(struct student*)malloc(sizeof(struct student));
		if(head==NULL)
		head=current;
		else
		prev->next=current;
		current->next=NULL;
		strcpy(current->name,input);
		puts("输入学生学号");
		scanf("%d",&current->number);
		getchar();
		prev=current;
		puts("输入学生姓名,空行结束输入");	
	}
	if(head==NULL)
	{ 
	printf("无数据\n");
	return -1; //空链表情况排除 
    }
	space();
    space();
    printf("\b\b\b\b\b\b\b欢迎使用本系统\n");
    space(); 
    star();
    printf("\n");
    space();
    printf("1.信息显示\t\t\t2.信息修改\n");
    space();
    printf("3.信息添加\t\t\t4.信息删除\n");
    space();
    printf("5.信息查询\t\t\t6.退出\n");
    space();
    star();
    printf("\n");
    printf("请输入指令\n");
    while(scanf("%d",&choice)==1)
    {   getchar();//剔除换行符 
    	switch(choice)
    	{
    		case 1:
    			{
    			    printf("学生信息回显\n");
    				show(head);
    			}
    		        break;
    		case 2:
    			{
    			printf("修改学生信息，输入要修改的学生姓名\n");
	            gets(input);
	            amend(head,input);
				}
    	    break;
    	    case 3:
    	    {
    	  	  printf("添加学生信息，输入要添加的姓名和学号\n");
              gets(input);
	          scanf("%d",&n);
	          getchar();
	          add(head,input,n);
			 }
    		break;
    		case 4:
    		{
    		printf("删除学生信息，输入要删除的姓名\n");
	        gets(input);	
	        remove(head,input);
	        }
    		break;
    		case 5:
    		{
    		printf("输入要查找学生的姓名\n");
    		gets(input);	
    		seek(head,input);
    	    }
    		break;
    		case 6:
    		break;
    		default :
    		printf("请输入正确的指令!\n");
    	    break;
        }
    	    if(choice==6)
    	    {
    	    printf("再见\n");
    	    break;
         	}
      	printf("请输入指令\n");		    		
	}
   
		current=head;
		while(current!=NULL)
		{
			free(current);
			current=current->next;	
		}
		printf("释放空间\n");
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
	 	if(temp==head)//头节点
	   { 
	    
	 	printf("删除此学生：%s\n",temp->name);
	 	head=head->next;
	     //头节点下移
		free(temp);//删除头节点出现问题 
	    }
	    else
	    {
	    	p->next=temp->next;//表中节点，包含尾节点 
	    	printf("删除此学生：%s\n",temp->name);
	    	free(temp);		
		}
	}
	else
		printf("没有找到学生信息\n");	
	    return head;	
}
struct student *add(struct student *head,char *pstr,int n)//顺序插入 
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
	if(n<=p2->number)//找到位置
	if(head==p2)//在表头插入 
	{
		head=p1;
		p1->next=p2;
		printf("插入成功\n");
	 } 
	 else //表中插入
	 {
	   p3->next=p1;
	   p1->next=p2;
	   printf("插入成功\n");
	 }
	else//表尾插入
	{
	p2->next=p1;
	p1->next=NULL;
	printf("插入成功\n");
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
		printf("重新输入学生信息\n");
		gets(input);
		scanf("%d",&n);
		getchar();
		strcpy(p1->name,input);
		p1->number=n;
		printf("信息修改成功\n");
	}
	else
	printf("学生信息不存在\n");
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
	p1=head;//找到头指针 
	while(strcmp(p1->name,pstr)!=0&&p1->next!=NULL)
     {
     	p2=p1;
     	p1=p1->next;
	 }
	 if(strcmp(p1->name,pstr)==0)
	 {
	 printf("学生信息:\n");
	 printf("姓名:%s\t学号:%d\n",p1->name,p1->number);
     }
   printf("查询成功\n");
	
}
void show(struct student*head)
{    
     struct student *current=head;
		while(current!=NULL)
	{
		printf("姓名%+10s   学号%5d\n",current->name,current->number);
		current=current->next;
	}
	
}	




























