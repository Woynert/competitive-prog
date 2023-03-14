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
        
        // Socks types counter
        if(socks.find(type) == socks.end()) tsocks++; 

        if(fit == "any"){
            socks[type][2] = k;
        }else if(fit == "left"){
            socks[type][0] = k;
        }else {
            socks[type][1] = k;
        }
    }

    // Iterate each key and find the worst case
    map<string, array<int, 3>>::iterator it = socks.begin();
    int global_worst = 0; 
    int impossible_count = 0; 
    
    while(it != socks.end()){
        int left, right, any;
        string key = it -> first;
        left = it->second[0];
        right = it->second[1];
        any = it->second[2];

        int limited_any = min(1, any);
        int lr_max = max(left, right);
        int local_worst = max(limited_any, lr_max); // Local worst case
        global_worst += local_worst;  // Increment the global worst
        
        if((any <= 1) && (left == 0 || right == 0)) impossible_count++; 
		it++; 
	}
	
	
	impossible_count == tsocks ? cout << "impossible" : cout << global_worst + 1; 
	cout << endl; 
	
	// deb(tsocks); 
	// deb(global_worst); 
	// cout << global_worst << endl; 
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    if(multi)cin>>t;
    while(t--)solve();
    return 0;
}
