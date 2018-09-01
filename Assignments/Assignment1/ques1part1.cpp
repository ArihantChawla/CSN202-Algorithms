/*
 *      CSN204 Assignment 1 Part 1
 *      AUTHOR - Arihant Chawla
 *      SID - 17103036
 *      BASE PROBLEM - A frog stands in front of a flight of n stairs. In one jump, the frog can cover one, two or three steps.
 *      In how many ways can the frog cross all the steps? Call it C(n).
 *      For example, if n = 4, then all the possibilities for the frog are (1,1,1,1), (1,1,2), (1,2,1), (1,3),
 *      (2,1,1), (2,2) and (3,1). Therefore, C(4) = 7.
 *      SUBPROBLEM 1 - Frame a recurrence relation for C(n), and make a straightforward recursive implementation. (Write
 *      a recursive function.)
 */
#include<iostream>
using namespace std;
int no_of_ways(int n);
int main()
{
    int n,temp;
    cout << "\n\n----------------------------------------------------\n\nThis is the first part of the problem\nin which a simple recursive approach\nis taken to solve the base problem\n\n----------------------------------------------------\n\nEnter the number of stairs:  ";
    again:
    cin >> n;
    if(n<0||n>36)
    {
        cout << "Invalid input. The number of stairs can't be negative or greater than 36\n\n----------------------------------------------------\n\nPlease enter a valid number of stairs:  ";
        goto again;
    }
    cout << "The number of ways for the frog to cross the stairs is:  " << no_of_ways(n) << ".\nThe recurrance relation for this problem is: T(n) = T(n-1) + T(n-2) + T(n-3)\nSolving the recurrance relation, the time complexity of the problem using using this approach becomes Ѳ(n)=n^3\n\n----------------------------------------------------\n\nThis is the first part of the problem\nin which a simple recursive approach\nis taken to solve the base problem\n\n----------------------------------------------------\n\n";
}
int no_of_ways(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(n==3)
        return 4;
    return (no_of_ways(n-1)+no_of_ways(n-2)+no_of_ways(n-3));
}
