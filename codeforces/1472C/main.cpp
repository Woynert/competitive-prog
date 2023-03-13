#include <iostream>
#include <queue>
#include <cmath>

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
	int n; cin >> n; 
	ll lmax = 0, gmax = 0;
	int ns[n]; 
	ll dp[n] = {}; 
	
	// receive
	for(int i=0; i < n; i++){
		cin >> ns[i]; 
	}
	
	// Create the dp arr
	queue<vector<ll>> queue; 
	int curri = 0; 

	// Iterate each index
	for(int i=0; i<n; i++){
		curri = i; 
		lmax = 0; 
		
		// Check arr bound
		while(curri < n){
			if(dp[curri] != 0){
				break; 
			}else{
				// Add to the queue
				vector<ll> currItem = {curri, ns[curri]}; 
				queue.push(currItem); 

				// Increase the local max
				lmax += ns[curri]; // Add to the local max
				deb(ns[curri]);
				deb(lmax); 
				
				// Increment the index
				curri += ns[curri]; 
			}
		}
		
		int prevNumber = 0; 
		
		// Calculate the local and max sum
		while(queue.size() != 0){
			//cout << "Deque" << endl; 
			vector<ll> el = queue.front(); 
			queue.pop(); 
			dp[el[0]] = lmax - prevNumber; 
			gmax = max(gmax, dp[el[0]]); 
			prevNumber = el[1]; 
		}
		
		// cout << endl; 
	}
	
	// Print the final dp array
	/*
	for(int i=0; i < n; i++){
		deb(dp[i]); 
	}*/
	
	cout << gmax << endl; 
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	if (multi)cin>>t;
	while(t--)solve();
	return 0;
}
