#include<bits/stdc++.h>
using namespace std;

int Min_diff(int arr[], int n, int k)
{
  if(n<=1)
    return 0;
    
  sort(arr,arr+n);
  int max = arr[n-1];
  int min = arr[0];
  
  if((max-min)<=k)
    return (max-min);
  
  arr[n-1] = arr[n-1] - k;
  arr[0] = arr[0] + k;
  int new_max = max(arr[n-1],arr[0]);
  int new_min = min(arr[n-1],arr[0]);
  for(int i = 1;i<n-1;i++)
  {
    if(arr[i] < new_min)
      arr[i] = arr[i] - k;
    elif(arr[i] > new_max)
      arr[i] = arr[i] + k;
    elif ((arr[i] - new_min) > (new_max - arr[i]))
      arr[i] = arr[i] - k;
     else
      arr[i] = arr[i] + k;
      
    new_max = max(arr[i],new_max);
    new_min = min(arr[i],new_min);
  }
   return (new_max - new_min);  
   
}

int main()
{
  int arr[] = {3,5,32,6};
  int n = (sizeof(arr))/(sizeof(arr[0]);
  int k = 3;
  cout << "Minimum diff between heights is " << Min_diff(arr,n,k) << endl;
}
