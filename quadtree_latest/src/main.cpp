#include <iostream>
#include "../inc/Quadtree.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <random>
#include <chrono>

using namespace std;

QuadTree <double>* qtree;

int main()
{
    Vertex origin(0, 0);
    Vertex axis(-512.0, 512.0);
    static int bucketSize = 1;
    qtree = new QuadTree<double>(origin, axis, 1, 16);
	std::mt19937_64 machine;
	std::uniform_real_distribution<long double> distrubition(-512.0, 512.0);
	vector<Vertex> random_points;
	for (int i = 0; i < 10e5; i++)
	{
		Vertex newpoint(distrubition(machine), distrubition(machine));
		random_points.push_back(newpoint);
	}
	using namespace std::chrono;
	auto begin = high_resolution_clock::now();
	for (auto& i : random_points)
	{
		qtree->insert(i, 1);
	}
	auto end = high_resolution_clock::now();
	std::cout << "Inserted\n";
	duration<long double> duration = end - begin;
	std::cout << "Duration:" << duration.count() << std::endl;
	qtree->write_to_file(random_points);
    //cout << qtree->print();
	cout << "Fnished";
    cin.get();
    return 0;
}