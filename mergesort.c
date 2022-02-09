#include <stdio.h>

void mergesort(int List[], int left, int right);
void merge(int List[], int left, int mid, int right);
int main()
{
    //int List[] = {3,4,6,2,1,5,8,7};
    int List[] = {4,3,2,1};
    int len = sizeof(List) / sizeof(int);
    int left = 0;
    int right = len - 1;
    mergesort(List,left,right);
    printf("The sorted list is : ");
    for(int i = 0; i < len; i++)
    {
        printf("%d ",List[i]);
    }
    return 0;
}

void mergesort(int List[], int left, int right)
{
    int mid;
    if(left < right)
    {
        mid = (left + right) / 2;
        mergesort(List,left,mid);
        mergesort(List,mid+1,right);
        merge(List,left,mid,right);
    }
}
void merge(int List[], int left, int mid, int right)
{
    int mergelist[20];
    int ptr1 = left;
    int ptr2 = mid + 1;
    int ptr3 = left;
    while(ptr1 <= mid && ptr2 <= right)
    {
        if(List[ptr1] <= List[ptr2])
        {
            mergelist[ptr3] = List[ptr1];
            ptr1++;
            ptr3++;
        }
        else
        {
            mergelist[ptr3] = List[ptr2];
            ptr2++;
            ptr3++;
        }
    }
    while (ptr1 <= mid)
    {
         mergelist[ptr3] = List[ptr1];
        ptr1++;
        ptr3++;
        
    }
    while (ptr2 <= right)
    {
        mergelist[ptr3] = List[ptr2];
        ptr2++;
        ptr3++;
    }
    
    for(int i = left; i < ptr3; i++)
    {
        List[i] = mergelist[i];
    }
    

}