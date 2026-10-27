
#include <iostream>
#include <algorithm>
using namespace std;

#define V 4

int tsp(int graph[V][V], int start)
{
    int city[V - 1];
    int index = 0;

    // Store all cities except the starting city
    for (int i = 0; i < V; i++)
    {
        if (i != start)
            city[index++] = i;
    }

    int minCost = 99999;

    // Generate all possible permutations
    do
    {
        int currentCost = 0;
        int k = start;

        for (int i = 0; i < V - 1; i++)
        {
            currentCost += graph[k][city[i]];
            k = city[i];
        }

        // Return to the starting city
        currentCost += graph[k][start];

        minCost = min(minCost, currentCost);

    } while (next_permutation(city, city + V - 1));

    return minCost;
}

int main()
{
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int start = 0;

    cout << "Minimum cost of Travelling Salesman Problem: "
         << tsp(graph, start) << endl;

    return 0;
}
