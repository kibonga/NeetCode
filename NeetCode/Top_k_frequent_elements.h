#pragma once
#include <vector>
#include <map>
#include <cmath>
using namespace std;



struct node {
	int freq;
	int value;
	node(int v, int f) {
		value = v;
		freq = f;
	}
};

void swap(node& a, node& b) {
	node c = a;
	a = b;
	b = c;
}

void heapify(vector<node> &vec, int root) {
	int left, right, largest;
	largest = root;
	left = (root * 2) + 1;
	right = (root * 2) + 2;

	if (left < vec.size() && vec[left].freq > vec[largest].freq)
		largest = left;

	if (right < vec.size() && vec[right].freq > vec[largest].freq)
		largest = right;

	if (largest == root) return;

	swap(vec[largest], vec[root]);
	heapify(vec, largest);
}

void build_heap(vector<node> &vec) {
	int i = (int)ceil( (float)(vec.size() / 2) ) - 1;
	while (i >= 0) {
		heapify(vec, i--);
	}
}

int pop(vector<node> &vec) {
	swap(vec[0], vec[vec.size() - 1]);
	node node = vec.back();
	int value = node.value;
	vec.pop_back();
	heapify(vec, 0);
	return node.value;
}

void top_k_freq_elems(vector<int> &vec, int k, vector<int> &top_k_elems) {
	map<int, int> map;

	for (auto v : vec) {
		map[v] += 1;
	}

	vector<node> vec_map;
	for (auto& m : map) {
		vec_map.push_back(node(m.first, m.second));
	}

	build_heap(vec_map);
	vec_map;

	vector<node> node_elems(vec_map.begin(), vec_map.begin() + k);
	//vector<node> node_elems;
	//memcpy(&node_elems, &vec_map, k * sizeof(node));

	for (int i = 0; i < k; i++) {
		top_k_elems.at(i) = pop(vec_map);
	}
}