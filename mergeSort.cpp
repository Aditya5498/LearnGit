#include<iostream>
using namespace std;

// Merge sort uses 2 functions, 1 for dividing the array and other for merging 2 array's
// Read programiz tutorial on merge sort for further explanation

// merge function to sort and merge split array
// algorithm:
// take left, right and mid variables, create size of left and right sub arrays.
// copy the original data from the array and add it to left and right sub array.
// compare the 2 subarray and arrange the data in ascending order in the original array
void merge(int *arr,int left,int mid,int right){

    int const subArrayOne=mid-left+1, subArrayTwo=right-mid;

    int *leftArray=new int[subArrayOne], 
    *rightArray=new int[subArrayTwo];

    for(int i=0;i<subArrayOne;i++) leftArray[i]=arr[left+i];
    for(int i=0;i<subArrayTwo;i++) rightArray[i]=arr[mid+1+i];

    int idx1=0,idx2=0,idxMerge=left;

    while(idx1<subArrayOne && idx2<subArrayTwo){

        if(leftArray[idx1]<=rightArray[idx2]) {
            arr[idxMerge]=leftArray[idx1];
            idx1++;
            }

        else{
            arr[idxMerge]=rightArray[idx2];
            idx2++;
        }
        
        idxMerge++;
    }

    while (idx1<subArrayOne)
    {
        arr[idxMerge]=leftArray[idx1];
        idx1++;
        idxMerge++;
    }

    while (idx2<subArrayTwo)
    {
        arr[idxMerge]=rightArray[idx2];
        idx2++;
        idxMerge++;
    }
    
    delete[] leftArray;
    delete[] rightArray;

}

// merge sort - divide the array into 2 halves recursively
void mergeSort(int *arr,int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}

void print(int *arr,int size){
    for(int i=0;i<size;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
int arr[6]={16,5,4,3,2,-1};
cout<<"Input array\n";
print(arr,6);
mergeSort(arr,0,6);
cout<<"After merge sort\n";
print(arr,6);
}
