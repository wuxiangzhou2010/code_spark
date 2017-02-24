/**
 On most systems this will cause a crash--historically, 
 a null pointer corresponds to memory location 0, which
 is usually restricted to the operating system kernel 
 and not accessible to user programs.
 usage: "gcc -Wall -g coredump_test.c"
		"gdb a.out core"
		"bt full"
		"print p"
		"backtrace"
		
output:
(gdb) bt full
#0  0x080483dc in a (p=0x0) at coredump_test.c:39
        y = 32768
#1  0x080483d1 in main () at coredump_test.c:33
        p = 0x0
(gdb) print p
$1 = (int *) 0x0
(gdb) backtrace
#0  0x080483dc in a (p=0x0) at coredump_test.c:39
#1  0x080483d1 in main () at coredump_test.c:33


*/

int a (int *p);

int
main (void)
{
  int *p = 0;   /* null pointer */
  return a (p);
}

int
a (int *p)
{
  int y = *p;
  return y;
}
