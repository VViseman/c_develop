#include <stdio.h>

#define NUM_ITEMS 10

void quickSort(int numbers[], int array_size);
void q_sort(int numbers[], int left, int right);
void printArray(int numbers[], int array_size);

int main(){

    int numbers[NUM_ITEMS] = {10,9,8,7,6,5,4,3,2,1};

    printf("Start: ");
    printArray(numbers, NUM_ITEMS);
    printf("\n");

    //perform quick sort on array
    quickSort(numbers, NUM_ITEMS);

    printf("Done with sort.\n");
    printArray(numbers, NUM_ITEMS);
    printf("\n");

    return 0;
}

void quickSort(int numbers[], int array_size)
{
    q_sort(numbers, 0, array_size - 1);
}

void q_sort(int numbers[], int left, int right)
{
    int pivot, l_hold, r_hold;

    l_hold = left;
    r_hold = right;
    pivot = numbers[left];
    while (left < right)
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        q_sort(numbers, left, pivot-1);
    if (right > pivot)
        q_sort(numbers, pivot+1, right);
}

void printArray(int numbers[], int array_size)
{
    int x;
    for (x = 0; x < array_size; x++) {
        printf("%d ", numbers[x]);
    }
}
