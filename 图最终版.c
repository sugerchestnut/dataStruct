#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXVEX 20         //��ʾ��󶨵����
#define INFINITY 32767     //��ʾ����ֵ
#define MAXSIZE 20         //���е���������ռ�
int v1,v2;
int visited[MAXVEX]={0};   //���ʱ�־����
//�ڽӱ�

typedef struct ArcNode
{
	char adjvex;//����еĽ��ֵ
	int weight;//������������Ȩֵ
	struct ArcNode *next;
}ArcNode;//�ڽӱ�Ļ����

typedef struct 
{
	int insum;
	int outsum;
    char vexdata;
	ArcNode *head;
}VertexNode;//�ڽӱ�ı�ͷ���

typedef struct 
{
    VertexNode vextex[MAXVEX];//һά��ı�ͷ����
	int vexnumber;//������
	int arcnumber;//����
}AdjList;//

//�ڽӾ���
typedef struct
{
	int out;
	int in;
	char v;
}VEX;     //������Ϣ�������Ⱥ���ȣ��ڽӾ���
typedef struct
{
    int arcs[MAXVEX][MAXVEX];  //�߻򻡵���Ϣ
    VEX vex[MAXVEX];                //������������
    int vexnum;              //ͼ�Ķ������
	int arcnum;                //ͼ�ı߸���
}AdjMatrix;      //�ڽӾ���

typedef struct
{
	char ch[MAXSIZE];
	int rear,front;
}SeQueue;
SeQueue *v;
void init_SeQueue()             // ��ʼ������
{
	v=malloc(sizeof(SeQueue));
	v->front=v->rear=0;
	
}

void Push_SeQueue(char ch)      //��Ӳ���
{
	v->rear++;
	v->ch[v->rear]=ch;
}
char Pop_SeQueue()    //���Ӳ���
{
	char d;
	v->front++;
    d=v->ch[v->front];
	return d;
}

int Empty()         //�����пղ���
{
	if(v->front==v->rear)
		return 0;
	else
		return 1;
}
void chang(char vex1,char vex2)
{
	
	switch(vex1)
			{
			case 'a':v1=1;break;
			case 'b':v1=2;break;
			case 'c':v1=3;break;
			case 'd':v1=4;break;
			case 'e':v1=5;break;
			case 'f':v1=6;
				break;
			}
			switch(vex2)
			{
			case 'a':v2=1;break;
			case 'b':v2=2;break;
			case 'c':v2=3;break;
			case 'd':v2=4;break;
			case 'e':v2=5;break;
			case 'f':v2=6;
				break;
			}
}

int chan(char t)
{
	int n;
    switch(t)
			{
			case 'a':n=1;break;
			case 'b':n=2;break;
			case 'c':n=3;break;
			case 'd':n=4;break;
			case 'e':n=5;break;
			case 'f':n=6;break;
			}
	return n;
}
char change(int i)
{
	char t;
    switch(i)
			{
			case 1:t='a';break;
			case 2:t='b';break;
			case 3:t='c';break;
			case 4:t='d';break;
			case 5:t='e';break;
			case 6:t='f';break;
			}
	return t;
}
char FirstAdiVex(AdjList *h,char ms)   //ͼh��ms�ĵ�һ���ڽӵ�
{
    int i,n;
//VertexNode *ve;
    ArcNode *ar;
	for(i=1;i<=h->vexnumber;i++)
	{
		if(h->vextex[i].vexdata==ms)
			break;
	}
    ar=h->vextex[i].head;
	n=chan(ar->adjvex);//ת��ar->adjvex��ֵ
	while(visited[n]!=0 && ar->next )
	{
		ar=ar->next;
        n=chan(ar->adjvex);
	}
	if(ar)
    	return ar->adjvex;
	else
		return 'z';
}

