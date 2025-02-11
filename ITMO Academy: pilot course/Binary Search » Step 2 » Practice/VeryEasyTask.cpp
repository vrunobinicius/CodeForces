// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
#include <bits/stdc++.h>

using namespace std;

int n, x, y;

bool f(int m) { return (m <= (x + y)) ? true : false; }

int main(int argc, char const *argv[])
{

    cin >> n >> x >> y;

    int l = 1, r = n;
    while ((l + 1) < r)
    {
        int mid = (r + l) / 2;
        if (f(mid))
            l = mid;
        else
            r = mid;
    }

    cout << r << "\n";

    return 0;
}
