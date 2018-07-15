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

int binary_search(int *array,int l,int r,int x)
{
    if(r>=l)
    {
        int mid = l+(r-l)/2;
        if(x==array[mid])
            return mid;
        if(x>array[mid])
            return binary_search(array,mid+1,r,x);
        if(x<array[mid])
            return binary_search(array,0,mid-1,x);
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
int result = binary_search(array,0,size-1,x);
if(result==-1)
    cout<<"Number not found"<<endl;
else
    cout<<"Number found at position"<< result <<endl;
duration= (std::clock()-start)/(double) CLOCKS_PER_SEC;
cout<<"duration---"<<duration<<endl;
}

