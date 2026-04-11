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

vector<string> get(string &var){
    string s;
    cin >> s; // for
    cin >> var; // a
    cin >> s; // in
    cin >> s; // range
    vector<string> a;
    string now = "";
    rep(i, 6, sz(s)){
        if(s[i] == ','){
            a.emplace_back(now);
            now = "";
        }
        else if(s[i] == ')' && now != ""){
            a.emplace_back(now);
            now = "";
        }else now += s[i];
    }
    return a;
};

ll var = 8e18;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vl fi(3, 0); fi[2] = 1;
    vl se(3, 0); se[2] = 1;

    string var1 , var2;
    string s; cin >> s; // ans=0;
    
    auto a = get(var1);
    rep(i, 0, sz(a)) fi[i] = stoll(a[i]);

    auto b = get(var2);
    rep(i, 0, sz(b)){
        if(b[i] == var1) se[i] = var;
        else se[i] = stoll(b[i]);
    }

    cin >> s; // ans+=b;
    cin >> s; // print;
    ll ans = 0;
    for(int i = fi[0]; (fi[2] > 0 ? i < fi[1] : i > fi[1]); i += fi[2]){
        vl now(3);
        rep(j, 0, 3) now[j] = (se[j] == var ? i : se[j]);

        bool inv = false;
        if(now[2] < 0){
            rep(j, 0, 3) now[j] = (now[j] * (-1));
            inv = true;
        }
        if(now[0] < now[1] && now[2] > 0){
            now[1]--;
            // crece
            ll t = (now[1] - now[0]) / now[2];
            ll lst = now[0] + t * now[2];
            ll add = (now[0] + lst) * (t + 1) / 2;

            // inv
            if(inv) ans -= add;
            else ans += add;
        }
    }
    cout << ans << "\n";
}