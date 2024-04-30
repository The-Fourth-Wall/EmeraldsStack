#ifndef __STACK_BASE_H_
#define __STACK_BASE_H_

#include <stdlib.h> /* malloc, calloc, realloc, free */

/* Stack gets implemented using a vector */
#include "../../libs/Vector/export/Vector.h"

/**
 * @struct: stack
 * @desc: A stack data structure implementation
 * @param length -> The number of items pushed in the stack
 * @param top -> The index of the item on the top of the stack
 * @param items -> A vector of items
 **/
typedef struct stack {
  size_t length;
  size_t top;
  vector *items;
} stack;

/**
 * @func: stack_new
 * @desc: Creates a basic stack data structure using a dynamic array
 * @return The newly created stack
 **/
stack *stack_new(void);

/**
 * @func: stack_length
 * @desc: Returns the number of elements pushed in the array
 * @param st -> The stack to use
 * @return The length (st->length)
 **/
size_t stack_length(stack *st);

/**
 * @func: stack_is_empty
 * @desc: Checks whether the stack is empty or not
 * @param st -> The stack to use
 * @return A boolean
 **/
bool stack_is_empty(stack *st);

/**
 * @func: stack_push
 * @desc: Performs  bury operation on the stack
 * @param st -> The stack to use
 * @param item -> The item to push to the stack
 **/
void stack_push(stack *st, void *item);

/**
 * @func: stack_pop
 * @desc: Performs a pop operation on the stack
 * @param st -> The stack to use
 * @return The item on the top of the stack
 **/
void *stack_pop(stack *st);

/**
 * @func: stack_peek
 * @desc: Performs a peek operation on the stack
 * @param st -> The stack to use
 * @return The item on top of the stack withou removing it
 **/
void *stack_peek(stack *st);

/**
 * @func: stack_free
 * @brief Frees the stack memory space
 * @param st -> The stack to free
 */
void stack_free(stack *st);

#endif
