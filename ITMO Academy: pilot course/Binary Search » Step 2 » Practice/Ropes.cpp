// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B
#include <bits/stdc++.h>

using namespace std;

int n, k;
double ropes[10'000];

bool f(double x)
{
    int result = 0;

    if (x == 0)
        return false;

    for (int i = 0; i < n; i++)
        result += floor(ropes[i] / x);

    return (result >= k);
}

int main(int argc, char const *argv[])
{

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> ropes[i];

    double r = 1e8, l = 0;
    for (int i = 0; i < 100; i++)
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

    cout << setprecision(20) << l << "\n";

    return 0;
}
