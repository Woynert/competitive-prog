#include<bits/stdc++.h>
//#include <cctype>
//#include <cmath>
//#include <unordered_map>
using namespace std;

// debug utils
//#define DEBUG 1
#ifdef DEBUG
    #define deb(x) cerr << #x << " = " << x << endl
#else
    #define deb(x)
#endif

#define umap unordered_map
#define ll long long

bool multi=true;

//bool isupper(char c){ return (c - 'A') < 26; }
char change_case (char c) {
    if (isupper(c)) 
        return tolower(c); 
    else
        return toupper(c); 
}

void solve(){
    ll n, k;
    string s;
    cin >> n >> k >> s;

    ll cnt = 0;
    umap<char, ll> m;

    for(ll i = 0; i < n; i++){
        char c = s[i];

        m[c]++;

        if (m[change_case(c)]){
            cnt++;
            m[c]--;
            m[change_case(c)]--;
        }
    }

    deb(k);
    deb(cnt);

    for(umap<char,ll>::iterator it = m.begin(); it != m.end(); it++){
        deb(it->first);
        deb(it->second);
        if (!k) break;
        if (!it->second) continue;
        deb(it->first);
        //int q = min(k);
        ll q = min<ll>(k, floor((double)(it->second/2)));

        k -= q;
        cnt += q;
        m[it->first] -= q*2;
    }
    deb(k);
    deb(cnt);

    cout << cnt << endl;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    if(multi)cin>>t;
    while(t--)solve();
    return 0;
}
