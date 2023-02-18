#pragma once

struct Line {
	ll m,c;
	Line(): m(0), c(INF) {}
	Line(ll m, ll c): m(m), c(c) {}
	ll eval(ll x){ return m*x+c; }
};

struct LiChaoTree {
	int sz;
	bool isMax; // whether this maintains max
	vector<Line> v;
	LiChaoTree(): sz(0), isMax(false), v(vector<Line>()) {}
	LiChaoTree(int sz, bool isMax): sz(sz), isMax(isMax) {
		v.resize(sz*4, {0,INF});
	}
	void addline(Line& val) {
		if(isMax) {
			val.m = -val.m;
			val.c = -val.c;
		}
		addline(val, 1, 0, sz-1);
	}
	ll query(int x) {
		return (isMax ? -1 : 1) * query(x, 1, 0, sz-1);
	}
	void addline(Line& val, int k, int l, int r) {
		int mid = (l+r)>>1;
		bool lc = val.eval(l) <= v[k].eval(l);
		bool mc = val.eval(mid) <= v[k].eval(mid);
		if(mc) swap(val, v[k]);
		if(l==r) return;
		if(lc==mc) addline(val, k*2, l, mid);
		else addline(val, k*2+1, mid+1, r);
	}
	ll query(int x, int k, int l, int r) {
		ll cur = v[k].eval(x);
		if(l==r) return cur;
		int mid=(l+r)>>1;
		if(x<=mid) return min(cur, query(x, k*2, l, mid));
		return min(cur, query(x, k*2+1, mid+1, r));
	}
};
