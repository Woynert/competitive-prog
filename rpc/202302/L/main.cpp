#include<bits/stdc++.h>
#include <cmath>
#include <math.h>
using namespace std;

// debug util
#ifdef DEBUG
    #define deb(x) cerr << #x << " = " << x << endl
#else
    #define deb(x)
#endif

// useful
#define ll long long
#define ld long double
#define umap unordered_map
bool multi = false;

void solve(){
    // get inputs
    ll n, pos, k;
    ld prob, expPos;
    cin >> n >> pos >> k;

    // case 1 keep the same position

    prob = (pos - 1) * ((ld)1 / n);
    prob = powl(prob, k);

    expPos = prob * pos;
    deb(expPos);

    // case 2 get shuffled

    for (ll i = pos; i <= n; i++)
    {
        prob = powl( (ld)i / n, k );
        prob -= powl( (ld)(i-1) / n, k );

        expPos += prob * ((ld)(i+1) / 2);

        deb(i);
        deb(expPos);
    }

    cout << fixed << setprecision(9) << expPos << endl;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    if(multi)cin>>t;
    while(t--)solve();
    return 0;
}
