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

int sequential_search(int *array,int l,int r,int x)
{
    for(int i = 0; i<r ; i++)
    {
        if(x==array[i])
            return i;
    }
    return -1;
}



int main(int argc,char* argv[])
{
std::clock_t start;
double duration;
string str;
int n,x;
cout<<"Length of array to be used"<<endl;
cin>>n;
int array[n];
int size = sizeof(array)/sizeof(array[0]);
for(int y =1; y<argc; y++)
    str=(argv[y]);
read(str,array);
cout<<"Enter the number you want to find in the array"<<endl;
cin>>x;
start = std::clock();
int result = sequential_search(array,0,size,x);
if(result==-1)
    cout<<"Number not found"<<endl;
else
    cout<<"Number found at position-->"<< result <<endl;
duration= (std::clock()-start)/(double) CLOCKS_PER_SEC;
cout<<"Duration-->"<<duration<<endl;
}

