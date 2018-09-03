/*
 *      CSN204 Assignment 1 Part 1
 *      AUTHOR - Arihant Chawla
 *      SID - 17103036
 *      BASE PROBLEM - A frog stands in front of a flight of n stairs. In one jump, the frog can cover one, two or three steps.
 *      In how many ways can the frog cross all the steps? Call it C(n).
 *      For example, if n = 4, then all the possibilities for the frog are (1,1,1,1), (1,1,2), (1,2,1), (1,3),
 *      (2,1,1), (2,2) and (3,1). Therefore, C(4) = 7.
 *      SUBPROBLEM 3 - Suppose you want to compute C(n,m) which stands for the number of ways the frog can cross n
 *      steps in exactly m jumps. Derive a recurrence relation for C(n,m), and write a recursive function for
 *      it. )
 */
#include<iostream>
using namespace std;
int no_of_ways(int n,int m);
int main()
{
    int n,m,temp;
    cout << "\n\n----------------------------------------------------\n\nThis is the third part of the problem\nin which a simple recursive approach\nis taken to solve the base problem in exactly m steps\n\n----------------------------------------------------\n\nEnter the number of stairs and the number of exact steps you want to achieve the crossing with:  ";
    again:
    cin >> n >> m;
    if(n<0||n>36)
    {
        cout << "Invalid input. The number of stairs can't be negative or greater than 36\n\n----------------------------------------------------\n\nPlease enter a valid number of stairs:  ";
        goto again;
    }
    cout << "The number of ways for the frog to cross the stairs is:  " << no_of_ways(n,m) << ".\nThe recurrance relation for this problem is: T(n,m) = T(n-1,m-1) + T(n-2,m-1) + T(n-3,m-1)\n\n----------------------------------------------------\n\nThis is the third part of the problem\nin which a simple recursive approach\nis taken to solve the base problem in exactly m steps\n\n----------------------------------------------------\n\n";
}
int no_of_ways(int n,int m)
{
    if(n<m||n>(3*m)||n==0)
        return 0;
    if(n==1&&m==1)
        return 1;
    if(n==2&&m==1)
        return 1;
    if(n==2&&m==2)
        return 1;
    if(n==3&&m==1)
        return 1;
    if(n==3&&m==2)
        return 2;
    if(n==3&&m==3)
        return 1;
    if(n==5&&m==2)
        return 3;
    return (no_of_ways(n-1,m-1)+no_of_ways(n-2,m-1)+no_of_ways(n-3,m-1));
}
