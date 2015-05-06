#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
	typedef struct
	{
	     char data[N];
	     int top;
	}SeqStack;          
    SeqStack *t;       //栈   
    
    typedef struct
	{
	     char dat[N];
	     int rear,front;
	}SeQueue;
    SeQueue *h; 	//队列

SeqStack * init_SeqStack()          //初始化栈
{
	SeqStack *s;
	s=malloc(sizeof(SeqStack));
    s->top=-1;
    return s;
}

SeQueue * init_SeQueue()             // 初始化队列
{
	SeQueue *sq;
	sq=malloc(sizeof(SeQueue));
	sq->front=sq->rear=0;
	return sq;
}

void TrateLate(SeQueue *h)         //翻译函数
{
   int a=h->front+1;
	while(a!=h->rear+1)
	{
		switch(h->dat[a])
		{
		   case'a':
			   {printf("天");break;}
		   case'b':
			   {printf("上");break;}
		   case'c':
			   {printf("一");break;}
		   case'd':
			   {printf("只");break;}
		   case'e':
			   {printf("鹅");break;}
		   case'f':
			   {printf("地");break;}
		  // default:
			  // {printf("?");break;}
		}
		a++;
	}
}       

void Push_SeqStack(char ch)        //入栈操作
{       
       t->top++;
       t->data[t->top]=ch;               
}
void Push_SeQueue(SeQueue *h,char ch)      //入队操作
{
	h->rear++;
	h->dat[h->rear]=ch;
}
void Read_Array1(char  *s)                //括号里的字符入栈
{
	int i,l,j;
	char p;
	l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i]=='(')
		{		    
			  p=s[i+1];
			  Push_SeqStack(p);
			  break;
		}
	}
	if(i<l)
	{
	   for(i=i+2;s[i]!=')';i++)
	   {          
	    Push_SeqStack(s[i]);
		Push_SeqStack(p);
	   }
	}
	for(j=t->top;j!=-1;j--)
		printf("%c",t->data[j]);
}

void Read_Array2(char *s)              //所有字符全部入队
{
    int i,l,m;	
	m=0;
	l=strlen(s);
    for(i=0;i<l;i++)
	{
		if(s[i]=='A')
		{
            Push_SeQueue(h,'d');
			Push_SeQueue(h,'e');
			Push_SeQueue(h,'f');
		}
		else if(s[i]=='B')
		{
            Push_SeQueue(h,'c');
			Push_SeQueue(h,'b');
			Push_SeQueue(h,'a');
		}

		else if(s[i]=='(')
		{
			while(t->top!=-1)
			{
                if(t->data[t->top]=='A')
				{
                    Push_SeQueue(h,'d');
		        	Push_SeQueue(h,'e');
			        Push_SeQueue(h,'f');
				}
				else if(t->data[t->top]=='B')
				{
                    Push_SeQueue(h,'c');
			        Push_SeQueue(h,'b');
			        Push_SeQueue(h,'a');
				}
				else
                    Push_SeQueue(h,t->data[t->top]);

		        t->top--;
				m++;
			}
			i=((m+1)/2+1)+i;//遇到左括号将栈中元素保存完后，注意此时遍历字符数组的下标，需要跳到括号后的紧接着的字符处
		}
		else
		   Push_SeQueue(h,s[i]);  
	}
} 


int main(void)
{
	char s[N];
	t=init_SeqStack();
	h=init_SeQueue();
	printf("\n\n\t魔王只说  a b c d e f (A-def) (B-abc) 这几个字母,不认识的不翻译\n\n\n");
	printf("\t\t\ta 天\n");
	printf("\t\t\tb 上\n");
	printf("\t\t\tc 一\n");
	printf("\t\t\td 只\n");
	printf("\t\t\te 鹅\n");
	printf("\t\t\tf 地\n");
    printf("输入魔王的语言:");
	gets(s);
    Read_Array1(s);
	Read_Array2(s);	
	TrateLate(h);
}
