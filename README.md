# Stack

A stack data structure implemented using a dynamic array.

# Installation

`$ em list`
`$ em install`
`$ em build lib`

## Usage

`$ touch test.c`

```c
#include "Stack.h"
#include <stdio.h>

int main(void) {
    stack *st = stack_new();
    stack_push(st, 2);
    stack_push(st, 3);
    stack_push(st, -1);
    printf("item %d, should be -1\n", stack_pop(st));
    printf("item %d, should be 3\n", stack_pop(st));
    printf("peek item %d should be 2\n", stack_peek(st));
    printf("item %d, should be 2\n", stack_pop(st));
}
```

`$ clang test.c Stack.so`

## Development

* Write tests

## Contributing

1. Fork it (<https://github.com/Oblivious-Oblivious/Stack/fork>)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## Contributors

- [Oblivious](https://github.com/Oblivious-Oblivious) - creator and maintainer
