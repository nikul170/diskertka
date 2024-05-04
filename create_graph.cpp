#include "includes.hpp"

vector<vector<int>> graph;
int point_count, edge_count;

int Graph(){
    ifstream in("input.txt");
    int point;

    if (!in) throw "No file";

    in >> point_count >> edge_count;
    graph.resize(point_count);
    for(int i = 0; i < edge_count; i++){
        int a, b;
        in >> a >> b;

        if (a < 0 || a > point_count) throw "Bad A";
        if (b < 0 || b > point_count) throw "Bad B";

        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    in >> point;
    if (point < 0 || point > point_count) throw "Bad start point";
    return point - 1;

}
