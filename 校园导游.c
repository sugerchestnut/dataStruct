#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#define MAXVEX 50
#define MAXSIZE 25
#define N 0
#define INFINITY 32767
int visited[19]={0};
int visited2[19]={0};
int w;
int way[100]={0};
int opp=5000;
typedef struct
{
	char na[25];
	int number;
}Vextype;//顶点的结构体

typedef struct
{
	int arcs[MAXVEX][MAXVEX];
	Vextype vex[MAXVEX];
	int vexnum;
	int arcnum;
}AdjMatrix;//邻接矩阵

typedef struct
{
	int no;//顶点代号
	char na[20];//顶点名字
	char in[250];//顶点的相关信息描述
}Elemsn;

typedef struct ArcNode
{
     char s[20];//顶点名字
	int adjvex;//顶点代号
	int weight;//表头顶点到该顶点的距离
	struct ArcNode *next;
}ArcNode;//邻接表中顶点结点

typedef struct VertexNode
{
    char c[20];//顶点名字
	int vexdata;//顶点代号
	ArcNode *head;
}VertexNode;//邻接表中的表头元素

typedef struct 
{
	VertexNode vertex[MAXVEX];//表头数组
	int vexnumber;//顶点数
	int arcnumber;//弧个数
}AdjList;//邻接表


int FirstAdiVex(AdjList *h,int ms)   //图h中ms的第一个邻接点,返回顶点的代号
{
    ArcNode *ar;
    ar=h->vertex[ms].head;
	//while(visited[ar->adjvex]!=0 && ar->next)
	//	ar=ar->next;
	if(ar)
    	return ar->adjvex;
	else
		return 0;
}

int NextAdiVex(AdjList *h,int ms,int t)//图中顶点ms相对于顶点t的下一个邻接点
{
    ArcNode *ar;
	
	ar=h->vertex[ms].head;
	for(;ar;ar=ar->next)
	{
		if(ar->adjvex==t)
		{
			ar=ar->next;
			break;
		}	
	}
	if(ar)
	{
		
		return ar->adjvex;
	}
	else
    return 0;	
} 

void Print()
{
	printf("\n\n");
	    printf("\t\t\t\t****************************************\n");
        printf("\t\t\t\t               地方名--(代号)           \n");
        printf("\t\t\t\t      (1)北门                           \n");
        printf("\t\t\t\t                              (2)行政楼 \n");
        printf("\t\t\t\t    (3)大学生活动中心                   \n");
        printf("\t\t\t\t                              (4)情人湖 \n");
        printf("\t\t\t\t      (5)图书馆                         \n");
        printf("\t\t\t\t                              (6)体育馆 \n");
	    printf("\t\t\t\t      (7)操场                           \n");
	    printf("\t\t\t\t                              (8)旭日苑 \n"); 
	    printf("\t\t\t\t      (9)超市                           \n");
	    printf("\t\t\t\t                              (10)美广  \n");
	    printf("\t\t\t\t      (11)医院                          \n");
	    printf("\t\t\t\t                              (12)澡堂  \n");
	    printf("\t\t\t\t      (13)篮球场                        \n");
	    printf("\t\t\t\t                         (14)三号实验楼 \n");
	    printf("\t\t\t\t     (15)二号实验楼                     \n");
	    printf("\t\t\t\t                         (16)一号实验楼 \n");
	    printf("\t\t\t\t     (17)b栋教学楼                      \n");
	    printf("\t\t\t\t                         (18)a栋教学楼  \n");
	    printf("\t\t\t\t           (19)学术交流活动中心         \n");
		printf("\t\t\t\t****************************************\n");
}

