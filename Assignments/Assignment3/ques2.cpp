/*
 *      CSN204 Assignment 3 Question 2
 *      AUTHOR - Arihant Chawla
 *      SID - 17103036
 *      You are given a set X = {x1 , x2 , . . . , xn } of points on the real line. Your task is to design a
 *      greedy algorithm that finds a smallest set of intervals, each of length 2, that contains all the given
 *      points.
 */
#include<iostream>
using namespace std;
int main()
{
    cout << "\n\n----------------------------------------------------\n\nThis is a program to find the smallest set of intervals\neach of length 2, that contains all the given points\nusing greedy approach.\n\n----------------------------------------------------\n\nEnter the number of points on the number line:  ";
    int n;
    cin >> n;
    float a[n];
    cout << "\nEnter the points on the number line in increasing order : " << endl;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    float start=a[0];
    int count=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]>(start+2))
        {
            start=a[i];
            count++;
        }
    }
    cout << "\n\n----------------------------------------------------\n\nThe smallest number of intervals of size two that contain all the points are " << count << "\n\n----------------------------------------------------\n\nThis is a program to find the smallest set of intervals\neach of length 2, that contains all the given points\nusing greedy approach.\n\n----------------------------------------------------\n\n";
}
