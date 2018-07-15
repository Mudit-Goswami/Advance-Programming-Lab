#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

void write(int num)
{
    srand((unsigned)time(0));
    vector<int> random;
    ofstream myfile ("random.txt");
    if(myfile.is_open())
    {
        for(int i =0; i<num;i++)
        {
            random.push_back(rand());
            myfile<<random[i]<<"\n";

        }

    }
    else cout<<"Unable to onpen file"<<endl;
}

int main()
{
int n;
cout<<"Enter the no. of intergers to be generated"<<endl;
cin>>n;
//int array[n];
write(n);
}


