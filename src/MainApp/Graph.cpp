#include "Graph.h"


std::vector<int> Graph::parse(std::string& s) {

	int len = s.size();
	std::vector<int> result;
	std::string v = "", u = "";

	for (int i = 0; i < len; i++) {
		if (s[i] == ' ') {
			u += s[i];
		}
		else if (s[i] == '\n' || s[i] == '\r') {
			if (!v.empty() && !u.empty()) {
				try {
					result.push_back(stoi(v));
					result.push_back(stoi(u));
				}
				catch (...) {
					set_error("Некорректные входные данные");
					return result;
				}
			}
			v = ""; u = "";
		}
		else if (i == len - 1) {
			u += s[i];
			if (!v.empty() && !u.empty()) {
				try {
					result.push_back(stoi(v));
					result.push_back(stoi(u));
				}
				catch (...) {
					set_error("Некорректные входные данные");
					return result;
				}
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

std::vector<int> Graph::read_file(std::string& _path) {

	std::string path = "";
	for (char i : _path) {
		if (i != '\n' && i != '\r') path += i;
	}

	std::ifstream in(path);
	std::vector<int> result;

	if (!in.is_open()) {
		set_error("Не удалось открыть файл");
		return result;
	}

	try {
		in >> n >> m;
		result.resize(2 + 2 * m);
		result[0] = n; result[1] = m;

		for (int i = 0; i < 2 * m; i += 2) {
			in >> result[i + 2] >> result[i + 3];
		}
	}
	catch (...) {
		set_error("Некорректные входные данные");
		in.close();
		return result;
	}


	return result;
}


Graph::Graph(std::string& s, bool file_input) {
	std::vector<int> input = (file_input ? read_file(s) : parse(s));

	if (input.empty()) {
		return;
	}

	if (!error.empty()) {
		return;
	}

	n = input[0];
	m = input[1];
	if (std::min(n, m) < 0) {
		set_error("Некорректные входные данные");
		return;
	}

	gr.resize(n);
	edges.resize(m);
	for (int i = 2, edge_ind = 0; i < 2 * m + 2; i += 2, edge_ind++) {
		int v = input[i] - 1, u = input[i + 1] - 1;
		if (std::min(v, u) < 0 || std::max(v, u) >= n) {
			set_error("Некорректные входные данные");
			return;
		}
		edges[edge_ind] = { v,u,edge_ind };
		gr[v].push_back({ v,u,edge_ind });
		gr[u].push_back({ u,v,edge_ind });
	}

	std::string input_path = "..\\..\\TextFiles\\input_graph.txt";
	std::ofstream out(input_path);

	out << n << " " << m << "\n";
	for (int i = 0; i < m; i++) {
		out << edges[i].from + 1 << " " << edges[i].to + 1 << "\n";
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

	std::string Bridges_path = "..\\..\\TextFiles\\Bridges.txt";;
	std::ofstream out(Bridges_path);

	std::vector<std::pair<int, int>> result;
	out << (int)bridge_ind.size() << "\n";
	for (int i : bridge_ind) {
		result.push_back({ edges[i].from,edges[i].to });
		out << edges[i].from + 1 << " " << edges[i].to + 1 << "\n";
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

	std::string ArticulationPoints_path = "..\\..\\TextFiles\\ArticulationPoints.txt";
	std::ofstream out(ArticulationPoints_path);

	for (int i : ArticulationPoints) {
		out << i + 1 << " ";
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


std::vector<std::vector<int>> Graph::Get_Components() {
	used.assign(n, 0);
	Components.clear();

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			Components.push_back({});
			DFS_Components(i);
		}
	}

	std::string Components_path = "..\\..\\TextFiles\\Components.txt";
	std::ofstream out(Components_path);

	out << (int)Components.size() << "\n";
	for (std::vector<int>& component : Components) {
		for (int i : component) {
			out << i + 1 << " ";
		}
		out << "\n";
	}

	out.close();
	return Components;
}


void Graph::run_python(const std::string& scriptPath) {
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


void Graph::Show_ArticulationPoints() {
	if (ArticulationPoints.empty()) {
		this->Get_ArticulationPoints();
	}

	run_python("..\\..\\scripts\\show_ArticulationPoints.py");
}

void Graph::Show_Bridges() {
	if (bridge_ind.empty()) {
		this->Get_Bridges();
	}

	run_python("..\\..\\scripts\\show_Bridges.py");
}

void Graph::Show_Components() {
	if (Components.empty()) {
		this->Get_Components();
	}

	run_python("..\\..\\scripts\\show_Components.py");
}



void Graph::set_error(const char* error_msg) {
	error = error_msg;
}


bool Graph::correct(std::string& error_msg) {
	error_msg = error;
	return error.empty();
}


