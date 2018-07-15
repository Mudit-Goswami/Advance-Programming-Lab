#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

void mymakematrix(float **&temp, unsigned short int rws, unsigned short int cls) //create a matrix
{
    unsigned short int i;
    temp = new float* [rws];
    for(i=0; i<rws; ++i)
        temp[i] = new float [cls];
}

int upperleft(float **graph,int row, int column, int n)
{
 while(row>=0 && column>=0)
 {
     int n_row = row-1;
     int n_column = column-1;
     cout<<"any insertion herejugkh"<<endl;
     row--;
     column--;
     if(graph[n_row][n_column] == 0 )
     {
         cout<<"any insertion here"<<endl;
         graph[n_row][n_column] = 1;
     }
 }
}

int upperright(float **graph,int row, int column, int n)
{
 while(row<0 && column>n)
 {
     int n_row = row-1;
     int n_column = column+1;
     row--;
     column++;
     if(graph[n_row][n_column] == 0 )
         graph[n_row][n_column] = 1;
 }
}

int lowerleft(float **graph,int row, int column,int n)
{
    while(row<n && column>=0)
    {
        int n_row = row+1;
        int n_column = column-1;
        cout<<"any insertion lowerleft"<<endl;

        row++;
        column--;
        if(graph[n_row][n_column] == 0 )
            graph[n_row][n_column] = 1;
    }
}

int lowerright(float **graph,int row, int column,int n)
{
  while(row<n && column<n)
  {
      int n_row = row +1;
      int n_column = column+1;
      cout<<"any insertion lowerright"<<endl;

      row++;
      column++;
      if(graph[n_row][n_column] == 0 )
      {
          graph[n_row][n_column] = 1;
          cout<<"any insertion herejugkh"<<endl;

  }
  }
}

int curr_row(float **graph,int row, int column, int n)
{
    cout<<graph[0][0]<<endl;
   for(int i = 0; i<n ; i++)
   {
       if(i<=n-2)
       {
           int s = i+1;
           graph[s][row] = 1;
       cout<<graph[0][0]<<graph[1][0]<<graph[2][0]<<graph[3][0]<<endl;
       cout<<"does  "<<i<<endl;
       graph[row][column]=2;
   }
   }

}

int curr_column(float **graph, int row, int column, int n)
{
    cout<<graph[0][0]<<endl;
    for(int j = 0; j<n ; j++)
    {
//        if(graph[column][i+1] == 0)
            graph[column][j+1] = 1;
            cout<<graph[0][0]<<graph[0][1]<<graph[0][2]<<graph[0][3]<<endl;
            graph[row][column]=2;

    }
}

void printmyboard(float **graph, int row, int column, int n)
{
    for(int i=0; i< n; i++)
    {
        for(int j=0; j<n ; j++)
        {
//            cout<<graph[i][j];
//            cout<<"/n"<<endl;
        }
    }
}

int main()
{
    float **graph;
    int n,row,column,i;
    cout<<"Enter the size of the ChessBoard to be used"<<endl;
    cout<<">>> ";
    cin>>n;
    column =n;
    mymakematrix(graph,n,n);
    for(i = 0; i<n ; i++)
    {
        for(int j = 0; j<column ; j++)
        {
            if(i==0 && j==0)
            {
                cout<<"here"<<endl;
                graph[i][j] = 2;
//                graph[i+1][j] = 1;
//                graph[i][j+1]=1;
//                 if((i+1)<=n && (j+1)<=n && (i-1)>=0 && (j-1)<=0)
//                 {
                graph[i+1][j+1]=1;
//                 }
                curr_row(graph,i,j,n);
                curr_column(graph,i,j,n);
//                lowerright(graph,i,j,n);
            }
             cout<<graph[i][j]<<"   just a check"<<endl;
            if(graph[i][j]==0)
            {
                 cout<<"see any here"<<endl;
               graph[i][j]=2;
               curr_row(graph,i,j,n);
               curr_column(graph,i,j,n);
               if((i+1)<=n && (j+1)<=n && (i-1)>=0 && (j-1)<=0 )
                {
                   cout<<"see any here"<<endl;
                   if(graph[i+1][j+1]==0)
                       graph[i+1][j+1]=1;
                   if(graph[i+1][j-1]==0)
                        graph[i+1][j-1]=1;
                   if(graph[i-1][j-1]==0)
                       graph[i-1][j-1]=1;
                   if(graph[i-1][j+1]==0)
                       graph[i-1][j+1]=1;

               }
            }

}



//            if(graph[i][j] == 0)
//

//            {
//                graph[i][j] = 2;
//                curr_row(graph,i,j,n);
//                curr_column(graph,i,j,n);
//                cout<<"fault 1"<<endl;

//                if(j==0 && graph[i][j]!=1 )
//                {

//                }


//                if(i>0)
//                {
//                upperleft(graph,i,j,n);
//                cout<<"fault 2"<<endl;
//                upperright(graph,i,j,n);
//                cout<<"fault 3"<<endl;
//                lowerleft(graph,i,j,n);
//                cout<<"fault 4"<<endl;
//                lowerright(graph,i,j,n);
//                cout<<"fault 5"<<endl;
//                }
//                i++;
//            }



printmyboard(graph,row,column,n);

}
}
