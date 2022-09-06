#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
	int src;
	int dst;
	int weight;

	bool operator<(Edge& e) {
		return weight < e.weight;
	}

	bool operator>(Edge& e) {
		return weight > e.weight;
	}
};


struct Node {

	int id;
	int rank;
	int parent;

public:
	Node(int _id) : id(_id), rank(0), parent(_id) {}
};

class DisjointSet {

private:
	vector<Node> nodes;

public:
	void make_set(int id) { nodes.emplace_back(id); }

	int find(int id) {
	
		while (id != nodes[id].parent)
			id = nodes[id].parent;

		return id;
	}

	void union_set(int x, int y) {
		int root_x = find(x);
		int root_y = find(y);
	
		if (root_x == root_y)
			return;

		if (nodes[root_x].rank > nodes[root_y].rank)
			swap(root_x, root_y);

		nodes[root_x].parent = nodes[root_y].parent;
		nodes[root_y].rank++;
	}
};

vector<Edge> Kruskal(vector<Edge>& graph, int vertex_count) {
	sort(graph.begin(), graph.end(), greater<>());

	DisjointSet dset;

	for (int i = 0; i < vertex_count; i++)
		dset.make_set(i);

	vector<Edge> MST;

	while (graph.empty() == false) {
		Edge e = graph.back();
		graph.pop_back();

		while (dset.find(e.src) != dset.find(e.dst)){
			MST.emplace_back(Edge{ e.src, e.dst, e.weight }); 
			dset.union_set(e.src, e.dst);
		}
	}

	return MST;

}

void main() {
	vector<Edge> graph;
	int vertex_count = 8;

	graph.emplace_back(Edge{ 0, 1, 2 });
	graph.emplace_back(Edge{ 0, 4, 3 });
	// 2
	graph.emplace_back(Edge{ 1, 0, 2 });
	graph.emplace_back(Edge{ 1, 4, 3 });
	graph.emplace_back(Edge{ 1, 3, 1 });
	// 5
	graph.emplace_back(Edge{ 2, 3, 2 });
	graph.emplace_back(Edge{ 2, 6, 3 });
	// 7
	graph.emplace_back(Edge{ 3, 1, 1 });
	graph.emplace_back(Edge{ 3, 2, 2 });
	graph.emplace_back(Edge{ 3, 4, 2 });
	graph.emplace_back(Edge{ 3, 5, 4 });
	graph.emplace_back(Edge{ 3, 7, 5 });
	// 12
	graph.emplace_back(Edge{ 4, 0, 3 });
	graph.emplace_back(Edge{ 4, 1, 5 });
	graph.emplace_back(Edge{ 4, 3, 2 });
	graph.emplace_back(Edge{ 4, 7, 3 });
	// 16
	graph.emplace_back(Edge{ 5, 3, 4 });
	graph.emplace_back(Edge{ 5, 6, 4 });
	graph.emplace_back(Edge{ 5, 7, 1 });
	// 19
	graph.emplace_back(Edge{ 6, 2, 3 });
	graph.emplace_back(Edge{ 6, 5, 4 });
	// 21
	graph.emplace_back(Edge{ 7, 3, 5 });
	graph.emplace_back(Edge{ 7, 4, 3 });
	graph.emplace_back(Edge{ 7, 5, 1 });
	// 24
	// Edge의 정점 번호는 1부터 시작하지만 DisjointSet의 Node는 Zero-Base이기 때문에
	// 잘못된 메모리 번지를 참조할 가능성이 있다.
	// 따라서 정점 번호를 모두 1씩 뺀다.
	// (Weight은 예외)

	vector<Edge> MST = Kruskal(graph, vertex_count);

	cout << "src\t" << "dst\t" << "weight" << endl;

	for (int i = 0; i < MST.size(); i++)
		cout << MST[i].src << '\t' << MST[i].dst << '\t' << MST[i].weight << endl;

}
#1234