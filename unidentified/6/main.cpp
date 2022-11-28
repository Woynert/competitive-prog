#include <iostream>

using namespace std;

bool isfr(int a, int b, int c, int d){
    if (a > c && b > d)
        return true;
    if (c > a && d > b)
        return true;
    return false;
}

int main(){

    bool finded = false;
    int n;
    int a, b;
    int x, y;

    while(cin >> n){
        if (n == 0) break;


        // get ropes
        int r[n][2];
        for (int i = 0; i < n *2; i++){
            if (i < n)
                cin >> r[i][0];
            else
                cin >> r[i -n][1];
        }

        a = r[0][0];
        b = r[0][1];
        x = r[0][0];
        y = r[0][1];

        // untangled

        int maxunt = 1;
        int maxtan = 1;

        for (int i = 0; i < n; i++){
            int tan = 1;
            int unt = 1;

            int ropes1 = 0;
            int u1[n][2];

            int ropes2 = 0;
            int u2[n][2];

            a = r[i][0];
            b = r[i][1];
            x = r[i][0];
            y = r[i][1];

            for (int j = 0; j < n; j++){
                if (i == j) continue;

                if (!isfr(x, y, r[j][0], r[j][1])){
                    bool sirve = true;
                    for (int k = 0; k < ropes2; k++){
                        if (isfr(r[j][0], r[j][1], u2[k][0], u2[k][1])){
                            sirve = false;
                            break;
                        }
                    }
                    if (sirve){
                        tan++;
                        u2[ropes2][0] = r[j][0];
                        u2[ropes2][1] = r[j][1];
                        ropes2++;
                    }
                }

                if (isfr(a, b, r[j][0], r[j][1])){
                    bool sirve = true;
                    for (int k = 0; k < ropes1; k++){
                        if (!isfr(r[j][0], r[j][1], u1[k][0], u1[k][1])){
                            sirve = false;
                            break;
                        }
                    }
                    if (sirve){
                        unt++;
                        u1[ropes1][0] = r[j][0];
                        u1[ropes1][1] = r[j][1];
                        ropes1++;
                    }
                }

            }
            if (unt > maxunt)
                maxunt = unt;
            if (tan > maxtan)
                maxtan = tan;
        }

        cout << maxunt << " " << maxtan << endl;

    }

    return 0;
}
