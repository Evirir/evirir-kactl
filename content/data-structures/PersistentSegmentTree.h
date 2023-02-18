/**
 * Author: Evirir
 * Description: rawr o.=.o
 */
#pragma once

inline ll merge(ll x, ll y){
	return x+y;
}
struct Node {
	Node *l, *r;
	ll sum=0;
	Node(ll val): l(nullptr), r(nullptr), sum(val) {}
	Node(Node *l, Node *r): l(l), r(r), sum(0) {
		if(l) sum=merge(sum, l->sum);
		if(r) sum=merge(sum, r->sum);
	}
};
class PersistSegmentTree {
private:
	int size_;
	Node* build(int l, int r)
	{
		if(l==r) return new Node(0);
		int mid=(l+r)>>1;
		return new Node(build(l, mid), build(mid+1, r));
	}
	Node* build(ll a[], int l, int r)
	{
		if(l==r) return new Node(a[l]);
		int mid=(l+r)>>1;
		return new Node(build(a, l, mid), build(a, mid+1, r));
	}
	Node* update(Node* k, int p, ll val, int l, int r)
	{
		if(l==r) return new Node(k->sum + val); //modification
		int mid=(l+r)>>1;
		if(p<=mid) return new Node(update(k->l, p, val, l, mid), k->r);
		return new Node(k->l, update(k->r, p, val, mid+1, r));
	}
	ll query(Node* k, int s, int e, int l, int r)
	{
		if(r<s || e<l) return 0; //dummy value
		if(s<=l && r<=e) return k->sum;
		int mid=(l+r)>>1;
		return merge(query(k->l, s, e, l, mid), query(k->r, s, e, mid+1, r));
	}

public:
	PersistSegmentTree(): size_(0) {}
	PersistSegmentTree(int n): size_(n) {}
	inline Node* build(){
		return build(0, size_-1);
	}
	inline Node* build(ll a[]){
		return build(a, 0, size_-1);
	}
	inline Node* update(Node* k, int p, ll val){
		return update(k, p, val, 0, size_-1);
	}
	inline ll query(Node* k, int l, int r){
		return query(k, l, r, 0, size_-1);
	}
};
