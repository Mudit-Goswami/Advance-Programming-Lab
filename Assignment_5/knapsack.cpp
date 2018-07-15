#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <bits/stdc++.h>

using namespace std;

void read(const char* str,int array[])
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
//    for(int i=0; i<j;i++)
//    {
//        cout<<array[i]<<endl;
//    }
}

struct Item
{
    int value, weight;
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int n)
{
    sort(arr, arr + n, cmp);


    int curWeight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++)
    {

        if (curWeight + arr[i].weight <= W)
        {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }


        else
        {
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double) remain / arr[i].weight);
            break;
        }
    }


    return finalvalue;
}

int compare_max(int a,int b)
{
    return (a > b)? a : b;

}

int knapsack(int total_cost, int weight[], int items[], int n)
{
    int i,w;
    int k[n+1][total_cost+1];

    for(i=0 ; i<=n; i++)
    {
        for(w=0; w<= total_cost; w++)
        {
            if(i==0 || w==0)
                k[i][w] = 0;
            else if (weight[i-1] <=w)
                k[i][w] = max(items[i-1] + k[i-1][w-weight[i-1]], k[i-1][w]);
            else
                k[i][w] = k[i-1][w];
        }
    }
    return k[n][total_cost];
}

int knapSack(int W, int wt[], int val[], int n)
{

   if (n == 0 || W == 0)
       return 0;


   if (wt[n-1] > W)
       return knapSack(W, wt, val, n-1);


   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),
                    knapSack(W, wt, val, n-1)
                  );
}

int main()
{
const char* str;
const char* str1;
const char* str2;
str = "02_c.txt";
str1 = "02_p.txt";
str2 = "02_w.txt";
int n = 24;
int total_cost[1];
int weight[n];
int item[n];
read(str1,item);
read(str2,weight);
read(str,total_cost);
Item arr[24];
for(int i=0; i<n;i++)
{
  arr[i].weight   = weight[i];
  arr[i].value = item[i];
}
int total = total_cost[0];
cout<< knapSack(total,weight,item,n)<<endl;
//cout<< knapsack(total,weight,item,n)<<endl;
//cout<<fractionalKnapsack(total,arr,n);
}
