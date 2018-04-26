//
// Created by ozdenur on 25.04.2018.
//

#ifndef QUADTREE_LATEST_NODE_H
#define QUADTREE_LATEST_NODE_H


#include <cstdlib>
#include <vector>
#include "Vertex.h"

template <class T>
class Node
{

public:

    Vertex center, range;
    bool leaf;// Yaprak mı yoksa dal mı diye kontrol etmek için bool değişken
    Node* child[4];

    std::vector< std::pair <Vertex,T >> bucket;

    Node<T> (Vertex new_center, Vertex new_range)
    {
        for (int i = 0; i < 4; i++)
        {
            child[i] = NULL;//Tüm çocukları başlangıçta  null olarak oluşturur.
        }
        center = new_center;
        range = new_range;
        leaf = true;
    }
    ~Node()
    {
        for (int i = 0; i < 4; ++i)
        {
            if(child[i])
                delete child[i];
        }
    }


};

#endif //QUADTREE_LATEST_NODE_H
