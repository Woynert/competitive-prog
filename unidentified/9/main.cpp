#include <iostream>
#include <cmath>

#define fo(i,s,e) for(int i = s; i < e; i++)
#define type long long ll;

using namespace std;

int main(){

    int q;
    cin >> q;
    /*fo(i,0,100){
        cout << "1 ";
    }
    cout << endl;*/
    //for (int i = 0; i < q; i++){
    fo(i,0,q){


        int n, k, prom, promc, promf;
         prom = promc = promf = 0;

        int mina = pow(10,8), maxa = 0;

        cin >> n >> k;


        int as[n];
        //cout << n << k;

        //for (int j = 0; j < k; j++){
        fo(j,0,n){
            int a;
            cin >> as[j];

            // get bigger smaller
            mina = min(mina, as[j]);
            maxa = max(maxa, as[j]);

            prom += as[j];
        }

        //cout << mina << " " << maxa << endl;


        prom = floor((prom + 0.0)/n);

        promf = floor((prom + 0.0)/n);
        promc = ceil((prom + 0.0)/n);

        if((abs(maxa - promf) > k && abs(maxa - promc) > k) && (abs(mina - promf) > k && abs(mina - promc) > k)){

            cout << "here-1" << endl;
            continue;
        }



//        if ((maxa - mina) > k*2){
//            cout << "-1" << endl;
//            continue;
//        }

        //cout << endl;
        // from pron to up
        bool pass = false;
        int u = k;
        int uworked = 0;
        //while((prom + u) < k){

        while(true){
            //cout << (prom + u) << endl;
            //cout << mina << prom + u << endl;
            if (( abs(mina - (prom + u)) <= k ) &&
            ( abs(maxa - (prom + u)) <= k )){

                pass = true;
                uworked = u;
                break;
            }
            if (u < 0){
                //cout << "br "<< prom + u << endl;
                break;
            }
            u--;
        }

        if (pass)
            cout << prom + uworked << endl;
        else
            cout << "-1" << endl;

    }


	return 0;
}

