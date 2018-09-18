/*
 *      CSN204 Assignment 4 Part 1
 *      AUTHOR - Arihant Chawla
 *      SID - 17103036
 */
#include<iostream>
using namespace std;
static int count=0;
int n,p;
int main()
{
    int wait=0;
    int total_time=0;
    cout << "\n\n----------------------------------------------------\n\nn =  ";
    cin >> n;
    cout << "p =  ";
    cin >> p;
    cout << "\nEnter customer times: \n\n";
    int t[n];
    for(int i=0;i<n;i++)
    {
        cin >> t[i];
    }
    int f[p];
    int index[p][n+1];                  //stores the index of element
    int schedule[p][n+1];
    for(int i=0;i<p;i++)                //initializtion of schedule array
    {
        if(n<p&&i>=n)
        {
            f[i]=0;
            schedule[i][1]=0;            //initializes the first p columns
            index[i][1]=0;
            schedule[i][0]=0;               //initializes the number of tasks scheduled at counter i
            index[i][0]=0;
        }
        else
        {
            schedule[i][0]=1;               //initializes the number of tasks scheduled at counter i
            index[i][0]=1;
            schedule[i][1]=t[i];            //initializes the first p columns
            index[i][1]=count++;
            f[i]=t[i];
        }
    }
    for(int i=0;i<p;i++)
    {
        for(int j=2;j<n+1;j++)
        {
            index[i][j]=0;
            schedule[i][j]=0;
        }
    }
    for(int k=p;k<n;k++)
    {
        int temp=0;
        int min=f[0];
        for(int i=1;i<p;i++)            //finding minimum finishing time
        {
            if(f[i]<min)
            {
                min=f[i];
                temp=i;
            }
        }
        total_time+=min;
        for(int i=0;i<p;i++)
        {
            if(i==temp)                 //updating the finishing times
                f[i]=t[count];
            else
                f[i]=f[i]-min;
        }
        schedule[temp][0]++;            //working
        index[temp][0]++;               //working
        schedule[temp][schedule[temp][0]]=t[count];
        index[temp][schedule[temp][0]]=count;
        count++;
        wait=wait+total_time;
    }
    int max=f[0],temp=0;
    for(int i=1;i<p;i++)            //finding minimum finishing time
    {
        if(f[i]>max)
        {
            max=f[i];
            temp=i;
        }
    }
    total_time+=max;
    cout << "\n\n----------------------------------------------------\n\n";
    for(int i=0;i<p;i++)
    {
        cout << "Counter\t" << i << ":";
        for(int j=1;j<n+1;j++)
        {
            if(schedule[i][j]==0)
                break;
            cout << "\t" << index[i][j] << " (" << schedule[i][j] << ")";
        }
        cout << endl;
    }
    cout << "Bank finishes at time " << total_time << endl;
    cout << "Total waiting time = " << wait << "\n\n----------------------------------------------------\n\n";
}
