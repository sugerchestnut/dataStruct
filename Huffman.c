#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 90
#define M 2*N-1
#define G 90

typedef struct
{
	int weigh;
	int parent;
	int Lchild;
	int Rchild;
}HTNode,HuffmanTree[M+1];

typedef char * HuffmanCode[N+1];

struct  node
{
	char zifu1;//
	char code[N];//�ַ��ı���
}HT[N];//����ĸ����������һ��

struct Count
{
	char al;
	int num;
}HT1[G];//�ļ����ַ������༰Ȩֵ

FILE * fp;
FILE * fp1;
char a1[N];
char CH[N];//��������0 1����
int count,count1,count2,count4=0;//count2����ĳ��ȣ�0 1��count�ļ����ַ��ĳ���
int Num;
char CQ[N];
char CA[N];
char sh[N];//���������8λ�Ķ������ַ�

void Selete(HuffmanTree ht,int n,int * x1,int * x2)//����huffman��ʱ��Ҫ��selet����
{
	int i;
	int MIN1,MIN2;
	ht[0].weigh=300;
	MIN1=ht[0].weigh;//���⣺�±�������
	MIN2=ht[0].weigh;
	for(i=1;i<=n;i++)
		if(ht[i].weigh<ht[MIN1].weigh&&ht[i].parent==0)
			MIN1=i;
	*x1=MIN1;
	for(i=1;i<=n;i++)
		if(ht[i].weigh<ht[MIN2].weigh&&i!=*x1&&ht[i].parent==0)
			MIN2=i;
	*x2=MIN2;
}

void CrtHuffmanTree(HuffmanTree ht,int h[],int n)//����huffman��
{
	int s1,s2;
	int m=2*n-1,i;
	for(i=1;i<=n;i++)
	{   ht[i].weigh=h[i];
		ht[i].Lchild=0;
		ht[i].Rchild=0;
		ht[i].parent=0;
	}
	for(i=n+1;i<=m;i++)
	{
		ht[i].weigh=0;//�ṹ����Ҫһһ��ֵ���������帳ֵ
		ht[i].Lchild=0;
		ht[i].Rchild=0;
		ht[i].parent=0;
	}
	for(i=n+1;i<=m;i++)
	{
		Selete(ht,i-1,&s1,&s2);//���±�������͵�ȡ��ַ
		ht[i].weigh=ht[s1].weigh+ht[s2].weigh;
		ht[i].Lchild=s1;
		ht[i].Rchild=s2;
		ht[s1].parent=i;
		ht[s2].parent=i;
	}
}

//����ģ��
void CrtHuffmanCodel(HuffmanTree ht,HuffmanCode hc,int n)//����
{
	char * cd;
	int start,c,p,i;
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(i=1;i<=n;i++)
	{
		start=n-1;
		c=i;
		p=ht[i].parent;
		while(p!=0)
		{
			--start;
			if(ht[p].Lchild==c)
				cd[start]='0';
			else
				cd[start]='1';
			c=p;
			p=ht[p].parent;
		}
		hc[i]=(char *)malloc((n-start)*sizeof(char));
		strcpy(hc[i],&cd[start]);
	}
}

//�������ģ��
void TransCodes(struct node HT[],char s[],int n,int length,char a1[])
{
	int i=0,j=0,k,h=1,p;
	printf("\n��������ַ����ı������£�\n");
	while(j<length)
	{
		for(i=1;i<=n;i++)
			if(s[j]==HT[i].zifu1)
			{
				printf("%s",HT[i].code);
				k=strlen(HT[i].code);
				for(p=0;p<k;p++)
				{
					a1[h]=HT[i].code[p];
					h++;
				}
			}
		j++;
	}
	printf("\n");
}

void Read_file1(struct Count HT1[])
{
	int i,k;
	char ch1;
	if((fp=fopen("E:\\stringcodes.txt","r"))==0)
	{	printf("\n\t\t�ܱ�Ǹ!û������Ҫ��ѯ������\n");
        exit(1);
	}
	ch1=fgetc(fp);
	i=1;
	while(ch1!=EOF) 
	{
		CA[i]=ch1;
		printf("%c",ch1);
		for(k=1;CA[i]!=HT1[k].al&&HT1[k].al!='0';k++)
			;
		if(HT1[k].al=='0')
		{
			HT1[k].al=CA[i];
			HT1[k].num++;
		}//ͳ��ÿ���ַ���Ȩֵ
		else
			if(CA[i]==HT1[k].al)//(�������е��ַ�)
				HT1[k].num++;
		ch1=fgetc(fp);
		i++;
	}
	printf("\n");
	fclose(fp);
	count=i-1;
	count1=i-1;
}

