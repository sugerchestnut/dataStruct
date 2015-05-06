#include<stdio.h>
#include<stdlib.h>
struct gat
{
	char ch;
	struct gat* next;
};
struct gat *Creatlink()               //创建带头结点的链表
{
	struct gat *h,*t,*p;
	char ch;
	printf("以'#'键结束\n");
	p=(struct gat *)malloc(sizeof(struct gat)); //头结点
	t=h=p;scanf("%c",&ch);
    while(ch!='#')
	{
		p=(struct gat *)malloc(sizeof(struct gat));
		
		p->ch=ch;
		t->next=p;
		t=p;
		scanf("%c",&ch);
	}
	p->next=NULL;
	return h;
}
struct gat *Union(struct gat *h1,struct gat *h2)   //集合的并集
{
	struct gat *p,*q,*r,*s,*h;
	int flag=0;
    h=(struct gat *)malloc(sizeof(struct gat));r=h;    //创建c链表的头结点
	for(p=h1->next;p!=NULL;p=p->next)                  //将a链表放入b链表中
	{
		s=(struct gat *)malloc(sizeof(struct gat));
		s->ch=p->ch;
		r->next=s;
		r=s;
	}
	for(p=h2->next;p!=NULL;p=p->next)
	{
		flag=0;
	   for(q=h1->next;q!=NULL;q=q->next)
	   {
		   if(q->ch==p->ch)
		   {
			   flag=1;
			   break;
		   }
	   }
	   if(flag==0)
	   {
           s=(struct gat *)malloc(sizeof(struct gat));
           s->ch=p->ch;
		   r->next=s;
		   r=s;
	   }
	}
	r->next=NULL;
	return h;
}
struct gat *Com(struct gat *h1,struct gat *h2)    //集合的交集
{
	struct gat *p,*q,*h,*r,*s; 
	int flag=0;
	h=(struct gat *)malloc(sizeof(struct gat));   //c集合的头结点
	r=h;
	for(p=h1->next;p!=NULL;p=p->next)
	{
		flag=0;
		for(q=h2->next;q!=NULL;q=q->next)
		{
			if(q->ch==p->ch)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)               //相同的字符存入c集合中
		{
           s=(struct gat *)malloc(sizeof(struct gat));
           s->ch=q->ch;
		   r->next=s;
		   r=s;
		}
	}
	r->next=NULL;
	return h;
}
struct gat *Comple(struct gat *h1,struct gat *h2)    //集合的补集
{
	struct gat *h3,*p,*q,*t;
	int flag=0,c;
	h3=Union(h1,h2);
	printf("请选择<1.a的补集 2.b的补集>:");
	scanf("%d",&c);
	if(c==1)
	{
	   printf("a集合的补:\n");
	   for(p=h1->next;p!=NULL;p=p->next)
	   {
		  for(t=h3,q=h3->next;q!=NULL;t=q,q=q->next)
		  {
			 if(q->ch==p->ch)
			 {
                flag=1;
				break;
			 }
		  }
		 if(flag==1)
		 {
			t->next=q->next;
			free(q);
		 }
	   }	
	}
	else
	{
	   printf("b集合的补:\n");
	   for(p=h2->next;p!=NULL;p=p->next)
	   {
		  for(t=h3,q=h3->next;q!=NULL;t=q,q=q->next)
		  {
			 if(q->ch==p->ch)
			 {
                flag=1;
				break;
			 }
		  }
		 if(flag==1)
		 {
			t->next=q->next;
			free(q);
		 }
	   }
	 }
	return h3;
}
struct gat *Sub(struct gat *h1,struct gat *h2)    //集合减
{
    struct gat *h3,*p,*q,*t;int c;
	h3=Com(h1,h2);
	printf("请选择<1.a-b  2.b-a>:");
	scanf("%d",&c);
	if(c==1)
	{
	  for(p=h3->next;p;p=p->next)
	  {
		for(q=h1;q->next;q=q->next)
		{
			if(q->next->ch==p->ch)
			{
				t=q->next;
				q->next=t->next;
				free(t);
			}
		}
	  }
	  return h1;
	}
	else
	{
		for(p=h3->next;p;p=p->next)
		{
		  for(q=h2;q->next;q=q->next)
		  {
			if(q->next->ch==p->ch)
			{
				t=q->next;
				q->next=t->next;
				free(t);
			}
		  }
		}
		return h2;
	}
}
void Print(struct gat *h3)             //集合的输出
{
	for(h3=h3->next;h3!=NULL;h3=h3->next)
	{
		printf("%c",h3->ch);
	}
	printf("\n\n");
}
void menu()
{
	printf("------------------------------------------\n");
	printf("                1.集合交                  \n");
	printf("                2.集合并                  \n");
	printf("                3.集合补                  \n");
    printf("                4.集合减                  \n");
	printf("                0.退出                    \n");
    printf("------------------------------------------\n");
}
int main(void)
{
	struct gat *a,*b,*c;
	int ch;
	menu();
	printf("输入a集合:\n");
	a=Creatlink();
	printf("输入b集合:\n");
	b=Creatlink();        
	printf("请选择:");        
	scanf("%d",&ch);
	while(ch)
	{
			
	     if(ch==1)
			{
	          printf("两个集合的交集:\n");
	          c=Com(a,b);
	          Print(c);
			}
	     else if(ch==2)
			{
	         printf("两个集合的并集:\n");
	         c=Union(a,b);
	         Print(c);
			}
	     else if(ch==3)
			{
				printf("两个集合的补集:\n");
				c=Comple(a,b);
				Print(c);
			}
		 else if(ch==4)
			{
				printf("集合的减:\n");
				c=Sub(a,b);
				Print(c);
			}
		 printf("请选择:");   
		 scanf("%d",&ch);
	}
} 