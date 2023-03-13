#include<bits/stdc++.h>
#include<cmath>
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
bool multi=false;

void solve(){
    ll area; cin >> area;
    double PI = M_PI;
    double rad = sqrt(area / PI);
    double diam = 2 * rad;
    double res = diam * PI; 
    cout << fixed << setprecision(9) << res << endl;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    if(multi)cin>>t;
    while(t--)solve();

    
    //deb(PI);

    return 0;
}