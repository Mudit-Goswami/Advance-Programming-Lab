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
    ofstream bub("merge.txt");
    if(bub.is_open())
    {
     for(int r=0;r<no-1;r++)
        bub<< array[r]<<"\n";
    }
    else cout<<"Unable to onpen file"<<endl;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int *L= new int[n1];
    int *R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int i = 0;

        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);


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
int *array= new int[n];
//array = new int [n];
//int size = sizeof(array)/sizeof(array[0]);
for(int y =1; y<argc; y++)
    str=(argv[y]);
read(str,array);
start = std::clock();
mergeSort(array, 0, n-1);
duration= (std::clock()-start)/(double) CLOCKS_PER_SEC;
cout<<"duration---"<<duration<<endl;
write(array,n);
}