char NextAdiVex(AdjList *h,char ms,char t)//ͼ�ж���ms����ڶ���t����һ���ڽӵ�
{
    int i,n;
    ArcNode *ar;
	for(i=1;i<=h->vexnumber;i++)//�ҵ�ms�ڱ�ͷ�����λ��
	{
		if(h->vextex[i].vexdata==ms)
			break;
	}ar=h->vextex[i].head;
	for(;ar->adjvex!=t && ar->next;ar=ar->next);//�ҵ�����t����msΪ��ͷ���ڽӱ��е�λ��   
	ar=ar->next;
	if(ar)
	{
		n=chan(ar->adjvex);
		while(visited[n]!=0 && ar!=NULL)
		{
			ar=ar->next;
			n=chan(ar->adjvex);	
		}
		if(ar)  return ar->adjvex;
	}
    return 'z';	
} 

int FirstMatrix(AdjMatrix * G, int v0 )
{/*{{{*/
        int i;
        for( i=1; i<=G->vexnum; i++)
        {
                if( G->arcs[v0][i]!=0)
                {
                        return i;
                }
        }
        return -1;
}/*}}}*/

int NextMatrix(AdjMatrix *G, int v0, int w)
{/*{{{*/
        
        for( w++; w<=G->vexnum; w++  )
        {
                if( G->arcs[v0][w] != 0 )
                {
                        return w;
                }
        }
        return -1;
}/*}}}*/
//��������������Ȩֵ��ͼ�������ڽӾ���
void Creat(AdjMatrix *h)
{
	int i,j,k,weight;
	char vex1,vex2;
	printf("�������������еĶ������ͱ���:");
	scanf("%d%d",&h->vexnum,&h->arcnum);         //%d֮�䲻���ö���
	for(i=1;i<=h->vexnum;i++)            //���ڽӾ���������Ԫ�ظ������
		for(j=1;j<=h->vexnum;j++)
			h->arcs[i][j]=0;
		printf("����������ͼ��%d������\n",h->vexnum);
		for(i=1;i<=h->vexnum;i++)
		{
			fflush(stdin);
			printf("��%d������",i);		
			scanf("%c",&h->vex[i].v);
		}
		printf("��������������%d����:",h->arcnum);
		for(k=0;k<h->arcnum;k++)
		{
			fflush(stdin);
			printf("\n no.%d����:\n�����:",k+1);
			scanf("%c",&vex1);
			fflush(stdin);
			printf("������:");
			scanf("%c",&vex2);
			fflush(stdin);
			printf("Ȩֵ:");
			scanf("%d",&weight);
			chang(vex1,vex2);//�������Ϣת��������
			h->arcs[v1][v2]=weight;//��Ȩֵ
		}
}

//����Ѵ����õ�������,����������ĳ��Ⱥ����
void Print(AdjMatrix *h)
{
    int i,j,k,m;
	
	printf(" ");
	for(i=1;i<=h->vexnum;i++)
		printf("%3c",h->vex[i].v);
	printf("\n");
	for(m=1;m<=h->vexnum;m++)
		h->vex[m].in=0;
	for(j=1;j<=h->vexnum;j++)
	{
        h->vex[j].out=0;
	
		printf("%-3c",h->vex[j].v);
		for(k=1;k<=h->vexnum;k++)
		{
				chang(h->vex[j].v,h->vex[k].v);
			printf("%-3d",h->arcs[v1][v2]);
			if(h->arcs[v1][v2]!=0)
			{
				h->vex[j].out++;
				h->vex[k].in++;
			}
		}
		//printf("����Ϊ:%3d",h->vex[j].out);
		printf("\n");
	}
	printf("\n\n----����--���\n");
	for(m=1;m<=h->vexnum;m++)
		printf("%3c%3d%5d\n",h->vex[m].v,h->vex[m].out,h->vex[m].in);	
}

