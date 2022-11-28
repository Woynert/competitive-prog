#include <iostream>
#include <cmath>

using namespace std;

int main(){

    bool finded = false;
    int n, a, b, c;

    while(cin >> n){

        finded = false;

        if(n == 0) break;

        for(int i=1; i<sqrt(n); i++){
            for(int j =i + 1; j<n; j++){

                if(i * j > n) break;

                for(int k = j +1; k<n; k++){
                    int ans = i * j + i * k + j * k;

                    if(ans > n) break;

                    //cout << ans << endl;

                    if(ans == n){
                        finded = true;
                        a = i;
                        b = j;
                        c = k;
                        break;
                    }
                }

                if(finded) break;
            }

            if(finded) break;

        }

        finded == true ? cout << a << " " << b << " " << c << endl : cout << "idoneal" << endl;

    }

    return 0;
}
