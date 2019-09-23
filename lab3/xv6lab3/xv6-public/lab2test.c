#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int priority=-1, pid=-1;

  if(argc < 2) {
    printf(2, "Usage: lab2test pid priority // to set priority\n");
    printf(2, "Usage: lab2test pid //to get prioroty\n");
    exit();
  }
  if ( argc == 2){
    pid = atoi(argv[1]);
    priority = get_priority(pid);
    printf(1, "Got priority=%d for pid=%d\n", priority, pid);
  }
  if( argc == 3){
  pid = atoi(argv[1]);
  priority = atoi(argv[2]);
  if (priority < 0 || priority > 39) {
    printf(2, "Invalid priority (0-39)!\n");
    exit();
  }
  printf(1, "pid=%d, priority=%d\n", pid, priority);
  if (set_priority(pid, priority) == 0)
    printf(1, "Successfully set priority=%d to pid=%d\n", pid, priority);
  else
    printf(1, "Failed set priority to pid=%d\n", pid );    
}
  exit();
}
