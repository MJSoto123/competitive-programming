#include<bits/stdc++.h>
using namespace std;


const int inf = 1e9 + 100;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; cin >> n >> k;
    vector<long long> a(n);
    vector<long long> b(n);
    vector<long long> c(n);

    for(int i = 0; i < n; i++) cin >> a[i];    
    for(int i = 0; i < n; i++) cin >> b[i];    
    for(int i = 0; i < n; i++) cin >> c[i];    

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    long long ans;
    set<tuple<int, int, int>> vis;
    priority_queue<pair<long long, tuple<int,int,int>>> q;

    q.emplace(a[n - 1] * b[n - 1] + a[n - 1] * c[n - 1] + b[n - 1] * c[n - 1], make_tuple(n - 1, n - 1, n - 1));

    while(k){
        k--;
        tuple<int,int,int> t; tie(ans, t) = q.top(); q.pop();
        int aa, bb, cc; tie(aa, bb, cc) = t;
        
        if(aa && vis.count({aa - 1, bb, cc}) == 0) {
            q.emplace(a[aa - 1] * b[bb] + a[aa - 1] * c[cc] + b[bb] * c[cc], make_tuple(aa - 1, bb, cc));
            vis.emplace(aa - 1, bb, cc);
        }
        if(bb && vis.count({aa, bb - 1, cc}) == 0){
            q.emplace(a[aa] * b[bb - 1] + a[aa] * c[cc] + b[bb - 1] * c[cc], make_tuple(aa, bb - 1, cc));
            vis.emplace(aa, bb - 1, cc);
        }
        if(cc && vis.count({aa, bb, cc - 1}) == 0) {
            q.emplace(a[aa] * b[bb] + a[aa] * c[cc - 1] + b[bb] * c[cc - 1], make_tuple(aa, bb, cc - 1));
            vis.emplace(aa, bb, cc - 1);
        }
    }
    cout << ans << "\n";
}