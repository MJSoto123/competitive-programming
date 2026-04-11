#include<bits/stdc++.h>
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
#define rep(i , a, b) for(int i = a ; i < (b); i++)
using namespace ::std;
using ll = long long;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int ,int> pii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    string a; cin >> a;
    vi suff(n + 1 , 100);
    suff[n] = (a[n - 1] - 'a');
    // cout << "Suf: " << suff[n] << '\n';
    for(int i = n - 1; i >= 0; i--)
        suff[i] = min(suff[i + 1], (a[i] - 'a'));
    // for(int i : suff) cout << char(i + 'a') << ' '; cout << '\n';
    int id = -1;
    char l ;
    for(int i = 0 ; i < n - 1 ; i++){
        int val = a[i] - 'a';
        if(val > suff[i + 1]){
            id = i;
            l = (char)(suff[i + 1] + 'a');
            break;
        }
    }
    // cout << id << '\n';
    if(id != -1){
        int id2 = -1;
        for(int i = 0; i < n; i++){
            if(a[i] == l) id2 = i;
        }
        swap(a[id] , a[id2]);
    }
    cout << a << '\n';
}