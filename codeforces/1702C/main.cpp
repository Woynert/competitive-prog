#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int rounds, n, k, s, start, end;
	
	cin >> rounds;
	
	while(rounds--){
		cin >> n >> k;
		
		//int asize = 2*(int)pow(10,5);
		//cout << asize;
		
		map<int, bool> si;
		map<int, int[2]> ss;
		
		// Receive stations
		for(int i=0; i<n; i++){
			cin >> s;
			
			if (!si[s]){
				ss[s][0] = i;
				ss[s][1] = i;
				si[s] = true;
			}
			else{ 
				ss[s][1] = i;
			}
			
			//cout << ss[s][0] << " " << ss[s][1] << endl; 
		}
		
		while(k--){
			cin >> start >> end; 
			
			if(ss.find(start) == ss.end() || ss.find(end) == ss.end()){
				cout << "NO" << endl;
			}else{
				int min_start_index = ss[start][0];
				int max_end_index = ss[end][1];
				//cout << min_start_index << " " << max_end_index << endl;
				if(max_end_index > min_start_index){
					cout << "YES" << endl;
				}else{
					cout << "NO" << endl;
				}
			}
			
		}
			
	}
	
	return 0;
}
