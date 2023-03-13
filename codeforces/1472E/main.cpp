#include <array>
#include <bits/stdc++.h>
#include <unordered_map>
#include <map>

using namespace std;

// deug util
#ifdef DEBUG
	#define deb(x) cerr << #x << " = " << x << endl
#else
	#define deb(x)
#endif

// useful
#define ll int
#define umap unordered_map
bool multi = true;

void solve(){
	ll n, wback, w, h, maxw = 0;
	cin >> n;
	
	//umap<ll, ll> min;
	//umap<ll, ll> min;
	umap<ll, array<int, 2>*> min;
	
	ll in[n][2];

	
	// get boxes
	for (ll i = 0; i < n; i++){
		
		cin >> w >> h;
		if (w < h){
			wback = w;
			w = h;
			h = wback;
		}
		in[i][0] = w;
		in[i][1] = h;

		if (w > maxw) maxw = w;
		
		deb(w);
		deb(h);
		
		// make array of min width / min height
		//if (min.find(w) == min.end()){
		if (min[w] == NULL){
			min[w] = new array<int,2>();
			(*min[w])[0] = h;
			(*min[w])[1] = i;
		}
		else if (h < (*min[w])[0]){
			(*min[w])[0] = h;
			(*min[w])[1] = i;
		}
	}
	//cout << 222 <<endl;
	//cout << 222 <<endl;

	bool lastexists = false;
	array<int, 2> last;
	for (ll i = 0; i <= maxw; i++){
		if (min[i] != NULL){
			last = (*min[i]);
			lastexists = true;
		}
		else if (lastexists){
			//cout << min[i] << endl;
			min[i] = &last;
			//cout << min[i] << endl;
		}
	}

	for (ll i = 0; i <= maxw; i++){
		if (min[i] != NULL)
		cout << i << " " << (*min[i])[0] << " " << (*min[i])[1] << endl;
	}

	//cout << "asn: ";
	//cout << "asn: ";
	
	// check
	bool found = false;
	for (ll i = 0; i < n; i++){
		found = false;
		w = in[i][0];
		h = in[i][1];
		
		for (ll j = w-1; j > 0; j--){
			//if (min.find(j) == min.end()) continue;
			if (min[j] == NULL) continue;
			if ((*min[j])[0] == 0) continue;
			if ((*min[j])[0] < h){
				deb((*min[j])[0]);
				deb(h);
				cout << (*min[j])[1]+1 << " ";
				found = true;
				break;
			}
		}
			
		if (found) continue;
		cout << "-1 ";
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	if (multi)cin>>t;
	while(t--)solve();
	return 0;
}
