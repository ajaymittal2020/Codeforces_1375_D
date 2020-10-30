#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll ,ll> pll;
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(), (X).end()
#define REP(i,x,y) for(ll i = x;i <= y;++i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
vector<string> vec_splitter(string s) {
    for(char& c: s) c = c == ','?  ' ': c;
    stringstream ss; ss << s;
    vector<string> res;
    for(string z; ss >> z; res.push_back(z))
        ;
    return res;
}
void debug_out(vector<string> args, int idx) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, Head H, Tail... T) {
    if(idx > 0) cerr << ", ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, T...);
}
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __VA_ARGS__)
void localTest() {
    #ifndef ONLINE_JUDGE
        freopen("inp", "r", stdin);
        freopen("out", "w", stdout);
    #endif      
}
bool isSorted(vector<ll> &A) {
	ll n = A.size();
	for(ll i = 1; i < n; ++i) {
		if(A[i] < A[i - 1]) {
			return false;
		}
	}
	return true;
}
int main() {

    localTest();
    fastio;
    ll t;
    cin >> t;
    while(t--) {
    	ll n;
    	cin >> n;
    	vector<ll> A(n);
    	for(auto &x : A) {
    		cin >> x;
    	}
    	vector<ll> ans;
    	vector<ll> vis(n, 0);
    	while(!isSorted(A)) {
    		vector<ll> has(n + 1, 0);
    		for(auto x : A) {
    			has[x]++;
    		}
    		ll mex = 0;
    		for(ll i = 0; i <= n; ++i) {
    			if(!has[i]) {
    				mex = i;
    				break;
    			}
    		}
    		if(mex < n) {
    			ll idx = mex;
    			while(idx < n && vis[idx]) {
    				idx++;
    			}
    			vis[idx] = 1;
    			A[idx] = mex;
    			ans.pb(idx);
    		} else {
    			ll idx = n - 1;
    			for(ll i = 0; i < n; ++i) {
    				if(!vis[i]) {
    					idx = i;
    				}
    			}
    			A[idx] = mex;
    			ans.pb(idx);
    		}
    	}
    	cout << ans.size() << "\n";
    	for(auto u : ans) {
    		cout << u + 1 << " ";
    	}
    	cout << "\n";
    }

    return 0;
}
