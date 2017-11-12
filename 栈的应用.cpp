#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#define MAX 8
typedef struct
{
	char *base;
	char *top;
    int stacksize;
} STACK;
 void InitStack(STACK *stack);
 bool Is_Empty(STACK *stack); 
 bool Is_Full(STACK *stack);
 int push(STACK *stack,char *ch);
 int pop(STACK *stack,char *);
 char Gettop(STACK *stack);
 int main()
 {  
    char ch[8];
	char str;
	int i;
    char *p;
    p=ch;
    STACK stack;
    InitStack(&stack);
    printf("�����ַ�(,),{,},[,]\n");
    gets(ch);
    for(i=0;i<strlen(ch);i++)
    {
    	switch(p[i])
    	{
    		case '{':
    	    case '[':
    	    case '(':push(&stack,&p[i]);
    	             printf("��ջ�ɹ�,��ջԪ��Ϊ%c\n",p[i]); 
    	             break;         /*ֻҪ�������ž�ѹջ���������������Ϊƥ����� 
    	                              ���ƥ��ͼ�����һ�����ŵļ���ƥ�䣬��ƥ��ֱ����ֹ���� */
    	    case ')':
    	    	if(!Is_Empty(&stack)&&Gettop(&stack)=='(')
    	    	{ 
    	    	   pop(&stack,&str);
    	    	   printf("��ջ�ɹ�,��ջԪ��Ϊ%c\n",str); 
    	    	} 
    	    	else
    	    	   {
    	    	   	printf("ƥ��ʧ��\n");
    	    	   	return 0; 
				   }
    	    	   break;
    	    case ']':
    	    	if(!Is_Empty(&stack)&&Gettop(&stack)=='[')
    	    	{ 
    	    	   pop(&stack,&str);
    	    	   printf("��ջ�ɹ�,��ջԪ��Ϊ%c\n",str); 
    	    	} 
    	    	   else
    	    	   {
    	    	   	printf("ƥ��ʧ��\n");
    	    	   	return 0; 
				   }
    	    	    break;
    	    case '}':
    	    	if(!Is_Empty(&stack)&&Gettop(&stack)=='{')
    	    	{ 
    	    	   pop(&stack,&str);  
				   printf("��ջ�ɹ�,��ջԪ��Ϊ%c\n",str); 
				} 
    	    	   else
    	    	   {
    	    	   	printf("ƥ��ʧ��\n");
    	    	   	return 0; 
				   }
    	    	   break;
    	    default:
    	    	break;//��������Ƿ������ַ�ʱ����Ҳ���� 
    	}
    }
    	if(Is_Empty(&stack))
    	{
    		printf("����ƥ��ɹ�\n");
		}
		else
		printf("����ƥ��ʧ��\n");
 	return 0;
 }
 void InitStack(STACK *stack)
 {
 	stack->base=(char *)malloc(sizeof(char)*MAX);
 	if(stack->base==NULL)exit(-1);
	 else
	 {
	   	stack->top=stack->base;
	   	stack->stacksize=MAX;
	    printf("��ʼ���ɹ�\n");
	 } 
	
}
bool Is_Empty(STACK *stack)
{
	
	if(stack->base==stack->top) 
	   return true;
	   else
	   return false; 
}
bool Is_Full(STACK *stack)
{
	if(stack->top-stack->base>=MAX)
	{
		printf("ջ����\n");
		return true;
	}
	else
	return false;
}
 int push(STACK *stack,char *ch)
 {
 	if(Is_Full(stack))
 	{
 	  printf("ջ����\n");
 	  return 0;
    }
    else
    {
    	*stack->top++=*ch;
	}
	return 0;	
 }//ѹջ 
  int pop(STACK *stack,char *e)
  {
  	if(Is_Empty(stack))
  	return 0;
  	else
  	{
  		--stack->top;
  		*e=*stack->top;
	}
	return 0;
  }//��ջ 
char Gettop(STACK *stack)
{   char e;
	if(Is_Empty(stack))
	return 0;
	else
	{
		e=*(stack->top-1);
	}
	return e;
}






