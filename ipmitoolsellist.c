#include <errno.h>
#include <error.h>
#include <unistd.h>

int main() {
  if (geteuid() != 0)
    error(1, errno, "must be run as root\r\n");

  char *cmd = "/usr/bin/ipmitool";
  char *args[5];
  args[0] = cmd;
  args[1] = "-c";
  args[2] = "sel";
  args[3] = "list";
  args[4] = NULL;

  execvp(cmd, args);
}