void Informan(AdjList *h)//查询指定顶点的信息
{
	int i,a;
	FILE *fp;
	Elemsn m[20];//顶点结构体
	printf("请输入要查询的顶点序号(1-19):");
	scanf("%d",&a);
	if((fp=fopen("E:\\information.txt","r"))==NULL)//打开保存信息的文件
		{
			printf("cannot open file\n");
			exit(0);
		}
	while(a)
	{	
	    for(i=1;i<=h->vexnumber;i++)
		{
			fscanf(fp,"%d %s %s",&m[i].no,m[i].na,m[i].in);//从文件中读取
			if(i==a)
				printf("%-5d %5s %10s",m[i].no,m[i].na,m[i].in);
		}
		printf("\n\t\t\t继续查询？继续查询（输入要查询的顶点序号）退出查询（请输入0）:");
		scanf("%d",&a);
	}
	fclose(fp);
}

void map()//地图展示
{
printf("\n\n\n\n\n ----------------———————————————---------------【北门】------———-------------------——————————------|\n");
printf("|                                                 ------------------------------------------------【行政楼】------------------|\n");
printf("|                                               ------------------------------------------【附属楼【行政楼】------------------|\n");
printf("| -----【学】--------------------                      【水煮】-------------------------——————————————————  |\n");
printf("| -----【术】----------【~基础教学楼Ａ楼~】   ---------【鸽子】                                                               |\n");
printf("| -----【交】------------------------------   --------------------------------------------------------------------------------|\n");
printf("| -----【流中心】------【~基础教学楼Ｂ楼~】   -------------------------------------------------------------------【~情*人*坡~ |\n");
printf("|---------【~~~~~~】------【~~~~一号~~~~】-------    -------------------------- 乐水         【~大学生~】---------------------|\n");
printf("|---------【~~~~~~】------【~~~实验楼~~~】-------    -------------------------- 大道         【活动中心】---------------------|\n");
printf("|---------【~~~~~~】------【~~~~二号~~~~】-------    --------------------------   -------------------【~情*人*湖~】  小树林   |\n");
printf("|---------【~~~~~~】------【~~~实验楼~~~】-------                                                                       道  路|\n");
printf("|---------【~~~~~~】------【~~~~三号~~~~】-------                                                      【自在*咖啡】          |\n");
printf("|---------【~~~~~~】------【~~~实验楼~~~】              -----------【校史|~~~~~~~~~~~~~~~~~~】                                | \n");
printf("|----------------------------------           银杏-------                        【~~~~~图*书*馆~~~~~】-----------------      |\n");
printf("|-------------【水沐年华】------         -----  林                 【~馆~|~~~~~~~~~~~~~~~~~~】    校  门                      |\n");
printf("|———————————————            ———————             —————             ————————————   景  点|\n");
printf("|                                                                                                                  【东门】---|\n");
printf("|                                                                                ————————————————————— - |\n");
printf("|           【~~~~医**院~~~~】                                                                               |————————|          | \n");
printf("|           【~~~学*工*部~~~】                                                                        ~网球场~                |\n");
printf("|    | 【~~~~~~~~】 |                                                                                                         | \n");
printf("|    | 【~~~美~~~】 |                                                                                                         | \n");
printf("|    | 【~~~广~~~】 |                                运  动                             【~~~体育~~~】---------     操        | \n");
printf("|    | 【~~~~~~~~】 |                                  场                                【~~~馆~~~】-------                  | \n");
printf("|                                                                                                                   场        | \n");
printf("|      树         林                                                                                                          |\n");
printf("|          【西门】                                                |【~~~旭日苑~~~~】|                                        | \n");
printf("|———————————————————————————    -------【~~~~~~~~~~~~~~~】    -----------—————————— ——||\n");
printf("|        【~05号楼~】            【~04号楼~】                 【~~~~~~~~~~~~~~~】                  【12号楼】       【13号楼】|\n");
printf("|——————  ————————————  —————         ———————————        ————                            |\n");
printf("|                                                                                                                             |\n");
printf("|------------【~~~~~~~~06号楼~~~~~~~~】---------------------- ------【~超市~】------           ----【~14号楼|15 号楼|16号楼~】| \n");
printf("|———————————————————————————------------------ ——————————----------------------—————|\n");
}

