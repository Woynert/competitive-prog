#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool disfor(string a, string b, map<string, int> mp, int check){
	int d1 = 0;
	if (mp[a] >= mp[b]) {
		d1 = mp[a] - mp[b] ;
	}
	else if (mp[b] > mp[a]) {
		d1 = (mp[a]+12) - mp[b] ;
	}
	
	return (d1 == check);
}

string dis(string a, string b, map<string, int> mp, int check){
	// get 
	int d1, d2 = 0;
	if (mp[b] >= mp[a]) {
		d1 = mp[b] - mp[a] ;
		d2 = (mp[a]+12) - mp[b] ;
	}
	else if (mp[a] > mp[b]) {
		d2 = mp[a] - mp[b] ;
		d1 = (mp[b]+12) - mp[a] ;
	}
	
	if (d1 == check){
		return b;
	}
	if (d2 == check){
		return a;
	}
	return " ";
	
}

int main(){
	
	map<string, int> mp;
	string in[3];
	
	mp["C"] = 1;
	mp["C#"] = 2;
	mp["D"] = 3;
	mp["D#"] = 4;
	mp["E"] = 5;
	mp["F"] = 6;
	mp["F#"] = 7;
	mp["G"] = 8;
	mp["G#"] = 9;
	mp["A"] = 10;
	mp["B"] = 11;
	mp["H"] = 12;
	
	cin >> in[0] >> in[1] >> in[2];
	
	// major
	for (int i = 0; i <= 2; i++){
		string w = dis(in[(0+i)%3], in[(1+i)%3], mp, 4);
		if (w != " "){
			
			if (disfor(in[(2+i)%3], w, mp, 3)){
				cout << "major\n";
				return 0;
			}
		}
	}
		
	// minor
	for (int i = 0; i <= 2; i++){
		string w = dis(in[(0+i)%3], in[(1+i)%3], mp, 3);
		if (w != " "){
			
			if (disfor(in[(2+i)%3], w, mp, 4)){
				cout << "minor\n";
				return 0;
			}
		}
	}
	
	cout << "strange\n";
	return 0;
}

/*
deletes all the vowels,
inserts a character "." before each consonant,
replaces all uppercase consonants with corresponding lowercase ones. 
*/

