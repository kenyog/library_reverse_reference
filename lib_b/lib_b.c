#include <stdio.h>
#include <string.h>

extern int func_main(const char *from, int indent_level);

int func_lib_b(const char *from, int indent_level) {
  static int count = 0;
  count++;

  char indent[10] = "";
  memset(indent, ' ', sizeof(indent));
  if (indent_level < 5) {
    indent[indent_level*2] = '\0';
  }

  printf("%sfunc_lib_b from %s:\n", indent, from);
  printf("%s--> count=%d\n", indent, count);

#ifndef _WIN32
  printf("%s--> call func_main\n", indent);
  int b = func_main("lib_b", indent_level+1);
  printf("%s--> func_main returns %d\n", indent, b);
#endif

  return count;
}

