#include <iostream>
#include <set>
using namespace std;
int main()
{
    std::set<char> a;
    a.insert('G');
    a.insert('F');
    a.insert('G');
    //for (auto& str : a) {
    for (set<char>::iterator it = a.begin(); it != a.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
    return 0;
}
