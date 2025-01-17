#include <iostream>

#define V 9

using namespace std;

int minDistanceVertexIdx(int distance[], bool shortestPathTreeSet[]){
    int minIndex = 0;
    int min = INT_MAX;

    for (int v = 0; v < V; v++){
        if (shortestPathTreeSet[v] == false && distance[v] <= min){
            min = distance[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void DijkstraAlgorithm(int graph[V][V], int srcIndex){
    // distance[i] is the shortest distance from src to i
    int distance[V];

    // shortestPathTreeSet[i] will be true if i is in shortest path tree
    // or shortest distance from src to i has been finalized.
    bool shortestPathTreeSet[V];

    // Init arrays
    for (int i = 0; i < V; i++){
        distance[i] = INT_MAX;
        shortestPathTreeSet[i] = false;
    }
    distance[srcIndex] = 0;

    for (int i = 0; i < V - 1; i++){
        // Find the minimum distance vertex from the set of vertices not yet processed
        // vertices not yet processed. At the beginning, this is always the src
        int minDistVertIdx = minDistanceVertexIdx(distance, shortestPathTreeSet);

        // Mark the picked vertex as processed
        shortestPathTreeSet[minDistVertIdx] = true;

        // Update distance value of the adjacent vertices of the picked vertex.
        for(int v = 0; v < V; v++){
            if (!shortestPathTreeSet[v] // not in shortestPathTreeSet
                && graph[minDistVertIdx][v] != 0 // there is an edge from minDistVertIdx to v
                && distance[minDistVertIdx] != INT_MAX // safekeeping
                && distance[minDistVertIdx] + graph[minDistVertIdx][v] < distance[v]){
                distance[v] = distance[minDistVertIdx] + graph[minDistVertIdx][v];
            }
        }
    }

    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++){
        cout << i << " \t\t " << distance[i] << endl;
    }
}

int main() {
    // Adjacency matrix. Vertices represented by index number
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    DijkstraAlgorithm(graph, 0);

    return 0;
}