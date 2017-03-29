#include <errno.h>
#include <error.h>
#include <unistd.h>

int main() {
  if (geteuid() != 0)
    error(1, errno, "must be run as root\r\n");

  char *cmd = "/usr/bin/ipmitool";
  char *args[3];
  args[0] = "lan";
  args[1] = "print";
  args[2] = NULL;

  execvp(cmd, args);
}
