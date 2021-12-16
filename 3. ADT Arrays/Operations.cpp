#include <iostream>
using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};
void Display(struct Array arr)
{
    int i;
    cout << "Elements are : ";
    for (i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}
void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
        //arr->length++; Alternative
    }
}
void Insert(struct Array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}
int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;

    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return 0;
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int LinearSearch(struct Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}
int BinarySearch(struct Array arr, int key)
{
    int l, mid, h;
    l = 0;
    h = arr.length - 1;

    while (l <= h)
    {

        mid = (l + h) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
void Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)

        cout << arr.A[index] << endl;
}
int Set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
    return arr->A[index];
}
int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}
int Min(struct Array arr)
{
    int Min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < Min)
        {
            Min = arr.A[i];
        }
    }
    return Min;
}
int Sum(struct Array arr)
{
    int Sum = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        Sum += arr.A[i];
    }
    return Sum;
}
float Average(struct Array arr)
{
    return (float)Sum(arr) / arr.length; //While returning float we have to double mention it
}
void Reverse(struct Array *arr) // Reversing using Auxillary array method
{
    int *B;
    int i, j;

    B = new int[10];
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }
    for (i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}
void Reverse2(struct Array *arr)
{
    int i, j, temp; // Reversing using swaping method
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}
void leftshiftone(struct Array *arr)
{

    int temp = arr->A[0];
    int i;

    for (i = 0; i < arr->length - 1; i++) // this should be arr.length-1
    {
        arr->A[i] = arr->A[i + 1];
    }

    arr->A[i] = temp;
}

void leftshift(struct Array *arr, int d)
{

    int i;

    for (i = 0; i < d; i++)

        leftshiftone(arr); // pass arr. dont pass arr->A[i]
}
void InsertSort(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}
int isSort(struct Array arr)
{
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return false;
    }
    return true;
}
void Rearrange(struct Array *arr)
{
    int i = 0, j = arr->length - 1;

    while (i < j)
    {
        while (arr->A[i] < 0)
            i++;

        while (arr->A[j] >= 0)
            j--;
        if (i < j)
        {
            swap(&arr->A[i], &arr->A[j]);
        }
    }
}
struct Array* Merge(struct Array *arr1,struct Array *arr2)
{
    int i, j,k;
    i=k=j=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct
                                                       Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}
int main()
{
    struct Array arr1 = {{2, 6, 10, 15, 20}, 10, 5};
    struct Array arr2 = {{3, 4, 7, 18, 25}, 10, 5};
    struct Array *arr3;

    arr3=Merge(&arr1,&arr2);
Display(*arr3);

    return 0;
}
