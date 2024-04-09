#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

vector<vector<int>> graph;
int point_count, edge_count;

int Graph(){
    ifstream in("input.txt");
    int point;

    if (!in) throw "No file";

    in >> point_count >> edge_count;
    in >> point;
    if (point < 0 || point > point_count) throw "Bad start point";
    graph.resize(point_count);
    for(int i = 0; i < edge_count; i++){
        int a, b;
        in >> a >> b;

        if (a < 0 || a > point_count) throw "Bad A";
        if (b < 0 || b > point_count) throw "Bad B";

        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }


    return point - 1;

}

vector<bool> is_visited;
bool DFS(int current_point, int prev_position = -1){
    is_visited.resize(point_count);
    bool result = false;

    is_visited[current_point] = true;

    for(int edge: graph[current_point]) if(edge != prev_position) {
            if (is_visited[edge] && edge != prev_position) return true;
            result = DFS(edge, current_point);
        }

    return result;
}


int main() {
    try{
        int point = Graph();
        ofstream out("output_file");
        out << DFS(point);
    }
    catch (const char* error_message){
        cout << error_message << endl;
    }



    return 0;
}
