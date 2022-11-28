#include <iostream>
#include <cmath>

typedef long long int ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*string txt;
    cin >> txt;
    cout << "Text is: " << txt << endl;*/

    int cases;
    int n;
    int done = false;

    cin >> cases;
    for (int i = 0; i < cases; i++){

        cin >> n;

        int a[n];
        int b[n];
        done = false;

        for (int j = 0; j < n; j++){

            cin >> a[j];

            if (done) continue;


            if (j == 0)
                b[0] = a[0];

            else{
                int sir = -1;
                int r1 = abs(b[j-1] + a[j]);

                if (a[j] == abs(r1 - b[j-1]))
                    sir = r1;

                int r2 = abs(b[j-1] - a[j]);

                if (a[j] == abs(r2 - b[j-1]) && (r1 != r2))
                    if (sir == -1)
                        sir = r2;
                    else
                        done = true;

                //cout << "a " << r1 << " " << r2 << endl;

                b[j] = sir;
            }
        }

        if (done)
            cout << -1;
        else
            for (int j = 0; j < n; j++){
                cout << b[j] << " ";
            }
        cout << endl;


    }

	return 0;
}


