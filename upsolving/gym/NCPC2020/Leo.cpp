#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif

using namespace std;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define sz(a) ((int)(a).size())
#define ff first
#define ss second
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define approx(a) fixed << setprecision(a)

template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <class T> void ckmin(T &a, const T &b) { a = min(a, b); }
template <class T> void ckmax(T &a, const T &b) { a = max(a, b); }

template <class T> void read(vector<T> &v);
template <class F, class S> void read(pair<F, S> &p);
template <class T, size_t Z> void read(array<T, Z> &a);
template <class T> void read(T &x) {cin >> x;}
template <class R, class... T> void read(R& r, T&... t){read(r); read(t...);};
template <class T> void read(vector<T> &v) {for(auto& x : v) read(x);}
template <class F, class S> void read(pair<F, S> &p) {read(p.ff, p.ss);}
template <class T, size_t Z> void read(array<T, Z> &a) { for(auto &x : a) read(x); }

template <class F, class S> void pr(const pair<F, S> &x);
template <class T> void pr(const T &x) {cout << x;}
template <class R, class... T> void pr(const R& r, const T&... t) {pr(r); pr(t...);}
template <class F, class S> void pr(const pair<F, S> &x) {pr("{", x.ff, ", ", x.ss, "}\n");}
void ps() {pr("\n");}
template <class T> void ps(const T &x) {pr(x); ps();}
template <class T> void ps(vector<T> &v) {for(auto& x : v) pr(x, ' '); ps();}
template <class T, size_t Z> void ps(const array<T, Z> &a) { for(auto &x : a) pr(x, ' '); ps(); }
template <class F, class S> void ps(const pair<F, S> &x) {pr(x.ff, ' ', x.ss); ps();}
template <class R, class... T> void ps(const R& r,  const T &...t) {pr(r, ' '); ps(t...);}

void solve(){
	string s;
	int n;

	auto get_str = [&](int& pos){
		string cur = "";
		if(s[pos] == '"'){
			int close = 1;
			while(pos < n){
				cur += s[pos];
				if(s[pos] == '"'){
					if(close == 1) {
						cur.pop_back();
						close--;
					}
					else if(pos + 1 < n && s[pos + 1] == '"'){
						cur += s[pos + 1];
						pos++;
					}
					else {
						assert(pos == n - 1 || s[pos + 1] == ',');
						cur.pop_back();
						pos++;
						break;
					}
				}
				pos++;
			}
		}else{
			while(pos < n && s[pos] != ','){
				cur += s[pos++];
			}
		}
		assert(pos == n || s[pos] == ',');
		return cur;
	};

	vector<vector<string>> g;
	map<string, int> getp; // almaceno los acronimos de los padres
	map<string, int> idxp;

	int idx = 0;
	while(getline(cin, s)){
		vector<string> sep;
		n = (int) s.size();
		int pos = 0;
		sep.push_back(get_str(pos));
		pos++;
		sep.push_back(get_str(pos));
		pos++;
		sep.push_back(get_str(pos));
		pos++;
		sep.push_back(get_str(pos));
		pos++;
		sep.push_back(get_str(pos));
		pos++;
		sep.push_back(get_str(pos));
		g.push_back(sep);
		
		if(sep[5] == "Parent Event"){
			getp[sep[2]]++;
			idxp[sep[2]] = idx;
		}
		idx++;
	}

	set<string> bad;
	for(auto [acr, cnt] : getp){
		if(cnt > 1) bad.insert(acr);
	}

	
	map<string, vector<int>> children;
	int m = (int) g.size();

	for(int i = 0; i < m; i++){
		auto& curs = g[i];


		if(curs[5] == "Parent Event") continue;
		if(curs[2].empty()) continue;
		if(!getp.count(curs[2])) continue;
		if(bad.count(curs[2])) continue;

		children[curs[2]].push_back(i);
	}

	for(auto [acr, vv] : children){
		if(vv.empty()) continue;
		int parent_idx = idxp[acr];
		string code = "";
		
		for(int i : vv){
			if(code == "???") break;
			if(code.empty()){
				code = g[i][4];
			}else if(code != g[i][4]){
				code = "???";
			}
		}

		for(int j = 0; j <= 5; j++){
			if(j == 1 || j == 2 || j == 5) cout << '"';
			cout << g[parent_idx][j];
			if(j == 1 || j == 2 || j == 5) cout << '"';
			if(j == 4){
				cout << code;
			} 
			cout << ",\n"[j == 5];
		}
		sort(all(vv), [&](int i, int j){ return g[i][1] < g[j][1];  });
		for(int i : vv){
			for(int j = 0; j <= 5; j++){
				if(j == 1 || j == 2 || j == 5) cout << '"';
				cout << g[i][j];
				if(j == 1 || j == 2 || j == 5) cout << '"';
				cout << ",";
			}
			cout << g[parent_idx][0] << '\n';
		}
	}

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
}
