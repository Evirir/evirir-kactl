#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#define watch(x) cout<<(#x)<<"="<<(x)<<'\n'
#define mset(d,val) memset(d,val,sizeof(d))
#define cbug if(DEBUG) cout
#define setp(x) cout<<fixed<<setprecision(x)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define forn(i,a,b) for(int i=(a);i<(b);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define F first
#define S second
#define fbo find_by_order
#define ook order_of_key
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
//template<typename T>
//using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void SD(int t=0){ cout<<"PASSED "<<t<<endl; }
ostream& operator<<(ostream &out, ii x){ out<<"("<<x.F<<","<<x.S<<")"; return out; }
const ll INF = ll(1e18);
const int MOD = 998244353;

const bool DEBUG = 0;
const int MAXN = 100005;
const int LG = 21;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
}
