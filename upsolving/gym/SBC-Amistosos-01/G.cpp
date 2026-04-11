#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vvl vector<vl>
#define pii pair<int,int>
#define vl vector<long long>
#define vii vector<pair<int,int>>
using namespace std;

const int MOD = 1e9 + 7;
inline ll gcd(ll a, ll b) { while (b != 0) swap(b, a %= b); return a; }



const int MX = 2e5+5;
const int LG = 20;
int spt[LG][MX];   
int arr[MX];
int n;
void build() {
    for (int i = 0; i < n; i++) spt[0][i] = arr[i];
    for (int j = 0; j < LG-1; j++)
        for (int i = 0; i+(1<<(j+1)) <= n; i++)
            spt[j+1][i] = min(spt[j][i], spt[j][i+(1<<j)]);
}

int rmq(int i, int j) {
    int k = 31-__builtin_clz(j-i+1);
    return min(spt[k][i], spt[k][j-(1<<k)+1]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q; cin >> n >> q;
    vi a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(count(a.begin() + 1, a.end(), 0) == n){
        cout << "YES\n";
        for(int i = 0; i < n; i++) cout << q << " ";
        cout << "\n";
        return 0;
    }

    vi zeros;
    for(int i = 1; i <= n; i++){
        if(a[i] != 0) continue;

        zeros.emplace_back(i);
        if(i > 1 && a[i - 1] != 0) a[i] = a[i - 1];
    }

    for(int i = n; i >= 1; i--) if(a[i] == 0) a[i] = a[i + 1];

    if(!count(a.begin() + 1, a.end(), q)){
        if(zeros.empty()){ cout << "NO\n"; return 0; }
        a[zeros[0]] = q;
    }

    for(int i = 1; i <= n; i++) arr[i - 1] = a[i];
    build();

    unordered_map<int, int> l;
    unordered_map<int, int> r;

    for(int i = 1; i <= n; i++){
        if(!l.count(a[i])) l[a[i]] = i;
        r[a[i]] = i;
    }

    for(int i = 1; i <= n; i++){
        int mn = rmq(l[a[i]] - 1, r[a[i]] - 1);
        if(mn < a[i]){ cout << "NO\n"; return 0; }
    }

    cout << "YES\n";
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
}