#include <bits/stdc++.h>
//#include <unordered_map>
#define map unordered_map

using namespace std;

map<char, int> cal(string str){
    map<char,int> mp;
    char c;

    for (int i = 0; i < str.size(); i++){
        c = str[i];

        mp[c]++;
        //if (mp.find(c) != mp.end()) {
        //} else {
            ////mp.insert(make_pair(c, 1));
            //mp[c] = 1;
        //}
    }

    return mp;
}

bool checkBothMaps(map<char, int> map1, map<char, int> map2){
    map<char,int> mp;
    char c;

    mp.insert(map1.begin(), map1.end());
    mp.insert(map2.begin(), map2.end());

    if ((mp.size()) != 25)
        return false;

    // check is not odd
    int c1;
    int c2;

    for (map<char,int>::iterator it = mp.begin(); it != mp.end(); it++){
        c = it->first;

        //if (map1.find(c) != map1.end()) {
            //c1 = map1[c];
        //} else {
            //c1 = 0;
        //}

        //if (map2.find(c) != map2.end()) {
            //c2 = map2[c];
        //} else {
            //c2 = 0;
        //}

        if ((map1[c] + map2[c]) % 2 == 0){
            //cout << c << " " << (c1 + c2) << endl;
            return false;
        }
    }

    return true;
}

int main() {

    int n, cnt = 0, nigh = 0;
    string curstr, constr;

    cin >> n;
    string str[n];
    map<char,int> arrmp[n];

    while (n--){

        // save string
        cin >> str[cnt];
        curstr = str[cnt];
        arrmp[cnt] = cal(curstr);

        // iterate through previous ones
        for (int i = 0; i <= cnt; i++){

            // concatenate
            //constr = curstr + str[i];

            // is not odd
            if ((curstr.size() + str[i].size()) % 2 == 0)
                continue;

            // ocurrences of each letter is odd
            if (!checkBothMaps(arrmp[cnt], arrmp[i]))
                continue;
            nigh ++;
        }
        cnt++;
    }

    cout << nigh << endl;
}
