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
    printf("输入字符(,),{,},[,]\n");
    gets(ch);
    for(i=0;i<strlen(ch);i++)
    {
    	switch(p[i])
    	{
    		case '{':
    	    case '[':
    	    case '(':push(&stack,&p[i]);
    	             printf("入栈成功,入栈元素为%c\n",p[i]); 
    	             break;         /*只要是左括号就压栈，以最近的右括号为匹配对象， 
    	                              如果匹配就继续下一个括号的检验匹配，不匹配直接终止程序 */
    	    case ')':
    	    	if(!Is_Empty(&stack)&&Gettop(&stack)=='(')
    	    	{ 
    	    	   pop(&stack,&str);
    	    	   printf("出栈成功,出栈元素为%c\n",str); 
    	    	} 
    	    	else
    	    	   {
    	    	   	printf("匹配失败\n");
    	    	   	return 0; 
				   }
    	    	   break;
    	    case ']':
    	    	if(!Is_Empty(&stack)&&Gettop(&stack)=='[')
    	    	{ 
    	    	   pop(&stack,&str);
    	    	   printf("出栈成功,出栈元素为%c\n",str); 
    	    	} 
    	    	   else
    	    	   {
    	    	   	printf("匹配失败\n");
    	    	   	return 0; 
				   }
    	    	    break;
    	    case '}':
    	    	if(!Is_Empty(&stack)&&Gettop(&stack)=='{')
    	    	{ 
    	    	   pop(&stack,&str);  
				   printf("出栈成功,出栈元素为%c\n",str); 
				} 
    	    	   else
    	    	   {
    	    	   	printf("匹配失败\n");
    	    	   	return 0; 
				   }
    	    	   break;
    	    default:
    	    	break;//当输入的是非括号字符时程序也运行 
    	}
    }
    	if(Is_Empty(&stack))
    	{
    		printf("括号匹配成功\n");
		}
		else
		printf("括号匹配失败\n");
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
	    printf("初始化成功\n");
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
		printf("栈已满\n");
		return true;
	}
	else
	return false;
}
 int push(STACK *stack,char *ch)
 {
 	if(Is_Full(stack))
 	{
 	  printf("栈已满\n");
 	  return 0;
    }
    else
    {
    	*stack->top++=*ch;
	}
	return 0;	
 }//压栈 
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
  }//出栈 
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






