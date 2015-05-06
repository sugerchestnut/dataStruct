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
}Vextype;//����Ľṹ��

typedef struct
{
	int arcs[MAXVEX][MAXVEX];
	Vextype vex[MAXVEX];
	int vexnum;
	int arcnum;
}AdjMatrix;//�ڽӾ���

typedef struct
{
	int no;//�������
	char na[20];//��������
	char in[250];//����������Ϣ����
}Elemsn;

typedef struct ArcNode
{
     char s[20];//��������
	int adjvex;//�������
	int weight;//��ͷ���㵽�ö���ľ���
	struct ArcNode *next;
}ArcNode;//�ڽӱ��ж�����

typedef struct VertexNode
{
    char c[20];//��������
	int vexdata;//�������
	ArcNode *head;
}VertexNode;//�ڽӱ��еı�ͷԪ��

typedef struct 
{
	VertexNode vertex[MAXVEX];//��ͷ����
	int vexnumber;//������
	int arcnumber;//������
}AdjList;//�ڽӱ�


int FirstAdiVex(AdjList *h,int ms)   //ͼh��ms�ĵ�һ���ڽӵ�,���ض���Ĵ���
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

int NextAdiVex(AdjList *h,int ms,int t)//ͼ�ж���ms����ڶ���t����һ���ڽӵ�
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
        printf("\t\t\t\t               �ط���--(����)           \n");
        printf("\t\t\t\t      (1)����                           \n");
        printf("\t\t\t\t                              (2)����¥ \n");
        printf("\t\t\t\t    (3)��ѧ�������                   \n");
        printf("\t\t\t\t                              (4)���˺� \n");
        printf("\t\t\t\t      (5)ͼ���                         \n");
        printf("\t\t\t\t                              (6)������ \n");
	    printf("\t\t\t\t      (7)�ٳ�                           \n");
	    printf("\t\t\t\t                              (8)����Է \n"); 
	    printf("\t\t\t\t      (9)����                           \n");
	    printf("\t\t\t\t                              (10)����  \n");
	    printf("\t\t\t\t      (11)ҽԺ                          \n");
	    printf("\t\t\t\t                              (12)����  \n");
	    printf("\t\t\t\t      (13)����                        \n");
	    printf("\t\t\t\t                         (14)����ʵ��¥ \n");
	    printf("\t\t\t\t     (15)����ʵ��¥                     \n");
	    printf("\t\t\t\t                         (16)һ��ʵ��¥ \n");
	    printf("\t\t\t\t     (17)b����ѧ¥                      \n");
	    printf("\t\t\t\t                         (18)a����ѧ¥  \n");
	    printf("\t\t\t\t           (19)ѧ�����������         \n");
		printf("\t\t\t\t****************************************\n");
}

void Informan(AdjList *h)//��ѯָ���������Ϣ
{
	int i,a;
	FILE *fp;
	Elemsn m[20];//����ṹ��
	printf("������Ҫ��ѯ�Ķ������(1-19):");
	scanf("%d",&a);
	if((fp=fopen("E:\\information.txt","r"))==NULL)//�򿪱�����Ϣ���ļ�
		{
			printf("cannot open file\n");
			exit(0);
		}
	while(a)
	{	
	    for(i=1;i<=h->vexnumber;i++)
		{
			fscanf(fp,"%d %s %s",&m[i].no,m[i].na,m[i].in);//���ļ��ж�ȡ
			if(i==a)
				printf("%-5d %5s %10s",m[i].no,m[i].na,m[i].in);
		}
		printf("\n\t\t\t������ѯ��������ѯ������Ҫ��ѯ�Ķ�����ţ��˳���ѯ��������0��:");
		scanf("%d",&a);
	}
	fclose(fp);
}

