#include "../export/EmeraldsStack.h" /* IWYU pragma: keep */

#include <stdio.h> /* printf */

int main(void) {
  int *st = NULL;

  printf("TESTING STACK\n");
  stack_push(st, 2);
  stack_push(st, 3);
  stack_push(st, -1);
  printf("item %d, should be -1\n", stack_pop(st));
  printf("item %d, should be 3\n", stack_pop(st));
  printf("peek item %d should be 2\n", stack_peek(st));
  printf("item %d, should be 2\n", stack_pop(st));

  stack_free(st);

  stack_push(st, 88);
  printf("-> %d should be 88\n", stack_pop(st));
  stack_push(st, 99);
  printf("-> %d should be 99\n", stack_pop(st));

  stack_free(st);

  return 0;
}
