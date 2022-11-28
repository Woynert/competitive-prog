#include <iostream>

using namespace std;

int dist(int a, int b, int c, int d){
	return abs(a - c) + abs(b - d);
}

int main(){
	
	int dx, dy, n, q, csx, csy, qi, cmax, pmax, cmaxxi, cmaxyi, it, ll;
	it = 1; 
	
	do{
		
		cin >> dx >> dy >> n >> q; 
		int res[q], css[n][2];
		
		if(dx == 0) break; 
		
		for(int i=0; i<n; i++){ //c shops
			cin >> csx >> csy;
			css[i][0] = csx;
			css[i][1] = csy;
		}
	
		cout << "Case " << it << ":" << endl; 
	
		for(int i=0; i<q; i++){ //Queries
			cin >> qi;
			pmax = 0;
			cmaxxi = cmaxyi = 1;
			
			for(int cpx=1; cpx<=n; cpx++){
				for(int cpy=1; cpy<=n; cpy++){
						
					cmax = 0;
					
					for(int csi = 0; csi<n; csi++){
						int d = dist(cpx, cpy, css[csi][0], css[csi][1]);
						if(d <= qi) cmax++;
					}
					
					if(cmax > pmax){					
						 pmax = cmax;
						 cmaxxi = cpx;
						 cmaxyi = cpy;
					}else if(cmax == pmax){
						
						if(cpy < cmaxyi){
							cmaxxi = cpx;
						 	cmaxyi = cpy;
						}else if(cpx < cmaxxi){
							cmaxxi = cpx;
						 	cmaxyi = cpy;
						}
						
					}
					
					// if(cpx == 3 && cpy == 4) cout << "B- " << cmax << endl; 
					
				}
			}
			res[i] = pmax;
			cout << pmax << " (" << cmaxxi << "," << cmaxyi << ")" << endl;
		}
		
		it++;
		
	}while(true);
	
    return 0;
}


