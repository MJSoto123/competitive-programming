#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;

    vector<string> a(n);
    vector<string> b(m);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    auto compare = [&](int x, int y){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(a[i + x][j + y] != b[i][j]) return false;
            }
        }
        return true;
    };

    for(int i = 0; i <= n - m; i++){
        for(int j = 0; j <= n - m; j++){
            if(compare(i, j)) {
                cout << i + 1 << " " << j + 1 << "\n";
                return 0;
            }
        }
    }
}