#include<stdio.h>

int col[8]={0};
int left[15]={0};
int right[15]={0};
int Q[8]={0};
int t=0;
void Queen(int i)
{
	int j,k;
	for(j=0;j<8;j++)
	{
		if((!col[j]) && (!left[i+j]) && (!right[7+i-j]))
		{
			col[j]=1;
			left[i+j]=1;
			right[7-i+j]=1;
			Q[i]=j;

			if(i<7)
				Queen(i+1);
			else
			{
				t++;
				for(k=0;k<8;k++)
					printf("%3d%3d%3d",t,k,Q[k]);
				printf("\n");
			}
			col[j]=0;
			left[i+j]=0;
			right[7+i-j]=0;
		}
	}
	return;
}

int main(void)
{
	int i;
	i=0;
	Queen(i);
}