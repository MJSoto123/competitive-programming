#include <bits/stdc++.h>
using namespace std;

vector<int> suffix_array(string &s) {
	s += char(0);
	const int n = s.size();
	vector<int> mapeo(n, 0);
	vector<int> a(n);
	iota(a.begin(), a.end(), 0);
	sort(a.begin(), a.end(), [&] (int i, int j) {
		return s[i] < s[j];	
	});
	mapeo[a[0]] = 0;
	for(int i = 1; i < n; i++) {
		mapeo[a[i]] = mapeo[a[i - 1]] + (s[a[i - 1]] != s[a[i]]);
	}
	int len = 1;
	vector<int> head(n);
	vector<int> new_mapeo(n);
	vector<int> sorted_by_second(n);
	while(len < n) {
		for(int i = 0; i < n; i++) {
			sorted_by_second[i] = (a[i] + n - len) % n;
		}
		for(int i = n - 1; i >= 0; i--) {
			head[mapeo[a[i]]] = i;
		}
		for(int i = 0; i < n; i++) {
			int x = sorted_by_second[i];
			a[head[mapeo[x]]++] = x;
		}
		// Asignar los nuevos mapeos
		new_mapeo[a[0]] = 0;
		for(int i = 1; i < n; i++) {
			if(mapeo[a[i - 1]] != mapeo[a[i]]) {
				new_mapeo[a[i]] = new_mapeo[a[i - 1]] + 1;
			}
			else {
				int pre = mapeo[(a[i - 1] + len) % n];
				int cur = mapeo[(a[i] + len) % n];
				new_mapeo[a[i]] = new_mapeo[a[i - 1]] + (pre != cur);
			}
		}
		swap(new_mapeo, mapeo);
		len <<= 1;
	}
	s.pop_back();
	return vector<int>(a.begin() + 1, a.end());
}

vector<int> lcp_array(string &s, vector<int> &a) {
	// O(n)
	const int n = s.size();
	vector<int> rank(n);
	for(int i = 0; i < n; i++) rank[a[i]] = i;
	int k = 0;
	vector<int> lcp(n);
	for(int i = 0; i < n; i++) {
		if(rank[i] + 1 == n) {
			k = 0;
			continue;
		}
		int j = a[rank[i] + 1];
		while(i + k < n and j + k < n and s[i + k] == s[j + k]) {
			k++;
		}
		lcp[rank[i]] = k;
		if(k > 0) k--;
	}
	lcp.pop_back();
	return lcp;
}

int main() {
	cin.tie(0) -> sync_with_stdio(false);
    int nn; cin >> nn;
	string s;
	cin >> s;
	vector<int> a = suffix_array(s);
	vector<int> lcp = lcp_array(s, a);
    cerr << "\n";
    for(int x : a) {
		cerr << s.substr(x) << endl;
	}
	cerr << endl;
	for(int x : lcp) {
		cerr << x << " ";
	}
	cerr << endl;

    int n = lcp.size();
    vector<vector<int>> ans;
    vector<int> cur;
    for(int i = 0; i < n; i++){
        if(lcp[i] == 0){
            if(cur.size()) ans.emplace_back(cur);
            cur.clear();
        } else cur.emplace_back(lcp[i]);
    }
    if(cur.size()) ans.emplace_back(cur);

    int len = 0;
    for(auto x : ans) len = max(len, (int)x.size());
    cerr << "no ceros " << len << "\n";

    int mx = 0, id = 0;
    int idnow = 0;
    for(int i = 0; i < (int)(ans.size()); i++){
        for(auto x : ans[i]) cerr << x << " "; cerr << "\n";
        if((int)ans[i].size() == len){
            int anshere = 1e9, idmn = 0;
            for(int j = 0; j < (int)(ans[i].size()); j++){
                if(ans[i][j] < anshere){
                    anshere = ans[i][j];
                    idmn = idnow + j;
                }
            }
            if(anshere > mx){
                id = idmn + 1;
                mx = anshere;
            }
        }
        idnow += (int)ans[i].size();
    }

    if(mx == 0){ cout << s << "\n"; return 0; }
    cout << s.substr(a[id], mx) << "\n";
	return 0;
}