void WriteFile(AdjList *h)//将数据保存到文件中
{
	FILE *fp;
	int i;
	char t='#';
	ArcNode *p;
	if((fp=fopen("routine.txt", "w"))==NULL)
	{
		printf("cannot open file\n");
		exit(0);
	}
    fprintf(fp,"%d\n",h->vexnumber);//顶点数
	fprintf(fp,"%d\n",h->arcnumber);//边数
	
	for(i=1;i<=h->vexnumber;i++)
	{
		p=h->vertex[i].head;
	    fprintf(fp,"%d %s",h->vertex[i].vexdata,h->vertex[i].c);//写入邻接表一位数组表头的信息
	    while(p)
		{
		   fprintf(fp,"%d %s %d",p->adjvex,p->s,p->weight);//写入表头数组后面的链表顶点的信息
		   p=p->next;
		}
		fprintf(fp,"%c\n",t);//写入结束符

	}
	fclose(fp);
}

void ReadFile(AdjList *h)//读取文件里的信息
{
	FILE *fp;
	ArcNode *p,*l,*q;
	int i;
	char c;
	if((fp=fopen("E:\\routine.txt","r"))==NULL)
	{
		printf("cannot open file\n");
		exit(0);
	}
    fscanf(fp,"%d",&h->vexnumber);//顶点数
	fscanf(fp,"%d",&h->arcnumber);//边数

	for(i=1;i<=h->vexnumber;i++)
		h->vertex[i].head=NULL;
	for(i=1;i<=h->vexnumber;i++)
	{
			c='p';
			l=h->vertex[i].head;
		
			fscanf(fp,"%d %s",&h->vertex[i].vexdata,h->vertex[i].c);
		
	        while(c!='#')
			{
			
				p=(ArcNode *)malloc(sizeof(ArcNode));//创建一个顶点
				fscanf(fp,"%d %s %d",&p->adjvex,p->s,&p->weight);//从文件中读取顶点信息
				p->next=NULL;//顶点的next域赋空
				l=h->vertex[i].head;
                while(l && l->next) 
                        l=l->next;
                if(!l)   
                        h->vertex[i].head=p;
                else    
                        l->next=p;
				
				fscanf(fp,"%c",&c);
			}
	     
    }
	fclose(fp);
	/*for(i=1;i<=h->vexnumber;i++)//按邻接表的输出从文件中读取的信息
        {
                q=h->vertex[i].head;
				
                printf("%5d%3s",h->vertex[i].vexdata,h->vertex[i].c);
                while(q)
                {
                        printf("%5d%3s%5d",q->adjvex,q->s,q->weight);
                        q=q->next;
                }
                printf("\n");
        }*/
}

