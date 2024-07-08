//Implement Bubble sort, selection sort, Insertion sort, quick sort ,merge sort.
#include <stdio.h>

void printArray(int arr[],int size){
    printf("--Array = { ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("}\n");
}



void Selection_Sort(int arr[],int size){
    int i,j,min_idx,temp;
    for(i=0;i<size-1;i++){
        min_idx=i;
        for(j=1;j<size;j++){
            if(arr[min_idx]>arr[j]){
                min_idx=j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
void Bubble_Sort(int arr[],int size){
    int i,j,temp;
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
        
    }
}
void Insertion_Sort(int arr[],int size){
    int i,j,temp;
    for(i=1;i<size;i++){
        temp = arr[i];
        j=i-1;
        while(j>=0 && temp<=arr[j]){
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
}
int partition(int arr[],int Start,int end){
    int pivot = arr[end];
    int i=(Start - 1);
    for(int j=Start;j<=end;j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[end];
    arr[end] = temp;
    return (i+1);
}
void Quick_Sort(int arr[],int Start,int end){
    if(Start<end){
        int p = partition(arr,Start,end);
        Quick_Sort(arr,Start,p-1);
        Quick_Sort(arr,p+1,end);
    }
}

void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Merge_Sort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        Merge_Sort(arr, left, middle);
        Merge_Sort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}



int main(){
    int arr[]= {43, 17, 9, 28, 91, 56, 72, 34, 89, 2, 58, 13, 67, 75, 24};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Array before Sorying\n");
    printArray(arr,size);
    
    printf("\nArray After Sorying\n");
    printf("Selection sort  ");
    Selection_Sort(arr,size);
    printArray(arr,size);
    
    printf("Bubble sort  \t");
    Bubble_Sort(arr,size);
    printArray(arr,size);
    
    printf("Insertion sort  ");
    Insertion_Sort(arr,size);
    printArray(arr,size);
    
    printf("Quick sort  \t");
    Quick_Sort(arr,0,size-1);
    printArray(arr,size);
    
    printf("Merge sort  \t");
    Merge_Sort(arr,0,size-1);
    printArray(arr,size);
    

return 0;
}