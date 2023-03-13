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
    while(true){

        multiset<vector<int>> ts;
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
            int time = 0;

            deb(i);
            deb(j);
            deb(time);

            // different speed
            if (dro[i][1] == dro[j][1])
                continue;

            time = ceil((float)(dro[i][0] - dro[j][0]) / (dro[j][1] - dro[i][1]));
            if (time <= 0) continue;
            finished = false;

            ts.insert({time, i, j});
            i = *it;
        }


        // iterate each item in the list
        for (multiset<vector<int>>::iterator it = ts.begin(); it != ts.end(); it++)
        {
            vector<int> v = *it;
            deb("collision");
            deb(v[0]);
            deb(v[1]);
            deb(v[2]);

            // check they still exists

            if (!(dro[v[1]][2] && dro[v[2]][2]))
                continue;
            
            // only bigger than 0
            if (v[0] <= 0)
                continue;

            dro[v[1]][2] = 0;
            dro[v[2]][2] = 0;

            // remove from list
            ld.remove(v[1]);
            ld.remove(v[2]);

            deb("removed");
        }

        if (finished) break;
    }

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