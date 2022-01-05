#include "../../path_planning.cpp"

int main(){
    std::vector<std::vector<bool>> map(80, std::vector<bool>(80, false));
    create_obstacle(&map, 60, 10, 79, 10);
    create_obstacle(&map, 50, 17, 70, 17);
    create_obstacle(&map, 50, 0, 50, 30);
    create_obstacle(&map, 20, 40, 79, 40);
    create_obstacle(&map, 10, 30, 25, 30);
    create_obstacle(&map, 0, 60, 50, 60);
    create_obstacle(&map, 40, 70, 79, 70);
    create_obstacle(&map, 60, 50, 60, 70);
    create_obstacle(&map, 15, 70, 15, 79);

    point start(70, 5);
    point end(8, 75);

    std::vector<point> route = AStar(map, start, end, "maze.tmp", "solved_maze.tmp");

    return 0;
}