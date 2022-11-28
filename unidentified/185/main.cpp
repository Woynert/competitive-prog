#include <iostream>

using namespace std;

string hardstr = "";
bool endReached = false;

// ABAC ABCACBABCABAC ABCACBACABAC
//      ABCACBACABAC

bool isHard(string s){
	
	cout << "check this: " << s << endl; 
	
	bool hard = true; 
	
	for(int i=1; i<=s.length() / 2; i++){
		string s1, s2 = "";
		
		s1 = s.substr(s.length() - i, i);
		s2 = s.substr(s.length() - i * 2, i); 
		cout << endl; 
		cout << s1 << endl; 
		cout << s2 << endl;
		cout << endl; 
		
		if(s1 == s2) return false; 
	}
	
	//if (s.length() > 5)
	//	return false;
	
	return hard; 
	
}

void printSlicedStr(string s){
	for(int i=0; i<s.length(); i+=4){
		cout << s.substr(i, 4) << " ";
		if(i / 4 == 17) cout << endl; 
	}
	
	cout << endl; 
	cout << s.length() << endl; 
}


bool recCheck(string b, int d, int L){
	
	cout << "h  " << b << endl;
	
	bool found = false;
	
	if (d == 0){
		cout << "ch " << b << endl;
		hardstr = b;
		endReached = true;
		bool is = isHard(b);
		if (is){
			cout << "ggg" << endl;
		}
		
		return is;
			
	}
	
	for (int i = 0; i < L; i++){
		char c;
		c = 'A' + i;
		
		if (isHard(b)){
			hardstr = b;
			found = found || recCheck(b + c, d-1, L);
		}
			
		if (found) break;
	}
	
	return found;
}

int main(){
	
	bool allEasy;
	int n, L, back;
	string si; 

	do{
		hardstr = "";
		allEasy = true;
		back = 0;
		
		si = "A";
		cin >> n >> L; 
	
		if(n == 0) break; 
		
		//while (allEasy){
			
			
		
			for(int j=0; j<n; j++){
				cout << si << " - " << j << endl;
				
				allEasy = true;
				
				// charatcers
				for (int i = 0; i < L; i++){
					char c;
					c = 'A' + i;
					
					// check ishard
					
					
					//if(isHard(si + c)){		
					
					if (back > 0){
						cout << endl << si.substr(0, si.length() -back) << endl;	
						
						cout << " +-+- " << back << " " <<  si.length() << endl;
						if (recCheck(si.substr(0, si.length() -back), back+1, L)){
							//si += c;
							//cout << "ff" << hardstr << endl;
							si = hardstr;
							allEasy = false;
							cout << " ++ " << back << " " << si.length() << endl;
							//found = true;
							break; 
						}
						else if (back == si.length()-1){
							cout << " -- "  << endl;
						}
					}
					else{
						if (recCheck(si + c, back, L)){
							si += c;
							allEasy = false;
							break; 
						}
					}
					
					
				
					
					//cout << endl << si.substr(0, si.length() -back) << endl;
				}	
				
				if (allEasy){
					back++;
					cout << "Going back " << back << endl;
					
					if (back == si.length())
						break;
				}
			}
			
			
		//}
	
		if (endReached)
			printSlicedStr(si); 
		else
			printSlicedStr(hardstr); 
	
	}while(true);
	
    return 0;
}


