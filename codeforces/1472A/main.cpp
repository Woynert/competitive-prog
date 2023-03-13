#include <bits/stdc++.h>

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
bool multi = true;

void solve(){
	int w, h, n; 
	cin >> w >> h >> n; 
	int pw = 1, ph = 1; 
	int wc = 0, hc = 0; 
	
	while(w % 2 == 0){
		pw += pow(2, wc); 
		w = floor(w / 2);
		wc++; 
	}
	
	while(h % 2 == 0){
		ph += pow(2, hc); 
		h = floor(h / 2);
		hc++; 
	}
	
	deb(pw); 
	deb(ph); 
	int mp = pw * ph; 
	mp >= n ? cout << "YES" : cout << "NO"; 
	cout << endl; 
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	if (multi)cin>>t;
	while(t--)solve();
	return 0;
}