void Filecode(HuffmanTree ht,HuffmanCode hc,struct node HT[],struct Count HT1[])
{
	int i,j=1,num,quan[N];
	char Ch[N];
	while(HT1[j].al!='0')
	{
		printf("HT1[%d].al=%c  HT1[%d].num=%d\n",j,HT1[j].al,j,HT1[j].num);
		Ch[j]=HT1[j].al;
		quan[j]=HT1[j].num; 
		j++;
	}
	num=j-1;
	CrtHuffmanTree(ht,quan,num);//����������Ȩֵ���飬Ҷ������
	CrtHuffmanCodel(ht,hc,num);//��������;
	printf("�������£�\n");
	for(i=1;i<=num;i++)
	{
		HT[i].zifu1=HT1[i].al;//�����ַ�������strcpy,ֻ���ַ�������
		printf("HT[%d].zifu1=%c  ",i,HT[i].zifu1);
		strcpy(HT[i].code,hc[i]);//hc[i]Ϊÿ���ַ��ı�����ַ���
		printf("HT[%d].code=%s\n",i,HT[i].code);
	}
	for(i=0;i<count;i++)
		CA[i]=CA[i+1];
	TransCodes(HT,CA,num,count,a1);
}

void Save_file()//��������01���浽transtion�ļ���
{
	int i=1;
	fp=fopen("E:\\Translation.txt","w");
	CH[i]=a1[i];
	while(a1[i]!='\0')
	{
		fputc(CH[i],fp);
		i++;
		CH[i]=a1[i];
	}
	fclose(fp);
	count2=i-1;
	printf("count2=%d\n",count2);
}

void Read_file2()
{
	int i;
	char ch1;
	if((fp=fopen("E:\\Translation.txt","r"))==0)
	{	printf("\n\t\t�ܱ�Ǹ!û������Ҫ��ѯ������\n");
        exit(1);
	}
	ch1=fgetc(fp);//��translation�ļ��еı��������
	i=1;
	while(ch1!=EOF) 
	{
		CQ[i]=ch1;//
		i++;
		ch1=fgetc(fp);
	}
	printf("\n");
	fclose(fp);
	Num=i-1;
}

void Trans(char CQ[])//����ʱ���е�01 ���ַ������ƥ��
{
	int i=1,w,d,k,j,f;
	while(i<=Num)	
	{
		w=i;	//i����,w��ס��ʼʱi��λ��
		for(j=1;j<=count1;j++)//�ַ�������(3���ַ�)
		{
			k=strlen(HT[j].code);
			d=0;
			for(f=0;f<k;f++)
				if(CQ[i]==HT[j].code[f])
				{
					d++;
					i++;
				}
			if(d==k)                         
			{
				printf("%c",HT[j].zifu1);//
				i=w+d;//ƥ��ɹ�,i������
				break;
			}
			else
				i=w;//���ɹ�,i�˻�
		}
	}
	printf("\n");
}

void Check()//����ƥ������
{
	int count5=0;
	char ch,ch1;
	if((fp=fopen("E:\\Translation.txt","r"))==0)
	{	printf("\n\t\t�ܱ�Ǹ!û������Ҫ��ѯ������\n");
        exit(1);
	}
	if((fp1=fopen("E:\\check.txt","r"))==0)
	{	printf("\n\t\t�ܱ�Ǹ!û������Ҫ��ѯ������\n");
        exit(1);
	}
	ch=fgetc(fp);
	ch1=fgetc(fp1);
	while(ch!=EOF&&ch1!=EOF)
	{
		if(ch==ch1)
			count5++;
		ch=fgetc(fp);
		ch1=fgetc(fp1);
	}
	if(count2==count5)
		printf("\n��ѹ�ɹ�!\n");
	else
		printf("��ѹʧ��!\n");
	fclose(fp);
    fclose(fp1);

}

void Dail(int a[],int n)//n�Ǵ�������ʮ���Ƹ���
{
	int i=1,j,m,t,k1,q,count3,p,g;
	int k[8];
	char ch;
	printf("count4=%d\n",count4);
	printf("-------\n");
	for(i=1;i<=count4;i++)
		printf("sh[%d]=%c  ",i,sh[i]);
	printf("\n");
	fp=fopen("E:\\check.txt","w");
	for(i=1;i<=n;i++)
	{
		if(i==n&&count4!=0)//����Ǹ�����8λ�Ķ����Ʊ���
			for(g=1;g<=count4;g++)
			{
				printf("%c",sh[g]);	//sh��ȫ������
				fputc(sh[g],fp);
			}
		if(i<n)//ǰ������8λ
		{
			j=8;
			while(a[i]!=0)
			{
				k[j]=a[i]%2;
				a[i]=a[i]/2;
				j--;
			}
			if(j>0&&i!=n)//ʮ����ת���ɰ�λʱ����8λ�ֶ���0
			{
				for(;j>=1;j--)
					k[j]=0;
			}
			for(m=1;m<=8;m++)
			{
				printf("%d",k[m]);
				ch=k[m]+48;// 0 1ת�����ַ���
				fputc(ch,fp);
			}
		}
		//printf("\n");
	}
	fclose(fp);
	Check();
}

