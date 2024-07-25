#include <iostream>
using namespace std;
template <typename T>
void myswap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
void rank1(T arr[], int len)
{
    for (int j = 0; j < len - 1; j++)
        for (int i = 0; i < len - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                myswap(arr[i + 1], arr[i]);
            }
        }
}

int main()
{
    char arr[] = "anvkjsdnvk";
    int len = sizeof(arr) / sizeof(char);
    rank1(arr, len);
    for (int i = 0; i < len; i++)
    {
        cout << arr[i];
    }
    return 0;
}