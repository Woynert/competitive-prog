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
	int n;
	cin >> n;
	
	
	int p1 = 0, p2 = 0;
	int c1 = 0, c2 = 0;
	
	// count ns
	while(n--){
		int p;
		cin >> p;
		if (p == 1)
			c1++;
		else
			c2++;
	}
	deb(c1);
	deb(c2);
	
	if ((c2 % 2 == 0) && (c1 % 2 == 0)){
		cout << "YES" << endl;
		return;
	}
	if ((c2 % 2 != 0) && (c1 % 2 == 0) && (c1 != 0)){
			cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
	return;
	

	deb(p1);
	deb(p2);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	if (multi)cin>>t;
	while(t--)solve();
	return 0;
}
