#include<stdio.h>
#include<math.h>

#define infinity 54372.0

double prim(int n,double **a,double **tree);





int main()
{
    int i,j,n;
    double **a,**tree,tc;
    //float w[n];
     FILE *fp;
    fp=fopen("euc5000.txt","r");
    fscanf(fp,"%d",&n);
    double w[2*n];
    //printf("%d",n);

    for(i=0;i<2*n;i++)
           {fscanf(fp,"%lf ",&w[i]);
              //printf("%0.7f ",w[i]);
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



    tc=prim(n,a,tree);


    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
            printf("%f  ",tree[i][j]);
    }

    printf("\n\nTotal cost of spanning tree=%0.7f",tc);
    return 0;
}

double prim(int n,double **a,double **tree)
{
    double **cost;
    double mdis,dis[n],minc;
    int u,v,from[n],visited[n],e,i,j;

    cost=(double**)malloc(n*sizeof(double*));
      for(i=0;i<n;i++)
        cost[i]=(double*)malloc(n*sizeof(double));


    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            tree[i][j]=0.0;
            if(a[i][j]==0.0)
                cost[i][j]=infinity;
            else
                cost[i][j]=a[i][j];

        }


    dis[0]=0.0;
    visited[0]=1;

    for(i=1;i<n;i++)
    {
        dis[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }

    minc=0.00000;
    e=n-1;

    while(e>0)
    {

        mdis=infinity;
        for(i=1;i<n;i++)
            if(visited[i]==0&&dis[i]<mdis)
            {
                v=i;
                mdis=dis[i];
            }

        u=from[v];


        tree[u][v]=dis[v];
        tree[v][u]=dis[v];
        e--;
        visited[v]=1;


        for(i=1;i<n;i++)
            if(visited[i]==0&&cost[i][v]<dis[i])
            {
                dis[i]=cost[i][v];
                from[i]=v;
            }

        minc=minc+cost[u][v];
    }

    return minc;
}
