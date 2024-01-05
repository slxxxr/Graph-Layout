#include "Graph.h"


std::vector<int> Graph::parse(std::string s) {
	int len = s.size();
	std::vector<int> result;
	std::string v = "", u = "";
	for (int i = 0; i < len; i++) {
		if (s[i] == ' ') {
			u += s[i];
		}
		else if (s[i] == '\n' || s[i] == '\r') {
			if (!v.empty() && !u.empty()) {
				result.push_back(stoi(v));
				result.push_back(stoi(u));
			}
			v = ""; u = "";
		}
		else if (i == len - 1) {
			u += s[i];
			if (!v.empty() && !u.empty()) {
				result.push_back(stoi(v));
				result.push_back(stoi(u));
			}
		}
		else {
			if (u.empty()) {
				v += s[i];
			}
			else {
				u += s[i];
			}
		}
	}
	return result;
}


Graph::Graph(std::string s) {
	std::vector<int> input = parse(s);
	if (input.empty()) {
		return;
	}

	n = input[0];
	if (n < 0) {
		graph_correct = false;
		return;
	}
	graph_empty = n < 1;
	m = input[1];

	if (m < 0) {
		graph_correct = false;
		return;
	}
	
	gr.resize(n);
	edges.resize(m);
	for (int i = 2, edge_ind = 0; i < 2 * m + 2; i += 2, edge_ind++) {
		int v = input[i] - 1, u = input[i + 1] - 1;
		if (std::min(v, u) < 0 || std::max(v, u) >= n) {
			graph_correct = false;
			return;
		}
		edges[edge_ind] = { v,u,edge_ind };
		gr[v].push_back({ v,u,edge_ind });
		gr[u].push_back({ u,v,edge_ind });
	}

	std::string input_path = "D:\\GraphLayout\\TextFiles\\input_graph.txt";
	std::ofstream out(input_path);

	out << n << " " << m << "\n";
	for (int i = 0; i < m; i++) {
		out << edges[i].from << " " << edges[i].to << "\n";
	}
	out.close();
}

void Graph::DFS_Bridge(int v, int ind, int p) {
	used[v]++;
	d[v] = h[v] = (p == -1 ? 0 : h[p] + 1);
	for (auto& e : gr[v]) {
		if (e.ind == ind) { continue; }
		if (used[e.to]) {
			d[v] = std::min(d[v], h[e.to]);
		}
		else {
			DFS_Bridge(e.to, e.ind, v);
			d[v] = std::min(d[v], d[e.to]);
			if (d[e.to] > h[v]) {
				bridge_ind.push_back(e.ind);//find bridge
			}
		}
	}
}


std::vector<std::pair<int, int>> Graph::Get_Bridges() {
	used.assign(n, 0);
	h.assign(n, 0);
	d.assign(n, 0);
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			DFS_Bridge(i, -1, -1);
		}
	}

	std::string Bridges_path = "D:\\GraphLayout\\TextFiles\\Bridges.txt";;
	std::ofstream out(Bridges_path);

	std::vector<std::pair<int, int>> result;
	out << (int)bridge_ind.size() << "\n";
	for (int i : bridge_ind) {
		result.push_back({ edges[i].from,edges[i].to });
		out << edges[i].from << " " << edges[i].to << "\n";
	}

	out.close();
	return result;
}


void Graph::DFS_ArticulationPoints(int v, int ind, int p)
{
	used[v]++;
	d[v] = h[v] = (p == -1 ? 0 : h[p] + 1);
	int children = 0;

	for (auto& e : gr[v]) {
		if (e.ind == ind) continue;
		if (used[e.to]) {
			d[v] = std::min(d[v], h[e.to]);
		}
		else {
			DFS_ArticulationPoints(e.to, e.ind, v);
			if (d[e.to] >= h[v] && p != -1) {
				ArticulationPoints.insert(v);//find Articulation Point
			}
			children++;
			d[v] = std::min(d[v], d[e.to]);
		}
	}
	if (p == -1 && children > 1) {
		ArticulationPoints.insert(v);//find Articulation Point
	}
}



