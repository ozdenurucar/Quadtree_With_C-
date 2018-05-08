//
// Created by ozdenur on 25.04.2018.
//

#ifndef QUADTREE_LATEST_VERTEX_H
#define QUADTREE_LATEST_VERTEX_H

class Vertex
{

public:
	long double x;
	long double y;

    Vertex()
    {
        x=0.0;
        y=0.0;
    }
    Vertex(long double new_x, long double new_y)
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
