/*
 *      CSN204 Assignment 2 Question 2
 *      AUTHOR - Arihant Chawla
 *      SID - 17103036
 *      An array A[1 . . 2n + 1] is wiggly if A[1] <= A[2] >= A[3] <= A[4] >= . . . <= A[2n] >=
 *      A[2n + 1]. Given an unsorted array B[1 . . 2n + 1] of real numbers, write an efficient code that
 *      outputs a permutation A[1 . . 2n + 1] of B such that A is a wiggly array.
 */
#include<iostream>
using namespace std;
void swap(int* a, int* b);
int main()
{
    cout << "\n\n----------------------------------------------------\n\nThis is a program to convert an unsorted array wiggly\n\n----------------------------------------------------\n\nEnter the value of n(will create an array of 2n+1 elements):  ";
    int n;
    cin >> n;
    int a[2*n+1];
    cout << "Enter the elements of the array: " << endl;
    for(int i=0;i<(2*n+1);i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<(2*n-1);i++)
    {
        if((i%2==0)&&(a[i]>a[i+1]))
            swap(a[i],a[i+1]);
        if((i%2==1)&&(a[i]<a[i+1]))
            swap(a[i],a[i+1]);
    }
    cout << "\n\n----------------------------------------------------\n\nThe \"wiggly\" array is: \n" << endl;
    for(int i=0;i<(2*n+1);i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n\n----------------------------------------------------\n\nThis is a program to convert an unsorted array wiggly\n\n----------------------------------------------------\n\n";
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
