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
    ofstream bub("heap.txt");
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

void heapify(int *array, int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && array[l] > array[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && array[r] > array[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(array[i], array[largest]);

        // Recursively heapify the affected sub-tree
        heapify(array, n, largest);
    }
}

// main function to do heap sort
void heapSort(int *array, int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(array[0], array[i]);

        // call max heapify on the reduced heap
        heapify(array, i, 0);
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
int *array = new int[n];

//array = new int [n];
//int size = sizeof(array)/sizeof(array[0]);
for(int y =1; y<argc; y++)
    str=(argv[y]);
read(str,array);
start = std::clock();
heapSort(array,n);
duration= (std::clock()-start)/(double) CLOCKS_PER_SEC;
cout<<"duration---"<<duration<<endl;
write(array,n);
}
