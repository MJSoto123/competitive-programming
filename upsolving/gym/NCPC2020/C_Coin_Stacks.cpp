#include <bits/stdc++.h>
#define all(x) x.begin() , x.end()
using namespace :: std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);

    for(int& i : a) cin >> i;
    priority_queue<pair<int, int>> Q;

    for(int i = 0; i < n; i++) if(a[i] > 0) Q.emplace(a[i] , i + 1);
    vector<pair<int , int>> ans;

    while(Q.size() > 1){
        auto ff = Q.top();
        Q.pop();
        auto ss = Q.top();
        Q.pop();
        
        auto ff = Q.top();
        Q.pop();
        auto ss = Q.top();
        Q.pop();
        ff.first -= 1;
        ss.first -= 1;
        ans.emplace_back(ff.second , ss.second);
        if(ss.first > 0) Q.emplace(ss);
        if(ff.first > 0) Q.emplace(ff); 
        if(ss.first > 0) 
            Q.emplace(ss);
        if(ff.first > 0)
            Q.emplace(ff); 
    }
    if(Q.size()){
        cout << "no\n";
        return 0;
    }
    cout << "yes\n";
    for(auto pp : ans)  cout << pp.first << " " << pp.second << endl;
}