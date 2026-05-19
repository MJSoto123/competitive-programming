#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<string> a(n);

    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) reverse(all(a[i]));
    string s = a[0];

    vi b(n);
    iota(all(b), 0);

    int cnt = 0;
    int d = 0;
    bool fs = true;
    rep(i, 0, sz(s)){
        vi b2;
        bool ok = true;
        char c = a[0].back();
        for(auto id : b){
            if(sz(a[id]) == 0 || a[id].back() != c) ok = false;
            else{
                a[id].pop_back();
                b2.emplace_back(id);
            }
        }
        b = b2;
        if(ok) d++;

        if(!ok){
            if(d == 0) cnt++;
            else{
                cnt += 2;
                d = 0;
            }
        }
    }

    if(d) cnt++;
    cout << cnt << "\n";
}