#include<bits/stdc++.h>
using namespace std;

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

    int n;
    cin >> n;

    //array<array<int,2>,n> dro = {};
    int dro[n][3];
    list<int> ld;

    // get input, add to list 
    for (int i = 0; i < n; i++){
        cin >> dro[i][0] >> dro[i][1];
        dro[i][2] = 1;
        ld.push_back(i);
    }

    // check each paur until there is no more positive numbers
    //while(true){

        multiset<vector<long double>> ts;
        bool finished = true;

        // save time to temporary list
        //for (int i = 0; i < n-1; i++){
        int i = -1;
        int j = -1;
        for (list<int>::iterator it = ld.begin(); it != ld.end(); it++){
            
            if (it == ld.begin()){
                j = *it;
                continue;
            }
            i = j;
            j = *it;
            long double time = 0;


            // different speed
            if (dro[i][1] == dro[j][1])
                continue;

            time = ((long double)(dro[i][0] - dro[j][0])) / (dro[j][1] - dro[i][1]);
            if (time <= 0) continue;
            finished = false;

            ts.insert({time, (long double)i, (long double)j});
            i = *it;
        }

		bool potentialCol = true;
		
		//while (potentialCol){
			//potentialCol = false;
			deb(1);
			// iterate each item in the list
			for (multiset<vector<long double>>::iterator it = ts.begin(); it != ts.end(); it++)
			{
				vector<long double> v = *it;
				deb("collision");
				int v1 = (int)v[1];
				int v2 = (int)v[2];
				deb(v[0]);
				deb(v[1]);
				deb(v[2]);

				// check they still exists

				if (!(dro[v1][2] && dro[v2][2])){
					finished = false;
					continue;
				}
				
				// only bigger than 0
				if (v[0] <= 0)
					continue;

				dro[v1][2] = 0;
				dro[v2][2] = 0;

				// remove from list
				ld.remove(v1);
				ld.remove(v2);
				deb("removed");
				
				// calculate time for new adjacente nodes
				v1--;
				v2++;
				if ((v1 >= 0) && (v2 < n)){
					it = ts.begin();
					
					// different speed
					if (dro[v1][1] == dro[v2][1])
						continue;

					long double time = ((long double)(dro[v1][0] - dro[v2][0])) / (dro[v2][1] - dro[v1][1]);
					if (time <= 0) continue;
					//finished = false;

					ts.insert({time, (long double)v1, (long double)v2});
					//potentialCol = true;
					
					
					//break;
				}
				

			}
		//}

        //if (finished) break;
    //}

    // print solution
    cout << ld.size() << endl;
    for (list<int>::iterator it = ld.begin(); it != ld.end(); it++){
        int i = *it;
        cout << i+1 << " ";
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    if(multi)cin>>t;
    while(t--)solve();
    return 0;
}
