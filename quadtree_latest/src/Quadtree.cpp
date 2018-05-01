//
// Created by ozdenur on 25.04.2018.
//

#include "../inc/Quadtree.h"


template <typename T>
QuadTree<T>::QuadTree(Vertex center, Vertex range, unsigned bucketSize, unsigned depth) {

    root = new Node<T>(center, range);
    maxDepth = depth;
    maxBucketSize = bucketSize;
}

template <typename T>
QuadTree<T>::~QuadTree() {
    delete root;
}

template <typename T>
void QuadTree<T>::insert(Vertex v, T data) {
    insert(v, data, root, 0);
}

template <typename T>
int QuadTree<T>::direction(const Vertex& point, Node<T>* node) {

    unsigned X = 0, Y = 0;
    X |= ((point.x >= node->center.x) << 1);
    Y |= ((point.y >= node->center.y) << 0);

    return (X | Y);
}


template <typename T>
Node<T>* QuadTree<T>::childNode(const Vertex& v, Node<T>* node) {

    unsigned dir = direction(v, node);

    if (node->child[dir]) {
        return node->child[dir];
    }
    else {
        Vertex r(node->range.x / 2.0, node->range.y / 2.0);
        node->child[dir] = new Node<T>(newCenter(dir, node), r);
        return node->child[dir];
    }

}


template <typename T>
Vertex QuadTree<T>::newCenter(int direction, Node<T>* node) {

    Vertex v(node->center.x, node->center.y);
    switch (direction) {

        case LOWER_LEFT_QUAD:
            v.x -= node->range.x / 2.0;
            v.y -= node->range.y / 2.0;
            break;
        case UPPER_LEFT_QUAD:
            v.x -= node->range.x / 2.0;
            v.y += node->range.y / 2.0;
            break;
        case LOWER_RIGHT_QUAD:
            v.x += node->range.x / 2.0;
            v.y -= node->range.y / 2.0;
            break;
        case UPPER_RIGHT_QUAD:
            v.x += node->range.x / 2.0;
            v.y += node->range.y / 2.0;
            break;

    }
    return v;
}

template <typename T>
void QuadTree<T>::insert(Vertex v, T data, Node<T>* node, unsigned depth) {
// yaprak mı diye bakıyor, eğer  yaprak
    if (node->leaf)
    {

        if (node->bucket.size() < maxBucketSize)
        {
            node->bucket.push_back({ v,data });
        }
        else if (depth < maxDepth)
        {
            node->leaf = false;
            insert(v, data, childNode(v, node), depth + 1);

            for (int i = 0; i < node->bucket.size(); ++i) 
			{
                insert(node->bucket[i].first, data, childNode(node->bucket[i].first, node), depth + 1);
            }

            node->bucket.clear();

        }


    }
    else
        {
        insert(v, data, childNode(v, node), depth + 1);
    }

}

template <typename T>
string QuadTree<T>::print() {
    stringstream ss;
    print(root, ss);
    return ss.str();
}


template <typename T>
void QuadTree<T>::print(Node<T>* node, stringstream& ss)
{
    for (int i = 0; i < 4; i++)
    {
        if (node->child[i])
        {
            print(node->child[i], ss);
        }
    }
    if (node->leaf) {
        long double x = node->bucket[0].first.x;
        long double y = node->bucket[0].first.y;
        Vertex p(x, y);
        int dir = direction(p, node);
        ss << "Bolge:" << dir << " -> " << '{' << node->bucket[0].first.x << ',' << node->bucket[0].first.y << '}' << '\n';

    }

    return;
}
