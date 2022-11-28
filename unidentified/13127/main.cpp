#include <iostream>
#include <string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int s;

    while (cin >> s){
        int r, b, p;

        int nod[s][s];

        for(int i = 0; i < s; i++){
            fill(nod[i], nod[i] + s, 100000000);
            nod[i][i] = 0;
        }

        cin >> r >> b >> p;
        int ban[b];
        int pol[p];

        // get roads

        for(int i = 0; i < r; i++){
            int ni,nf,t;
            cin >> ni >> nf >> t;
            nod[ni][nf] = t;
            nod[nf][ni] = t;

        }


        // floyd - warshall

        for(int k = 0; k < s; k++){
            for(int i = 0; i < s; i++){
                for(int j = i+1; j < s; j++){
                    if ((nod[i][j] > nod[i][k] + nod[k][j])){
                        nod[i][j] = nod[i][k] + nod[k][j];
                        nod[j][i] = nod[i][j];
                    }
                }
            }
        }

        /*for(int i = 0; i < s; i++){
            for(int j = 0; j < s; j++){
                    if (nod[i][j] == 100000000)
                    cout <<  "-1 ";
                else
                cout << nod[i][j] << " ";
            }
            cout << endl;
        }*/


        // get sites

        for (int i = 0; i < b; i++){
            cin >> ban[i];
        }
        for (int i = 0; i < p; i++){
            cin >> pol[i];

        }
        // iterar policias

        int bkpol[b];
        fill(bkpol, bkpol + b, -1);

        for (int i = 0; i < b; i++){

            for (int j = 0; j < p; j++){
                if (bkpol[i] == -1)
                    bkpol[i] = nod[ban[i]][pol[j]];
                else
                    bkpol[i] = min(bkpol[i], nod[ban[i]][pol[j]]);
            }
        }

        // get max
        string fartest = "";
        int nbanks = 0;
        int maxd = 0;

        for (int i = 0; i < b; i++){

            if (bkpol[i] > maxd){
                maxd = bkpol[i];
                nbanks = 1;
                fartest = to_string( ban[i] );
            }
            else if (bkpol[i] == maxd){
                nbanks++;
                fartest += " " + to_string( ban[i] );
            }
        }

        if (maxd == 100000000)
            cout << nbanks << " *" << endl;
        else
            cout << nbanks << " " << maxd << endl;
        cout << fartest << endl;


    }

	return 0;
}



