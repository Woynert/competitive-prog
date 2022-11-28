#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

int main(){
	
	int n;
	
	cin >> n;
	
	while (n--){
		vector<int> quest;
		map<char, int> maxs;
		map<char, int> mp;
		map<char, int> total;
		
		//int c = 0, u = 0;
		string str;
		bool done = true;

		cin >> maxs['0'] >> maxs['1'];
		cin >> str;
		
		mp['0'] = maxs['0'];
		mp['1'] = maxs['1'];
		//cout << str << endl;
		
		for (int i = 0; i < floor(str.length() / 2); i++){
			//cout << str[i];
			char f, l;
			f = str[i];
			l = str[str.length() -(i+1)];
			
			if ((l != '?') && (f != '?') && (l != f)){
				done = false; break;
			}
			else if ((l == '?') && (f == '?')){
				quest.push_back(i);
				continue;
			}
			
			total[f]++;
			total[l]++;
		}
		
		if ((str.length() % 2) != 0)
			total[str[floor(str.length() / 2)]]++;
		
		//cout << total['0'] << " : " << total['1'] << endl;
		
		for (int i = 0; i < floor(str.length() / 2); i++){
			char f, l;
			f = str[i];
			l = str[str.length() -(i+1)];
			if (l == '?'){
				if (f != '?')
					if ((mp[f] > 0) && (total[f]+1 <= maxs[f])) {
						str[str.length() -(i+1)] = f;
						mp[f]--;
						total[f]++;
					}
					else{
						done = false;break;
					}
			}
			else if (f == '?'){
				if (l != '?')
					if ((mp[l] > 0) && (total[l]+1 <= maxs[l])){
						str[i] = l;
						mp[l]--;
						total[l]++;
					}
					else{
						done = false;break;
					}
			}
		}
		
		//cout << endl  << "size " << quest.size() << endl;
		for (int i = 0; i < quest.size(); i++){
			int l;
			l = str.length() -(quest[i]+1);
			//
			if ((mp['0'] >= 2) && (total['0']+2 <= maxs['0'])){
				str[quest[i]] = '0';
				str[l] = '0';
				mp['0'] -= 2;
				total['0'] += 2;
			}
			else if ((mp['1'] >= 2) && (total['1']+2 <= maxs['1'])){
				str[quest[i]] = '1';
				str[l] = '1';
				mp['1'] -= 2;
				total['1'] += 2;
			}
			else{
				done = false;break;
			}
		}
		
		// impar
		
		if ((str.length() % 2) != 0){
			int mid = ceil(str.length() / 2);
			if (str[mid] == '?'){
			//cout << "\nim" << endl;
				if ((mp['0'] > 0) && (total['0']+1 <= maxs['0'])){
					str[mid] = '0';
					mp['0'] --;
					total['0']++;
				}
				else if ((mp['1'] > 0) && (total['1']+1 <= maxs['1'])){
					str[mid] = '1';
					mp['1'] --;
					total['1']++;
				}
			}
		}
		
		//cout << endl << total['1'] << " " << maxs['1'] << " " << total['0'] << " " << maxs['0'] << endl;
		
		if (done){
			if ((total['1'] == maxs['1']) && (total['0'] == maxs['0']))
				cout << str;
			else
				cout << "-1";
		}
		else
			cout << "-1";
		
		//cout << str;
		cout << endl;
	}
	
	return 0;
}

