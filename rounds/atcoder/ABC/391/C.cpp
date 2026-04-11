#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q; cin >> n >> q;

    vector<int> a(n + 1);
    vector<int> cnt(n + 1);

    for(int i = 0; i <= n; i++) a[i] = i;
    for(int i = 0; i <= n; i++) cnt[i] = 1;

    int ans = 0;
    for(int i = 0; i < q; i++){
        int op; cin >> op;
        if(op == 2) cout << ans << "\n";
        else{
            int p, nest; cin >> p >> nest;
            int curr = a[p];
            if(cnt[curr] == 2) ans--;
            cnt[curr]--;

            if(cnt[nest] == 1) ans++;
            cnt[nest]++;

            a[p] = nest;
        }
    }
}