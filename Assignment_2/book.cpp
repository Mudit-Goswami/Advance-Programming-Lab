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

void read(string str,int *array, int *arr)
{
    int j = 0;
    string line;
    ifstream file (str);
    while(getline(file, line))
    {
        stringstream x(line);
       x >> array[j] >> arr[j];
       j++;
    }
}

void write(int *array,int no)
{
    ofstream bub("bubble.txt");
    if(bub.is_open())
    {
     for(int r=0;r<no-1;r++)
        bub<< array[r]<<"\n";
    }
    else cout<<"Unable to onpen file"<<endl;
}



int main(int argc,char* argv[])
{
float **graph;
std::clock_t start;
double duration;
string str;
int n = 20000000;
int end_index, nt1,nt2;
int *array, *arr;
array = new int [n];
arr = new int [n];
for(int y =1; y<argc; y++)
    str=(argv[y]);
read(str,array,arr);
int count = 0;
cout<<"Number of Students>> "<< array[0]<<endl;
int size = array[0];
for(int i=0 ; i<n ; i++)
{
    if(array[i] == arr[i] && count==0)
    {
        end_index = i-1;
        nt1 = array[i+1];
        nt2 = arr[i+1];
        cout<<"Test Case Numbers are>> "<<nt1<< " "<<nt2<<endl;
        count++;
    }
}
mymakematrix(graph,size,size);
//for(int i=1 ; i<=end_index ; i++)
//{
//    graph[array[i]][arr[i]] = 1;
//}
for(int i = 1;i<=end_index ; i++)
{
    graph[array[i]][arr[i]] = 1;
    for(int j=1;j<=end_index;j++)
    {
      if(array[i]==array[j] && graph[arr[i]][arr[j]] != 1 )
      {
        graph[arr[i]][arr[j]] = 2;
      }
      if(arr[i]==arr[j] && graph[array[i]][array[j]] != 1)
      {
          graph[array[i]][array[j]] = 2;
      }
      if(array[i]==arr[j] && graph[array[j]][arr[i]] != 1 )
      {
          graph[array[j]][arr[i]] = 2;
          graph[arr[j]][array[i]] = 2;
      }
      if((array[i]==arr[j] && arr[j]==array[j+1]) && (graph[arr[i]][arr[j+1]] != 2 && graph[arr[i]][arr[j+1]] != 1) )
      {
//          graph[arr[i]][arr[j+1]] = 3;
          graph[arr[i]][array[i]] = 3;
          cout<<graph[arr[i]][array[i]]<<endl;
          cout<<"1"<<endl;
      }
      if(array[i]==array[j] && array[j]==array[j+1] && graph[arr[i]][arr[j+1]] != 1 && graph[arr[i]][arr[j+1]] != 2 )
      {
              graph[arr[i]][arr[j+1]] = 3;
              cout<<graph[arr[i]][arr[j+1]]<<endl;
              cout<<"2"<<endl;
      }
      if(arr[i]==arr[j] && arr[j]==arr[j+1] && graph[array[i]][array[j+1]] != 1 && graph[array[i]][array[j+1]] != 2)
      {
       graph[array[i]][array[j+1]] = 3;
       cout<<graph[array[i]][array[j+1]]<<endl;

       cout<<"3"<<endl;
      }
      if(arr[i]==arr[j] && arr[j]==array[j+1] && graph[array[i]][arr[j+1]] !=1 && graph[array[i]][arr[j+1]] !=2)
      {
          graph[array[i]][arr[j+1]] =3;
          cout<<graph[array[i]][arr[j+1]]<<endl;

          cout<<"4"<<endl;
      }
      if(array[i]==array[j] && array[j]==arr[j+1] && graph[arr[i]][array[j+1]] !=1 && graph[arr[i]][array[j+1]] !=2)
      {
          graph[arr[i]][array[j+1]] =3;
          cout<<graph[arr[i]][array[j+1]]<<endl;

          cout<<"5"<<endl;
      }
      if(array[i]==arr[j] && arr[j]==arr[j+1] && graph[arr[i]][array[j+1]] !=1 && graph[arr[i]][array[j+1]] !=2)
      {
          graph[arr[i]][array[j+1]] = 3;
          cout<<graph[arr[i]][array[j+1]]<<endl;

          cout<<"6"<<endl;
      }
      if(arr[i]==array[j] && array[j]== array[j+1] && graph[array[i]][arr[j+1]] != 1 && graph[array[i]][arr[j+1]] != 2)
      {
          graph[array[i]][arr[j+1]] =3;
          cout<<graph[array[i]][arr[j+1]]<<endl;

          cout<<"7"<<endl;
      }
//      if(arr[i]==array[j] && arr[j]==arr[j+1] && graph[array[i]][array[j+1]] !=1 && graph[array[i]][array[j+1]] !=2)
//      {
//          graph[array[i]][array[j+1]] =3;
//      }
      if(arr[i]==array[j] && arr[j]==array[j+1] && graph[array[i]][array[j+1]] !=1 && graph[array[i]][array[j+1]] !=2)
      {
          graph[array[i]][array[j+1]] =3;
          cout<<graph[array[i]][array[j+1]]<<endl;

          cout<<"8"<<endl;
      }
      if(array[i]==arr[j] && array[j]==arr[j+1] && graph[arr[i]][arr[j+1]]!=1 && graph[arr[i]][arr[j+1]]!=2)
      {
          graph[arr[i]][arr[j+1]]=3;
          cout<<graph[arr[i]][arr[j+1]]<<endl;

          cout<<"9"<<endl;
      }
//      if(array[i]==arr[j] && array[j]==array[j+1] && graph[arr[i]][arr[j+1]] !=1 &&graph[arr[i]][arr[j+1]] !=2 )
//      {
//          graph[arr[i]][arr[j+1]] =3;
//      }
//      if(array[i]==arr[j] && arr[j]==array[j+1] && graph[arr[i]][arr[j+1]] !=1 && graph[arr[i]][arr[j+1]] !=2)
//          graph[arr[i]][arr[j+1]] =3;
      if(array[i]==array[j] && arr[j]==array[j+1] && graph[arr[i]][arr[j+1]] !=1 && graph[arr[i]][arr[j+1]] !=2)
          graph[arr[i]][arr[j+1]] =3;
      if(arr[i]==arr[j] && array[j]==arr[j+1] && graph[array[i]][array[j+1]] !=1 && graph[array[i]][array[j+1]] !=2)
          graph[array[i]][array[j+1]] = 3;
      if(array[i]==array[j] && arr[j]==arr[j+1] && graph[arr[i]][array[j+1]]!=1 && graph[arr[i]][array[j+1]]!=2)
          graph[arr[i]][array[j+1]] = 3;
      if(arr[i]==arr[j] && array[j]==array[j+1] && graph[array[i]][arr[j+1]]!=1 && graph[array[i]][arr[j+1]]!=2)
          graph[array[i]][arr[j+1]] = 3;

    }
}
cout<<graph[7][6]<<endl;

cout<<"Checking the Test Case"<<endl;

if(graph[nt1][nt2]==1)
    cout<<"Roll number>> "<< nt1 <<" and  "<< nt2 <<" are friends "<<endl;
if(graph[nt1][nt2]==2)
    cout<<"Roll number>> "<< nt1 <<" and  "<< nt2 <<" are friend of friend "<<endl;
if(graph[nt1][nt2]==3)
    cout<<"Roll number>> "<< nt1 <<" and  "<< nt2 <<" are friend of friend of friend "<<endl;
if(graph[nt1][nt2]==0)
    cout<<"not friends"<<endl;
//start = std::clock();
//duration= (std::clock()-start)/(double) CLOCKS_PER_SEC;
//cout<<"duration---"<<duration<<endl;
//write(array,n);
}
