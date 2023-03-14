#include<bits/stdc++.h>
#include <list>
#include <iterator>
using namespace std;
#include <iostream>

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
	int n, cn, mind = -1, minn; cin >> n;
	list<int> cl;
	int ds[n]; 
	
	for(int i=0; i<n; i++){
		cin >> cn; 
		cl.push_back(cn);
	}

	// 1. fill the distances arr
	list<int>::iterator bit, ait, startPnt, it = cl.begin(); 
	int db, da, index = 0; 
	
	while(it != cl.end()){
		// Find the distances to the next and before elemnet
		bit = ait = it; 
		it == --cl.end() ? ait = cl.begin() : ++ait; 
		it == cl.begin() ? bit = --cl.end() : --bit;
		db = abs(*it - *bit);
		da = abs(*it - *ait);
		
		// Take the min one
		ds[index] = min(db, da);  
		
		// If the globals were not initialized yet
		if(mind == -1){
			mind = ds[index]; 
			minn = *it; 
			startPnt = it; 
		}
		// If an equal distance was foumd
		else if(ds[index] == mind){
			if(minn > *it){
				startPnt = it; 
				minn = *it; 
			} 
		}
		// If a new min distance was found
		else if(ds[index] < mind){
			mind = ds[index]; 
			minn = *it; 
			startPnt = it; 
		}
		
		// Iterate
		index++; 
		it++; 
	}
	
	// deb(mind); 
	// deb(minn); 

	// 2. Eat
	int clvl = minn * 2;
	int minlvl = minn;  
	int needs = 0; 
	
	it = startPnt; // Initialize the current iterator
	
	while(cl.size() != 1){
		// Find the lowest distance to the ngbrs
		bit = it; 
		ait = it; 
		it == --cl.end() ? ait = cl.begin() : ++ait; 
		it == cl.begin() ? bit = --cl.end() : --bit;
		
		deb(*bit);
		deb(*it);
		deb(*ait);
		
		int d1 = clvl - *bit; 
		int d2 = clvl - *ait;
		
		deb(clvl);  
		deb(d1);
		deb(d2); 
		
		if(d1 > d2){
			// Go to the left
			needs = clvl >= *bit ? 0 : abs(d1); 
			clvl += *bit; 
			cl.erase(bit); 
		}else{
			// Go to the right
			needs = clvl >= *ait ? 0 : abs(d2);
			clvl += *ait; 
			cl.erase(ait); 
		}		
		
		deb(needs); 
		minlvl += needs;
		clvl += needs; 
	}
	
	cout << minlvl << endl; 
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    if(multi)cin>>t;
    while(t--)solve();
    return 0;
}
