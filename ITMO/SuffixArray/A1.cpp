#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i,a,b) for(int i = (a) ; i < (b) ; i++)

using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int , int> pii;
typedef vector<pii> vii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    s += "$";
    int n = sz(s);
    int k = log2(n) + 1;
    vi p(n);
    rep(i, 0, n - 1) p[i] = int(s[i] - 'a' + 1);
    p[n - 1] = 0;

    rep(pot, 0, k){
        int len = (1 << pot);
        vii tmp(n);
        rep(i, 0, n) tmp[i] = {p[i], p[(i + len) % n]};

        vi ord(n);
        iota(all(ord), 0);
        sort(all(ord), [&](int l, int r){
            return tmp[l] < tmp[r];
        });
        vi perm(n);
        int id = 0;
        perm[ord[0]] = 0;
        rep(i, 1, n){
            if(tmp[ord[i]] != tmp[ord[i - 1]]) id++;
            perm[ord[i]] = id;
        }
        p = perm;
    }
    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int l, int r){
        return p[l] < p[r];
    });

    rep(i, 0, n) cout << ord[i] << " ";
    cout << "\n";
}