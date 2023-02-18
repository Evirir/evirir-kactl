#pragma once

class SegmentTree2D {
private:
	int size_n, size_m;
	vector<vector<ll>> v;
	void build(const vector<vector<ll>> &a, int k, int l, int r)
	{
		if(r >= size_n) return;
		if(l != r){
			int mid = (l+r)>>1;
			build(a, k*2, l, mid);
			build(a, k*2+1, mid+1, r);
		}
		build2(a, k, l, r, 1, 0, size_m-1);
	}
	void build2(const vector<vector<ll>> &a, int k, int l, int r, int k2, int l2, int r2)
	{
		if(l2 == r2){
			if(l >= a.size() || l2 >= a[0].size()) return;
			if(l == r)
				v[k][k2] = a[l][l2];
			else
				v[k][k2] = merge(v[k*2][k2], v[k*2+1][k2]);
			return;
		}
		int mid2 = (l2+r2)>>1;
		build2(a, k, l, r, k2*2, l2, mid2);
		build2(a, k, l, r, k2*2+1, mid2+1, r2);
		v[k][k2] = merge(v[k][k2*2], v[k][k2*2+1]);
	}
	void update(int p1, int p2, ll val, int k, int l, int r)
	{
		if(p1 < l || r < p1) return;
		if(l != r){
			int mid = (l+r)>>1;
			update(p1, p2, val, k*2, l, mid);
			update(p1, p2, val, k*2+1, mid+1, r);
		}
		update2(p1, p2, val, k, l, r, 1, 0, size_m-1);
	}
	void update2(int p1, int p2, ll val, int k, int l, int r, int k2, int l2, int r2)
	{
		if(p2 < l2 || r2 < p2) return;
		if(l2 == r2){
			if(l == r)
				v[k][k2] ^= val;	//modification
			else
				v[k][k2] = merge(v[k*2][k2], v[k*2+1][k2]);
			return;
		}
		int mid2 = (l2+r2)>>1;
		update2(p1, p2, val, k, l, r, k2*2, l2, mid2);
		update2(p1, p2, val, k, l, r, k2*2+1, mid2+1, r2);
		v[k][k2] = merge(v[k][k2*2], v[k][k2*2+1]);
	}
	ll query(int s, int e, int s2, int e2, int k, int l, int r)
	{
		if(e < l || r < s) return 0;	//dummy value
		if(s <= l && r <= e) return query2(s2, e2, k, 1, 0, size_m-1);
		int mid = (l+r)>>1;
		ll lc = query(s, e, s2, e2, k*2, l, mid);
		ll rc = query(s, e, s2, e2, k*2+1, mid+1, r);
		return merge(lc, rc);
	}
	ll query2(int s2, int e2, int k, int k2, int l2, int r2)
	{
		if(e2 < l2 || r2 < s2) return 0;	//dummy value
		if(s2 <= l2 && r2 <= e2) return v[k][k2];
		int mid2 = (l2+r2)>>1;
		ll lc = query2(s2, e2, k, k2*2, l2, mid2);
		ll rc = query2(s2, e2, k, k2*2+1, mid2+1, r2);
		return merge(lc, rc);
	}

public:
	SegmentTree2D(): v(vector<vector<ll>>()) {}
	SegmentTree2D(int n, int m){
		for(size_n=1;size_n<n;) size_n<<=1;
		for(size_m=1;size_m<m;) size_m<<=1;
		v.resize(4*size_n, vector<ll>(4*size_m));
	}
	inline ll merge(ll x, ll y){
		return x+y;
	}
	inline void build(const vector<vector<ll>> &a){
		build(a, 1, 0, size_n-1);
	}
	inline void update(int p1, int p2, ll val){
		update(p1, p2, val, 1, 0, size_n-1);
	}
	inline ll query(int l, int r, int l2, int r2){
		return query(l, r, l2, r2, 1, 0, size_n-1);
	}
};
