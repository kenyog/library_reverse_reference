#include <stdio.h>
#include <string.h>

#include "lib_b.h"

void use_a(const char *libpath);

int main(int argc, char **argv) {

  printf("main\n");
  printf("--> call lib_b\n");
  int b = func_lib_b("main", 1);
  printf("--> lib_b returns %d\n", b);

  printf("--> call lib_b\n");
  b = func_lib_b("main", 1);
  printf("--> lib_b returns %d\n", b);

  if (argc > 1) {
    use_a(argv[1]);

    use_a(argv[1]);
  }

  printf("--> call lib_b\n");
  b = func_lib_b("main", 1);
  printf("--> lib_b returns %d\n", b);
}

int func_main(const char *from, int indent_level) {
  static int count = 0;
  count++;

  char indent[10] = "";
  memset(indent, ' ', sizeof(indent));
  if (indent_level < 5) {
    indent[indent_level*2] = '\0';
  }

  printf("%sfunc_main from %s:\n", indent, from);
  printf("%s--> count=%d\n", indent, count);

  return count;
}

#ifdef _WIN32
#include <windows.h>
typedef int (*func_a)(const char *from, int lv);
void use_a(const char *libpath) {
  HMODULE dlh = LoadLibrary(libpath);
  if (!dlh) {
    fprintf(stderr, "could not open %s", libpath);
  }

  func_a a = GetProcAddress(dlh, "func_lib_a");
  if (!a) {
    fprintf(stderr, "func_lib_a not found");
  }

  printf("--> call lib_a\n");
  int b = a("main", 1);
  printf("--> lib_a returns %d\n", b);
}
#else
#include <dlfcn.h>
typedef int (*func_a)(const char *from, int lv);
void use_a(const char *libpath) {
  void *dlh = dlopen(libpath, RTLD_NOW | RTLD_LOCAL);
  if (!dlh) {
    fprintf(stderr, "could not open %s", libpath);
  }


  func_a a = dlsym(dlh, "func_lib_a");
  if (!a) {
    fprintf(stderr, "func_lib_a not found");
  }

  printf("--> call lib_a\n");
  int b = a("main", 1);
  printf("--> lib_a returns %d\n", b);
}
#endif

