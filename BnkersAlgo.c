#include<stdio.h>

int allo[5][3];
int max[5][3];
int req[5][3];
int finish[5]={0,0,0,0,0};
int need[5][3];
int sum=0;
int i,j,k=0,c=0;
int ans[5];
int aval[3]={3,3,2};

void request_process()
{
    int a,b,c;
    sum=0;
    int finish[5]={0,0,0,0,0};
    int aval[3]={3,3,2};
    c=0;
    a=b=c=0;    
    for(i=0;i<5;i++)
    {
        a+=req[i][0];
        b+=req[i][1];
        c+=req[i][2];
        if(a<=aval[0] && b<=aval[1] && c<=aval[2])
        {
            aval[0]-=a;
            aval[1]-=b;
            aval[2]-=c;
            for(i=0;i<5;i++)
            {
                for(j=0;j<3;j++)
                {
                    allo[i][j]+=req[i][j];
                }
            }
            for(i=0;i<5;i++)
            {
                for(j=0;j<3;j++)
                {
                    need[i][j]=max[i][j]-allo[i][j];
                }
            }
            while(sum!=5 && c!=6)
            {
            for(i=0;i<5;i++)
            {
                if(finish[i]==0)
                {
                    if(aval[0]>=need[i][0] && aval[1]>=need[i][1] && aval[2]>=need[i][2])
                    {
                        finish[i]=1;
                        aval[0]+=allo[i][0];
                        aval[1]+=allo[i][1];
                        aval[2]+=allo[i][2];
                        sum+=1;
                        ans[k]=i;
                        k++;
                    }
                }
            }
            c++;
            }
            if(sum==5)
            {   
                printf("Safe Sequence is when Request is completed:\n<");
                for(i=0;i<5;i++)
                {
                    printf("P%d ",ans[i]);
                }
                printf(">\n");
            }
            else
            {
                printf("DeadLock Arrised");
            }
        }
        else
        {
            printf("Request cannot be processed");  
        }
    }
    
}


void main()
{
    
    printf("Enter data for allocated\n");   
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&allo[i][j]);
        }
    }
    printf("Enter data for Max\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter data for Request\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&req[i][j]);
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            need[i][j]=max[i][j]-allo[i][j];
        }
    }
    while(sum!=5 && c!=6)
    {
        for(i=0;i<5;i++)
        {
            if(finish[i]==0)
            {
                if(aval[0]>=need[i][0] && aval[1]>=need[i][1] && aval[2]>=need[i][2])
                {
                    finish[i]=1;
                    aval[0]+=allo[i][0];
                    aval[1]+=allo[i][1];
                    aval[2]+=allo[i][2];
                    sum+=1;
                    ans[k]=i;
                    k++;
                }
            }
        }
        c++;
    }
    if(sum==5)
    {   
        printf("Safe Sequence is:\n<");
        for(i=0;i<5;i++)
        {
            printf("P%d ",ans[i]);
        }
        printf(">\n");
    }
    else
    {
        printf("DeadLock Arrised");
    }
    request_process();
}