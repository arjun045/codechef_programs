
#include<stdio.h>
#include<stdlib.h>
struct city{
int ci;
struct city *next;
};
 
struct city *ptr[10001];
 
int n,k,p[10001],db[10001][101];
 
void rec(int prc,int pac)
{
    struct city *temp;
    int j;
    temp=ptr[prc];
 
    db[prc][p[prc]]=prc;
    while(temp)
    {
        if(temp->ci==pac)
        {
            temp=temp->next;
            continue;
        }
 
        rec(temp->ci,prc);
        for(j=1;j<=k;j++)
            if(db[prc][j]>db[temp->ci][j])
               db[prc][j]=db[temp->ci][j];
        temp=temp->next;
    }
 
    return ;
 
 
 
}
 
void rec1(int prc,int pac)
{
 
    int j;
    struct city *temp;
    for(j=1;j<=k;j++)
    {
        if(db[prc][j]==n+1)
            db[prc][j]=db[pac][j];
    }
    temp=ptr[prc];
    while(temp)
    {
        if(temp->ci==pac)
        {
            temp=temp->next;
            continue;
        }
 
        rec1(temp->ci,prc);
        temp=temp->next;
 
 
 
    }
 
 
 
    return;
 
 
}
 
 
 
 
int main()
{
    struct city *temp;
    int q,chci,pr,i,j,x,y,cap;
    scanf("%d",&n);
    scanf("%d",&k);
    scanf("%d",&cap);
    for(i=1;i<=n;i++)
        for(j=1;j<=k;j++)
            db[i][j]=n+1;
    for(i=0;i<n-1;i++)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        //for city x
        temp=(struct city*)malloc(sizeof(struct city));
        temp->ci=y;
        temp->next=ptr[x];
        ptr[x]=temp;
 
         temp=(struct city*)malloc(sizeof(struct city));
        temp->ci=x;
        temp->next=ptr[y];
        ptr[y]=temp;
    }
 
  /* for( i=1;i<=n;i++)
   {
       temp=ptr[i];
       while(temp)
       {
           printf("%d ",temp->ci);
           temp=temp->next;
       }
       printf("\n");
   }*/
   for(i=1;i<=n;i++)
    scanf("%d",&p[i]);
   rec(cap,cap);
   rec1(cap,cap);
 
/*for(i=1;i<=n;i++)
{
        for(j=1;j<=k;j++)
            printf("%d ",db[i][j]);
printf("\n");
}*/
 
 
scanf("%d",&q);
  for(i=0;i<q;i++)
  {
      scanf("%d",&chci);
      scanf("%d",&pr);
      if(db[chci][pr]==n+1)
        printf("%d\n",-1);
      else
      printf("%d\n",db[chci][pr]);
  }
 
 
 
 
return 0;
}
 

