#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double grasshopper(int n) {
    if (n == 1) {
        return 0;
    }

    double ans;
    vector<double> a(n + 1, 100000000);
    a[1] = 0;
    ans = 1000000000;
    for (int i = 1; i < n; ++i) {
        a[i + 1] = min(a[i + 1], a[i] + abs(sin((double)i)));
        if (i * i >= n) {
            ans = min(ans, a[i] + (double)(i * i - i) * abs(sin((double)(i*i))));
        }
        else {
            a[i*i] = min(a[i*i], a[i] + (double)(i * i - i) * abs(sin((double)(i * i))));
        }
    }
    ans = min(ans, a[n]);
    return ans;
}

int main() {
    cout << grasshopper(20);

    return 0;
}
