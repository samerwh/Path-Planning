#include "../../AStar.cpp"

int main(){
    std::vector<std::vector<bool>> map(40, std::vector<bool>(40, false));
    create_obstacle(&map, 0, 10, 15, 10);
    create_obstacle(&map, 8, 17, 25, 17);
    create_obstacle(&map, 20, 24, 39, 24);

    point start(5, 5);
    point end(32, 35);

    std::vector<point> route = AStar(map, start, end, "map1.tmp", "solved_map1.tmp");

    return 0;
}