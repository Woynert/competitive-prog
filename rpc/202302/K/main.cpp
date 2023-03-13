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
    int n, k, tsocks = 0; cin >> n;
    string type, fit; 

    // [left, right, any]
    map<string, array<int, 3>> socks; 

    // Receive each group
    while(n--){
        cin >> type >> fit >> k;

        if(fit == "any"){
            socks[type][2] = k;
        }else if(fit == "left"){
            socks[type][0] = k;
        }else {
            socks[type][1] = k;
        }
    }

    // Iterate each key and find the worst case
    int gmin = -1;
    map<string, array<int, 3>>::iterator it = socks.begin();

    int worst = 0;

    while(it != socks.end()){
        int left, right, any;
        string key = it -> first;
        left = it->second[0];
        right = it->second[1];
        any = it->second[2];

        int limited_any = min(1, any);
        int lr_max = max(left, right);
        worst += max(limited_any, lr_max);

        // Continue iterating
        it++;
    }
    
    it = socks.begin();

    while(it != socks.end()){
        int left, right, any, lmax;
        string key = it->first;
        left = it->second[0];
        right = it->second[1];
        any = it->second[2];

        // deb(key);
        int limited_any = min(1, any);
        int lr_max = max(left, right);
        int lworst = max(limited_any, lr_max);
        // deb(lworst);

        gmin == -1 ? gmin = worst - lworst : gmin = max(gmin, worst - lworst);
        it++;

        // 🏳️
    }

    cout << gmin << endl;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    if(multi)cin>>t;
    while(t--)solve();
    return 0;
}