void map()//��ͼչʾ
{
printf("\n\n\n\n\n ----------------������������������������������---------------�����š�------������-------------------��������������������------|\n");
printf("|                                                 ------------------------------------------------������¥��------------------|\n");
printf("|                                               ------------------------------------------������¥������¥��------------------|\n");
printf("| -----��ѧ��--------------------                      ��ˮ��-------------------------������������������������������������  |\n");
printf("| -----������----------��~������ѧ¥��¥~��   ---------�����ӡ�                                                               |\n");
printf("| -----������------------------------------   --------------------------------------------------------------------------------|\n");
printf("| -----�������ġ�------��~������ѧ¥��¥~��   -------------------------------------------------------------------��~��*��*��~ |\n");
printf("|---------��~~~~~~��------��~~~~һ��~~~~��-------    -------------------------- ��ˮ         ��~��ѧ��~��---------------------|\n");
printf("|---------��~~~~~~��------��~~~ʵ��¥~~~��-------    -------------------------- ���         ������ġ�---------------------|\n");
printf("|---------��~~~~~~��------��~~~~����~~~~��-------    --------------------------   -------------------��~��*��*��~��  С����   |\n");
printf("|---------��~~~~~~��------��~~~ʵ��¥~~~��-------                                                                       ��  ·|\n");
printf("|---------��~~~~~~��------��~~~~����~~~~��-------                                                      ������*���ȡ�          |\n");
printf("|---------��~~~~~~��------��~~~ʵ��¥~~~��              -----------��Уʷ|~~~~~~~~~~~~~~~~~~��                                | \n");
printf("|----------------------------------           ����-------                        ��~~~~~ͼ*��*��~~~~~��-----------------      |\n");
printf("|-------------��ˮ���껪��------         -----  ��                 ��~��~|~~~~~~~~~~~~~~~~~~��    У  ��                      |\n");
printf("|������������������������������            ��������������             ����������             ������������������������   ��  ��|\n");
printf("|                                                                                                                  �����š�---|\n");
printf("|                                                                                ������������������������������������������ - |\n");
printf("|           ��~~~~ҽ**Ժ~~~~��                                                                               |����������������|          | \n");
printf("|           ��~~~ѧ*��*��~~~��                                                                        ~����~                |\n");
printf("|    | ��~~~~~~~~�� |                                                                                                         | \n");
printf("|    | ��~~~��~~~�� |                                                                                                         | \n");
printf("|    | ��~~~��~~~�� |                                ��  ��                             ��~~~����~~~��---------     ��        | \n");
printf("|    | ��~~~~~~~~�� |                                  ��                                ��~~~��~~~��-------                  | \n");
printf("|                                                                                                                   ��        | \n");
printf("|      ��         ��                                                                                                          |\n");
printf("|          �����š�                                                |��~~~����Է~~~~��|                                        | \n");
printf("|������������������������������������������������������    -------��~~~~~~~~~~~~~~~��    -----------�������������������� ����||\n");
printf("|        ��~05��¥~��            ��~04��¥~��                 ��~~~~~~~~~~~~~~~��                  ��12��¥��       ��13��¥��|\n");
printf("|������������  ������������������������  ����������         ����������������������        ��������                            |\n");
printf("|                                                                                                                             |\n");
printf("|------------��~~~~~~~~06��¥~~~~~~~~��---------------------- ------��~����~��------           ----��~14��¥|15 ��¥|16��¥~��| \n");
printf("|������������������������������������������������������------------------ ��������������������----------------------����������|\n");
}

void WriteFile(AdjList *h)//�����ݱ��浽�ļ���
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
    fprintf(fp,"%d\n",h->vexnumber);//������
	fprintf(fp,"%d\n",h->arcnumber);//����
	
	for(i=1;i<=h->vexnumber;i++)
	{
		p=h->vertex[i].head;
	    fprintf(fp,"%d %s",h->vertex[i].vexdata,h->vertex[i].c);//д���ڽӱ�һλ�����ͷ����Ϣ
	    while(p)
		{
		   fprintf(fp,"%d %s %d",p->adjvex,p->s,p->weight);//д���ͷ�����������������Ϣ
		   p=p->next;
		}
		fprintf(fp,"%c\n",t);//д�������

	}
	fclose(fp);
}

