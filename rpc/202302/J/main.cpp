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
	int n;
	cin >> n;
	
	bool first = true;
	bool vis[720] = {};
	
	int i, j, bk;
	
	// get input
	while(n--){
		cin >> j >> j;
		j += 360;
		j %= 360;
		//j += 360;
		
		if (first){
			i = j;
			
			first = false;
			continue;
		}
		
		
		// get min and max
		if ((i) > (j)){
			bk = i;
			i = j;
			j = bk;
		}
		
		int from, to;
		
		// 
		if ((j - i) < (360-j+i)){
		}
		else{
			bk = i;
			i = j;
			j = bk;
		}
		
		deb(i);
		deb(j);
		
		// fill visited
		cout << i << " " << j << " " << endl;
		for (int f = i; f <= j; f++){
			int s = i + (f-i);
			vis[(s % 360)*2] = true;
			
			cout << (s % 360)*2 << " ";
			if (f != j){
				vis[(s % 360)*2+1] = true;
				cout << (s % 360)*2+1 << " ";
			}
		}
		
		cout << endl;
		
		i = j;
	}
	
	// check everything is visited
	
	for (int i = 0; i < 720; i++){
		cout << vis[i] << " ";
		// cout << i << " " << vis[i] << " ";
		/*if (!vis[i]){
			cout << "no" << endl;
			return;
		}*/
	}
	cout << "yes" << endl;
	
	// iterate each
	
		// fill array
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    if(multi)cin>>t;
    while(t--)solve();
    return 0;
}
