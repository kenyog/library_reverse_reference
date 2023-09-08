#include <stdio.h>
#include <string.h>

#include "lib_b.h"

int func_lib_a(const char *from, int indent_level) {
  static int count = 0;
  count++;

  char indent[10] = "";
  memset(indent, ' ', sizeof(indent));
  if (indent_level < 5) {
    indent[indent_level*2] = '\0';
  }

  printf("%sfunc_lib_a from %s:\n", indent, from);
  printf("%s--> count=%d\n", indent, count);
  printf("%s--> call lib_b\n", indent);
  int b = func_lib_b("lib_a", indent_level+1);
  printf("%s--> lib_b returns %d\n", indent, b);

  return count;
}
