#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>

class point {
    public:
        int x;
        int y;
        point(int a, int b){ x = a; y = b;}
};

class val_idx {
    public:
        double val;
        point idx;
        val_idx(double a, int x, int y): idx(x, y){val = a;}
};

bool samepoint(point p1, point p2);
std::vector<std::vector<unsigned>> makeMap(std::vector<std::vector<bool>> input_map);
val_idx minim(std::vector<std::vector<double>> arr);
template <typename T> void printArray(std::vector<std::vector<T>> arr);
template <typename T> void printArray(std::vector<T> arr);
void printPoints(std::vector<std::vector<point>> arr);
std::vector<std::vector<int>> heuristic(unsigned nrows, unsigned ncols, point end);
std::vector<point> traceRoute(std::vector<std::vector<point>> parent, point end, point start);
void mapToFile(std::vector<std::vector<unsigned>> map, const char *filename);
void create_obstacle(std::vector<std::vector<bool>> *map, unsigned r1, unsigned c1, unsigned r2, unsigned c2);
