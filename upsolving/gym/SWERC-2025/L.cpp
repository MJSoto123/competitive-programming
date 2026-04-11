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

int v = 0;
ll x = 0, y = 0;

ll F(){
    v++;
    cout << "? F" << endl;
    ll d; cin >> d;
    return d;
}

ll L(){
    v++;
    cout << "? L" << endl;
    ll d; cin >> d;
    return d;
}

ll R(){
    v++;
    cout << "? R" << endl;
    ll d; cin >> d;
    return d;
}


ll mx = 1e6 + 100;
ll mn = -mx;

ll rotate(){
    F(); L(); L(); L();
    R(); L(); L(); L();
}

ll move4LEFT(){
    F(); R(); R(); R();
    R(); L(); L(); L();
    x -= 4;
}

ll move4UP(){
    L(); R(); R(); R();
    L(); L(); L(); L();
    y += 4;
}

ll move4DOWN(){
    
    y -= 4;
}

signed main(){
    int d1 = F();
    int d2 = 0;
    while(x < mx){
        d2 = F(); 
        x += v++;
    }

    int sm = v * (v - 1) / 2 - 1;
    int h = ((d2 + d1) - sm) / 2;

    
}