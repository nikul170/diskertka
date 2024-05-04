#pragma once

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
extern vector<vector<int> > graph;
extern int point_count, edge_count;
bool BFS(int current_point);
bool DFS(int current_point);
int Graph();

