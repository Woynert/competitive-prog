#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct node{
	vector<char> links;
	bool markP;
	bool markL;
};

/*node* create_node(){
	node n;
	node n
	return &n;
}*/

int main(){
	
	
	string line;
	
	char currn;
	node n;
	
	char L;
	char P;
	//char pos[2];
	
	// vars
	
	
	//node mynode;
	
	//nodes.insert(make_pair('A', mynode));
	//nodes['A'].markL = true;
	
	do{
		int inp = 0;
		map<char, node> nodes;
		
		inp = 0;
		
		cin >> line;
		
		if (line == "#"){
			cout << endl;
			break;
		}
		
		for (int i = 0; i <= line.length(); i++){
			
			//node newnode;
			char c = line[i];
			
			
			if (c == ':'){
				inp = 1;
				continue;
			}
			else if ((c == ';') || (c == '.')){
				inp = 0;
				
				// sort links
				//sort(nodes[currn].links.begin(), nodes[currn].links.end());
				
				/*for(int j=0;j<nodes[currn].links.size();j++){
					cout << currn << " " << nodes[currn].links[j];
				}
				cout << endl;*/
				
				if (c == '.')
					break;
				else
					continue;
			}
			
			
			
			switch(inp){
				case 0:
					currn = c;
					
					nodes.insert(make_pair(currn, (node){}));
					nodes[currn].markP = false;
					nodes[currn].markL = false;
					
					inp++;
					break;
					
				case 1:
					nodes[currn].links.push_back(c);
					// add if not exists
					if (nodes.find(c) == nodes.end()){
						nodes.insert(make_pair(c, (node){}));
						
						//if (nodes[c].links.find(currn) == nodes[c].links.end())
						nodes[c].links.push_back(currn);
					}
					else{
						if (find(nodes[c].links.begin(), nodes[c].links.end(), currn) == nodes[c].links.end())
							nodes[c].links.push_back(currn);
					}
					
					break;
					
			}
		}
		
		cin >> P;
		cin >> L;
		
		// iterations
		
		bool Ptrapped = false;
		bool Ltrapped = false;
		bool Lded = false;
		
		if (nodes.find(P) != nodes.end()){
			nodes.insert(make_pair(P, (node){}));
			nodes[P].markP = false;
			nodes[P].markL = false;
		}
		else
			Ptrapped = true;
		if (nodes.find(L) != nodes.end()){
			nodes.insert(make_pair(L, (node){}));
			nodes[L].markP = false;
			nodes[L].markL = false;
			
		}
		else
			Ltrapped = true;
			
		nodes[P].markP = true;
		nodes[L].markL = true;
		
		
		do{
			//cout << "START" << endl;
			if (P == L){
				cout << "Both annihilated in node " << P << " ";
				cout << endl;
				break;
			}
			
			// pask
			//cout << P << " link size " << nodes[P].links.size() << endl;

			bool wa = false;
			
			for (int i = 0; i < nodes[P].links.size(); i++){
				char ni = nodes[P].links[i];
				
				//cout << P << " i " << i << endl;
				
				// mover
				if (!nodes[ni].markL && !nodes[ni].markP){
					if (!wa){
						if (ni>P){
							nodes[ni].markP = true;
							P = ni;
							
							
							//cout << P << " i " << i << endl;
							break;
						}
					}
					else{
						nodes[ni].markP = true;
						P = ni;
						
						//cout << P << " i " << i << endl;
						break;
					}
					
					
				}
				
				
				if (i == nodes[P].links.size()-1){
					
					//cout<< " wa " << wa << endl;
					if (wa){
						Ptrapped = true;
						break;
					}
					
					wa = true;
					i = -1;
					//cout<< " newi " << nodes[P].links.size() << endl;
				}
			}
			
			// lisp
			
			wa = false;
			
			for (int i = nodes[L].links.size() -1; i >= 0; i--){
				char ni = nodes[L].links[i];
				
				// mover
				if (!wa){
					if (!nodes[ni].markL && ni<L){
						nodes[ni].markL = true;
						L = ni;
						
						if (nodes[ni].markP) Lded = true;
						
						break;
					}
				}
				else{
					if (!nodes[ni].markL){
						nodes[ni].markL = true;
						L = ni;
						
						if (nodes[ni].markP) Lded = true;
						
						//wa = false;
						break;
					}
				}
				if (i == 0){
					
					if (wa){
						Ltrapped = true;
						break;
					}
					
					wa = true;
					i = nodes[L].links.size();
					
				}
			}
			
			
			
			
			if (Ptrapped){
				cout << "Paskill trapped in node " << P << " ";
			}
			
			
			if (P == L){
				cout << "Both annihilated in node " << P << " ";
				cout << endl;
				break;
			}
			
			if (Ltrapped){
				cout << "Lisper trapped in node " << L << " ";
			}
			
			if (Lded){
				cout << "Lisper destroyed in node " << L << " ";
			}
			
			
			
			if (Ptrapped || Ltrapped || Lded ){
				cout << endl;
				break;
			}
			
			//break;
			
		}while(true);
		
	}while(true);
	
	//cout << nodes['A'].markL << endl;
	
	return 0;
}



/*
if either of them cant move they halt.
If they reach the same node simultaniously the die both.
lisper dies if enters an already visited node by paskill
Paskill forward
Lisper backwards
*/


