#include <iostream>

using namespace std;

int main(){

    int n, m, W;

    while (cin >> n){
        if (n == 0) break;

        cin >> m >> W;

        // get puntajes
        int equ[n];
        for (int i = 0; i < n; i++){
            int pun;
            cin >> pun;
            equ[i] = pun;
        }

        // get matchs
        int mat[m][2];

        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            mat[i][0] = a;
            mat[i][1] = b;
        }

        // do the matches
        for (int i = 0; i < m; i++){
            /*for (int i = 0; i < m; i++){
                cout << equ[i] << " ";
            }
            cout << endl;*/

            int A = mat[i][0];
            int B = mat[i][1];

            if (A == W)
                equ[W]++;
            else if (B == W)
                equ[W]++;
            else{
                if (equ[A] > equ[B])
                    equ[A]++;
                else
                    equ[B]++;
            }

        }

        /*for (int i = 0; i < m; i++){
            cout << equ[i] << " ";
        }
        cout << endl;*/

        bool win = true;
        for (int i = 0; i < n; i++){
            if (equ[i] > equ[W]){
               win = false;
               break;
            }
        }

        (win == true) ? cout << "YES" : cout << "NO";
        cout << endl;
    }

    return 0;
}


