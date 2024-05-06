#ifndef __STACK_BASE_H_
#define __STACK_BASE_H_

#include <stdlib.h> /* malloc, calloc, realloc, free */

/* EmeraldsStack gets implemented using an EmeraldsVector */
#include "../../libs/EmeraldsVector/export/EmeraldsVector.h"

/**
 * @struct: EmeraldsStack
 * @desc: A stack data structure implementation
 * @param length -> The number of items pushed in the stack
 * @param top -> The index of the item on the top of the stack
 * @param items -> A vector of items
 **/
typedef struct EmeraldsStack {
  size_t length;
  size_t top;
  EmeraldsVector *items;
} EmeraldsStack;

/**
 * @func: stack_new
 * @desc: Creates a basic stack data structure using a dynamic array
 * @return The newly created stack
 **/
EmeraldsStack *stack_new(void);

/**
 * @func: stack_length
 * @desc: Returns the number of elements pushed in the array
 * @param st -> The stack to use
 * @return The length (st->length)
 **/
size_t stack_length(EmeraldsStack *st);

/**
 * @func: stack_is_empty
 * @desc: Checks whether the stack is empty or not
 * @param st -> The stack to use
 * @return A boolean
 **/
bool stack_is_empty(EmeraldsStack *st);

/**
 * @func: stack_push
 * @desc: Performs  bury operation on the stack
 * @param st -> The stack to use
 * @param item -> The item to push to the stack
 **/
void stack_push(EmeraldsStack *st, void *item);

/**
 * @func: stack_pop
 * @desc: Performs a pop operation on the stack
 * @param st -> The stack to use
 * @return The item on the top of the stack
 **/
void *stack_pop(EmeraldsStack *st);

/**
 * @func: stack_peek
 * @desc: Performs a peek operation on the stack
 * @param st -> The stack to use
 * @return The item on top of the stack withou removing it
 **/
void *stack_peek(EmeraldsStack *st);

/**
 * @func: stack_free
 * @brief Frees the stack memory space
 * @param st -> The stack to free
 */
void stack_free(EmeraldsStack *st);

#endif
