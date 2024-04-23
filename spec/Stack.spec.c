#include "../libs/cSpec/export/cSpec.h"

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

int main(void) {
  run_spec_suite("all");
}
