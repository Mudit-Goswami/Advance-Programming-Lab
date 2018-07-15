//#ifndef KNAPSACK_H
#define KNAPSACK_H
#include <vector>
#include <random>
#include <iostream>
#include <time.h>
#include <algorithm>


class knapsack
{

public:
    struct population
    {
        int fitness;
        int weight;
        int pop[5];
    };

public:

    knapsack();

    void initPopulation(std::vector<population> &pop, std::vector<knapsack::population> &initBuffer);
    void calFitness(std::vector<population> &pop, int userInput[][5]);

    void sortByFitness(std::vector<population> &sort);

    void mate(std::vector<population> &mate1, std::vector<population> &mate2);
    void copyNewGeneration(std::vector<population> &copyFrom, std::vector<population> &copyTo);
    void mutate(std::vector<population> &mutate, std::vector<population> &buffer);

    void swap(std::vector<knapsack::population> &pop, std::vector<knapsack::population> &buffer);

    int randGenerate(int start, int end);

    void print(std::vector<knapsack::population> &pop);

    void solve(int userInput[][5]);

private:
    int popSize;
    int maxB;
    int maxW;
    int bagWeight;

public:
    std::default_random_engine dRandom;
};


typedef std::vector<knapsack::population> chromosomes;

knapsack::knapsack():dRandom(), popSize(10), maxB(0), maxW(0), bagWeight(20){}

void knapsack::initPopulation( chromosomes &initPop,  chromosomes &initBuffer)
{
    knapsack::population p;

    int gene = 0;

    for(int i = 0; i < popSize; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            gene = randGenerate(0, 2);
            p.pop[j] = gene;
        }

        initPop.push_back(p);
    }

    initBuffer.resize(popSize);
}

int knapsack::randGenerate(int start, int end)
{
    std::uniform_int_distribution<int> genenNum(start, end - 1);

    return genenNum(dRandom);
}
void knapsack::calFitness( chromosomes &pop, int userInput[][5])
{
    int fit    = 0;
    int weight = 0;
    for(int i = 0; i < popSize; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(pop[i].pop[j] == 1)
            {
                weight         += userInput[0][j];
                fit            += userInput[1][j];
                pop[i].weight  = weight;
                pop[i].fitness = fit;

                if(weight > bagWeight)  pop[i].fitness = 0;
            }
            else
            {
                weight         += 0;
                fit            += 0;
                pop[i].weight  = weight;
                pop[i].fitness = fit;
            }

        }
        weight = 0;
        fit    = 0;
    }

}

void knapsack::copyNewGeneration( chromosomes &copyFrom,  chromosomes &copyTo)
{
    for(int i = 0; i < popSize;i++)
    {
        for(int j = 0; j < 5; j++)
        {
            copyTo[i].pop[j] = copyFrom[i].pop[j];
        }

        copyTo[i].fitness = copyFrom[i].fitness;
    }
}

void knapsack::mutate( chromosomes &mutate,  chromosomes &buffer)
{

    int pIndex1 = randGenerate(0, popSize);
    int  pIndex2= randGenerate(0, popSize);

    int index1 = randGenerate(0, 5);
    int index2 = randGenerate(0, 5);


    buffer[pIndex1].pop[index1] = mutate[pIndex2].pop[index2];



}

void knapsack::mate( chromosomes &mate1,  chromosomes &mate2)
{
   copyNewGeneration(mate1,mate2);

   for(int i= 0; i < 5; i++ )
   {
       int index1 = randGenerate(0, 5);
       int index2 = randGenerate(0, 5);


       if(mate2[i].weight < bagWeight || mate2[i].weight > bagWeight)
         {
             mate2[index1].pop[i] = mate1[index2].pop[i];
         } 

   }

   mutate(mate1,mate2);
}

void knapsack::sortByFitness( chromosomes &sort)
{

    std::sort(sort.begin(),sort.end(),
        []( const population & x, const population & y) -> bool { return( x.fitness > y.fitness);} );
}

void knapsack::swap( chromosomes &pop,  chromosomes &buffer)
{
     chromosomes *temp = &pop;
     pop = buffer;
     buffer = *temp;
}

void knapsack::print( chromosomes &pop)
{

    if(pop[0].fitness > maxB)
       {
           maxB = pop[0].fitness;
       }

    std::cout<< " Max Benefit : "<<maxB<<std::endl;
}

void knapsack::solve(int userInput[][5])
{

     chromosomes initPop, initBuffer, *pop, *buffer;


    initPopulation(initPop, initBuffer);

    pop    = &initPop;
    buffer = &initBuffer;

    for(int i = 0; i < 100; i++)
    {
        calFitness(*pop, userInput);
        sortByFitness(*pop);
        print(*pop);            
        mate(*pop,*buffer);
        swap(*pop,*buffer);

    }
}

int main()
{
    srand(unsigned(time(NULL)));

    int u[2][5] = {{2 , 7 , 1 , 4 , 1},{5 , 3 , 2 , 9 , 6}};

    knapsack ks;

    ks.solve(u);


    std::cin.get();

    return 0;
}



