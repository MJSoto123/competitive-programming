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

vi pts = {80, 68, 62, 57, 53, 50, 48, 46, 44, 42};

int puntos(int place){
    if(place > 50) return 0;
    if(place > 10) return 51 - place;
    return pts[place - 1];
}

int get(){
    int n; cin >> n;
    vector<string> name(n);
    vi prob(n), place(n);

    rep(i, 0, n) cin >> name[i] >> prob[i] >> place[i];
    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int l, int r){
        if(prob[l] == prob[r]) return place[l] < place[r];
        return prob[l] > prob[r];
    });

    int ans = 10 * prob[ord[0]] + 2 * puntos(place[ord[0]]);
    if(n > 1) ans += puntos(place[ord[1]]);
    if(n > 2) ans += puntos(place[ord[2]]);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a = get();
    int b = get();
    int c = get();

    cout << 4 * a + 3 * b + 2 * c;
}