#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    vector<int> arr(t);

    for (int i = 0; i < t; i++)
    {
        int n, y, r;
        cin >> n >> y >> r;

        if (r + y / 2 > n)
        {
            arr[i] = n;
        }
        else
        {
            arr[i] = r + y / 2;
        }
    }

    for (int x : arr)
    {
        cout << x << endl;
    }
}
