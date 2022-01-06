#include "../../path_planning.cpp"

int main(){
    std::vector<std::vector<bool>> map(80, std::vector<bool>(80, false));
    create_obstacle(&map, 0, 0, 70, 20);
    create_obstacle(&map, 0, 10, 60, 30);
    create_obstacle(&map, 0, 30, 15, 60);
    create_obstacle(&map, 20, 45, 40, 60);
    create_obstacle(&map, 40, 45, 50, 50);
    create_obstacle(&map, 0, 45, 10, 50);
    create_obstacle(&map, 30, 30, 35, 40);
    create_obstacle(&map, 70, 25, 79, 79);
    create_obstacle(&map, 60, 50, 70, 79);
    create_obstacle(&map, 55, 65, 60, 79);
    create_obstacle(&map, 30, 60, 40, 70);
    create_obstacle(&map, 15, 70, 25, 79);
    create_obstacle(&map, 55, 35, 60, 45);

    point start(75, 5);
    point end(8, 72);

    std::vector<point> route = AStar(map, start, end, "map4.tmp", "solved_map4.tmp");

    return 0;
}