#include <stdio.h>
#include <conio.h>
void partition(int key, int List[], int lb, int ub);
void quicksort(int List[],int lb, int ub);
int main()
{
    //int List[] = {4,3,2,1,5,6};
    int List[] = {8,5,6,9,4,19,7,2};
    int len = sizeof(List) / sizeof(int);
    quicksort(List, 0, len - 1);
    printf("\nThe sorted list is......");
    for(int i = 0; i < len; i++)
    {
        printf("%d ",List[i]);
    }

    return 0;
}

void partition(int key, int List[], int lb, int ub)
{
    int i = lb;
    int j = ub;
    int temp;
    while (i <= j)
    {
        while (List[i] <= key)
        {
            i++;
        }
        while (List[j] > key)
        {
            j--;
        }
        printf("list[i] = %d, list[j] = %d\n",List[i],List[j]);
        if(i <= j)
        {
            temp = List[i];
            List[i] = List[j];
            List[j] = temp;
        }   
        //printf("The exchanged list[i] = %d, list[j] = %d\n",List[i],List[j]);
    }
    //printf("i' = %d, j' = %d\n",i,j);
    temp = List[j];
    List[j] = List[lb-1];
    List[lb-1] = temp;
    if(j > lb) quicksort(List,lb-1,j-1);
    if(j < ub) quicksort(List,j+1,ub);
    
}
void quicksort(int List[],int lb, int ub)
{
    int pivot = List[lb];
    lb++;
    partition(pivot,List,lb,ub);
}