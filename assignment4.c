#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment4.h"

/* Question 1 */

int queue_size(queue_t* q) {
    if (q == NULL) {
        return 0;
    }
    int count = 0;
    queue_t* temp = queue_create();
    while (!queue_is_empty(q)) {
        int val = dequeue(q);
        enqueue(temp, val);
        count++;
    }
    while (!queue_is_empty(temp)) {
        enqueue(q, dequeue(temp));
    }
    queue_free(temp); 
    return count;
}

bool queue_equal(queue_t* q1, queue_t* q2) {
    if (q1 == NULL || q2 == NULL) {
        return q1 == q2; 
    }
    
    queue_t* temp1 = queue_create();
    queue_t* temp2 = queue_create();
    bool is_equal = true;
    while (!queue_is_empty(q1) && !queue_is_empty(q2)) {
        int val1 = dequeue(q1);
        int val2 = dequeue(q2);
        enqueue(temp1, val1);
        enqueue(temp2, val2);
        
        if (val1 != val2) {
            is_equal = false;
        }
    }
    if (!queue_is_empty(q1) || !queue_is_empty(q2)) {
        is_equal = false;
    }
    while (!queue_is_empty(q1)) {
        enqueue(temp1, dequeue(q1));
    }
    while (!queue_is_empty(q2)) {
        enqueue(temp2, dequeue(q2));
    }
    while (!queue_is_empty(temp1)) {
        enqueue(q1, dequeue(temp1));
    }
    while (!queue_is_empty(temp2)) {
        enqueue(q2, dequeue(temp2));
    }
    queue_free(temp1);
    queue_free(temp2);
    return is_equal;
}



/* Question 2 */
void LL_reverse(LL_t* list) {
    if (list == NULL || list->head == NULL || list->head->next == NULL) {
        return;
    }
    node_t* prev = NULL; 
    node_t* curr = list->head; 
    node_t* next = NULL;
    list->tail = list->head; 
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev; 
}

bool LL_equal(LL_t* list1, LL_t* list2) {
    if (list1 == NULL || list2 == NULL) {
        return list1 == list2; 
    }
    node_t* curr1 = list1->head;
    node_t* curr2 = list2->head;
    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->data != curr2->data) {
            return false; 
        }
        curr1 = curr1->next; 
        curr2 = curr2->next; 
    }
    return (curr1 == NULL && curr2 == NULL);
}

/* Question 3 */
void LL_insertion_sort(LL_t* list) {
    if (list == NULL || list->head == NULL || list->head->next == NULL) {
        return; 
    } 
    node_t* sorted_head = NULL; 
    node_t* sorted_tail = NULL;
    node_t* curr = list->head; 
    while (curr != NULL) {
        node_t* next = curr->next; 
        curr->next = NULL;
        if (sorted_head == NULL || sorted_head->data >= curr->data) {
            curr->next = sorted_head; 
            sorted_head = curr; 
            if (sorted_tail == NULL) {
                sorted_tail = curr;
            }
        } else {
            node_t* temp = sorted_head;
            while (temp->next != NULL && temp->next->data < curr->data) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
            if (curr->next == NULL) {
                sorted_tail = curr;
            }
        }
        curr = next;
    }
    list->head = sorted_head;
    list->tail = sorted_tail;
}