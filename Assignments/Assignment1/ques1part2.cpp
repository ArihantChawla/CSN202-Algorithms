/*
 *      CSN204 Assignment 1 Part 2
 *      AUTHOR - Arihant Chawla
 *      SID - 17103036
 *      BASE PROBLEM - A frog stands in front of a flight of n stairs. In one jump, the frog can cover one, two or three steps.
 *      In how many ways can the frog cross all the steps? Call it C(n).
 *      For example, if n = 4, then all the possibilities for the frog are (1,1,1,1), (1,1,2), (1,2,1), (1,3),
 *      (2,1,1), (2,2) and (3,1). Therefore, C(4) = 7.
 *      SUBPROBLEM 2 - Make an efficient (linear-time and constant-space in n) iterative implementation. (Write a nonrecursive
 *      function.)
 */
#include<iostream>
using namespace std;
int no_of_ways(int n);
int main()
{
    int n,temp,t1=1,t2=2,t3=4,x=0;
    cout << "\n\n----------------------------------------------------\n\nThis is the second part of the problem in which an\nefficient (linear-time and constant-space in n) iterative\nmethod is undertaken to solve the base problem\n\n----------------------------------------------------\n\nEnter the number of stairs:  ";
    again:
    cin >> n;
    if(n<0||n>36)
    {
        cout << "Invalid input. The number of stairs can't be negative or greater than 36\n\n----------------------------------------------------\n\nPlease enter a valid number of stairs:  ";
        goto again;
    }
    if(n==1)
        x=1;
    else if(n==2)
        x=2;
    else if(n==3)
        x=4;
    else
    {
        for(int i=3;i<n;i++)
        {
            x=t1+t2+t3;
            t1=t2;
            t2=t3;
            t3=x;
        }
    }
    cout << "The number of ways for the frog to cross the stairs is:  " << x << ".\n\n----------------------------------------------------\n\nThis is the second part of the problem in which an\nefficient (linear-time and constant-space in n) iterative\nmethod is undertaken to solve the base problem\n\n----------------------------------------------------\n\n";
}
