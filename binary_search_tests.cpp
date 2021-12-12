#include <bits/stdc++.h>

using namespace std;

void conquer(int arr[], int low, int mid, int high, int n)
{
    int i, j, k, bigarr[n];
    i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            bigarr[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            bigarr[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        bigarr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        bigarr[k] = arr[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = bigarr[i];
    }
}

void divide(int arr[], int low, int high, int n)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        divide(arr, low, mid, n);
        divide(arr, mid + 1, high, n);
        conquer(arr, low, mid, high, n);
    }
}

void writetofile(int arr[], int n)
{
    FILE *fp;
    fp = fopen("output.txt", "w");
    fprintf(fp, "%d\n", n);
    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d\n", arr[i]);
    }
    fclose(fp);
}

int main()
{
    int n;
    cout << "Enter the number of test inputs to be generated: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n + 1;
    }
    divide(arr, 0, n - 1, n);
    writetofile(arr, n);
    return 0;
}
