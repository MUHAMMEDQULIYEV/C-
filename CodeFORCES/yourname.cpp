#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{

  int a;
  cin >> a;
  string arr[a];
  int i = 0;
  int w = a;
  while (a > 0)
  {
    int l;
    cin >> l;
    string k, s;
    cin >> k;
    cin >> s;

    sort(k.begin(), k.end());
    sort(s.begin(), s.end());

    if (k == s)
    {
      arr[i] = "YES";
    }
    else
    {
      arr[i] = "NO";
    }
    i++;
    a--;
  }
  for (int j = 0; j < w; j++)
  {
    cout << arr[j] << endl;
  }
}