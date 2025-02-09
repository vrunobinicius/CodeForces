#include <bits/stdc++.h>

using namespace std;

int n, k;
double ropes[10'000];

bool f(int x)
{
    double result = 0;
    for (int i = 0; i < n; i++)
        result += (ropes[i] / x);

    return (result >= k);
}

int main(int argc, char const *argv[])
{

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> ropes[i];

    double r = 10'000, l = 0;
    while ((r - l) > 10e-6)
    {
        double mid = (l + r) / 2;
        if (f(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    cout << l << "\n";

    return 0;
}
