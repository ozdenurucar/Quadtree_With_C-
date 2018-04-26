//
// Created by ozdenur on 25.04.2018.
//

#ifndef QUADTREE_LATEST_QUADTREE_H
#define QUADTREE_LATEST_QUADTREE_H


#include <cstdlib>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>

#include "Node.h"
#include "Vertex.h"

using namespace std;

#define LOWER_LEFT_QUAD 0
#define UPPER_LEFT_QUAD 1
#define LOWER_RIGHT_QUAD 2
#define UPPER_RIGHT_QUAD 3


enum enclosure_status {
    NODE_NOT_IN_REGION,
    NODE_PARTIALLY_IN_REGION,
    NODE_CONTAINED_BY_REGION
};

template <typename T>
class QuadTree
{

public:

    QuadTree<T>(Vertex center, Vertex range, unsigned bucketSize = 1, unsigned depth = 16);
    ~QuadTree();

    void insert(Vertex v, T data);
    std::string print();

private:
    Node<T>* childNode(const Vertex& v, Node<T>* node);
    Vertex newCenter(int direction, Node<T>* node);
    int direction(const Vertex& point, Node<T>*node);
    void insert(Vertex v, T data, Node<T>* node, unsigned depth);
    void print(Node<T>* node, std::stringstream& ss);

    Node<T>* root; //Kök düğüm
    unsigned maxDepth, maxBucketSize;



};

#include "../src/Quadtree.cpp"

#endif //QUADTREE_LATEST_QUADTREE_H
