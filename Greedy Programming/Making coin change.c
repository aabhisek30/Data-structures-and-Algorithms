#include<stdio.h>
#include<conio.h>
// This function decides to choose type of coins and its count
void choose_coin(int a[],int amount,int size); 
// This function sort the coin denominations
void sort(int a[],int n);
// This function returns position of max element
int max(int a[],int n);
int main()
{
  int size,amount;
  printf("enter the number of type of coin available");
  scanf("%d",&size);
  int a[size],i;
  printf("enter type of coin order");
  for(i=0;i<size;i++)
  {
      scanf("%d",&a[i]);
  }
  printf("Enter the amount of currency required");
  scanf("%d",&amount);
  for(i=0;i<size;i++)
  {
      printf("%d\t",a[i]);
  }
  printf("\n");
  printf("amount required is %d\t",amount);
  printf("\n");
  // This function is called to sort the coin denominations
  sort(a,size);
  // this function choose_coin and its count
  choose_coin(a,amount,size);
}
void choose_coin(int a[],int amount,int size)
{
    int i,count=0;
    int flag=1;
    int sol[size];
    for(i=0;i<size;i++)
    {
        // intalizing the array of solution to zero
        sol[i]=0;
    }
    // while loop continues till amount become zero
    while(amount!=0)
    { 
        //this coin run for getting correct coin type
        for(i=0;i<size;i++)
        {
            if(amount>=a[i])
            {
            amount=amount-a[i];
            sol[i]+=1;
            count++;
            break;
            }
        }
        if((a[size-1]>amount) && (amount!=0))
        {
            printf("no sol exist");
            flag = 0; // if no solution than it flag =0 to avoid printing of partial result
            break;
        }
    }
    for(i=0;i<size;i++)
    {
        if((sol[i]>0) && (flag!=0))
        {
            printf("coin %d-%d\t",a[i],sol[i]);
        }
    }
    if(flag!=0)
    {
        printf("min no of coins required is %d",count);
    }
}
void sort(int a[],int n)
{
    // this function sort array by selection sort
    for(int i=0;i<n;i++)
    {
        int x,temp=0;
        x = max(&a[i],n-i);
        temp = a[x+i];
        a[x+i] = a[i];
        a[i] = temp;
    }
}
int max(int a[],int n)
{
    // this function returns index of the max element
    int maxpos = 0;
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]>a[maxpos])
        {
            maxpos = i;
        }
    }
    return maxpos;
}