void AddNode(AdjList *h)//在邻接表上添加顶点
{
	int n,distance,i;
	Elemsn el[25];
	int ch;
	ArcNode *p,*q,*t;
	char newno[25],tono[25],infor[50];
	printf("请输入你要添加的顶点:");
	scanf("%s",newno);
	for(n=1;n<=h->vexnumber;n++)
		if((strcmp(newno,h->vertex[n].c))==0)
		{
			printf("该顶点已存在,不能添加!!!\n");
			return;
		}
	printf("请输入该顶点可以到达的地方:");
	scanf("%s",tono);

	printf("这两个顶点之间的距离:");
	scanf("%d",&distance);
//	printf("请输入新添加地点的信息描述:");
//	scanf("%s",infor);

	for(n=1;n<=h->vexnumber;n++)
		if((strcmp(tono,h->vertex[n].c))==0)
			break;
        h->vexnumber=h->vexnumber++;//定点数加一
		strcpy(h->vertex[h->vexnumber].c,newno);
		h->vertex[h->vexnumber].vexdata=h->vexnumber;
		
			//strcpy(el[h->vexnumber].in,infor);

		p=(ArcNode *)malloc(sizeof(ArcNode));//创建顶点，终点挂到起始点上面去
		p->adjvex=n;
		strcpy(p->s,tono);
		p->next=NULL;
		p->weight=distance;
		h->vertex[h->vexnumber].head=p;

		q=(ArcNode *)malloc(sizeof(ArcNode));//起始点挂到终点上面去
		q->adjvex=h->vexnumber;
		strcpy(q->s,newno);
		q->weight=distance;
		q->next=NULL;
		t=h->vertex[n].head;

		while(t&&t->next)  t=t->next;
		if(!t)         h->vertex[n].head=q;
		else        t->next=q;

		for(i=1;i<=h->vexnumber;i++)//按邻接表的形式输出
        {
                q=h->vertex[i].head;
				
                printf("%5d%3s",h->vertex[i].vexdata,h->vertex[i].c);
                while(q)
                {
                        printf("%5d%3s%5d",q->adjvex,q->s,q->weight);
                        q=q->next;
                }
                printf("\n");
        }
		printf("是否将修改后的信息保存到文件中(1>是   2>否):");
		scanf("%d",&ch);
		if(ch==1)
			WriteFile(h);//将修改后的保存至文件
		printf("\n\n\t\t按任意键返回菜单");
		getchar();
		return;
}

void DeleNode(AdjList *h)//删除顶点
{
	int i,j,ch;
	char s1[25];
	ArcNode *q,*p;
	printf("请输入要删除的地名:");
	scanf("%s",s1);
	for(i=1;i<=h->vexnumber;i++)
		if((strcmp(s1,h->vertex[i].c))==0)		
			break;
	for(j=1;j<=h->vexnumber;j++)
    {
              q=h->vertex[j].head;			 
			  while(q)//表头后面是该删的节点
			  {			   		       
				   if(q->adjvex==i)
					   break;
				   p=q;	
				   q=q->next;
			  }
			  if(q)
			  {
				  if(q==h->vertex[j].head)
					  h->vertex[j].head=q->next;
				  else
					  p->next=q->next;
				  free(q);
			  }
			  
			    if(j==i)
				{
				   while(q)//删除表头数组的顶点
				   {
					    p=q; q=q->next;
						
						free(p);

				   }
				   h->vertex[i].head=NULL;
				}			
        }	
	for(j=1;j<=h->vexnumber;j++)
	{
		if(j==h->vexnumber) 
			break;
		
		if(j==i)
			j++;
		
		q=h->vertex[j].head;	
		while(q)  
		{
		  
			if(q->adjvex>i)
			{
				
				q->adjvex--;	
			}
			q=q->next;
		}		
	}
	if(j!=h->vexnumber)//如果要删除的不是最后一个
	{
	   for(j=i+1;j<=h->vexnumber;j++)//把后面的依次往前移
	   {
		strcpy(h->vertex[j-1].c,h->vertex[j].c);
		h->vertex[j-1].head=h->vertex[j].head;
		h->vertex[j-1].vexdata=j-1;
	   }
	}
	h->vexnumber--;
		for(j=1;j<=h->vexnumber;j++)
        {
                q=h->vertex[j].head;
				
                printf("%5d%3s",h->vertex[j].vexdata,h->vertex[j].c);
                while(q)
                {
                        printf("%5d%3s%5d",q->adjvex,q->s,q->weight);
                        q=q->next;
                }
                printf("\n");
        }
		printf("是否将修改后的信息保存到文件中(1>是   2>否):");
		scanf("%d",&ch);
		if(ch==1)
			WriteFile(h);//将修改后的保存至文件
		printf("\n\n\t\t按任意键返回菜单");
		getchar();
}

