#include <queue>
#include "includes.hpp"

 bool BFS(int current_point){
    vector<bool> is_visited;
    queue<int> points_queue;
    int points = 0, edges = 0;

    is_visited.resize(point_count, false);
    is_visited[current_point] = true;
    points_queue.push(current_point);

    while(!points_queue.empty()){
        int node = points_queue.front();
        points_queue.pop();
        for(int child: graph[node]) {
            if (!is_visited[child]) {
                is_visited[child] = true;
                points_queue.push(child);
            }
        }
        for(int i = 0; i < point_count; i++){
            if (is_visited[i]){
                points++;
                edges += graph[i].size();
            }
        }
    }

    return points - 1 != edges / 2;

}
