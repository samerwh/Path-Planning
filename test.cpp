#include <iostream>
#include "AStar.cpp"

int main(){
    std::vector<std::vector<bool>> map(40, std::vector<bool>(40, false));
    create_obstacle(&map, 2, 2, 2, 20);
    create_obstacle(&map, 16, 5, 20, 10);
    create_obstacle(&map, 10, 20, 15, 35);
    create_obstacle(&map, 25, 30, 30, 35);

    point start(5, 5);
    point end(32, 35);

    std::cout << "Map" << std::endl;
    printArray(map);
    std::vector<point> route = AStar(map, start, end, "map2.tmp", "donemap2.tmp");

    return 0;
}