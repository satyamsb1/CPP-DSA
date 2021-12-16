#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        Delete []A;
    }
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);

    int LinearSearch(int key);
    int BinarySearch(int key);
    void Get(int index);
    int Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Average();
    void Reverse();
    void Reverse2();
    void leftshiftone();
    void leftshift(int d);
    void InsertSort(int x);
    int isSort();
    void Rearrange();
    Array *Merge(Array *arr2);
    Array *Union(Array *arr2);
    Array *Intersection(Array *arr2);
    Array *Difference(Array *arr2);
};
void Array::Display()
{
    int i;
    cout << "Elements are : ";
    for (i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
}
void Array ::Append(int x)
{
    if (length < size)
    {
        A[length++] = x;
        //arr->length++; Alternative
    }
}
void Array ::Insert(int index, int x)
{
    int i;
    if (index >= 0 && index <= length)
    {
        for (int i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
}
int Array ::Delete(int index)
{
    int x = 0;
    int i;

    if (index >= 0 && index <length)
    {
        x = A[index];
        for (i = index; i < length - 1; i++)
        {
            i = i + 1;
        }
        length--;
        return x;
    }
    return 0;
}
void Array ::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int Array ::LinearSearch(int key)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (key == A[i])
        {
            swap(&A[i], &[0]);
            return i;
        }
    }
    return -1;
}
int Array ::BinarySearch(int key)
{
    int l, mid, h;
    l = 0;
    h = length - 1;

    while (l <= h)
    {

        mid = (l + h) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
void Array ::Get(int index)
{
    if (index >= 0 && index < length)

        cout << A[index] << endl;
}
int Array ::Set(int index, int x)
{
    if (index >= 0 && index < length)
    {
        A[index] = x;
    }
    return A[index];
}
int Array ::Max()
{
    int max = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}
int Array ::Min()
{
    int Min = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] < Min)
        {
            Min = A[i];
        }
    }
    return Min;
}
int Array ::Sum(struct Array arr)
{
    int Sum = A[0];

    for (int i = 1; i < length; i++)
    {
        Sum += A[i];
    }
    return Sum;
}
float Array ::Average()
{
    return (float)Sum(arr) / length; //While returning float we have to double mention it
}
void Array A ::Reverse() // Reversing using Auxillary array method
{
    int *B;
    int i, j;

    B = new int[10];
    for (i = length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }
    for (i = 0; i < length; i++)
    {
        A[i] = B[i];
    }
}
void Array ::Reverse2()
{
    int i, j, temp; // Reversing using swaping method
    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        swap(&A[i], &A[j]);
    }
}
void Array ::leftshiftone()
{

    int temp = A[0];
    int i;

    for (i = 0; i < length - 1; i++) // this should be arr.length-1
    {
        A[i] = A[i + 1];
    }

    [i] = temp;
}

void Array ::leftshift(int d)
{

    int i;

    for (i = 0; i < d; i++)

        leftshiftone(arr); // pass arr. dont pass arr->A[i]
}
void Array ::InsertSort(int x)
{
    int i = length - 1;
    if (length == size)
        return;
    while (i >= 0 && A[i] > x)
    {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = x;
    length++;
}
int Array ::isSort(struct Array arr)
{
    for (int i = 0; i < length - 1; i++)
    {
        if (A[i] > A[i + 1])
            return false;
    }
    return true;
}
void Array ::Rearrange()
{
    int i = 0, j = length - 1;

    while (i < j)
    {
        while (A[i] < 0)
            i++;

        while (A[j] >= 0)
            j--;
        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    }
}
Array *Merge( Array arr2)
{
    int i, j, k;
    i = k = j = 0;
    Array *arr3 = new Array(length+arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];
    arr3->length = length + arr2.length;
   

    return arr3;
}
Array *Union(Array arr2)
{
    int i, j, k;
    i = k = j = 0;
    Array *arr3 = new Array(length+arr2.length);
    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (A[i] > arr2.A[j])
            arr3->A[k++] = arr2.A[j++];
        else
            arr3->A[k++] = A[i++];
        j++;
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];
    for (; j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];
    arr3->length = length + arr2.length;
    

    return arr3;
}
Array *Intersection(Array arr2)
{
    int i, j, k;
    i = k = j = 0;
   Array *arr3 =new Array(length +arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            i++;
        else if (A[i] > arr2.A[j])
            j++;
        else if (A[i] == arr2.A[j])
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    arr3->length = k;
    return arr3;
}
Array *Difference( Array arr2)
{
    int i, j, k;
    i = k = j = 0;
    Array *arr3 = new Array (length + arr2.length);

    while (i < length && j < arr2.length)
    {
        if (A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (A[i] > arr2.A[j])
            j++;
        else if (A[i] == arr2.A[j])
        {
            i++;
            j++;
        }
    }
    for (; i < length; i++)
        arr3->A[k++] = A[i];

    arr3->length = length + arr2.length;
    

    return arr3;
}
int main()
{
    struct Array arr1;
    int ch;
    int x, index;
    do
    {
        cout << "\n\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6.Exit\n";

        cout << "enter you choice ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter an element and index ";

            cin >> x >> index;

            arr1->Insert(index, x);
            break;
        case 2:
            cout << "Enter index ";
            cin >> index;
            x = arr1->Delete(index);
            cout << "Deleted Element is" << x;
            break;
        case 3:
            cout << "Enter element to search ";
            cin >> x;
            index = arr1->LinearSearch(x);
            cout << "Element index " << index;
            break;
        case 4:
            cout << "Sum is " << arr1->Sum();
            break;
        case 5:
            arr1->Display();
        }
    } while (ch < 6);
    do
    {
        cout << "\n\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6.Exit\n";

        cout << "enter you choice ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter an element and index ";

            cin >> x >> index;

            Insert(index, x);
            break;
        case 2:
            cout << "Enter index ";
            cin >> index;
            x = Delete(index);
            cout << "Deleted Element is" << x;
            break;
        case 3:
            cout << "Enter element to search ";
            cin >> x;
            index = LinearSearch(x);
            cout << "Element index " << index;
            break;
        case 4:
            cout << "Sum is " << Sum();
            break;
        case 5:
            Display();
        }
    } while (ch < 6);
    return 0;
}
