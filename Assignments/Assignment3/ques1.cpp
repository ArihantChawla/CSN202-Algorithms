/*
 *      CSN204 Assignment 3 Question 1
 *      AUTHOR - Arihant Chawla
 *      SID - 17103036
 *      Let S be a sequence of m integer pairs 〈(x 1  , y 1  ), (x 2  , y 2  ), . . . , (x m  , y m  ). Each of the values x i
 *		and y i  , for all 1  ≤  i  ≤  m, is an integer between 1 and n. A domino sequence is a subsequence 〈(x i1  ,
 *		y i1  ), (x i2  , y i2  ),. . . , (x it  , y it  )〉 such that 1  ≤  i 1  < i 2  < ∙ ∙ ∙ < i t   ≤  n and, for all 1  ≤  j < t, y ij  = x ij+1  .
 *		Note that it isn’t necessarily true that i j+1   = i j   + 1, that is, the elements of the domino sequence
 *		don’t have to be consecutive in S, but they have to appear in the right order.
 *		Example: For S = 〈(1, 3), (4, 2), (3, 5), (2, 3), (3, 8)〉, both 〈(1, 3), (3, 5)〉 and 〈(4, 2), (2,
 *		3), (3, 8)〉 are domino sequences.
 *		Use dynamic programming to find a longest domino sequence of S in O(n + m) time. Argue briefly
 *		that the running time of your algorithm is indeed O(n + m) and that its output is indeed a longest
 *		domino sequence of S.
 */
#include<iostream>
using namespace std;
int main()
{
	int m;
	cout<<"\n\n----------------------------------------------------\n\nThis is a program to find the largest domino\nsubsequence using dynamic programming.\n\n----------------------------------------------------\n\nEnter the number of pairs in the original sequence:  ";
	cin>>m;
	int x[m+1],y[m+1];
	cout<<"\n\n----------------------------------------------------\n\nEnter the pairs:"<<endl;
	for(int i=1;i<m+1;i++)
	cin>>x[i]>>y[i];
    int n=x[1];
	for(int i=1;i<m+1;i++)
	{
		if(x[i]>n)
		n=x[i];
	    else if(y[i]>n)
			n=y[i];
	}
	int memo[n+1];
	for(int i=1;i<n+1;i++)
	memo[i]=-1;
	int ans[m+1];
	for(int i=m;i>0;i--)
	{
		  int temp;
			if(memo[y[i]]<0)
			{  temp=1;
				ans[i]=1;
			}
			else
			{
				ans[i]=1+ans[memo[y[i]]];
				temp=1+ans[memo[y[i]]];
			}
			if(memo[x[i]]<0  || ans[memo[x[i]]]<=temp)
				memo[x[i]]=i;

	}
	n=ans[1];
	for(int i=1;i<m+1;i++)
		if(ans[i]>n)
			n=ans[i];
		int v=0;
	cout << "\n\n----------------------------------------------------\n\nThe longest domino subsequence is:  ";
	int count=0;
	for(int i=1;i<m+1;i++)
	{
		if(ans[i]==n&&v==0)
		{
			cout<< "(" << x[i]<<','<<y[i]<< ")  ";
			v=i;
			n--;
			count++;
		}
		else
		{
			if(ans[i]==n&&x[i]==y[v])
			{
				cout<< "(" << x[i]<<','<<y[i]<< ")  ";
				v=i;
				n--;
				count++;
			}
		}
	}
	cout << "\nThe length of the longest domino subsequence is: " << count <<"\n\n----------------------------------------------------\n\nThis is a program to find the largest domino\nsubsequence using dynamic programming.\n\n----------------------------------------------------\n\n";
}
