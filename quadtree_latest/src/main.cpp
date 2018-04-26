#include <iostream>
#include "../inc/Quadtree.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

QuadTree <double>* qtree;

int main()
{
    Vertex origin(0, 0);
    Vertex axis(1024.0, 1024.0);
    static int bucketSize = 1;
    qtree = new QuadTree<double>(origin, axis, 1, 16);
    for (int i = 0; i < 10e5; i++)
    {
        Vertex newpoint(rand()%1024,rand()%1024);
        qtree->insert(newpoint, 1);
    }
    cout << qtree->print();
    cin.get();
    return 0;
}