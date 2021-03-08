#include "../export/Stack.h"

int main(void) {
    stack *st = stack_new();
    
    printf("TESTING STACK\n");
    stack_push(st, (void*)2);
    stack_push(st, (void*)3);
    stack_push(st, (void*)-1);
    printf("item %ld, should be -1\n", (long)stack_pop(st));
    printf("item %ld, should be 3\n", (long)stack_pop(st));
    printf("peek item %ld should be 2\n", (long)stack_peek(st));
    printf("item %ld, should be 2\n", (long)stack_pop(st));
    return 0;
}
