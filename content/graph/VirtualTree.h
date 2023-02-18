#pragma once

int buildVirtualTree(vector<int> nodes, vi vadj[])
{
	// Change these as needed
	auto reset = [&](int u) {
		vadj[u].clear();
	};
	auto connect = [&](int u, int v) {  // u is parent of v
		vadj[u].push_back(v);
	};

	auto cmpDfs = [&](int u, int v) {
		return in[u] < in[v];
	};
	sort(nodes.begin(), nodes.end(), cmpDfs);
	unordered_set<int> uniqueNodes(nodes.begin(), nodes.end());
	for (int i{1}; i < sz(nodes); i++)
		uniqueNodes.insert(getLca(nodes[i - 1], nodes[i]));
	nodes = vector<int>(uniqueNodes.begin(), uniqueNodes.end());
	sort(nodes.begin(), nodes.end(), cmpDfs);
	for_each(nodes.begin(), nodes.end(), reset);

	stack<int> stk;
    for (int u : nodes)
	{
		if (stk.empty()) { stk.push(u); continue; }
		while (!isChild(stk.top(), u)) stk.pop();
		connect(stk.top(), u);
		stk.push(u);
	}
	return nodes[0];
}
