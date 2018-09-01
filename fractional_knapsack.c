#include<stdio.h>
int n;
void swap_float(float*a,float*b);
void swap_int(int*a,int*b);
int partition(float arr[],int ind[],int low,int high);
void quickSort(float arr[],int ind[],int low,int high);
int main()
{
    float knapsack_weight;
    printf("Enter the weight of the knapsack: ");
    scanf("%f",&knapsack_weight);
    printf("Enter the number of articles: ");
    scanf("%d",&n);
    int ind[n];
    float profit[n],weight[n],p2w_ratio[n];
    for(int i=0;i<n;i++)
    {
        printf("\n");
        printf("Enter the profit of article %d : ",i+1);
        scanf("%f",&profit[i]);
        printf("Enter the weight of article %d : ",i+1);
        scanf("%f",&weight[i]);
        p2w_ratio[i]=profit[i]/weight[i];
        ind[i]=i;
    }
    quickSort(p2w_ratio,ind,0,n-1);
    float final_profit=0,remaining_weight=knapsack_weight;
    for(int i=0;i<n;i++)
    {
        if(remaining_weight>=weight[(ind[i])])
        {
            final_profit=final_profit+profit[(ind[i])];
            remaining_weight=remaining_weight-weight[(ind[i])];
        }
        else
        {
            final_profit=final_profit+(remaining_weight/weight[(ind[i])])*profit[(ind[i])];
            break;
        }
    }
    printf("\nThe final profit is %.f\n",final_profit);
}
void swap_float(float*a,float*b)
{
    float t =*a;
    *a=*b;
    *b=t;
}
void swap_int(int*a,int*b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partition (float arr[],int ind[],int low,int high)
{
    float pivot=arr[high];
    int i=(low - 1);
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap_float(&arr[i],&arr[j]);
            swap_int(&ind[i],&ind[j]);
        }
    }
    swap_float(&arr[i+1],&arr[high]);
    swap_int(&ind[i+1],&ind[high]);
    return (i+1);
}
void quickSort(float arr[],int ind[],int low,int high)
{
    if (low<high)
    {
        int pi = partition(arr,ind,low,high);
        quickSort(arr,ind,low,pi-1);
        quickSort(arr,ind,pi+1,high);
    }
}
