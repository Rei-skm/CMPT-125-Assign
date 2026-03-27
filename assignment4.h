#ifndef ASSIGNMENT4_H
#define ASSIGNMENT4_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "lib/queue.h"
#include "lib/LL.h"


/* Question 1 */

// returns the size of the queue
// when the function returns, q should be in the same state
// as it was in the beginning
int queue_size(queue_t* q);


// checks if the two queues are equal
// when the function returns, q1 and q2 should be in the same state
// as they were in the beginning
bool queue_equal(queue_t* q1, queue_t* q2);


/* Question 2 */

// gets a linked list and reverses the order of the elements in it
void LL_reverse(LL_t* list);


// checks if the two queues are equal
// when the function returns, list1 and list2 should be in the same
// state as they were in the beginning
bool LL_equal(LL_t* list1, LL_t* list2);


/* Question 3 */

// the function gets a linked list of ints
// The function applies Insertion Sort on the list
void LL_insertion_sort(LL_t* list);


#endif
