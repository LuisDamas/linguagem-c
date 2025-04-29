#include <stdio.h>
int main(void)
{
#ifdef __WINDOWS__
  puts("OS: Microsoft");
#elif defined(__LINUX__)
  puts("OS: Open Source");
#elif defined(__MAC_OS__) || defined(__IOS__)
  puts("OS: Apple");
#else
  #error No Operating system defined.
#endif

return 0;
}
