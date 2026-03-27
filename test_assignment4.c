#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "assignment4.h"

bool check_and_free(queue_t* q, int* ar, int n) {
  bool ret = true;
  for (int i = 0; i < n; i++)
    if (queue_is_empty(q) || dequeue(q)!=ar[i])
      ret = false;

  if (!queue_is_empty(q))
      ret = false;
  queue_free(q);
  return ret;
}

void test_q1_size()  {
  // create the strings
  int n = 5;
  int nums[] = {10,20,30,40,50};

  queue_t* q = queue_create();
  for (int i = 0; i < n; i++)
    enqueue(q, nums[i]);

  // testing the answer
  bool flag_ok = true;
  if (queue_size(q) != 5)
    flag_ok = false;
  if (!check_and_free(q, nums, 5))
    flag_ok = false;
  
  if (flag_ok)
    printf("Q1-size ok\n");
  else
    printf("Q1-size-1 ERROR\n");
}



void test_q1_equal_1()  {
  // create the strings
  int n = 5;
  int nums[] = {10,20,30,40,50};

  queue_t* q1 = queue_create();
  queue_t* q2 = queue_create();
  for (int i = 0; i < n; i++) {
    enqueue(q1, nums[i]);
    enqueue(q2, nums[i]);
  }

  // testing the answer
  bool flag_ok = true;
  if (queue_equal(q1, q2) == false)
    flag_ok = false;
  if (!check_and_free(q1, nums, n) || !check_and_free(q2, nums, n))
    flag_ok = false;
  
  if (flag_ok)
    printf("Q1-equal-1 ok\n");
  else
    printf("Q1-equal-1 ERROR\n");
}

void test_q1_equal_2()  {
  // create the strings
  int n1 = 5;
  int nums1[] = {10,20,30,40,50};
  int n2 = 5;
  int nums2[] = {10,20,30,40};

  queue_t* q1 = queue_create();
  queue_t* q2 = queue_create();
  for (int i = 0; i < n1; i++)
    enqueue(q1, nums1[i]);
  for (int i = 0; i < n2; i++)
    enqueue(q2, nums2[i]);

  // testing the answer
  bool flag_ok = true;
  if (queue_equal(q1, q2) == true)
    flag_ok = false;
  if (!check_and_free(q1, nums1, n1) || !check_and_free(q2, nums2, n2))
    flag_ok = false;
  
  if (flag_ok)
    printf("Q1-equal-2 ok\n");
  else
    printf("Q1-equal-2 ERROR\n");
}

LL_t* LL_create_from_arr(int* arr, int n) {
  LL_t* list = LLcreate();
  for (int i = n-1; i >= 0; i--)
    LL_add_to_head(list, arr[i]);
  return list;
}

bool check_list(LL_t* list, int* arr, int n) {
  if (!list)
    return false;
  node_t* cur = list->head;
  for (int i = 0; i < n; i++) {
    if (!cur || cur->data!=arr[i])
      return false;
    cur = cur->next;
  }
  return cur==NULL;
}

void test_q2_reverse() {
  int a[] = {4,3,2,1,0};
  LL_t* list = LL_create_from_arr(a,5);
  
  LL_reverse(list);

  int arr[] = {0, 1, 2, 3, 4};
  bool flag_ok = check_list(list, arr, 5);

  LL_free(list);

  if (flag_ok)
    printf("Q2-reverse ok\n");
  else
    printf("Q2-reverse ERROR\n");
}


void test_q2_equal_1() {
  int a[] = {0,1,2,3,4};
  LL_t* list1 = LL_create_from_arr(a,5);
  LL_t* list2 = LL_create_from_arr(a,5);
  
  bool flag_ok = LL_equal(list1, list2);

  LL_free(list1);
  LL_free(list2);

  if (flag_ok)
    printf("Q2-equal-1 ok\n");
  else
    printf("Q2-equal-1 ERROR\n");
}


void test_q2_equal_2() {
  int a1[] = {0,1,2,3,4};
  int a2[] = {4,2,0,8,1,6};
  LL_t* list1 = LL_create_from_arr(a1,5);
  LL_t* list2 = LL_create_from_arr(a2,6);

  bool flag_ok = !LL_equal(list1, list2);

  LL_free(list1);
  LL_free(list2);

  if (flag_ok)
    printf("Q2-equal-2 ok\n");
  else
    printf("Q2-equal-2 ERROR\n");
}


void test_q3() {
  int a[] = {1,4,0,3,2};
  LL_t* list = LL_create_from_arr(a,5);

  LL_insertion_sort(list);

  int arr[] = {0,1,2,3,4};
  bool flag_ok = check_list(list, arr, 5);

  LL_free(list);

  if (flag_ok)
    printf("Q3 ok\n");
  else
    printf("Q3 ERROR\n");
}


// when testing your code, it may be convenient 
// to comment out some of the test cases
// and focus only on the one you are working on right now
int main() {
  test_q1_size();

  test_q1_equal_1();
  test_q1_equal_2();

  test_q2_reverse();
  test_q2_equal_1();
  test_q2_equal_2();

  test_q3();
  
  return 0;
}
