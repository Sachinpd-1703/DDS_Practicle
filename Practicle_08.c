// Implement binary search and interpolation search.
#include <stdio.h>

int binnary_Search(int arr[],int beg,int end,int target);
int Interpolation_Search(int arr[],int beg,int end,int target);

int main(){
    int  arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target;
    printf("Enter element to find : ");
    scanf("%d",&target);

    int res1 = binnary_Search(arr,0,size-1,target);
    int res2 = Interpolation_Search(arr,0,size-1,target);
    if(res1!=-1 || res2!=-1){
        printf("Searched by Binnary Search : Element(%d) Found at Position %d\n",target,res1);
        printf("Searched by Interpolation Search : Element(%d) Found at Position %d",target,res2);
    }else{
        printf("Element is not Found");
    }



return 0;
}

int binnary_Search(int arr[],int beg,int end,int target){
    while(end>=beg){
        int mid = (end+beg)/2;
        if(arr[mid]==target){
            return mid+1;
        }else if(arr[mid]<target){
            beg = mid+1;
        }else{
            end = mid-1;
        }
    }
    return -1;
}

int Interpolation_Search(int arr[],int beg,int end,int target){
    while(end>=beg){
        
        int pos = beg+((end-beg)*(target-arr[beg])/(arr[end]-arr[beg]));
        if(arr[pos]==target){
            return pos+1;
        }else if(arr[pos]<target){
            beg = pos+1;
        }else{
            end = pos-1;
        }
    }return -1;
}