#include "dijkstra.hpp"

Dijkstra::Dijkstra(int graph[V][V], int srcIndex){
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

int Dijkstra::minDistanceVertexIdx(int distance[], bool shortestPathTreeSet[]){
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