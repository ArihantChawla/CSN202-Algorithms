/*
 *      CSN204 Assignment 4 Part 2
 *      AUTHOR - Arihant Chawla
 *      SID - 17103036
 */
#include<iostream>
using namespace std;
static int count=0;
int n,p;
void merge(int a[],int index[],int start, int mid, int end);
void sort(int a[],int index[],int start,int end);
void reverse(int a[],int low,int high);
int waiting_time(int schedule[]);
int main()
{
    int wait=0;
    int total_time=0;
    cout << "\n\n----------------------------------------------------\n\nn =  ";
    cin >> n;
    cout << "p =  ";
    cin >> p;
    cout << "\nEnter customer times: \n\n";
    int t[n],lol[n];
    for(int i=0;i<n;i++)
    {
        cin >> t[i];
        lol[i]=i;
    }
    sort(t,lol,0,n-1);
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
            index[i][1]=lol[i];
            f[i]=t[i];
            count++;
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
        index[temp][schedule[temp][0]]=lol[count];
        count++;
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
    int end[p];
    for(int i=0;i<p;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(schedule[i][j]==0)
            {
                end[i]=j-1;
                break;
            }
        }
    }
    for(int i=0;i<p;i++)
    {
        reverse(schedule[i],1,end[i]);
        reverse(index[i],1,end[i]);
    }
    for(int i=0;i<p;i++)
    {
        cout << "Counter\t" << i << ":";
        for(int j=1;j<n+1;j++)
        {
            if(schedule[i][j]==0)
            {
                break;
            }
            cout << "\t" << index[i][j] << " (" << schedule[i][j] << ")";
        }
        cout << endl;
    }
    for(int i=0;i<p;i++)
    {
        wait =wait + waiting_time(schedule[i]);
    }
    cout << "Bank finishes at time " << total_time << endl;
    cout << "Total waiting time = " << wait << "\n\n----------------------------------------------------\n\n";
}










void merge(int a[],int index[],int start, int mid, int end)
{
    int i, j, k;
    int l1=mid-start+1;
    int l2=end-mid;
    int left[l1],right[l2],templ[l1],tempr[l2];
    for(i=0;i<l1;i++)
    {
        left[i]=a[start+i];
        templ[i]=index[start+i];
    }
    for(j=0;j<l2;j++)
    {
        right[j]=a[mid+1+j];
        tempr[j]=index[mid+1+j];
    }
    i=0;
    j=0;
    k=start;
    while(i<l1&&j<l2)
    {
        if(left[i]>=right[j])
        {
            a[k]=left[i];
            index[k]=templ[i];
            i++;
        }
        else
        {
            a[k]=right[j];
            index[k]=tempr[j];
            j++;
        }
        k++;
    }
    while(i<l1)
    {
        a[k]=left[i];
        index[k]=templ[i];
        i++;
        k++;
    }
    while(j<l2)
    {
        a[k]=right[j];
        index[k]=tempr[j];
        j++;
        k++;
    }
}
void sort(int a[],int index[],int start,int end)
{
    if (start<end)
    {
        int mid=start+(end-start)/2;
        sort(a,index,start,mid);
        sort(a,index,mid+1,end);
        merge(a,index,start,mid,end);
    }
}
void reverse(int a[], int low, int high)
{
    while (low<high)
    {
        int temp=a[low];
        a[low]=a[high];
        a[high]=temp;
        low++;
        high--;
    }
}
int waiting_time(int schedule[])
{
    int temp[n+1],wait=0;
        temp[1]=0;
        for(int j=2;j<n+1;j++)
        {
            if(schedule[j]==0)
            {
                break;
            }
            temp[j]=temp[j-1]+schedule[j-1];
            wait=wait+temp[j];
        }
    return wait;
}
