/*
 *      CSN204 Assignment 2 Question 2
 *      AUTHOR - Arihant Chawla
 *      SID - 17103036
 *      Let A be an array containing n numbers (positive and negative). Develop an algorithm that finds
 *      the two indices 1   i   j   n such that S ≤ ≤ ≤ ij := Σjk=i A[k] is maximized. For example, in the array A =
 *      [10, −12, 5, 7, −2, 4, −11], the sub­array A[3, 6] has the sum S3,6 = 5 + 7 − 2 + 4 = 14 and no
 *      other sub­array contains  elements that sum to a value greater than 14,  so  for this input the
 *      algorithm should output (3, 6). Write a efficient code for the above
 */
#include<iostream>
using namespace std;
int main()
{
    cout << "\n\n----------------------------------------------------\n\nThis is a program to find maximum sum of a subarray\n\n----------------------------------------------------\n\nEnter the size of array:  ";
    int n;
    cin >> n;
    int a[n],s[n][n];
    cout << "\nEnter the elements of the array: " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
/*
    for(int i=0;i<n;i++)
    {
        s[i][i]=a[i];
        int sum=s[i][i];
        for(int j=0;j<n;j++)
        {
            if(j>i)
            {
                sum=sum+a[j];
                s[i][j]=sum;
            }
            if(j<i)
            {
                s[i][j]=-99999;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<< s[i][j] << " ";
        }
        cout << "\n";
    }
*/
    int max=0,sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
        if(sum<0)
        {
            sum=0;
        }
        if(sum>max)
            max=sum;
    }
    cout << "\nThe maximum sum of a subarray is " << max << "." << endl;
    cout << "\n\n----------------------------------------------------\n\nThis is a program to find maximum sum of a subarray\n\n----------------------------------------------------\n\n";
}
