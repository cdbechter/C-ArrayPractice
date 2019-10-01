#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LEN_A 10

/* function declarations */
void print_array(int[], int);
void reverse(int[], int);
double average(int[], int);
void insert(int[], int, int, int);
int less_than_average(int[], int);
void rotate_right(int[], int, int);
void array_copy(int[], int[], int);
void initialize(int[], int, int);
void evens_on_left(int[], int);
int find(int A[], int len, int x);
int find_last(int A[], int len, int x);
int contains_dup(int A[], int len);

int main(int argc, char **argv)
{
  int A[] = {9, 505, 321, 117, 27, 64, 13, 9, 12, 208};
  int B[LEN_A+1];
  int newValue=505;

  printf("A[] is: ");
  print_array(A, LEN_A);
  printf("\n");

  initialize(B, LEN_A+1, 0);
  printf("B[] is: ");
  print_array(B, LEN_A+1);
  printf("\n");

  array_copy(B, A, LEN_A);
  printf("but now it's ");
  print_array(B, LEN_A+1);
  printf("\n");

  insert(B, newValue, 0, LEN_A);
  printf("and after inserting %d at the beginning it's\n", newValue);
  print_array(B, LEN_A+1);
  printf("\n\n");

  printf("\nThe average of A[] is %f\n", average(A,LEN_A));
  printf("There are %d items in A[] less than this.", less_than_average(A,LEN_A));
  printf("\n");

  printf("The Reversed Array list is: ");
  reverse(A, LEN_A);
  print_array(A, LEN_A);
  printf("\n");

  printf("The rotated Array list is: ");
  rotate_right(A, LEN_A, 3);
  print_array(A, LEN_A);
  printf("\n\n");

  printf("The Evens on the left Array List is: ");
  evens_on_left(A, LEN_A);
  print_array(A, LEN_A);
  printf("\n");

  printf("The index of the first occurrence of %d is %d.\n", 9, find(A, LEN_A, 9));
  printf("The index of the last occurrence of %d is %d.\n", 9, find_last(A, LEN_A, 9));

  if (contains_dup(A, LEN_A))
    printf("A[] contains a dup\n");
  else
    printf("A[] doesn't contain a dup\n");

  if (contains_dup(B, LEN_A+1))
    printf("B[] contains a dup\n");
  else
    printf("B[] doesn't contain a dup\n");

  return 0;
}

/* functions implementation */

/* prints A[] inside parentheses with each value separated
   by commas to stdout (which will be the screen). */
void print_array(int A[], int length) {
  int i;
  for(i=0; i < length; i++) {
    printf("%d, ", A[i]);
  }  
}

/* returns the average of the items in A[] or 0.0 if A is empty */
double average(int A[], int length) {
  int i;
  int sum=0;
  double average;

  for(i=0; i<length; i++) {
    sum += A[i];
  }
  average = sum / length;
  
  return average;
}

/* returns the number of items in A that are less than the
  average of the items in A */
int less_than_average(int A[], int length) {
  int i;
  int sum;
  double average;
  int counter=0;

  for(i=0; i<length; i++){
    sum +=A[i];
  }
  average = sum/length;
  for(i=0; i<length; i++){
    if(A[i] < average)
      counter++;
  }

  return counter;
}

/* Reverses the values in A[].  For example, if before the function,
   A[] contained [1,2,3,4,5], after the function, A[] contains
   [5,4,3,2,1] */
void reverse(int A[], int length) {
  int start = 0;
  int end = length-1;
  int temp;

  while(start<end){
    temp = A[start];
    A[start] = A[end];
    A[end]=temp;
    start++;
    end--;
  }

}

/* returns the second largest item in A[], or -1 if len < 2 */
int secondLargest(int A[], int length) {
  int i, first, second;

  if(length < 2)
    return -1;

  for(i=0; i<length; i++){
    if(A[i] > first){
      second = first;
      first = A[i];
    } else if (A[i] > second && A[i] != first){

      second = A[i];
      }
    }
  return second;
}

/* rotates the values in the array numPlaces to the right */
/* for example, if A[] is initially 10,20,30,40,50, and numPlaces=2 */
/* after the function finishes, A[] would be 40,50,10,20,30 */
void rotate_right(int A[], int length, int numPlaces) {
  int i, temp;
  while(numPlaces) {
    temp=A[length-1];
    for(i=length-1; i>=1; i--)
      A[i]=A[i-1];
    A[0]=temp;
    numPlaces--;
  }
}

/* inserts the value n in A[] at the given index and shifts
   all other values up one position.  A[] contains length items.

   It is up to the caller to make sure that there is enough space
   in A[] to accomodate the new item, and that the index is valid. */
void insert(int A[], int n, int index, int length) {
  int i, j;
  for(i = length-1; i >= index; i--)
    A[i+1] = A[i];
  A[index] = n;
}

/* copies the first numItems from S to D. */
void array_copy(int D[], int S[], int numItems) {
  int i;
  for(i=0; i<numItems; i++){
    D[i] = S[i];
  }
}


/* sets the first len elements of A to initialValue */
void initialize(int A[], int len, int initialValue) {
  int i;
  for(i=0; i<len; i++)
    A[i] = initialValue;

}

/* shuffles the values in A so that the even values
   are all to the left of the odd values */
void evens_on_left(int A[], int len) {
  int temp=0, n=0, i, j;
  for(i=0; i<len; i++){
    if(A[i]%2==0){
      for(j=i;j>n;j--){
        temp=A[j-1];
        A[j-1]=A[j];
        A[j]=temp;
      }
      n++;
    }
  }
}

/* returns the index of the first occurrence of
 * x in A[] or -1 if x doesn't exist in A[] */
int find(int A[], int len, int x) {
  int i, first=-1;
  for(i=0; i<len;i++) {
    if(A[i] == x){
      first = i;
      break;
    }
  }
  if(first == -1)
    return -1;
  else
    return first;
}

/* returns the index of the last occurrence of
 * x in A[] or -1 if x doesn't exist in A[] */
int find_last(int A[], int len, int x) {
  int i, last = -1;
  for(i=len-1; i<len; i--){
    if(A[i] == x){
      last = i;
      break;
    }
  }
  if(last == -1)
    return -1;
  else
    return last;
}

/* returns 1 if there is at least one element in A[]
   that is contained elsewhere in A[], or 0 if there isn't */
int contains_dup(int A[], int len) {
  int i, j;
  for(i=0; i<len; i++){
    for(j=i+1; j<len; i++){
      if(A[i] == A[j])
        return 1;
    }
  }
  return 0;
}
