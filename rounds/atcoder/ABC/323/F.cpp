#include<bits/stdc++.h>
using namespace std;

bool mid(int l, int mid, int r){
    return (l <= mid && mid <= r) || (r <= mid && mid <= l);
}

void solve(){
    long long ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    
    long long ans = abs(ax - bx) + abs(ay - by) + abs(bx - cx) + abs(by - cy);

    if (bx == cx){
        
        if(ax == bx && mid(by, ay, cy)) ans += 2;
    } 
    else if (by == cy && ay == by && mid(bx, ax, cx)) ans += 2;
    else {
        // hori
        long long h = 2;
        int dh = cx - bx;
        int dh2 = bx - ax;
        if(dh * dh2 < 0) h++;
        if(dh * dh2 < 0 && mid()) 

        // vert
        long long v = 2;
        if (ax == bx && mid(by, ay, cy)) v += 2;

        ans = min(h, v);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}
