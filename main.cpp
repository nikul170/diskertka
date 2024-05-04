#include "includes.hpp"

int main() {
    try{
        int point = Graph();
        bool cycle_exist = DFS(point) && BFS(point);
        ofstream out("output_file");
        if (cycle_exist) out << "Cycle exists :)";
        else out << "Cycle doesn't exists :(";
    }
    catch (const char* error_message){
        cout << error_message << endl;
    }

    return 0;
}