void ReadFile(AdjList *h)//��ȡ�ļ������Ϣ
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
    fscanf(fp,"%d",&h->vexnumber);//������
	fscanf(fp,"%d",&h->arcnumber);//����

	for(i=1;i<=h->vexnumber;i++)
		h->vertex[i].head=NULL;
	for(i=1;i<=h->vexnumber;i++)
	{
			c='p';
			l=h->vertex[i].head;
		
			fscanf(fp,"%d %s",&h->vertex[i].vexdata,h->vertex[i].c);
		
	        while(c!='#')
			{
			
				p=(ArcNode *)malloc(sizeof(ArcNode));//����һ������
				fscanf(fp,"%d %s %d",&p->adjvex,p->s,&p->weight);//���ļ��ж�ȡ������Ϣ
				p->next=NULL;//�����next�򸳿�
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
	/*for(i=1;i<=h->vexnumber;i++)//���ڽӱ��������ļ��ж�ȡ����Ϣ
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

void AddNode(AdjList *h)//���ڽӱ�����Ӷ���
{
	int n,distance,i;
	Elemsn el[25];
	int ch;
	ArcNode *p,*q,*t;
	char newno[25],tono[25],infor[50];
	printf("��������Ҫ��ӵĶ���:");
	scanf("%s",newno);
	for(n=1;n<=h->vexnumber;n++)
		if((strcmp(newno,h->vertex[n].c))==0)
		{
			printf("�ö����Ѵ���,�������!!!\n");
			return;
		}
	printf("������ö�����Ե���ĵط�:");
	scanf("%s",tono);

	printf("����������֮��ľ���:");
	scanf("%d",&distance);
//	printf("����������ӵص����Ϣ����:");
//	scanf("%s",infor);

	for(n=1;n<=h->vexnumber;n++)
		if((strcmp(tono,h->vertex[n].c))==0)
			break;
        h->vexnumber=h->vexnumber++;//��������һ
		strcpy(h->vertex[h->vexnumber].c,newno);
		h->vertex[h->vexnumber].vexdata=h->vexnumber;
		
			//strcpy(el[h->vexnumber].in,infor);

		p=(ArcNode *)malloc(sizeof(ArcNode));//�������㣬�յ�ҵ���ʼ������ȥ
		p->adjvex=n;
		strcpy(p->s,tono);
		p->next=NULL;
		p->weight=distance;
		h->vertex[h->vexnumber].head=p;

		q=(ArcNode *)malloc(sizeof(ArcNode));//��ʼ��ҵ��յ�����ȥ
		q->adjvex=h->vexnumber;
		strcpy(q->s,newno);
		q->weight=distance;
		q->next=NULL;
		t=h->vertex[n].head;

		while(t&&t->next)  t=t->next;
		if(!t)         h->vertex[n].head=q;
		else        t->next=q;

		for(i=1;i<=h->vexnumber;i++)//���ڽӱ����ʽ���
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
		printf("�Ƿ��޸ĺ����Ϣ���浽�ļ���(1>��   2>��):");
		scanf("%d",&ch);
		if(ch==1)
			WriteFile(h);//���޸ĺ�ı������ļ�
		printf("\n\n\t\t����������ز˵�");
		getchar();
		return;
}

void DeleNode(AdjList *h)//ɾ������
{
	int i,j,ch;
	char s1[25];
	ArcNode *q,*p;
	printf("������Ҫɾ���ĵ���:");
	scanf("%s",s1);
	for(i=1;i<=h->vexnumber;i++)
		if((strcmp(s1,h->vertex[i].c))==0)		
			break;
	for(j=1;j<=h->vexnumber;j++)
    {
              q=h->vertex[j].head;			 
			  while(q)//��ͷ�����Ǹ�ɾ�Ľڵ�
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
				   while(q)//ɾ����ͷ����Ķ���
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
	if(j!=h->vexnumber)//���Ҫɾ���Ĳ������һ��
	{
	   for(j=i+1;j<=h->vexnumber;j++)//�Ѻ����������ǰ��
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
		printf("�Ƿ��޸ĺ����Ϣ���浽�ļ���(1>��   2>��):");
		scanf("%d",&ch);
		if(ch==1)
			WriteFile(h);//���޸ĺ�ı������ļ�
		printf("\n\n\t\t����������ز˵�");
		getchar();
}

/*void BFS(AdjList *h,Queue *q)//���������ص�֮���һ����̵ļ�·�������·�����ȡ�����ת�������٣�
{
	int m,i,j;
	int t;	
	char sta[20],end[20];
	printf("������Ҫ��ѯ����ʼ��:");
	scanf("%s",sta);
	for(i=1;i<=h->vexnumber;i++)
	{
		if((strcmp(sta,h->vertex[i].c))==0)		
			break;
	}
	printf("\n������Ҫ��ѯ���յ�:");
	scanf("%s",end);
	for(j=1;j<=h->vexnumber;j++)
		if((strcmp(end,h->vertex[j].c))==0)
			break;
	visited[i]=1;
    EnQueue(q,i);
	while(!IsQueueEmpty(q))
	{
      DeQueue(q,&t);
	  m=FirstAdiVex(h,t);//�ҳ���ͷԪ�صĵ�һ���ڽӵ�
	  while(m!=0)
	  {
		  if(m==j)
		  {
			  printf("%5d%s",h->vertex[m].vexdata,h->vertex[h->vertex[m].vexdata].c);
			  return;
		  }
		  if(!visited[m])//���mû�����ʹ�
		  {
			  printf("%5d%s",h->vertex[m].vexdata,h->vertex[m].c);
			  visited[m]=1;
              EnQueue(q,m);
		  }
		  m=NextAdiVex(h,t,m);
	  }
	}
}*/

void Exchang(AdjList *h1,AdjMatrix *h2)//���ڽӱ�ת�����ڽӾ���
{
	int i,j,m,n;
	ArcNode *t;
	h2->vexnum=h1->vexnumber;
	h2->arcnum=h1->arcnumber;
	for(m=1;m<=h1->vexnumber;m++)//��ʼ���ڽӾ���Ķ�ά����
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
		for(n=1;n<=h2->vexnum;n++)//�������ʱ������
			printf("%7d",n);
		printf("\n");
       for(i=1;i<=h2->vexnum;i++)
	   {
		     printf("%7d",i);//�������ʱ������
          for(j=1;j<=h2->vexnum;j++)
		     printf("%7d",h2->arcs[i][j]);
	      printf("\n");
	   }*/
	  // for(i=1;i<=h2->vexnum;i++)
	//	   printf("%10s",h2->vex[i].na);
}

void PathAll(AdjList *G,int u,int v,int path[], int d,int c)  
{//d�ǵ���ǰΪֹ�Ѿ��߹���·�����ȣ�����ʱ��ֵΪ-1  
   int m, i; 
   //char a[20],b[20];
   ArcNode *p; 
   visited[u] = 1;  
   d++;                              //·�����ȼ�1  
   path[d] = u;                       //����ǰ������ӵ�·����  
   if(u==v)               //���һ��·��  
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
   //p=G->vertex[u].head;         //��pָ�򶥵�u�ĵ�һ�����Ļ�ͷ���  
   while(p != NULL)  
   {  
      m = p->adjvex;                  //mΪu���ڽӶ���  
      if(visited[m] == 0)             //����ö���δ��Ƿ��ʣ���ݹ����֮  
          PathAll(G,m,v,path,d,c);  
      p=p->next;                    //u����һ���ڽӶ���  
   }  
   visited[u] = 0;                     //�ָ�������ʹ�ö����������ʹ��  
} 

void Location1(AdjList *h,int c)//���ݵص���ȷ���±�
{
	char s1[25],s2[25];
	int i,j,d,f;
	int path[25]={0};
	printf("��ʼ��:");
	scanf("%s",s1);

	printf("�յ�վ:");
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
	printf("��ʼ��:");
	scanf("%s",s1);

	printf("�յ�վ:");
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
	//dist�����¼�������·�����ȣ�path�����¼��Ӧ·���ϵĸ�����
	int mindist,i,j,k,t=1;
	//	printf("wwwwwwwwwwwwwww\n");
	for(i=1;i<=h->vexnum;i++)
	{
		dist[i]=h->arcs[start][i];
		if(h->arcs[start][i]!=INFINITY)
			path[i][1]=start;
	}
	path[start][0]=1;
	for(i=2;i<=h->vexnum;i++)//Ѱ�Ҹ������·��
	{
		mindist=INFINITY;
		for(j=1;j<=h->vexnum;j++)//ѡ��Ȩֵ��С��·��
			if(!path[j][0]&&dist[j]<mindist)
			{
				k=j;
				mindist=dist[j];
			}
			if(mindist==INFINITY)   return;
			path[k][0]=1;
			for(j=1;j<=h->vexnum;j++)//�޸�·��
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
		printf("%s---->%s�����·��Ϊ:��%s",h1->vertex[start].c,h1->vertex[endl].c,h1->vertex[start].c);
		for(j=2;path[i][j]!=0;j++)
			printf("->%s",h1->vertex[path[i][j]].c);
		printf("->%s,����Ϊ:%dm\n",h1->vertex[endl].c,dist[i]);
}

void Prim(AdjMatrix *h)//ͼ����Ѳ�������
{	
	struct node
	{
		int adjvex;
		int lowcost;
	}closedge[MAXVEX];//��prim�㷨��ʹ�õĽṹ��

	int i,e,k,m,min;
	int start;
	//printf("���������:");
	//scanf("%d",&start);
	char ii[25];
	printf("���������:");
	scanf("%s",ii);
	for(start=1;start<=h->vexnum;start++)//���±�
	{		
		if((strcmp(ii,h->vex[start].na))==0)		
			break;
	}
  //printf("%5d",start);
	closedge[start].lowcost=0;//��־����u�Ѽ��뵽������
	
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
		printf("��%s---%s:%dm\n",h->vex[closedge[m].adjvex].na,h->vex[m].na,closedge[m].lowcost);
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
	printf("\t\t\t\t****************У԰����ϵͳ*******************\n");
	printf("\t\t\t\t************** 1>��ʾ��ͼ *********************\n");
	printf("\t\t\t\t************** 2>��ѯ����·�� *****************\n");
	printf("\t\t\t\t************** 3>��ѯ�������·�� *************\n");
	printf("\t\t\t\t************** 4>��ѯ������ת��������·�� *****\n");
	printf("\t\t\t\t************** 5>��Ѳ������� *****************\n");
	printf("\t\t\t\t************** 6>��ӵص� *********************\n");
	printf("\t\t\t\t************** 7>��ѯ�ص���Ϣ *****************\n");
	printf("\t\t\t\t************** 8>ɾ���ص� *********************\n");
	printf("\t\t\t\t************** 0>�˳���ϵͳ *******************\n");
	printf("\n\n\t\t\t\t��ѡ��:");	
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
        h = (AdjList *)malloc(sizeof(AdjList));//�ڽӱ��ٿռ�
		p=(AdjMatrix *)malloc(sizeof(AdjMatrix));//�ڽӾ��󿪱ٿռ�
	ReadFile(h);//��ȡ�ļ�		
	Exchang(h,p);//ʵ���ڽӱ���ڽӾ����ת��
	printf("\n\n");
    Print();//����˵�

	menu();
	scanf("%d",&ch);	
	while(ch)
	{
		switch(ch)
		{
	        case 1:map();break;//��ʾ��ͼ
			case 2:Location1(h,ch);break;//��ѯ��������·��
			case 3:Location2(p,&i1,&j1);Dijkstra(p,h,i1,j1,dist,path);break;//��ѯ�������·��
			case 4:Location1(h,ch);break;//������ת�������ٵ�·��
			case 5:Prim(p);break;//��Ѳ�������
			case 6:AddNode(h);break;//����¶���
			case 7:Informan(h);break;//��ѯ�ص���Ϣ
			case 8:DeleNode(h);break;//ɾ������
			case 0:printf("\n\n\t\t\t��ӭ�´�ʹ��!\n");ending();break;
		}
		printf("\n\n\t\t\t\t��enter������:");
		fflush(stdin);
		getchar();
		printf("\n\n\n\t\t\t\t��ת��...");
		Sleep(3000);
		system("cls");
	    menu();
		scanf("%d",&ch);
	}
	return 0;
}


