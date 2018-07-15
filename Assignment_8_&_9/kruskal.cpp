#include<stdio.h>
#include<math.h>

#define infinity 543672.0

int parent[10000];
double kruskal(int n,double **c,double **tree);
int find(int);
int uni(int,int);




int main()
{
    int i,j,n;
    double **a,**tree,tc;
    //float w[n];
     FILE *fp;
    fp=fopen("euc10000.txt","r");
    fscanf(fp,"%d",&n);
    double w[2*n];
    //printf("%d",n);

    for(i=0;i<2*n;i++)
           {fscanf(fp,"%lf ",&w[i]);
              printf("%0.7f ",w[i]);
            }


       a=(double**)malloc(n*sizeof(double*));
      for(i=0;i<n;i++)
        a[i]=(double*)malloc(n*sizeof(double));

        tree=(double**)malloc(n*sizeof(double*));
      for(i=0;i<n;i++)
        tree[i]=(double*)malloc(n*sizeof(double));

        for(i=0;i<n;i++)
             for(j=0;j<n;j++)
                {
                    a[i][j]=(sqrt(pow((w[j]-w[i]),2)+pow((w[j+1]-w[i+1]),2)));
                    //printf("%f ",a[i][j]);
                }



    tc=kruskal(n,a,tree);


    for(i=0;i<n;i++)
    {
       printf("\n");
        for(j=0;j<n;j++)
            printf("%f  ",tree[i][j]);
    }

    printf("\n\nTotal cost of spanning tree=%0.7f",tc);
    return 0;
}
double kruskal(int n,double **c,double **tree){
  double **cost;
 double mdis,dis[n],min,mincost=0;
    int u,v,from[n],visited[n],e=0,i,j,a,b;
   for(i=0;i<n;i++)
    visited[i]=0;
    cost=(double**)malloc(n*sizeof(double*));
      for(i=0;i<n;i++)
        cost[i]=(double*)malloc(n*sizeof(double));

        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            tree[i][j]=0.0;
            if(c[i][j]==0.0)
                cost[i][j]=infinity;
            else
                cost[i][j]=c[i][j];

        }



 while(e<n){
min=infinity;
    for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
    if(cost[i][j]<min)
    {
     min=cost[i][j];
     a=u=i;
     b=v=j;
    }
   }
  }

   u=find(u);
  v=find(v);
  if(uni(u,v))
  {
tree[a][b]=cost[a][b];
mincost=mincost+min;
printf("%f\n",mincost);
 e++;}
 cost[a][b]=cost[b][a]=infinity;
  }

 return mincost;
}

int find(int i)
{
 while(parent[i])
  i=parent[i];
 return i;
}
int uni(int i,int j)
{
 if(i!=j)
 {
  parent[j]=i;
  return 1;
 }
 return 0;
}
