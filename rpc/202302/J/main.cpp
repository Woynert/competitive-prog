#include<bits/stdc++.h>
#include <iomanip>
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

	bool vis[720+1000] = {};

	int first, from, to;
	int start, end, bk;
	cin >> from >> from;
	first = from;

	for (int i = 0; i < n; i++){
		
		if (i < n-1)
			cin >> to >> to;
		// travel from the last to the first
		else
			to = first;

		// make [start] the smaller and [end] the bigger
		if (to > from){
			start = from;
			end = to;
		}
		else{
			start = to;
			end = from;
		}

		// get shortest route. Range [-180, 179]
		if (abs(start - end) > (360 - abs(start - end))){
			bk = start;
			start = end;
			end = bk;
		}

		deb(start);
		deb(end);

		// fill range as true (visited)
		int j = start;
		while(true){
			vis[1000 + j*2] = true;
			if (j != end)
				vis[1000 + j*2 +1] = true;
			else
				break;

			j++;
			if (j >= 180) j -= 360;
		}

		from = to;
	}

	// check all degrees are visited
	for (int i = 1000-180*2; i < 1000+180*2; i++){
		if (!vis[i]){
			cout << "no " << fixed << setprecision(1) << (double)(i-1000)/2 << endl;
			return;
		}
	}
	cout << "yes" << endl;
	
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    if(multi)cin>>t;
    while(t--)solve();
    return 0;
}