/*void BFS(AdjList *h,Queue *q)//任意两个地点之间的一条最短的简单路径（最短路径长度——中转次数最少）
{
	int m,i,j;
	int t;	
	char sta[20],end[20];
	printf("请输入要查询的起始点:");
	scanf("%s",sta);
	for(i=1;i<=h->vexnumber;i++)
	{
		if((strcmp(sta,h->vertex[i].c))==0)		
			break;
	}
	printf("\n请输入要查询的终点:");
	scanf("%s",end);
	for(j=1;j<=h->vexnumber;j++)
		if((strcmp(end,h->vertex[j].c))==0)
			break;
	visited[i]=1;
    EnQueue(q,i);
	while(!IsQueueEmpty(q))
	{
      DeQueue(q,&t);
	  m=FirstAdiVex(h,t);//找出队头元素的第一个邻接点
	  while(m!=0)
	  {
		  if(m==j)
		  {
			  printf("%5d%s",h->vertex[m].vexdata,h->vertex[h->vertex[m].vexdata].c);
			  return;
		  }
		  if(!visited[m])//如果m没被访问过
		  {
			  printf("%5d%s",h->vertex[m].vexdata,h->vertex[m].c);
			  visited[m]=1;
              EnQueue(q,m);
		  }
		  m=NextAdiVex(h,t,m);
	  }
	}
}*/

void Exchang(AdjList *h1,AdjMatrix *h2)//将邻接表转换成邻接矩阵
{
	int i,j,m,n;
	ArcNode *t;
	h2->vexnum=h1->vexnumber;
	h2->arcnum=h1->arcnumber;
	for(m=1;m<=h1->vexnumber;m++)//初始化邻接矩阵的二维数组
		for(n=1;n<=h1->vexnumber;n++)
			h2->arcs[m][n]=INFINITY;
		for(i=1;i<=h1->vexnumber;i++)
		{
		     t=h1->vertex[i].head;
			 strcpy(h2->vex[i].na,h1->vertex[i].c);
	         while(t)
			 {
				h2->arcs[i][t->adjvex]=t->weight;
				h2->arcs[t->adjvex][i]=t->weight;
				t=t->next;
			 }

		}
	/*	printf("\n     ");
		for(n=1;n<=h2->vexnum;n++)//矩阵输出时的列首
			printf("%7d",n);
		printf("\n");
       for(i=1;i<=h2->vexnum;i++)
	   {
		     printf("%7d",i);//矩阵输出时的行首
          for(j=1;j<=h2->vexnum;j++)
		     printf("%7d",h2->arcs[i][j]);
	      printf("\n");
	   }*/
	  // for(i=1;i<=h2->vexnum;i++)
	//	   printf("%10s",h2->vex[i].na);
}

void PathAll(AdjList *G,int u,int v,int path[], int d,int c)  
{//d是到当前为止已经走过的路径长度，调用时初值为-1  
   int m, i; 
   //char a[20],b[20];
   ArcNode *p; 
   visited[u] = 1;  
   d++;                              //路径长度加1  
   path[d] = u;                       //将当前顶点添加到路径中  
   if(u==v)               //输出一条路径  
   {  
	   if(c==4)
	   {
			if(opp>d)
			{
				opp=d;
				for(i=0;i<=d;i++)
				  way[i]=path[i];
			}
	   }
	  else if(c==2)
	  {
			for(i=0;i<=d;i++) 
			printf("%s  ",G->vertex[path[i]].c); printf("\n");
	  }

   } 
   p=G->vertex[u].head;
   //p=G->vertex[u].head;         //将p指向顶点u的第一条弧的弧头结点  
   while(p != NULL)  
   {  
      m = p->adjvex;                  //m为u的邻接顶点  
      if(visited[m] == 0)             //如果该顶点未标记访问，则递归访问之  
          PathAll(G,m,v,path,d,c);  
      p=p->next;                    //u的下一个邻接顶点  
   }  
   visited[u] = 0;                     //恢复环境，使该顶点可以重新使用  
} 

