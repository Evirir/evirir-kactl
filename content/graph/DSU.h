/**
 * Author: Evirir
 * Description: rawr o.=.o
 */
#pragma once

struct DSU {
	struct Node{ int p, sz; };
	vector<Node> dsu; int cc;
	Node& operator[](int id){ return dsu[rt(id)]; }
	DSU(int n){ dsu.resize(n);
		forn(i,0,n){ cc=n; dsu[i]={i,1}; }
	}
	inline int rt(int u){ return (dsu[u].p==u) ? u : dsu[u].p=rt(dsu[u].p); }
	inline bool sameset(int u, int v){ return rt(u)==rt(v); }
	void merge(int u, int v){
		u = rt(u); v = rt(v);
		if(u == v) return;
		if(dsu[u].sz < dsu[v].sz) swap(u,v);
		dsu[v].p = u;
		dsu[u].sz += dsu[v].sz;
		cc--;
	}
};
