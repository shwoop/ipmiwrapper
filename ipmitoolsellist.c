#include <errno.h>
#include <error.h>
#include <unistd.h>

int main() {
  if (geteuid() != 0)
    error(1, errno, "must be run as root\r\n");

  char *cmd = "/usr/bin/ipmitool";
  char *args[4];
  args[0] = "-c";
  args[1] = "sel";
  args[2] = "list";
  args[3] = NULL;

  execvp(cmd, args);
}
