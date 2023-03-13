#include<bits/stdc++.h>
using namespace std;

// debug util
#ifdef DEBUG
    #define deb(x) cerr << #x << " = " << x << endl
#else
    #define deb(x)
#endif

// useful
#define ll long long
#define umap unordered_map
bool multi = false;

void solve(){
    double n, k, d, s; cin >> n >> k >> d >> s;
    double res = ((d * n) - (k * s)) / (n - k);
    (res >= 0 && res <= 100) ?
     cout << fixed << setprecision(7) << res << endl : cout << "impossible" << endl;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    if(multi)cin>>t;
    while(t--)solve();
    return 0;
}