//��������������Ȩֵ��ͼ�������ڽӱ�
void Creat2(AdjList *h)
{
	int i,j,weight;
	ArcNode *p,*l;
	char vex1,vex2;
	printf("�������������еĶ������ͱ���:");
	scanf("%d%d",&h->vexnumber,&h->arcnumber);
	printf("����������ͼ��%d������\n",h->vexnumber);
	for(i=1;i<=h->vexnumber;i++)
	{
		fflush(stdin);
		printf("�������%d������",i);
	  scanf("%c",&h->vextex[i].vexdata);
	}
	printf("��������������%d����:",h->arcnumber);
	for(i=1;i<=h->vexnumber;i++)
		h->vextex[i].head=NULL;
	for(j=1;j<=h->arcnumber;j++)
	{
		fflush(stdin);
		printf("\nno.%d����:\n�����:",j);
		scanf("%c",&vex1);
		fflush(stdin);
		printf("������:");
		scanf("%c",&vex2);
		fflush(stdin);
		printf("Ȩֵ:");
		scanf("%d",&weight);
		chang(vex1,vex2);//�������Ϣת��������
	
        p=(ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex=vex2;
		p->weight=weight;
		p->next=NULL;
		if(h->vextex[v1].head==NULL)
			h->vextex[v1].head=p;
		else
		{
			l=h->vextex[v1].head;
			while(l->next)                //ע�ⲻ��д��while��l��
			{
				l=l->next;
			}
				l->next=p;
		}		
	}
}

void Print2(AdjList *h)//�ڽӱ��������
{
	int o,i;
	ArcNode *l;
	for(i=1;i<=h->vexnumber;i++)
	{
		h->vextex[i].insum=0;
	    h->vextex[i].outsum=0;
	}
	for(i=1;i<=h->vexnumber;i++)
	{
		printf("%3c",h->vextex[i].vexdata);
		l=h->vextex[i].head;
		while(l)
		{
			h->vextex[i].outsum++;
			o=chan(l->adjvex);
			h->vextex[o].insum++;
			printf("%5c%3d",l->adjvex,l->weight);
			l=l->next;
		}
		printf("\n");
	}
	printf("\n\n----����--���\n");
	for(i=1;i<=h->vexnumber;i++)
		printf("%3c%3d%5d\n",h->vextex[i].vexdata,h->vextex[i].outsum,h->vextex[i].insum);
}

//������ȱ�������ͼ
void DFS(AdjMatrix *h,char ms)
{
   char j;
   int t,o;
   printf("%3c",ms);//�������һ������
   o=chan(ms);//ת��ms��ֵΪ��
   visited[o]=1;
   t=FirstMatrix(h,o);//ͼh�ж���ms�ĵ�һ���ڽӵ�
   while(t!=-1)
   {
	   if(!visited[t]) 
	   {
           j=change(t);
		   DFS(h,j);}
	       t=NextMatrix(h,o,t);//ͼh�ж���ms����һ���ڽӵ�
   }
}

//������ȱ���
void BFS(AdjList *h,char ms)
{
	int n;
	char t,w;
	printf("%3c",ms);
	n=chan(ms);
	visited[n]=1;
    Push_SeQueue(ms);
	while(Empty())
	{
      t=Pop_SeQueue();
	  w=FirstAdiVex(h,t);
	  while(w!='z')
	  {
		  n=chan(w);
		  if(!visited[n])
		  {
			  printf("%3c",w);
			  visited[n]=1;
              Push_SeQueue(w);
		  }
		  w=NextAdiVex(h,t,w);
	  }
	}
}
int main(void)
{
	char r;
	int i;
	AdjMatrix g;
	AdjList q;
	Creat(&g);
    Print(&g);
	Creat2(&q);
	Print2(&q);
	printf("������ͼ�����ĵ�һ������:");
	fflush(stdin);
	scanf("%c",&r);
    init_SeQueue();
	DFS(&g,r);//������ȱ���
	for( i=1; i<=g.vexnum; i++ )
	{
		visited[i] =0;
	}
	printf("\n");
		BFS(&q,r);//������ȱ���
}