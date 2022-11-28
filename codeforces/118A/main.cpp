#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	string str;
	string fin = "";
	char vo[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
	
	cin >> str;
	
	
	
	// all lowercase
	for (int i = 0; i < str.length(); i++){
		
		
		if (find(vo, vo+6, tolower(str[i])) == vo+6){
			//cout << "b" <<  str[i] << endl;
			fin += '.';
			fin += tolower(str[i]);
		}
	}
	
	cout << fin << endl;
	
	
	return 0;
}

/*
deletes all the vowels,
inserts a character "." before each consonant,
replaces all uppercase consonants with corresponding lowercase ones. 
*/

