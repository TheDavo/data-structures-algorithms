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

int main() {

  struct Array arr= {{2,3,4,5,6,7,8}, 10, 7};

  Display(arr);
  Insert(&arr, 5, 10);

  Display(arr);
  return 0;
}
