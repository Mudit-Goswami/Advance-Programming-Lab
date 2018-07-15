#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define ROW 12
#define COL 16

using namespace std;

void mymakematrix(float **&temp, unsigned short int rws, unsigned short int cls) //create a matrix
{
    unsigned short int i;
    temp = new float* [rws];
    for(i=0; i<rws; ++i)
        temp[i] = new float [cls];
}

void read(string str,int graph[ROW][COL])
{
    int j = 0;
    int i = 0;
    int st = 0;
    int st1= 0;
    string line;
    ifstream file (str);
    while(getline(file, line))
    {

        if(j==0)
        {
             stringstream x(line);
         x >> st >> st1;
         cout<< st1 << " "<<st <<endl;
//         mymakematrix(graph,st,st1);
//         graph[st][st1];
            }
       if(j>0 && i<st)
       {
           stringstream x(line);

               for(int k=0 ; k<st1 ; k++)
               {
                   x >> graph[i][k] ;
                   cout<<graph[i][k]<< " ";
               }
               i++;
               cout<<" "<<endl;
              }
       j++;
    }
}

int no_row(string str)
{
    int st = 0;
    int st1= 0;
    string line;
    ifstream file (str);
    getline(file,line);
    stringstream x(line);
    x >> st >> st1;
    return st;
}

int no_column(string str)
{
    int st = 0;
    int st1= 0;
    string line;
    ifstream file (str);
    getline(file,line);
    stringstream x(line);
    x >> st >> st1;
    return st1;
}
int basic_condition(int graph[][COL], int row, int column, bool visited[][COL])
{
    return (row>=0) && (row<ROW) &&
            (column>=0) && (column<COL) &&
            (graph[row][column] && !visited[row][column]);
}


void depth_fs(int graph[][COL],int row1, int column1, bool visited[][COL])
{
    static int row_neutral[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int column_neutral[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    visited[row1][column1] = true;

    for (int i = 0; i<8 ; ++i)
    {
        if(basic_condition(graph, row1 + row_neutral[i], column1 + column_neutral[i], visited))
            depth_fs(graph, row1+row_neutral[i], column1+column_neutral[i],visited);
    }
}


int count_the_terrorist(int graph[ROW][COL])
{
    bool visited[ROW][COL];
    memset(visited, 0,sizeof(visited));

    int count = 0;
    for(int i=0 ; i<ROW; ++i)
    {
        for(int j=0; j<COL ; ++j)
        {
            if(graph[i][j] && !visited[i][j])
            {
                depth_fs(graph,i,j,visited);
                ++count;
            }
        }
    }
    return count;
}

int main(int argc,char* argv[])
{
int graph[ROW][COL];
string str;
int row,column;
for(int y =1; y<argc; y++)
    str=(argv[y]);
read(str,graph);
row = no_row(str);
column = no_column(str);

cout<< count_the_terrorist(graph)<<endl;
}
