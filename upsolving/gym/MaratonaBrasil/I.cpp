#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i , a, b) for(int i = a ; i < (b); i++)
using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int ,int> pii;
const int N = 30;
unordered_set<int> G[N];
int n;
vi res;
bool kanh(int nn){
    vi indeg(nn + 1);
    for(int i = 0; i < nn; i++){
        for(int ii : G[i])
            indeg[ii] += 1;
    }

    queue<int> q;
    for(int i = 0; i < nn;  i++)
        if(indeg[i] == 0)
            q.push(i);  
    while(q.size()){
        int u = q.front() ; q.pop();
        res.emplace_back(u);
        for(int ii : G[u]){
            indeg[ii]--;
            if(indeg[ii] == 0)
                q.push(ii);
        }
    }
    // for(int i : res) cout << i << ' '; cout << '\n';
    if(sz(res) != nn) return false;
    else              return true;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<string> ss(n);
    for(int i = 0; i < n; i++) cin >> ss[i];
    for(char c = 'a' ; c <= 'z'; c++){
        for(int i = 0; i < n; i++){
            int id = 0; 
            int t = sz(ss[i]);
            while(id < t && ss[i][id] != c) id++;
            // cout << "val: "  << ss[i] << '\n';
            // cout << ss[i] << '\n';
            // cout << "C: " << c << '\n';
            // cout << "Id: " << id << '\n';
            for(int ii = id ; ii < t; ii++){
                if(c == ss[i][ii]) continue;
                G[(c - 'a')].emplace(ss[i][ii] - 'a');
            }
        }
    }
    string ans = "";
    
    if(kanh(26)){
        cout << "SIM\n";
        // reverse(all(res));
        // for(int i : res) cout << i << ' '; cout << '\n';
        for(int i : res) ans += (char)(i + 'a');
        cout << ans << '\n';
    }
    else{
        cout << "NAO\n";
    }
    // for(int i = 0; i < 26; i++){
    //     cout << "I: " << (char)(i + 'a') << " ==> ";
    //     for(int vals: G[i]) cout << (char)(vals + 'a') << ' '; cout << '\n';
    // }
    
}