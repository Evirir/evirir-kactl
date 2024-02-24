/**
 * Author: Evirir
 * Description: rawr o.=.o
 */
#pragma once

vector<ll> fact,ifact,inv,pow2;
ll add(ll a, ll b, ll m = MOD)
{
	a+=b;
	if(abs(a)>=m) a%=m;
	if(a<0) a+=m;
	return a;
}
ll mult(ll a, ll b, ll m = MOD)
{
	if(abs(a)>=m) a%=m;
	if(abs(b)>=m) b%=m;
	a*=b;
	if(abs(a)>=m) a%=m;
	if(a<0) a+=m;
	return a;
}
void radd(ll &a, ll b, ll m = MOD){ a=add(a,b,m); }
void rmult(ll &a, ll b, ll m = MOD){ a=mult(a,b,m); }
ll pw(ll a, ll b, ll m = MOD)
{
	assert(b >= 0);  // can return 0 if desired
	if(abs(a)>=m) a%=m;
	if(a==0 && b==0) return 0; // value of 0^0
	ll r=1;
	while(b){
		if(b&1) r=mult(r,a,m);
		a=mult(a,a,m);
		b>>=1;
	}
	return r;
}
ll inverse(ll a, ll m = MOD)
{
	return pw(a,m-2);
}
ll choose(ll a, ll b)
{
	if(a<b) return 0;
	if(b==0) return 1;
	if(a==b) return 1;
	return mult(fact[a],mult(ifact[b],ifact[a-b]));
}
void init(ll _n)
{
	fact.clear(); ifact.clear(); inv.clear(); pow2.clear();
	fact.resize(_n+1); ifact.resize(_n+1); inv.resize(_n+1); pow2.resize(_n+1);
	pow2[0]=1; ifact[0]=1; fact[0]=1;
	for(int i=1;i<=_n;i++){
		pow2[i]=add(pow2[i-1],pow2[i-1]);
		fact[i]=mult(fact[i-1],i);
	}
	ifact[_n] = inverse(fact[_n]);
	for(int i=_n-1;i>=1;i--){
	    ifact[i] = mult(ifact[i+1], i+1);
	}
	for(int i=1;i<=_n;i++){
	    inv[i] = mult(fact[i-1], ifact[i]);
	}
}
// partition n into k blocks of size >= 0
ll nonneg_partition(ll n, ll k)
{
	assert(k >= 1);  // can return 0 if desired
	return choose(n + k - 1, k - 1);
}
// partition n into k blocks of size >= minVal
ll partition(ll n, ll k, ll minVal = 1)
{
	assert(k >= 1);  // can return 0 if desired
	return nonneg_partition(n - k * minVal, k);
}
