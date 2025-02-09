// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
#include <bits/stdc++.h>

using namespace std;

long long w, h, n;

bool f(long long x) { return ((x / w) * (x / h)) >= n; }

int main(int argc, char const *argv[])
{
    cin >> w >> h >> n;

    long long l = 0, r = 1;

    while (!f(r))
        r *= 2;

    while (l + 1 < r)
    {
        long long mid = (l + r) / 2;
        if (f(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    cout << r << "\n";

    return 0;
}
