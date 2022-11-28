#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int n;

    while(cin >> n){

        int compa = 0;
        if(n == 0) break;

        string pairs[n][3]; // 0 donor 1 recipient

        for(int i=0; i<n; i++){ //Receive pairs
            cin >> pairs[i][0];
            cin >> pairs[i][1];
            pairs[i][2] = "0";
            //cout <<  pairs[i][0] << " " <<  pairs[i][1] << endl;
        }

        for(int i=0; i<n; i++){ // Donor

            if(pairs[i][2] == "1") continue;

            for(int j=0; j<n; j++){ // Recipient

                if(pairs[j][2] == "1") continue;

                bool possible = true;
                int cges1 = 0, cges2 = 0;

                int mlen1 = min(pairs[i][0].length(), pairs[j][1].length());
                int mlen2 = min(pairs[i][1].length(), pairs[j][0].length());

                int maxcges1 = pairs[j][1].length() * 0.1;
                int maxcges2 = pairs[i][1].length() * 0.1;

                int resta1 = (int) pairs[i][0].length() - (int) pairs[j][1].length();
                int resta2 = (int) pairs[i][1].length() - (int) pairs[j][0].length();

                cges1 += abs(resta1);
                cges2 += abs(resta2);

                //cout << pairs[i][0] << " : " << pairs[i][1] << endl;
                //dcout << pairs[j][0] << " : " << pairs[j][1] << endl;

                for(int k=0; k<mlen1; k++){

                    if(i == j){
                        if(pairs[i][0][k] != pairs[j][1][k]) cges1++;

                        if(cges1 > maxcges1){
                            possible = false;
                            break;
                        }
                    }else{
                        if(pairs[i][0][k] != pairs[j][1][k]) cges1++;
                        if(pairs[i][1][k] != pairs[j][0][k]) cges2++;

                        if(cges1 > maxcges1 || cges2 > maxcges2){
                            possible = false;
                            break;
                        }

                    }

                }

                //cout << cges1 << " " << cges2 << endl;

                //cout << "Donante" << pairs[i][0].length() << endl;
                //cout << "Recive" << pairs[j][1].length() << endl;
                //cout << "abs val " << abs((int) pairs[i][0].length()) - ((int) pairs[j][1].length()) << endl;

                if(i == j){
                     if(cges1 > maxcges1){
                        possible = false;
                        //cout << pairs[i][i] << " " << cges << " : " << maxcges << " " << pairs[i][i] << endl;
                    }
                }else{
                    //cout << "Here " << endl;
                    if(cges1 > maxcges1 || cges2 > maxcges2)
                        possible = false;
                }

                if(possible){

                    if(i == j){
                        //cout << pairs[i][0] << " same line " << pairs[i][1] << endl;
                        pairs[i][2] = "1";
                        compa++;
                    }else{
                        //cout << pairs[i][0] << " diff line " << pairs[j][1] << endl;
                        //cout << pairs[i][1] << " diff line " << pairs[j][0] << endl;
                        pairs[i][2] = "1";
                        pairs[j][2] = "1";
                        compa += 2;
                    }

                    break;

                }

            }
        }

        cout << compa << endl;

    }

    return 0;
}
