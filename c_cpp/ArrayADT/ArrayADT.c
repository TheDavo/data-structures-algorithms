#include<stdio.h>

struct Array {
  int A[10];
  int size;
  int length;
};

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

  void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
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
int main() {

  struct Array arr= {{2,3,4,5,6,7,8}, 10, 7};

  printf("Binary Search result: %d", RBinarySearch(arr.A, 0, arr.length - 1, 3));
  return 0;
}