void Location1(AdjList *h,int c)//根据地点名确定下标
{
	char s1[25],s2[25];
	int i,j,d,f;
	int path[25]={0};
	printf("起始点:");
	scanf("%s",s1);

	printf("终点站:");
	scanf("%s",s2);
	d=-1;
	visited[19]=0;
	for(i=1;i<=h->vexnumber;i++)
		if((strcmp(s1,h->vertex[i].c))==0)		
			break;

	for(j=1;j<=h->vexnumber;j++)
		if((strcmp(s2,h->vertex[j].c))==0)
			break;
	if(c==2)
		PathAll(h,i,j,path,d,c);
	if(c==4)
	{
        printf("\n\n");
		PathAll(h,i,j,path,d,c);
		for(f=0;f<=opp;f++)
			printf("%-10s-->",h->vertex[way[f]].c);
	}
}
void Location2(AdjMatrix *h,int *m,int *n)
{
	char s1[25],s2[25];
	printf("起始点:");
	scanf("%s",s1);

	printf("终点站:");
	scanf("%s",s2);
	for(*m=1;*m<=h->vexnum;(*m)++)
	{
		
		if((strcmp(s1,h->vex[*m].na))==0)		
			break;
	}

	for(*n=1;*n<=h->vexnum;(*n)++)
	{
		
		if((strcmp(s2,h->vex[*n].na))==0)
			break;
	}
}

void Dijkstra(AdjMatrix *h,AdjList *h1,int start,int endl,int dist[],int path[][MAXVEX])
{
	//dist数组记录各条最短路径长度，path数组记录对应路径上的各顶点
	int mindist,i,j,k,t=1;
	//	printf("wwwwwwwwwwwwwww\n");
	for(i=1;i<=h->vexnum;i++)
	{
		dist[i]=h->arcs[start][i];
		if(h->arcs[start][i]!=INFINITY)
			path[i][1]=start;
	}
	path[start][0]=1;
	for(i=2;i<=h->vexnum;i++)//寻找各条最短路径
	{
		mindist=INFINITY;
		for(j=1;j<=h->vexnum;j++)//选择权值最小的路径
			if(!path[j][0]&&dist[j]<mindist)
			{
				k=j;
				mindist=dist[j];
			}
			if(mindist==INFINITY)   return;
			path[k][0]=1;
			for(j=1;j<=h->vexnum;j++)//修改路径
			{
				if(!path[j][0]&&h->arcs[k][j]<INFINITY && dist[k]+h->arcs[k][j]<dist[j])
				{
					dist[j]=dist[k]+h->arcs[k][j];
					t=1;
					while(path[k][t]!=0)
					{
						path[j][t]=path[k][t];
						t++;
					}
					path[j][t]=k;
					path[j][t+1]=0;
				}
			}
	}
	for(i=1;i<=h->vexnum;i++)
		if(i==endl)  break;
		printf("%s---->%s的最短路线为:从%s",h1->vertex[start].c,h1->vertex[endl].c,h1->vertex[start].c);
		for(j=2;path[i][j]!=0;j++)
			printf("->%s",h1->vertex[path[i][j]].c);
		printf("->%s,距离为:%dm\n",h1->vertex[endl].c,dist[i]);
}

void Prim(AdjMatrix *h)//图的最佳布网方案
{	
	struct node
	{
		int adjvex;
		int lowcost;
	}closedge[MAXVEX];//在prim算法中使用的结构体

	int i,e,k,m,min;
	int start;
	//printf("请输入起点:");
	//scanf("%d",&start);
	char ii[25];
	printf("请输入起点:");
	scanf("%s",ii);
	for(start=1;start<=h->vexnum;start++)//找下标
	{		
		if((strcmp(ii,h->vex[start].na))==0)		
			break;
	}
  //printf("%5d",start);
	closedge[start].lowcost=0;//标志顶点u已加入到集合中
	
	for(i=1;i<=h->vexnum;i++)
	{//printf("wwwwwwwwwwwwwwwwwww\n");
		if(i!=start)
		{
			closedge[i].adjvex=start;
			closedge[i].lowcost=h->arcs[start][i];
		}
	}
	for(e=1;e<=h->vexnum-1;e++)
	{		
		min=INFINITY;
		for(k=1;k<=h->vexnum;k++)
		{
			if(closedge[k].lowcost!=0 && closedge[k].lowcost<min)
			{
				m=k;
				min=closedge[k].lowcost;
			}
		}
		printf("从%s---%s:%dm\n",h->vex[closedge[m].adjvex].na,h->vex[m].na,closedge[m].lowcost);
		closedge[m].lowcost=0;
		for(i=1;i<=h->vexnum;i++)
		{
			if(i!=m&& h->arcs[m][i]<closedge[i].lowcost)
			{
					closedge[i].lowcost=h->arcs[m][i];
					closedge[i].adjvex=m;
			}
		}
	}
}

