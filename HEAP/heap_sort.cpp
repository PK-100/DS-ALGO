/*Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.

Input:
First line of the input denotes number of test cases T. First line of the test case is the size of array and second line consists of array elements.

Output:
Sorted array in ascending order.

Expected Time Complexity: O(N * Log(N)).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= arr[i] <= 106

Example:
Input:
2
5
4 1 3 9 7
10
10 9 8 7 6 5 4 3 2 1

Output:
1 3 4 7 9
1 2 3 4 5 6 7 8 9 10
*/
#include <bits/stdc++.h>
using namespace std;
void swapp(int *a,int *b){
    int c=*a;
    *a=*b;
    *b=c;
}
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i);

void buildHeap(int arr[], int n);

// main function to do heap sort
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)
    {
        swapp(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
void heapify(int arr[], int n, int i)  {
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[largest]<arr[l])
        largest=l;
    if(r<n && arr[largest]<arr[r])
        largest=r;
        if(largest!=i){
            swapp(&arr[i],&arr[largest]);
            heapify(arr,n,largest);
        }
}
void buildHeap(int arr[], int n)  {
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    // Your Code Here
}

