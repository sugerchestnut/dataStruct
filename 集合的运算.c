#include<stdio.h>
#include<stdlib.h>
struct gat
{
	char ch;
	struct gat* next;
};
struct gat *Creatlink()               //������ͷ��������
{
	struct gat *h,*t,*p;
	char ch;
	printf("��'#'������\n");
	p=(struct gat *)malloc(sizeof(struct gat)); //ͷ���
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
struct gat *Union(struct gat *h1,struct gat *h2)   //���ϵĲ���
{
	struct gat *p,*q,*r,*s,*h;
	int flag=0;
    h=(struct gat *)malloc(sizeof(struct gat));r=h;    //����c�����ͷ���
	for(p=h1->next;p!=NULL;p=p->next)                  //��a�������b������
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
struct gat *Com(struct gat *h1,struct gat *h2)    //���ϵĽ���
{
	struct gat *p,*q,*h,*r,*s; 
	int flag=0;
	h=(struct gat *)malloc(sizeof(struct gat));   //c���ϵ�ͷ���
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
		if(flag==1)               //��ͬ���ַ�����c������
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
struct gat *Comple(struct gat *h1,struct gat *h2)    //���ϵĲ���
{
	struct gat *h3,*p,*q,*t;
	int flag=0,c;
	h3=Union(h1,h2);
	printf("��ѡ��<1.a�Ĳ��� 2.b�Ĳ���>:");
	scanf("%d",&c);
	if(c==1)
	{
	   printf("a���ϵĲ�:\n");
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
	   printf("b���ϵĲ�:\n");
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
struct gat *Sub(struct gat *h1,struct gat *h2)    //���ϼ�
{
    struct gat *h3,*p,*q,*t;int c;
	h3=Com(h1,h2);
	printf("��ѡ��<1.a-b  2.b-a>:");
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
void Print(struct gat *h3)             //���ϵ����
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
	printf("                1.���Ͻ�                  \n");
	printf("                2.���ϲ�                  \n");
	printf("                3.���ϲ�                  \n");
    printf("                4.���ϼ�                  \n");
	printf("                0.�˳�                    \n");
    printf("------------------------------------------\n");
}
int main(void)
{
	struct gat *a,*b,*c;
	int ch;
	menu();
	printf("����a����:\n");
	a=Creatlink();
	printf("����b����:\n");
	b=Creatlink();        
	printf("��ѡ��:");        
	scanf("%d",&ch);
	while(ch)
	{
			
	     if(ch==1)
			{
	          printf("�������ϵĽ���:\n");
	          c=Com(a,b);
	          Print(c);
			}
	     else if(ch==2)
			{
	         printf("�������ϵĲ���:\n");
	         c=Union(a,b);
	         Print(c);
			}
	     else if(ch==3)
			{
				printf("�������ϵĲ���:\n");
				c=Comple(a,b);
				Print(c);
			}
		 else if(ch==4)
			{
				printf("���ϵļ�:\n");
				c=Sub(a,b);
				Print(c);
			}
		 printf("��ѡ��:");   
		 scanf("%d",&ch);
	}
} 