#pragma once
#include <vector>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <iostream>


#define NOMINMAX
#include <Windows.h>

class Graph {
private:
	struct edge {
		int from, to, ind;
	};

	int n = 0, m = 0;
	std::string error = "";

	std::vector<edge> edges;
	std::vector<std::vector<edge>> gr;
	std::vector<int> used, h, d;

	std::vector<int> parse(std::string& s);
	std::vector<int> read_file(std::string& path);

	std::vector <int> bridge_ind;
	void DFS_Bridge(int v, int ind, int p);

	std::set<int> ArticulationPoints;
	void DFS_ArticulationPoints(int v, int ind, int p);

	std::vector<std::vector<int>> Components;
	void DFS_Components(int v);

	void run_python(const std::string& scriptPath);

	void set_error(const char* error_msg);

public:
	Graph(std::string& s, bool file_input);

	std::vector<std::pair<int, int>> Get_Bridges();
	std::set<int> Get_ArticulationPoints();
	std::vector<std::vector<int>> Get_Components();

	void Show_ArticulationPoints();
	void Show_Bridges();
	void Show_Components();

	bool correct(std::string& error_msg);

};


