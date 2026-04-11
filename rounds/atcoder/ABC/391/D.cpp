#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, w; cin >> n >> w;
    vector<vector<pair<int,int>>> a(w + 1);

    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[x].emplace_back(y, i + 1);
    }

    vector<int> b(n + 1, 1e9 + 100);
    for(int i = 1; i <= w; i++) sort(a[i].rbegin(), a[i].rend());
    
    bool can = true;
    int mn = 0;
    while(can){
        for(int i = 1; i <= w; i++){
            if(a[i].size() == 0) can = false;
            else{
                mn = max(a[i].back().first, mn);
            }
        }
        if(!can) break;

        for(int i = 1; i <= w; i++){
            b[a[i].back().second] = mn;
            a[i].pop_back();
        }
        mn++;
    }

    int qq; cin >> qq;
    for(int i = 0; i < qq; i++){
        double t;
        int wi; cin >> t >> wi;
        t += 0.5;

        if(b[wi] < t) cout << "No\n";
        else cout << "Yes\n";
    }
}