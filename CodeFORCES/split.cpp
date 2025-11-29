#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> arr;
    vector<int> arr(t);

    for (int i = 0; i < t; i++)
    {
        vector<int> f;
        vector<int> k;
        vector<int> s;
        int n;
        cin >> n;
        for (int j = 0; j < n * 2; j++)
        {
            cin >> f[j];
        }
        for (int j = 0; j < n; j++)
        {
            k.push_back(f[j]);
        }
        for (int j = n; j < n * 2; j++)
        {
            s.push_back(f[j]);
        }
        sort(k.begin(), k.end());
        sort(s.begin(), s.end());

        int count1 = 0;
        int count2 = 0;
        int total = 0;
        for (int j = 1; j < n; j++)
        {
            if (k[j - 1] == k[j])
            {
                count1++;
            }
            else
            {
                if (count1 % 2 == 1)
                {
                    total += count1;
                }
                count1 = 0;
            }
            if (s[j - 1] == s[j])
            {
                count2++;
            }
            else
            {
                if (count2 % 2 == 1)
                {
                    total += count2;
                }
                count2 = 0;
            }
        }

        arr.push_back(total);
    }

    for (int x : arr)
    {
        cout << x << endl;
    }
}