void Jieya(int n)
{
	unsigned char ch;
	int k,a[50];
	if((fp=fopen("E:\\yasuo.txt","r"))==0)
	{	printf("\n\t\t�ܱ�Ǹ!û������Ҫ��ѯ������\n");
        exit(1);
	}
	ch=fgetc(fp);
	k=1;
	while(k<=n)
	{
		a[k]=ch;
		printf("a[%d]=%d\n",k,a[k]);
		k++;//k����һ��
		ch=fgetc(fp);
	}
	fclose(fp);
	k=k-1;
	Dail(a,k);//��ѹ��k����ʮ���Ƹ���
}

void Yasuo(int num[],int n)
{
	int i;
	unsigned char ch;//char����int���Զ�ת������
	for(i=1;i<=n;i++)
		printf("%d ",num[i]);
	printf("\n");
	for(i=1;i<=n;i++)
		printf("(i=%d %c)  ",i,num[i]);
	printf("\n");
	if((fp=fopen("E:\\yasuo.txt","w"))==NULL)
	{	printf("\n\t\t--�ܱ�Ǹ!û������Ҫ��ѯ������\n");
        exit(0);
	}
	i=1;
	while(i<=n)
	{
		ch=num[i];
		fputc(ch,fp);
		i++;
		
	}
	fclose(fp);
	Jieya(n);
}

void Change()//�����ƻ�ʮ����
{
	int i=1,j,a[20],num=1,sum=0,count[N],k=1,p,t=0,b,c;
	char ch1,z[8];
	if((fp=fopen("E:\\Translation.txt","r"))==NULL)
	{	printf("\n\t\t�ܱ�Ǹ!û������Ҫ��ѯ������\n");
        exit(1);
	}
	//ch1=fgetc(fp);
	//printf("\n");
	while(1)
	{
		if(t>count2)//count2��¼�ļ���0  1�ַ������ַ��ĸ���
			break;
		ch1=fgetc(fp);
		t++;
		i=1;
		while(ch1!=EOF) 
		{
			z[i]=ch1;
			//printf("z[%d]=%c  ",i,z[i]);
			if(i==8)//�ҵ�8λ��ʱ��ͽ�����������ת����ʮ����
				break;
			i++;
			ch1=fgetc(fp);
			t++;
		}
		//printf("\n");
		//printf("i=%d t=%d\n",i,t);
		if(t%8!=0)
		{
			i=i-1;
			for(b=1;b<=i;b++)
			{
				sh[b]=z[b];
				count4++;
			}//����8λ��¼����0 1
			for(b=1;b<=i;b++)
				z[9-b]=z[b];
			for(b=1;b<=8-i;b++)
				z[b]='0';
			//printf("----------\n");

		}
		//for(i=1;i<=8;i++)
			//printf("z[%d]=%c  ",i,z[i]);
		//printf("\n");
		sum=0;
		for(i=1;i<=8;i++)
		{
			num=1;
			if(z[i]=='1')
			{
				for(j=1;j<=8-i;j++)
					num=num*2;
				sum=sum+num;
				//printf("sum=%d\n",sum);
			}
		}
		//printf("sum=%d\n",sum);
		count[k]=sum;
		k++;
		//printf("\n");
	}
	//printf("k=%d\n",k);
	fclose(fp);
	Yasuo(count,k-1);
}

int main()
{
	int i=1,b,j=0,decide;
	int a[N];
	char zifu[N],s[N],ch; 
	HuffmanTree ht;
	HuffmanCode hc; 
	/*printf("������Ҷ�ӽ��ĸ�����");
	scanf("%d",&b);
	while(i<=b)
	{
		ch=getchar();//����
		printf("�������ַ���Ȩֵ��");
		scanf("%c%d",&zifu[i],&a[i]);
		i++;
	}
	printf("\n");
	CrtHuffmanTree(ht,a,b);//��������������Ȩֵ���飬Ҷ����
	printf("�������£�\n");
	CrtHuffmanCodel(ht,hc,b);//��������
	for(i=1;i<=b;i++)
	{
		HT[i].zifu1=zifu[i];
		printf("HT[%d].zifu1=%c  ",i,HT[i].zifu1);
		strcpy(HT[i].code,hc[i]);
		printf("HT[%d].code=%s\n",i,HT[i].code);
	}
	printf("������һ���ַ�����");
	scanf("%s",s);
	i=strlen(s);
	TransCodes(HT,s,b,i,a1);*/
	j=1;
	while(j<=G)
	{
		HT1[j].al='0';//�ַ�
		HT1[j].num=0;
		j++;
	}//��ʼ��
	Read_file1(HT1);
	Filecode(ht,hc,HT,HT1);
	Save_file();
	Read_file2();
	Trans(CQ);
	printf("�Ƿ����ѹ���ͽ�ѹ��(����1��ʾͬ�⣬����0����ʾ�ܾ�)");
	scanf("%d",&decide);
	if(decide==1)
		Change();
	else
		printf("���Խ�ѹ����!\n");
	printf("\n");
	return 0;
}




