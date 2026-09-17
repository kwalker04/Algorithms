/*
Implement the following catalan function f
f(n)=f(0)*f(n-1)+f(1)*f(n-2)+f(2)*f(n-3)+....+f(n-1)*f(0)
f(0)=1, f(1)=1
*/

#include <iostream>
#include <vector>
using namespace std;

int catalan(int n)
{
    vector<int> f;

    if ((n==0)||(n==1)) return 1;

    f.push_back(1); // f[0] = 1
    f.push_back(1); // f[1] = 1

    int s;
    for (int i=2; i<=n; i++) {
        s=0;
        for (int k=0; k<=i-1; k++)
            s = f[k] * f[i-1-k] + s;  // only change from dummy
        f.push_back(s);
    }
    return f[n];
}

int main() {
    int num;
    cout << "Please input a number: ";
    cin >> num;
    cout << "The number of legal sequences of "<< num << " pairs of parentheses is " << catalan(num);

    return 0;
}
