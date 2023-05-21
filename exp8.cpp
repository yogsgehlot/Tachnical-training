#include<bits/stdc++.h> 
using namespace std; 

void countSort(int arr[], int n, int k) 
{ 
    int count[k];
    for(int i=0;i<k;i++)
        count[i]=0;
    for(int i=0;i<n;i++)
        count[arr[i]]++;
        
    int index=0;
    for(int i=0;i<k;i++){
        for(int j=0;j<count[i];j++){
            arr[index]=i;
            index++;
        }
    }
} 
  
int main() 
{ 
    int arr[] = { 1,4,4,1,0,1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k=5;
    countSort(arr, n, k); 
   
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
        
    return 0; 
} 