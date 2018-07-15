#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>    // std::min_element, std::max_element


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
    ofstream bub("count.txt");
    if(bub.is_open())
    {
     for(int r=0;r<no-1;r++)
        bub<< array[r]<<"\n";
    }
    else cout<<"Unable to onpen file"<<endl;
}

void count(int *array, int *aux, int *raux, int n,int max )
{
    for(int i = 0; i<max ; i++)
    {
        aux[i] = 0;
    }
    for(int j = 0; j<max ; j++)
    {
        int indx = array[j];
        cout<<"1111"<<endl;
        aux[indx]++;
    }
    for(int i = 1; i<max ; i++)
    {
        aux[i] = aux[i]+aux[i-1];
    }
    for(int i = 0; i<n ; i++)
    {
        raux[aux[array[i]] - 1] = aux[i];
    }
    for(int i = 0 ; i <n ; i++)
    {
        array[i] = raux[i];
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
int *array,*aux,*raux;
array = new int [n];
raux = new int [n];
for(int y =1; y<argc; y++)
    str=(argv[y]);
read(str,array);
int max = *std::max_element(array,array+n);
aux = new int [max];
cout<<max<<endl;
start = std::clock();
count(array,aux,raux,n,max);
duration= (std::clock()-start)/(double) CLOCKS_PER_SEC;
cout<<"duration---"<<duration<<endl;
write(array,n);
}
