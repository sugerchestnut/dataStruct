#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
	typedef struct
	{
	     char data[N];
	     int top;
	}SeqStack;          
    SeqStack *t;       //ջ   
    
    typedef struct
	{
	     char dat[N];
	     int rear,front;
	}SeQueue;
    SeQueue *h; 	//����

SeqStack * init_SeqStack()          //��ʼ��ջ
{
	SeqStack *s;
	s=malloc(sizeof(SeqStack));
    s->top=-1;
    return s;
}

SeQueue * init_SeQueue()             // ��ʼ������
{
	SeQueue *sq;
	sq=malloc(sizeof(SeQueue));
	sq->front=sq->rear=0;
	return sq;
}

void TrateLate(SeQueue *h)         //���뺯��
{
   int a=h->front+1;
	while(a!=h->rear+1)
	{
		switch(h->dat[a])
		{
		   case'a':
			   {printf("��");break;}
		   case'b':
			   {printf("��");break;}
		   case'c':
			   {printf("һ");break;}
		   case'd':
			   {printf("ֻ");break;}
		   case'e':
			   {printf("��");break;}
		   case'f':
			   {printf("��");break;}
		  // default:
			  // {printf("?");break;}
		}
		a++;
	}
}       

void Push_SeqStack(char ch)        //��ջ����
{       
       t->top++;
       t->data[t->top]=ch;               
}
void Push_SeQueue(SeQueue *h,char ch)      //��Ӳ���
{
	h->rear++;
	h->dat[h->rear]=ch;
}
void Read_Array1(char  *s)                //��������ַ���ջ
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

void Read_Array2(char *s)              //�����ַ�ȫ�����
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
			i=((m+1)/2+1)+i;//���������Ž�ջ��Ԫ�ر������ע���ʱ�����ַ�������±꣬��Ҫ�������ź�Ľ����ŵ��ַ���
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
	printf("\n\n\tħ��ֻ˵  a b c d e f (A-def) (B-abc) �⼸����ĸ,����ʶ�Ĳ�����\n\n\n");
	printf("\t\t\ta ��\n");
	printf("\t\t\tb ��\n");
	printf("\t\t\tc һ\n");
	printf("\t\t\td ֻ\n");
	printf("\t\t\te ��\n");
	printf("\t\t\tf ��\n");
    printf("����ħ��������:");
	gets(s);
    Read_Array1(s);
	Read_Array2(s);	
	TrateLate(h);
}
