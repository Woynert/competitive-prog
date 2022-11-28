#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	int bp, res = -1, acc = 0; 
	int dp[7];
	
	cin >> bp; 
	
	for(int index = 0; index < 7; index++){
		cin >> dp[index];
		acc += dp[index]; 
		if(acc >= bp && res == -1) res = index + 1;
	}
	//cout << acc << endl; 
	
	if (res != -1) {
		cout << res << endl; 
	}else{
		// Iterate "again"
		int weeks = floor(bp / acc);
		int remaining = bp - (acc * weeks);
		
		if (remaining == 0)
			remaining = max(remaining, acc);
		
		//cout << remaining << endl; 
		
		for (int i = 0; i < 7; i++){
			remaining -= dp[i]; 
			
			if(remaining <= 0){
				res = i + 1; 
				break; 
			}
		}
		
		cout << res << endl; 
	}

	
	return 0;
}

