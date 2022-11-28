#include <iostream>
#include <map>
#include <algorithm>
#include <string>

typedef long long int ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, int> par;
    int n, l;
    string s;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> l;
        cin >> s;

        map<string, int> parCou;
        for (int j = 0; j < s.length()-1; j++){
            string p1(1, s[j]);
            string p2(1, s[j+1]);
            string p;

            if (s[j] > s[j+1])
                p = p2 + p1;
            else
                p = p1 + p2;

            parCou[p] ++;
            cout << p << endl;
        }

       map<string, int>::iterator it;

        for(it = parCou.begin(); it != parCou.end(); it++){
            par[it->first] += it->second * l;
            //cout << it->first << " " << it->second << endl;
        }


    }

    map<string, int>::iterator it;
    for(it = par.begin(); it != par.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    // build
    string res;
    for(it = par.begin(); it != par.end(); it++){

        string p = it->first;

        if (it == par.begin())
            res = p;
        else{
            // share a char
            int share = 0;
            int
            cordl = -1,
            cordr = -1;
            int chardir = -1;

            for (int i = 0; i < res.length(); i++){
                for (int j = 0; j < 2; j++){
                    if (p[j] == res[i]){
                        share++;
                        if (cordl == -1){
                            cordl = i;
                            chardir = j;
                            break;
                        }
                        else if (p[j] != res[cordl]){
                            cordr = i;
                            break;
                        }
                    }
                }
            }


            if (share == 0){
                res += p;
            }
            else if (share == 1){
                // extraer dos pares
                // left
                if (cordl > 0){
                    string parext = res.substr(cordl-1, 2);
                    bool add = true;
                    // existe y es mayor
                    if (par.find(parext) != par.end()){
                        if (par[parext] > par[p]){
                            add = false;
                        }
                    }

                    if (add){

                    }
                }

            }
            else if (share == 2){
                // ya existen y estan pegadas
                if ((cordr - cordl) == 1)
                    continue;
            }


            cout << res << endl;
            cout <<  p << " - " << share << " - " << cordl << " : " << cordr << endl;
        }
        cout << it->first << " " << it->second << endl;

    }


	return 0;
}


