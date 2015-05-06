#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXVEX 20         //表示最大定点个数
#define INFINITY 32767     //表示极大值
#define MAXSIZE 20         //队列的最大容量空间
int v1,v2;
int visited[MAXVEX]={0};   //访问标志数组
//邻接表

typedef struct ArcNode
{
	char adjvex;//结点中的结点值
	int weight;//连接两个结点的权值
	struct ArcNode *next;
}ArcNode;//邻接表的弧结点

typedef struct 
{
	int insum;
	int outsum;
    char vexdata;
	ArcNode *head;
}VertexNode;//邻接表的表头结点

typedef struct 
{
    VertexNode vextex[MAXVEX];//一维表的表头矩阵
	int vexnumber;//顶点树
	int arcnumber;//弧数
}AdjList;//

//邻接矩阵
typedef struct
{
	int out;
	int in;
	char v;
}VEX;     //顶点信息包括出度和入度（邻接矩阵）
typedef struct
{
    int arcs[MAXVEX][MAXVEX];  //边或弧的信息
    VEX vex[MAXVEX];                //顶点数据类型
    int vexnum;              //图的顶点个数
	int arcnum;                //图的边个数
}AdjMatrix;      //邻接矩阵

typedef struct
{
	char ch[MAXSIZE];
	int rear,front;
}SeQueue;
SeQueue *v;
void init_SeQueue()             // 初始化队列
{
	v=malloc(sizeof(SeQueue));
	v->front=v->rear=0;
	
}

void Push_SeQueue(char ch)      //入队操作
{
	v->rear++;
	v->ch[v->rear]=ch;
}
char Pop_SeQueue()    //出队操作
{
	char d;
	v->front++;
    d=v->ch[v->front];
	return d;
}

int Empty()         //队列判空操作
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
char FirstAdiVex(AdjList *h,char ms)   //图h中ms的第一个邻接点
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
	n=chan(ar->adjvex);//转换ar->adjvex的值
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

char NextAdiVex(AdjList *h,char ms,char t)//图中顶点ms相对于顶点t的下一个邻接点
{
    int i,n;
    ArcNode *ar;
	for(i=1;i<=h->vexnumber;i++)//找到ms在表头矩阵的位置
	{
		if(h->vextex[i].vexdata==ms)
			break;
	}ar=h->vextex[i].head;
	for(;ar->adjvex!=t && ar->next;ar=ar->next);//找到顶点t在以ms为开头的邻接表中的位置   
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
//创建有向网（带权值的图）利用邻接矩阵
void Creat(AdjMatrix *h)
{
	int i,j,k,weight;
	char vex1,vex2;
	printf("请输入有向网中的顶点数和边数:");
	scanf("%d%d",&h->vexnum,&h->arcnum);         //%d之间不能用逗号
	for(i=1;i<=h->vexnum;i++)            //将邻接矩阵中所有元素赋无穷大
		for(j=1;j<=h->vexnum;j++)
			h->arcs[i][j]=0;
		printf("请输入有向图中%d个顶点\n",h->vexnum);
		for(i=1;i<=h->vexnum;i++)
		{
			fflush(stdin);
			printf("第%d个顶点",i);		
			scanf("%c",&h->vex[i].v);
		}
		printf("请输入有向网中%d个边:",h->arcnum);
		for(k=0;k<h->arcnum;k++)
		{
			fflush(stdin);
			printf("\n no.%d条边:\n顶点出:",k+1);
			scanf("%c",&vex1);
			fflush(stdin);
			printf("顶点入:");
			scanf("%c",&vex2);
			fflush(stdin);
			printf("权值:");
			scanf("%d",&weight);
			chang(vex1,vex2);//将结点信息转换成数字
			h->arcs[v1][v2]=weight;//赋权值
		}
}

//输出已创建好的有向网,并计算出结点的出度和入度
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
		//printf("出度为:%3d",h->vex[j].out);
		printf("\n");
	}
	printf("\n\n----出度--入度\n");
	for(m=1;m<=h->vexnum;m++)
		printf("%3c%3d%5d\n",h->vex[m].v,h->vex[m].out,h->vex[m].in);	
}

//创建有向网（带权值的图）利用邻接表
void Creat2(AdjList *h)
{
	int i,j,weight;
	ArcNode *p,*l;
	char vex1,vex2;
	printf("请输入有向网中的顶点数和边数:");
	scanf("%d%d",&h->vexnumber,&h->arcnumber);
	printf("请输入有向图中%d个顶点\n",h->vexnumber);
	for(i=1;i<=h->vexnumber;i++)
	{
		fflush(stdin);
		printf("请输入第%d个顶点",i);
	  scanf("%c",&h->vextex[i].vexdata);
	}
	printf("请输入有向网中%d个边:",h->arcnumber);
	for(i=1;i<=h->vexnumber;i++)
		h->vextex[i].head=NULL;
	for(j=1;j<=h->arcnumber;j++)
	{
		fflush(stdin);
		printf("\nno.%d条边:\n顶点出:",j);
		scanf("%c",&vex1);
		fflush(stdin);
		printf("顶点入:");
		scanf("%c",&vex2);
		fflush(stdin);
		printf("权值:");
		scanf("%d",&weight);
		chang(vex1,vex2);//将结点信息转换成数字
	
        p=(ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex=vex2;
		p->weight=weight;
		p->next=NULL;
		if(h->vextex[v1].head==NULL)
			h->vextex[v1].head=p;
		else
		{
			l=h->vextex[v1].head;
			while(l->next)                //注意不能写成while（l）
			{
				l=l->next;
			}
				l->next=p;
		}		
	}
}

void Print2(AdjList *h)//邻接表的输出结果
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
	printf("\n\n----出度--入度\n");
	for(i=1;i<=h->vexnumber;i++)
		printf("%3c%3d%5d\n",h->vextex[i].vexdata,h->vextex[i].outsum,h->vextex[i].insum);
}

//深度优先遍历有向图
void DFS(AdjMatrix *h,char ms)
{
   char j;
   int t,o;
   printf("%3c",ms);//先输出第一个顶点
   o=chan(ms);//转换ms的值为数
   visited[o]=1;
   t=FirstMatrix(h,o);//图h中顶点ms的第一个邻接点
   while(t!=-1)
   {
	   if(!visited[t]) 
	   {
           j=change(t);
		   DFS(h,j);}
	       t=NextMatrix(h,o,t);//图h中顶点ms的下一个邻接点
   }
}

//广度优先遍历
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
	printf("请输入图遍历的第一个顶点:");
	fflush(stdin);
	scanf("%c",&r);
    init_SeQueue();
	DFS(&g,r);//深度优先遍历
	for( i=1; i<=g.vexnum; i++ )
	{
		visited[i] =0;
	}
	printf("\n");
		BFS(&q,r);//广度优先遍历
}