//
// Created by ozdenur on 25.04.2018.
//

#ifndef QUADTREE_LATEST_VERTEX_H
#define QUADTREE_LATEST_VERTEX_H

class Vertex
{

public:
    double x;
    double y;

    Vertex()
    {
        x=0.0;
        y=0.0;
    }
    Vertex(double new_x, double new_y)
    {
        x=new_x;
        y=new_y;
    }

    bool operator ==( Vertex v)
    {
        return ((x==v.x)&&(y==v.y));
    }

};

#endif //QUADTREE_LATEST_VERTEX_H
