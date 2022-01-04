#include <stdio.h>
#include <string>
#include <limits>
#include "path_planning.h"

std::vector<point> AStar(std::vector<std::vector<bool>> input_map, point start, point end, 
                            const char *filename1, const char *filename2){

    const unsigned nrows = input_map.size();
    const unsigned ncols = input_map[0].size();
    double inf = std::numeric_limits<double>::infinity();
    point p0(0, 0);
    std::vector<std::vector<unsigned>> map = makeMap(input_map);
    std::vector<std::vector<double>> f(nrows, std::vector<double>(ncols, inf));
    std::vector<std::vector<double>> g(nrows, std::vector<double>(ncols, inf));
    std::vector<std::vector<int>> h = heuristic(nrows, ncols, end);
    std::vector<std::vector<point>> parent(nrows, std::vector<point>(ncols, p0));
    map[start.x][start.y] = 5;
    map[end.x][end.y] = 6;
    mapToFile(map, filename1);

    g[start.x][start.y] = 0;
    f[start.x][start.y] = h[start.x][start.y];

    while (true) {
        
        val_idx current = minim(f);
        point n(0, 0);

        if(current.idx.x == end.x && current.idx.y == end.y) break;

        map[current.idx.x][current.idx.y] = 3;
        f[current.idx.x][current.idx.y] = inf;
        int i = current.idx.x;
        int j = current.idx.y;

        if(i>0 && i<nrows){
            n.x = i-1;
            n.y = j;
            if(map[n.x][n.y] !=2 && map[n.x][n.y] !=3 && map[n.x][n.y] !=5){
                map[n.x][n.y] = 4;
                g[n.x][n.y] = g[current.idx.x][current.idx.y] + 1;
                f[n.x][n.y] = g[n.x][n.y] + h[n.x][n.y];
                parent[n.x][n.y] = current.idx;
            }
        }

        if(i>=0 && i<nrows-1){
            n.x = i+1;
            n.y = j;
            if(map[n.x][n.y] !=2 && map[n.x][n.y] !=3 && map[n.x][n.y] !=5){
                map[n.x][n.y] = 4;
                g[n.x][n.y] = g[current.idx.x][current.idx.y] + 1;
                f[n.x][n.y] = g[n.x][n.y] + h[n.x][n.y];
                parent[n.x][n.y] = current.idx;
            }
        }

         if(j>0 && j<ncols){
            n.x = i;
            n.y = j-1;
            if(map[n.x][n.y] !=2 && map[n.x][n.y] !=3 && map[n.x][n.y] !=5){
                map[n.x][n.y] = 4;
                g[n.x][n.y] = g[current.idx.x][current.idx.y] + 1;
                f[n.x][n.y] = g[n.x][n.y] + h[n.x][n.y];
                parent[n.x][n.y] = current.idx;
            }
        }

        if(i>=0 && j<ncols-1){
            n.x = i;
            n.y = j+1;
            if(map[n.x][n.y] !=2 && map[n.x][n.y] !=3 && map[n.x][n.y] !=5){
                map[n.x][n.y] = 4;
                g[n.x][n.y] = g[current.idx.x][current.idx.y] + 1;
                f[n.x][n.y] = g[n.x][n.y] + h[n.x][n.y];
                parent[n.x][n.y] = current.idx;
            }
        }
    }

    map[start.x][start.y] = 5;
    std::vector<point> route = traceRoute(parent, end, start);
    for(int i=0; i<route.size(); i++){
        map[route[i].x][route[i].y] = 7;
    }

    std::cout << "Done Map" << std::endl;
    printArray(map);
    mapToFile(map, filename2);
    return route;
}

bool samepoint(point p1, point p2){
    if(p1.x == p2.x && p1.y == p2.y) return true;
    else return false;
}

std::vector<std::vector<unsigned>> makeMap(std::vector<std::vector<bool>> input_map){
    std::vector<std::vector<unsigned>> map(input_map.size(), std::vector<unsigned>(input_map[0].size(), 0));
    for(int i=0; i<input_map.size(); i++){
        for(int j=0; j<input_map[0].size(); j++){
            if(input_map[i][j] == false) map[i][j] = 1;
            else map[i][j] = 2;
        }
    }
    return map;
}

val_idx minim(std::vector<std::vector<double>> arr){
    val_idx min(arr[0][0], 0, 0);
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[0].size(); j++){
            if(arr[i][j] < min.val){
                min.val = arr[i][j];
                min.idx.x = i;
                min.idx.y = j;
            }
        }
    }
    return min;
}

template <typename T>
void printArray(std::vector<std::vector<T>> arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[0].size(); j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void printArray(std::vector<T> arr){
    for(int i=0; i<arr.size(); i++){
        std::cout << arr[i].x << ", " << arr[i].y << std::endl;
    }
}

void printPoints(std::vector<std::vector<point>> arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[0].size(); j++){
            std::cout << arr[i][j].x << "," << arr[i][j].y << "  ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> heuristic(unsigned nrows, unsigned ncols, point end){
    std::vector<std::vector<int>> h(nrows, std::vector<int>(ncols, 0));
    for(int i=0; i<nrows; i++){
        for (int j=0; j<ncols; j++){
            h[i][j] = abs(i-end.x) + abs(j-end.y);
        }
    }
    return h;
}

std::vector<point> traceRoute(std::vector<std::vector<point>> parent, point end, point start){
    std::vector<point> route;
    route.push_back(end);
  //  cout << "route: " << route[0].x << ", " << route[0].y << endl;

    while(!samepoint(parent[route[0].x][route[0].y], start)){
        route.insert(route.begin(), parent[route[0].x][route[0].y]);
        //cout << "route: " << route[0].x << ", " << route[0].y << endl;
    }
    return route;
}

void mapToFile(std::vector<std::vector<unsigned>> map, const char *filename){
    FILE *f = NULL;
    f = fopen(filename, "w");
    for(int i = 0; i < map.size(); i++){
        for(int j =0; j < map[0].size(); j++){
            fprintf(f, "%d", map[i][j]);
        }
        fprintf(f, "\n");
    }
}

void create_obstacle(std::vector<std::vector<bool>> *map, unsigned r1, unsigned c1,
                                                            unsigned r2, unsigned c2){
    for(int i = r1; i <= r2; i++){
        for (int j = c1; j <= c2; j++){
            map->at(i).at(j) = true;
        }
    }                      
}




