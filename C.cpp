#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::string;




class Abon {
public:
    string name;
    string number;
    long int dolg;

    void get_met() {
        cout << name << " " << number << " "<< dolg;
    }
};


bool sort(Abon a, Abon b) {
    if (a.dolg != b.dolg) {
        return a.dolg < b.dolg;
    }

}


int main() {
    int n, i;
    cin >> n;
    vector<Abon> sp(n);
    for (i = 0; i < n; ++i)
        cin >> sp[i].name >> sp[i].number >> sp[i].dolg;
   
    vector<Abon>dolg;

    for (int i = 0; i < n; ++i) {
        if (sp[i].dolg < 0) {
            dolg.push_back(sp[i]);
        }
    }

    sort(dolg.begin(), dolg.end(), sort);

    for (int i = 0; i < dolg.size(); i++) {
        dolg[i].get_met();
        cout << std::endl;
    
    }

}