std::set<int> Graph::Get_ArticulationPoints()
{
	used.assign(n, 0);
	h.assign(n, 0);
	d.assign(n, 0);
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			DFS_ArticulationPoints(i, -1, -1);
		}
	}

	std::string ArticulationPoints_path = "D:\\GraphLayout\\TextFiles\\ArticulationPoints.txt";
	std::ofstream out(ArticulationPoints_path);

	for (int i : ArticulationPoints) {
		out << i << " ";
	}
	out.close();

	return ArticulationPoints;
}

void Graph::DFS_Components(int v) {
	used[v]++;
	Components[(int)Components.size() - 1].push_back(v);
	for (auto& e : gr[v]) {
		if (!used[e.to]) {
			DFS_Components(e.to);
		}
	}
}

void Graph::run_python(const std::string& scriptPath){
	std::string command = "python " + scriptPath;  // Construct the command to run the script

	STARTUPINFOA startupInfo;
	PROCESS_INFORMATION processInfo;

	ZeroMemory(&startupInfo, sizeof(startupInfo));
	startupInfo.cb = sizeof(startupInfo);

	DWORD creationFlags = CREATE_NO_WINDOW;

	// Create the process
	if (CreateProcessA(
		nullptr,                     // Module name (null for command line)
		const_cast<char*>(command.c_str()),    // Command line
		nullptr,                     // Process handle not inheritable
		nullptr,                     // Thread handle not inheritable
		FALSE,                       // Set handle inheritance to FALSE
		creationFlags,               // Creation flags
		nullptr,                     // Use parent's environment block
		nullptr,                     // Use parent's starting directory
		&startupInfo,                // Pointer to STARTUPINFO structure
		&processInfo                 // Pointer to PROCESS_INFORMATION structure
	))
	{
		// Wait for the process to finish
		WaitForSingleObject(processInfo.hProcess, INFINITE);

		// Close process and thread handles
		CloseHandle(processInfo.hProcess);
		CloseHandle(processInfo.hThread);
	}
	else
	{
		std::cerr << "Failed to create process: " << GetLastError() << std::endl;
	}
}

std::vector<std::vector<int>> Graph::Get_Components(){
	used.assign(n, 0);
	Components.clear();

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			Components.push_back({});
			DFS_Components(i);
		}
	}

	std::string Components_path = "D:\\GraphLayout\\TextFiles\\Components.txt";
	std::ofstream out(Components_path);

	out << (int)Components.size() << "\n";
	for (std::vector<int>& component : Components) {
		for (int i : component) {
			out << i << " ";
		}
		out << "\n";
	}

	out.close();
	return Components;
}

std::map<int, std::pair<float, float>> Graph::Get_Positions(){

	std::map<int, std::pair<float, float>> result;

	run_python("D:\\GraphLayout\\Scripts\\get_positions.txt");
	
	std::string output_path = "D:\\GraphLayout\\TextFiles\\output_positions.txt";
	std::ifstream in(output_path);
	for (int i = 0; i < n; i++) {
		int v;
		float x, y;
		in >> v >> x >> y;
		result[v] = { x,y };
	}
	in.close();

	return result;

}

void Graph::Show_ArticulationPoints(){
	if (ArticulationPoints.empty()) {
		this->Get_ArticulationPoints();
	}

	run_python("D:\\GraphLayout\\Scripts\\show_ArticulationPoints.py");
}

void Graph::Show_Bridges() {
	if (bridge_ind.empty()) {
		this->Get_Bridges();
	}
	
	run_python("D:\\GraphLayout\\Scripts\\show_Bridges.py");
}

void Graph::Show_Components() {
	if (Components.empty()) {
		this->Get_Components();
	}
	
	run_python("D:\\GraphLayout\\Scripts\\show_Components.py");
}

bool Graph::correct(){
	return (!graph_empty && graph_correct);
}

bool Graph::empty(){
	return graph_empty;
}




