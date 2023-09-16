#include <iostream>
using namespace std;
float averageValue(int arr[],int size);
main()
{
    int arr[4]={3,4,5,6};
    averageValue(arr,4);
}
float averageValue(int arr[],int size);
{
    int sum;
    for(int x=0;x<size;x++ )
    {
        sum=sum+arr[x];
    }
    return sum/size;
}
