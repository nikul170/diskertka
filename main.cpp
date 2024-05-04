#include "includes.hpp"

int main() {
    try{
        int point = Graph();
        bool DFS_cycle_exist = DFS(point),  BFS_cycle_exist = BFS(point);
        ofstream out("output_file");
        if (DFS_cycle_exist == BFS_cycle_exist) {
            if (DFS_cycle_exist)
                out << "Cycle exists :)";
            else out << "Cycle dont exists :(";
        }
        else out << "Something's wrong";
    }
    catch (const char* error_message){
        cout << error_message << endl;
    }

    return 0;
}
