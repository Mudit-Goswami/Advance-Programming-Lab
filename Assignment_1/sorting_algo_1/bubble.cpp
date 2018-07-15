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
//    for(int t=0;t<j-1;t++)
//    {
//        cout<<array[t]<<"\n"<<endl;
//    }
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int *array, int num)
{
    for(int i=0;i<num-1;i++)
    {
        for(int j=0;j<num-i-1;j++)
        {
            if(array[j]>array[j+1])
                swap(&array[j],&array[j+1]);
        }
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
bubble_sort(array,n);
duration= (std::clock()-start)/(double) CLOCKS_PER_SEC;
cout<<"duration---"<<duration<<endl;
write(array,n);
}

