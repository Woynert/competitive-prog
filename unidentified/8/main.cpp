#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> eratostenes(int n){
		
	vector<int> primos, final; 
	bool wrong = false; 
	
	for(int i=2; i<ceil(sqrt(n)); i++){
		
		wrong = false; 
		
		for(int j=0; j < primos.size(); j++){ 
			if(i % primos[j] == 0){
				wrong = true;
				break; 
			}; 
		}
		
		if(!wrong && find(primos.begin(), primos.end(), i) == primos.end()){
			primos.push_back(i);
		}; 
	}
	
	return primos;
	
}

int main(){
	
	int hconst, h, nminis, N; 
	
	do{
		cin >> hconst >> nminis; 
		if(hconst == 0) break;
		N = 1; 
		
		vector<int> primos = eratostenes(nminis);
		vector<int> divisores; 
		
		h = nminis;
		
		while(h > 1){ // Find divisors
			for(int pi = 0; pi < primos.size(); pi++){
				if(h % primos[pi] == 0){
					h /= primos[pi]; 					
					if(h != 1) divisores.push_back(h);
				}
			}
		} 
		
		for(int di = divisores.size() -1; di >= 0; di--){
			int bc, potencia, h, hsum;
			bc = potencia = 1; 
			hsum = hconst; 
			h = nminis;  
			
			
			while(h % divisores[di] == 0){
				h /= divisores[di];
			}
			
			if(h == 1){
				
				h = hconst;
				
				while(h > 1){ 
					h = (1.0 / (divisores[di] +1)) * h;
					hsum += h * pow(divisores[di], potencia);
					if(h != 1) bc += pow(divisores[di], potencia);				
					potencia++; 
				}
				
				cout << bc << " " << hsum << endl; 
				break; 
				
			}
			
		}
		
	}while(true);
	
	return 0;
}

