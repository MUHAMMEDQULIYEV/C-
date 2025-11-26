#include <bits/stdc++.h>
#include <random>
using namespace std;
void sorting_alg(int);

int main()
{
    int a = 5;
    cout << "Hello world";
    sorting_alg(a);
    return 0;
}
void sorting_alg(int b)
{
    int A[5];
    for (int i = 0; i < b; i++)
    {
        A[i] = rand() % 10;
    }
    for (int i = 0; i < b; i++)
    {
        cout << A[i] << " ";
    }
}
