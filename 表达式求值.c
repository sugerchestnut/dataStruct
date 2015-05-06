//
//  main.c
//  算术表达式求值
//
//  Created by 潘璐pl on 14-10-12.
//  Copyright (c) 2014年 潘璐pl. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int level(char op)
{
    switch(op)
    {
        case '*':return 3;
        case '/':return 3;
        case '+':return 2;
        case '-':return 2;        
        case '@':return 0;
        default : return 1;
    }
}

int cal(char op,int x1,int x2)
{
    switch (op) {
        case '*':return x2*x1;
        case '/':return x2/x1;
        case '+':return x2+x1;
        case '-':return x2-x1;
    }
}

int process(char s[])
{
    char sop[100];
    int snum[100];
    int top,tnum,y,op,x1,x2;
    char *p=s;
    top=0;
    tnum=-1;
    y=0;        
    sop[top]='@';
    while(*p)
    {
        if(*p>='0'&&*p<='9')
        {
            while (*p>='0'&&*p<='9') {
                y=y*10+(*p-'0');
                p++;
            }
            snum[++tnum]=y;
        }
        else if (*p=='+'||*p=='-'||*p=='/'||*p=='*')
        {
            while (level(*p)<=level(sop[top])) {
                op=sop[top--];
                x1=snum[tnum--];
                x2=snum[tnum--];
                snum[++tnum]=cal(op, x1, x2);
            
            }sop[++top]=*p++;
        }
        else if(*p=='(')  sop[++top]=*p++;
        else if(*p==')')
        {
            while (sop[top]!=')') {
                op=sop[top--];
                x1=snum[tnum--];
                x2=snum[tnum--];
                snum[++tnum]=cal(op, x1, x2);
            }top--;p++;
        }
        else  p++;
    }
    while(sop[top]!='@')
    {
        op=sop[top--];
        x1=snum[tnum--];
        x2=snum[tnum--];
        snum[++tnum]=cal(op, x1, x2);
    }
    return snum[tnum];
}
int main(int argc, const char * argv[])
{
    char s[100];
    int x;
    printf("请输入表达式：");
    scanf("%s",s);
    x=process(s);
    printf("该表达式的值为：%d",x);
    return 0;    
}

