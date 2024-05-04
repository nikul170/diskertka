#include <stack>
#include "includes.hpp"

 bool DFS(int current_point){
    vector<bool> is_visited;
    stack<int> points_stack;
    int points = 0, edges = 0;

    is_visited.resize(point_count, false);
    is_visited[current_point] = true;
    points_stack.push(current_point);

    while(!points_stack.empty()){
        int node = points_stack.top();
        points_stack.pop();
        for(int child: graph[node]) {
            if (!is_visited[child]) {
                is_visited[child] = true;
                points_stack.push(child);
            }
        }

    }
     for(int i = 0; i < point_count; i++) {
         if (is_visited[i]) {
             points++;
             edges += graph[i].size();
         }
     }
    return points - 1 != edges / 2;

}