void menu()
{	
	printf("\n\n");
	printf("\t\t\t\t****************校园导游系统*******************\n");
	printf("\t\t\t\t************** 1>显示地图 *********************\n");
	printf("\t\t\t\t************** 2>查询两地路径 *****************\n");
	printf("\t\t\t\t************** 3>查询两地最短路径 *************\n");
	printf("\t\t\t\t************** 4>查询两地中转次数最少路径 *****\n");
	printf("\t\t\t\t************** 5>最佳布网方案 *****************\n");
	printf("\t\t\t\t************** 6>添加地点 *********************\n");
	printf("\t\t\t\t************** 7>查询地点信息 *****************\n");
	printf("\t\t\t\t************** 8>删除地点 *********************\n");
	printf("\t\t\t\t************** 0>退出该系统 *******************\n");
	printf("\n\n\t\t\t\t请选择:");	
}
void ending()
{
	printf("BB BB BB BB      YY          YY        EE EE EE EE    !! \n");
	printf("BB       BB        YY      YY          EE             !! \n");
	printf("BB       BB          YY  YY            EE             !! \n");
	printf("BB       BB            YY              EE             !! \n");
	printf("BB BB BB BB            YY              EE EE EE EE    !! \n");
	printf("BB       BB            YY              EE             !! \n");
	printf("BB       BB            YY              EE             !! \n");
	printf("BB       BB            YY              EE             !! \n");
	printf("BB BB BB BB            YY              EE EE EE EE    !! \n");
}
int main(void)
{
	int i1,j1;int ch;
	AdjList *h;
	AdjMatrix *p;
	int dist[MAXVEX];
	int path[MAXVEX][MAXVEX]={0};	
	i1=j1=1;//
        h = (AdjList *)malloc(sizeof(AdjList));//邻接表开辟空间
		p=(AdjMatrix *)malloc(sizeof(AdjMatrix));//邻接矩阵开辟空间
	ReadFile(h);//读取文件		
	Exchang(h,p);//实现邻接表和邻接矩阵的转换
	printf("\n\n");
    Print();//输出菜单

	menu();
	scanf("%d",&ch);	
	while(ch)
	{
		switch(ch)
		{
	        case 1:map();break;//显示地图
			case 2:Location1(h,ch);break;//查询两地所有路径
			case 3:Location2(p,&i1,&j1);Dijkstra(p,h,i1,j1,dist,path);break;//查询两地最短路径
			case 4:Location1(h,ch);break;//两地中转次数最少的路径
			case 5:Prim(p);break;//最佳布网方案
			case 6:AddNode(h);break;//添加新顶点
			case 7:Informan(h);break;//查询地点信息
			case 8:DeleNode(h);break;//删除顶点
			case 0:printf("\n\n\t\t\t欢迎下次使用!\n");ending();break;
		}
		printf("\n\n\t\t\t\t按enter键清屏:");
		fflush(stdin);
		getchar();
		printf("\n\n\n\t\t\t\t跳转中...");
		Sleep(3000);
		system("cls");
	    menu();
		scanf("%d",&ch);
	}
	return 0;
}


