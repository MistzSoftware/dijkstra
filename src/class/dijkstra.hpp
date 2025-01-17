#pragma once

#include <iostream>

using namespace std;

#define V 9

/**
 * @class Dijkstra
 * @brief Implements Dijkstra's algorithm for finding the shortest paths in a graph.
 * 
 * This class provides methods to compute the shortest path from a source vertex to all other vertices
 * in a given graph using Dijkstra's algorithm.
 * 
 * @note The graph is represented as a 2D array (adjacency matrix) where graph[i][j] holds the weight of the edge from vertex i to vertex j.
 */
class Dijkstra
{
private:
    /**
     * @brief Finds the vertex with the minimum distance value from the set of vertices not yet included in the shortest path tree.
     * 
     * @param distance Array holding the shortest distance from the source to each vertex.
     * @param shortestPathTreeSet Array indicating whether a vertex is included in the shortest path tree.
     * @return Index of the vertex with the minimum distance value.
     */
    int minDistanceVertexIdx(int distance[], bool shortestPathTreeSet[]);

public:
    /**
     * @brief Constructs a Dijkstra object and computes the shortest paths from the source vertex to all other vertices in the graph.
     * 
     * @param graph 2D array representing the adjacency matrix of the graph.
     * @param src Source vertex from which to calculate the shortest paths.
     */
    Dijkstra(int graph[V][V], int src);
};