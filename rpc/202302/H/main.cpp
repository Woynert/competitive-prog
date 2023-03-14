#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define PII pair<int, int>
#define int unsigned long long
#define all(x) x.begin, x.end
#define mem(a, b) memset(a, b, sizeof a)

// debug util
#ifdef DEBUG
    #define deb(x) cerr << #x << " = " << x << endl
#else
    #define deb(x)
#endif

const int INF = 1e13 + 5;
const int N = 1e6 + 5;
int n;
int a[N];

// mid: The current mid point of the binary search
// To check if the value works as tolerance level.
bool check(int mid){
  // The pair stores: {spiciness, plus value}
  vector<PII> v;
  int tol = mid;

  // Check the entire array
  for(int i=1; i <= n; i++){
    deb(a[i]);

    if(a[i] <= tol){
      // IF [CAN EAT]
      // cout << "CAN EAT" << endl;

      // Add the spiciness of the pizza to the
      // current tolerance
      tol += a[i];
      deb(tol);

      while(v.size() && v.back().fi <= tol){
        deb(v.back().fi);
        deb(v.back().se);
        // cout << "EATING..." << endl;
        // Try to eat the next pizza slice
        tol += v.back().se;
        deb(tol);
        // Remove the pizza slice from the vector of pairs
        v.pop_back();
      }
    }else{
      // IF [CANNOT EAT]
      // cout << "CANNOT EAT" << endl;

      v.pb({a[i], tol - mid + a[i]});
      tol = mid;
    }
  }

  return !v.size();
}

signed main(){
  // Receive the number of pizza slices
  cin >> n;

  for(int i=1; i <= n; i++){
    // This creates a circular list:
    // eg. [null, 10, 20, 15, 1, 10, 20, 15, 1]
    // For some reason, this person doesn't use the
    // index 0 as the first position of the array.
    cin >> a[i], a[i + n] = a[i];
  }


  // This is equivalent to n *= 2;
  n <<= 1;


  // Use binary search to find the initial tolerance
  // Initially, the left index is the begining of the array
  // and the right index is the lenfth of the array.
  int l = 0, r = INF;

  // This while loop is to check multiple tolerances until found
  // the lessest one that works
  while(l < r){
    // Find the mid point (as in every binary search algorithm)
    // r >> 1 is equivalent to floor(r / 2);
    int mid = l + r >> 1;
    deb(mid);

    if(check(mid)){
      // If the tolerance works, move the right index to the mid of the
      // array (FIND A LESSER VALUE).
      // cout << mid << " works" << endl;
      r = mid;
    }
    else {
      // If the tolerance doesn't works, move the left index to the mid
      // of the array. (FIND A HIGHTER VALUE)
      // cout << mid << " doesn't works" << endl;
      l = mid + 1;
    }
  }

  // They converge
  //deb(l);
  //deb(r);

  // Finally, print the lessest tolerance that works.
  cout << l << endl;
}
