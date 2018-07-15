#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <bits/stdc++.h>

using namespace std;

# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))


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
    ofstream bub("quick.txt");
    if(bub.is_open())
    {
     for(int r=0;r<no-1;r++)
        bub<< array[r]<<"\n";
    }
    else cout<<"Unable to onpen file"<<endl;
}

void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int array[],int start,int end)
{
    int pivot = array[end];
    int partition_index = start;
    for(int i = start; i<end; i++)
    {
        if(array[i]<=pivot)
        {
            swap(array[i],array[partition_index]);
                    partition_index++;
        }
    }
    swap(array[partition_index],array[end]);
    return partition_index;
}

void quickSort(int array[],int start,int end)
{
    if(start<end)
    {
    int pIndex = partition(array,start,end);
    quickSort(array,start,pIndex-1);
    quickSort(array,pIndex+1,end);
    }
}

int main(int argc,char* argv[])
{
std::clock_t start,end;
double duration;
string str;
int n;
cout<<"Length of array to be used"<<endl;
cin>>n;
int *array = new int[n];
//array = new int [n];
//int size = sizeof(array)/sizeof(array[0]);
for(int y =1; y<argc; y++)
    str=(argv[y]);
read(str,array);
start = std::clock();
quickSort(array, 0, n-1);
end=std::clock();
duration= (double)(end-start)/(double) CLOCKS_PER_SEC;
cout<<"duration---"<<duration<<endl;
write(array,n);
}
