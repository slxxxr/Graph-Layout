#pragma once
#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <iostream>


#define NOMINMAX
#include <Windows.h>

class Graph{
private:
	struct edge {
		int from, to, ind;
	};

	int n = 0, m = 0;
	bool graph_correct = true, graph_empty = true;
	std::vector<edge> edges;
	std::vector<std::vector<edge>> gr;

	std::vector<int> parse(std::string s);

	std::vector<int> used, h, d, bridge_ind;
	void DFS_Bridge(int v, int ind, int p);
	
	std::set<int> ArticulationPoints;
	void DFS_ArticulationPoints(int v, int ind, int p);

	std::vector<std::vector<int>> Components;
	void DFS_Components(int v);

	void run_python(const std::string& scriptPath);

public:
	Graph(std::string s);
	
	std::vector<std::pair<int, int>> Get_Bridges();
	std::set<int> Get_ArticulationPoints();
	std::vector<std::vector<int>> Get_Components();
	std::map<int,std::pair<float, float>> Get_Positions();
	void Show_ArticulationPoints();
	void Show_Bridges();
	void Show_Components();
	bool correct();
	bool empty();
};

