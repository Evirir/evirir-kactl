/**
 * Author: Evirir, zscoder
 * Description: rawr o.=.o
 */
#pragma once

vector<ll> primes, totient, sumdiv, bigdiv, lowprime;
vector<bool> prime;
void Sieve(ll n) // linear Sieve
{
	prime.assign(n+1, 1);
	lowprime.assign(n+1, 0);
	prime[1] = false;
	for(ll i = 2; i <= n; i++)
	{
		if(lowprime[i] == 0)
		{
			primes.pb(i);
			lowprime[i] = i;
		}
		for(int j=0; j<sz(primes) && primes[j]<=lowprime[i] && i*primes[j]<=n; j++)
		{
			prime[j] = false;
			lowprime[i*primes[j]] = lowprime[i];
		}
	}
}
ll phi(ll x)
{
	map<ll,ll> pf;
	ll num = 1; ll num2 = x;
	for(ll i = 0; primes[i]*primes[i] <= x; i++)
	{
		if(x%primes[i]==0)
		{
			num2/=primes[i];
			num*=(primes[i]-1);
		}
		while(x%primes[i]==0)
		{
			x/=primes[i];
			pf[primes[i]]++;
		}
	}
	if(x>1)
	{
		pf[x]++; num2/=x; num*=(x-1);
	}
	x = 1;
	num*=num2;
	return num;
}
bool isprime(ll x)
{
	if(x==1) return false;
	for(ll i = 0; primes[i]*primes[i] <= x; i++)
	{
		if(x%primes[i]==0) return false;
	}
	return true;
}
void SievePhi(ll n)
{
	totient.resize(n+1);
	for (int i = 1; i <= n; ++i) totient[i] = i;
	for (int i = 2; i <= n; ++i)
	{
		if (totient[i] == i)
		{
			for (int j = i; j <= n; j += i)
			{
				totient[j] -= totient[j] / i;
			}
		}
	}
}
void SieveSumDiv(ll n)
{
	sumdiv.resize(n+1);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i; j <= n; j += i)
		{
			sumdiv[j] += i;
		}
	}
}
ll getPhi(ll n)
{
	return totient[n];
}
ll getSumDiv(ll n)
{
	return sumdiv[n];
}
ll pw(ll a, ll b, ll mod)
{
	ll r = 1;
	if(b < 0) b += mod*100000LL;
	while(b)
	{
		if(b&1) r = (r*a)%mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return r;
}
ll inv(ll a, ll mod)
{
	return pw(a, mod - 2, mod);
}
ll invgeneral(ll a, ll mod)
{
	ll ph = phi(mod);
	ph--;
	return pw(a, ph, mod);
}
void getpf(vector<ii>& pf, ll n)
{
	for(ll i = 0; primes[i]*primes[i] <= n; i++)
	{
		int cnt = 0;
		while(n%primes[i]==0)
		{
			n/=primes[i]; cnt++;
		}
		if(cnt>0) pf.pb(ii(primes[i], cnt));
	}
	if(n>1)
	{
		pf.pb(ii(n, 1));
	}
}
void getdiv(vector<ll>& div, vector<ii>& pf, ll n = 1, int i = 0)
{
	ll x, k;
	if(i >= sz(pf)) return;
	x = n;
	for(k = 0; k <= pf[i].S; k++)
	{
		if(i == sz(pf) - 1) div.pb(x);
		getdiv(div, pf, x, i + 1);
		x *= pf[i].F;
	}
}
