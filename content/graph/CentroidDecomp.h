/**
 * Author: Evirir
 * Description: rawr o.=.o
 */
#pragma once

int sz[MAXN];
bool vst[MAXN];
int cprt[MAXN]; // centroid tree parent
vector<int> child[MAXN]; // subtree of centroid tree
mset(cprt,-1);

void dfs_sz(int u, int p)
{
	sz[u]=1;
	for(int v: adj[u])
	{
		if(v==p || vst[v]) continue;
		dfs_sz(v,u);
		sz[u]+=sz[v];
	}
}
int centroid(int u, int p, int r)
{
	for(int v: adj[u])
	{
		if(v==p || vst[v]) continue;
		if(sz[v]*2>sz[r]) return centroid(v,u,r);
	}
	return u;
}
int build_tree(int u)
{
	dfs_sz(u,-1);
	u=centroid(u,-1,u);
	vst[u]=1;
	for(int v: adj[u])
	{
		if(vst[v]) continue;
		cprt[build_tree(v)]=u;
	}
	return u;
}
void prep(int u, int p)
{
	for(int v: adj[u])
	{
		if(v==p || vst[v]) continue;

		prep(v, u);
	}
}
void solve(int u)
{
	dfs_sz(u,-1);
	u=centroid(u,-1,u);

	prep(u,-1);
	for(int v: adj[u])
	{
		if(vst[v]) continue;

	}

	// do stuffs

	vst[u]=1;
	for(int v: adj[u])
	{
		if(vst[v]) continue;
		solve(v);
	}
}
