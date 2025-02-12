// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D

#include <bits/stdc++.h>

using namespace std;

int m, n;

bool good(int t) {
    
}

int main(int argc, char const *argv[])
{
    cin >> m >> n;

    vector<pair<int, pair<int, int>>> tzy(n);

    for (int i = 0; i < n; i++)
    {
        int t, z, y;
        cin >> t >> z >> y;
        tzy[i].first = t;
        tzy[i].second.first = z;
        tzy[i].second.second = y;
    }

    int l = 0, r = 1000;
    while ((l + 1) < r)
    {
        int mid = (r + l) / 2;
        if (good(mid))
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
