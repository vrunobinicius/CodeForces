// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
#include <bits/stdc++.h>

using namespace std;

int n, x, y;

bool good(int m)
{
    if (m < min(x, y))
        return false;

    m -= min(x, y);
    return ((m / x) + (m / y)) + 1 >= n;
}

int main(int argc, char const *argv[])
{

    cin >> n >> x >> y;

    int l = 0, r = 1;
    while (!good(r))
        r *= 2;

    while ((l + 1) < r)
    {
        int mid = (r + l) / 2;
        if (good(mid))
            r = mid;
        else
            l = mid;
    }

    cout << r << "\n";

    return 0;
}
