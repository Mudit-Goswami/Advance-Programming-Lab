#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include<vector>
#include<algorithm>

using namespace std;

void mymakematrix(float **&temp, unsigned short int rws, unsigned short int cls) //create a matrix
{
    unsigned short int i;
    temp = new float* [rws];
    for(i=0; i<rws; ++i)
        temp[i] = new float [cls];
}

void read(string str,int *array, int *arr)
{
    int j = 0;
    string line;
    ifstream file (str);
    while(getline(file, line))
    {
        stringstream x(line);
       x >> array[j] >> arr[j];
       j++;
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

class Graph{
private:
        int V,E;
        vector<pair<int,pair<int,int> > > edges;
        vector<pair<int,pair<int,int> > > MST;
public:
        Graph(int V,int E);
        void addEdge(int u, int v, int w);
        int kruskalMST();
        void printMST();
};
Graph::Graph(int V,int E){
    this->V = V;
    this->E = E;
}
void Graph::addEdge(int u,int v,int w){
    edges.push_back({w,{u,v}});
}

void Graph::printMST(){
    vector<pair<int,pair<int,int> > >::iterator it;
    for(it = MST.begin();it!=MST.end();it++){
        cout << it->second.first << " - " << it->second.second << endl;
    }

}
struct DisjointSet{
    int *parent,*rnk;
    int n;

    DisjointSet(int n){
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];

        for(int i=0;i<=n;i++){
            rnk[i] = 0;
            parent[i] = i;
        }
    }
    int Find(int u){
        if(u == parent[u]) return parent[u];
        else return Find(parent[u]);
    }

    void Union(int x,int y){
        x = Find(x);
        y = Find(y);
        if(x != y){
            if(rnk[x] < rnk[y]){
                rnk[y] += rnk[x];
                parent[x] = y;
            }
            else{
                rnk[x] += rnk[y];
                parent[y] = x;
            }
        }
    }
};
int Graph::kruskalMST(){
    int MSTWeight = 0; //sum of all vertex weights
    sort(edges.begin(),edges.end());
    //for all u in G_v
    //    MAKE-SET(u)
    DisjointSet ds(this->V);

    vector<pair<int,pair<int,int> > >::iterator it;
    // for all edges in G
    for(it = edges.begin(); it!=edges.end();it++){
        int u = it->second.first;
        int v = it->second.second;

        int setU = ds.Find(u);
        int setV = ds.Find(v);


        if(setU != setV){
            int w = it->first;
            MST.push_back({w,{u,v}});
            MSTWeight += it->first;

            ds.Union(setU,setV);
        }
    }
    return MSTWeight;
}









int main(int argc,char* argv[])
{
float **graph;
std::clock_t start;
double duration;
string str;
int n = 20000000;
int end_index, nt1,nt2;
int *array, *arr;
array = new int [n];
arr = new int [n];
for(int y =1; y<argc; y++)
    str=(argv[y]);
read(str,array,arr);
int count = 0;
cout<<"Number of Students>> "<< array[0]<<endl;
int size = array[0];
for(int i=0 ; i<n ; i++)
{
    if(array[i] == arr[i] && count==0)
    {
        end_index = i-1;
        nt1 = array[i+1];
        nt2 = arr[i+1];
        cout<<"Test Case Numbers are>> "<<nt1<< i <<nt2<<endl;
        count++;
    }
}

Graph g(size,size);
    int u,v,w;
    for(int i=0;i<end_index;i++)
    {
        g.addEdge(array[i],arr[i],1);
        for(int j=1;j<=end_index;j++ )
        {
            if(array[i]==arr[j])
            {
                g.addEdge(array[j],arr[i],2);
                g.addEdge(arr[j],array[i],2);
            }


        }
    }

    int weight = g.kruskalMST();
    cout << "MST: " << endl;
    g.printMST();
    cout << "Weight of MST is: " << weight;

    return 0;


















//start = std::clock();
//duration= (std::clock()-start)/(double) CLOCKS_PER_SEC;
//cout<<"duration---"<<duration<<endl;
//write(array,n);
}
