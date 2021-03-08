#include "Stack.spec.h"

module(T_Stack, {
    describe("#get_value", {
        it("returns `Hello, World!`", {
            assert_that_charptr("Hello, World!" equals to "Hello, World!");
        });
    });
});

spec_suite({
    T_Stack();
});

spec({
    run_spec_suite("all");
});
