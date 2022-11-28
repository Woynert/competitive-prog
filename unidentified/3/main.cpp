#include <iostream>

using namespace std;

bool finished = false;
bool found = false;
int n, m;
int sta[2], fin[2];
int mapa[500][500];

void go(int x, int y, int seq[100], int d, int cis, int counter){

    if (found || finished) return;

    // check current pos
    if ((x+1 == fin[0]) && (y+1 == fin[1])){
        found = true;
        cout << counter << endl;

        return;
    }

    // add and check sequence index
    cis++;
    if (cis >= d)
        cis = 0;

    // move
    int dir;
    for (int i = 0; i < 2; i++){
        dir = -1 + (2*i);

        // x
        if (((x + dir) >= 0) && (y >= 0) && ((x + dir) < n) && (y < m)){
            if (mapa[x + dir][y] == seq[cis])
                go(x + dir, y, seq, d, cis, counter+1);
        }

        // y
        if ((x >= 0) && ((y + dir) >= 0) && (x < n) && ((y + dir) < m)){
            if (mapa[x][y + dir] == seq[cis])
                go(x, y + dir, seq, d, cis, counter+1);
        }
    }

    return;
}

int main(){

    int d;

    for (int i = 0; i < 500; i++){
        for (int j = 0; j < 500; j++){
            mapa[i][j] = -1;
        }
    }


    while(cin >> n){

        found = false;
        finished = true;


        if (n == 0) break;

        cin >> m >> sta[0] >> sta[1] >> fin[0] >> fin[1];
        cin >> d;

        // get sequence
        int seq[100];

        for (int i = 0; i < 100; i++){
            seq[i] = -1;
        }

        for (int i = 0; i < d; i++){
            int num;
            cin >> num;
            seq[i] = num;
        }

        // get map

        int color;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> color;
                mapa[i][j] = color;
            }
        }

        // agents
        finished = false;
        go(sta[0], sta[1], seq, d, 0, 0);

        if (!found){
            cout << "IMPOSSIBLE" << endl;
            found = true;
        }

        finished = true;
    }


    return 0;
}
