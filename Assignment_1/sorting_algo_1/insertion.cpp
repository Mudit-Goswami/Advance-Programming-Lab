#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

void read(string str,int *array)
{
    int j=0;
    ifstream myreadfile;
    myreadfile.open(str);
    if(myreadfile.is_open())
    {
    while(!myreadfile.eof())
    {
        myreadfile >> array[j];
        j++;
    }
    myreadfile.close();
    }
}

void write(int *array,int no)
{
    ofstream bub("insertion.txt");
    if(bub.is_open())
    {
     for(int r=0;r<no-1;r++)
        bub<< array[r]<<"\n";
    }
    else cout<<"Unable to onpen file"<<endl;
}

void insertion(int *array, int num)
{
    for(int i=1;i<num;i++)
    {
       int current_element=array[i];
       int j = i-1;

      while(j>=0 && array[j]>current_element)
      {
          array[j+1]=array[j];
          j=j-1;
      }
      array[j+1]=current_element;
    }
}

int main(int argc,char* argv[])
{
std::clock_t start;
double duration;
string str;
int n;
cout<<"Length of array to be used"<<endl;
cin>>n;
int *array;
array = new int [n];
for(int y =1; y<argc; y++)
    str=(argv[y]);
read(str,array);
start = std::clock();
insertion(array,n);
duration= (std::clock()-start)/(double) CLOCKS_PER_SEC;
cout<<"duration---"<<duration<<endl;
write(array,n);
}
