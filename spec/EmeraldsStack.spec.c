#include "../libs/cSpec/export/cSpec.h"
#include "stack_base/stack_base.module.spec.h"

spec_suite({ T_stack(); });

int main(void) { run_spec_suite("all"); }
