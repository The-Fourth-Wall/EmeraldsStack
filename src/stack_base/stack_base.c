#include "stack_base.h"

EmeraldsStack *stack_new(void) {
  EmeraldsStack *st = (EmeraldsStack *)malloc(sizeof(EmeraldsStack));

  /* Initial values */
  st->length = 0;
  st->top    = -1;
  st->items  = vector_new();

  return st;
}

size_t stack_length(EmeraldsStack *st) {
  if(st == NULL) {
    return 0;
  }

  return st->length;
}

bool stack_is_empty(EmeraldsStack *st) {
  if(st == NULL) {
    return 0;
  }

  return stack_length(st) == 0;
}

void stack_push(EmeraldsStack *st, void *item) {
  if(st == NULL) {
    return;
  }

  /* Keep track of the top element and the length */
  st->top++;
  st->length++;

  vector_add(st->items, item);
}

void *stack_pop(EmeraldsStack *st) {
  if(st == NULL) {
    return NULL;
  }

  if(!stack_is_empty(st)) {
    st->length--;
    return vector_get(st->items, st->top--);
  }
  return NULL;
}

void *stack_peek(EmeraldsStack *st) {
  if(st == NULL) {
    return NULL;
  }

  if(!stack_is_empty(st)) {
    return vector_get(st->items, st->top);
  }
  return NULL;
}

void stack_free(EmeraldsStack *st) {
  vector_free(st->items);
  free(st);
}
