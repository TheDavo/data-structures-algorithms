#include<stdio.h>
#include<stdlib.h>

struct Array {
  int A[10];
  int size;
  int length;
};

  void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
  }

  void Display(struct Array arr){
    int i;
    printf("\nElements are\n");
    for (i = 0; i < arr.length; i++){
      printf("%d:\t %d\n", i, arr.A[i]);
    }
  }

  void Append(struct Array *arr, int val){
    if (arr->length < arr->size) {
      arr->A[arr->length++] = val; // Using arr->length++ will increment the arr->length value
    }
  }

  void Insert(struct Array *arr, int loc, int val) {
    int i;
    
    if (loc >= 0 && loc <= arr->length) {
      // Perform a shift-right on array values to 'empty' the location that will have a value inserted
      for (i = arr->length; i > loc; i--) {
        arr->A[i] = arr->A[i-1]; 
      }
      arr->A[loc] = val;
      arr->length++;
    }
  }

  void InsertSort(struct Array *arr, int value) {
    int i = arr->length - 1;

    if(arr->length == arr->size) {
      return;
    }
    while (i >=0 && arr->A[i] > value) {
      arr->A[i+1] = arr->A[i];
      i--;
    }
    arr->A[i+1] = value;
    arr->length++;
  }

  int IsSorted(struct Array arr) {
    int i;

    for (i = arr.length; i > 0; i--) {
      if (arr.A[i] < arr.A[i-1]) {
        return 0;
      }
    }
    return 1;
  }

  void Rearrange(struct Array *arr) {
    int i, j;
    i = 0;
    j = arr->length - 1;

    while (i < j) {
      while (arr->A[i] < 0) i++;
      while (arr->A[j] >= 0) j--;
      if(i < j) swap(&arr->A[i], &arr->A[j]);
    }
  }

  void Delete(struct Array *arr, int loc) {
    int i;
    if (loc >= 0 && loc <= arr->length) {
      for (i = loc; i < arr->length-1; i++){
        arr->A[i] = arr->A[i+1];
      }
    }
    arr->A[arr->length] = 0;
    arr->length--;
  }



  int LinearSearch(struct Array *arr, int searchItem) {
    int i;

    for(i = 0; i < arr->length; i++) {
      if (arr->A[i] == searchItem){
        swap(&arr->A[i], &arr->A[0]); // Swap found item with index 0 item. If the item is searched for frequently it will take a shorter time to search for that item
        return i;
      }
    }

    return -1;
  }


  // Binary search requires that the list is sorted
  int BinarySearch(struct Array arr, int searchItem) {
    int lower, higher, mid;
    lower = 0;
    higher = arr.length-1;
    mid = (lower + higher) / 2;

    while (lower <= higher) {
      if (arr.A[mid] == searchItem)
        return mid;
      else if (searchItem < arr.A[mid])
        higher = mid - 1;
      else
        lower = mid + 1;

      mid = (lower + higher) / 2;
    }
    return -1;
  }

  int RBinarySearch(int arr[], int lower, int higher, int searchItem) {
    int mid;

    mid = (lower + higher) / 2;

    if (lower <= higher) {
      if(arr[mid] == searchItem) 
        return mid;
      else if (searchItem < arr[mid])
        return RBinarySearch(arr, lower, mid - 1, searchItem);
      else
        return RBinarySearch(arr, mid + 1, higher, searchItem);
    }

    return -1;
  }

  int Get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length) {
      return arr.A[index];
    }

    return -1;
  }

  void Set(struct Array *arr, int index, int newValue) {
    if (index >= 0 && index < arr->length) {
      arr->A[index] = newValue;
    }
  }

  int Max(struct Array arr) {
    int max = arr.A[0];

    int i;
    for (i = 1; i < arr.length; i++) {
      if ( arr.A[i] > max ) {
        max = arr.A[i];
      }
    }
    return max;
  }

  int Min(struct Array arr) {
    int min = arr.A[0];

    int i;
    for (i = 1; i < arr.length; i++) {
      if ( arr.A[i] < min ) {
        min = arr.A[i];
      }
    }
    return min;
  }

  int Sum(struct Array arr) {
    int sum = 0;
    int i;

    for(i = 0; i < arr.length; i++) {
      sum += arr.A[i];
    }

    return sum;
  }

  float Average(struct Array arr) {
    int sum = Sum(arr);

    return (float)(sum) / arr.length;

  }

  void Reverse(struct Array *arr) {
    int i,j;

    for(i = 0, j = arr->length-1; i < (arr->length-1)/2; i++,j--) {
      swap(&arr->A[i], &arr->A[j]);
    }
  }

  void LeftShift (struct Array *arr, int n) {
    int i;
    int len = arr->length;

    for (i = 0; i < len - n; i++) {
      arr->A[i] = arr->A[i+n];
    }

    for (i = len - n; i < len; i++) {
      arr->A[i] = 0;
    }
  }

  void RightShift (struct Array *arr, int n) {
    int i;
    int len = arr->length;

    for (i = len - 1; i >= n; i--) {
      arr->A[i] = arr->A[i-n];
    }

    for (i = n-1; i >= 0; i--) {
      arr->A[i] = 0;
    }
  }

  struct Array * MergeSorted(struct Array *arr1, struct Array *arr2) {
    int i, j, k;
    i = j = k = 0;

    struct Array *merged = (struct Array *)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length) {
      if(arr1->A[i] < arr2->A[j]) {
        merged->A[k++] = arr1->A[i++];
      } else {
        merged->A[k++] = arr2->A[j++];
      }
    }

    for (; i < arr1->length; i++) {
      merged->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++) {
      merged->A[k++] = arr2->A[j];
    }

    merged->length = arr1->length + arr2->length;
    merged->size = arr1->size + arr2->size;

    return merged;
  }

int main() {

  struct Array arr= {{1,2,3,4,5,6,7,8}, 10, 5};
  struct Array arr2= {{9,10,11,12,13,14,15,16}, 10, 5};
  printf("Average: %.2f \n", Average(arr));
  
  struct Array * new_array;
  new_array = MergeSorted(&arr, &arr2);
  Display(*new_array);

  return 0;
}
