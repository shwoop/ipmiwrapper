#include <errno.h>
#include <error.h>
#include <unistd.h>

int main() {
  if (geteuid() != 0)
    error(1, errno, "must be run as root\r\n");

  char *cmd = "/usr/bin/ipmitool";
  char *args[4];
  args[0] = cmd;
  args[1] = "lan";
  args[2] = "print";
  args[3] = NULL;

  execvp(cmd, args);
}
