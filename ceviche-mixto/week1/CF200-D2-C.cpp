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

    map<string, int> pts;
    map<string, int> cnt;
    map<string, int> scored; 
    map<string, int> missed;
    set<string> st;
    rep(i, 0, 5){
        string a, b; cin >> a >> b;
        string c; cin >> c;
        st.insert(a);
        st.insert(b);
        int g1 = c[0] - '0';
        int g2 = c[2] - '0';
        cnt[a]++;
        cnt[b]++;
        scored[a] += g1;
        missed[a] += g2;
        scored[b] += g2;
        missed[b] += g1;

        if(g1 == g2){
            pts[a]++;
            pts[b]++;
        }else if(g1 > g2) pts[a] += 3;
        else pts[b] += 3;
    }       

    vector<string> teams(all(st));
    string other = "";
    for(auto [s, c] : cnt){
        if(c == 2 && s != "BERLAND") other = s;
    }

    auto ok = [&](int p1, int p2){
        if(p1 <= p2) return false;
        pts["BERLAND"] += 3;
        scored["BERLAND"] += p1;
        scored[other] += p2;
        missed["BERLAND"] += p2;
        missed[other] += p1;


        vi ord(4);
        iota(all(ord), 0);
        sort(all(ord), [&](int l, int r){
            tuple<int, int, int> t1(
                pts[teams[l]], 
                scored[teams[l]] - missed[teams[l]],
                scored[teams[l]]
            );
            tuple<int, int, int> t2(
                pts[teams[r]], 
                scored[teams[r]] - missed[teams[r]],
                scored[teams[r]]
            );

            if(t1 == t2) return teams[l] < teams[r];
            return t1 > t2;
        });


        pts["BERLAND"] -= 3;
        scored["BERLAND"] -= p1;
        scored[other] -= p2;
        missed["BERLAND"] -= p2;
        missed[other] -= p1;

        if(teams[ord[0]] == "BERLAND" || teams[ord[1]] == "BERLAND") return true;
        return false;
    };

    vii valid;
    rep(i, 0, 100) rep(j, 0, 100){
        if(ok(i, j)) valid.emplace_back(i - j, j);
    }

    sort(all(valid));
    if(valid.empty()) cout << "IMPOSSIBLE\n";
    else cout << valid[0].first + valid[0].second << ":" << valid[0].second << "\n";
}