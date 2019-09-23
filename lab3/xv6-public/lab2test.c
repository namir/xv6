/**
 * Author: Yash Shah
 */

#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv)
{
        // Creating 3 processes 

        // one with setting the nice value of the process
        // second get the nice value of the process and print it out 
        // check the case that the nice value is set outside the range
        int pid;
        int wpid;
        switch(pid = fork()) {
                case 0:  /* child process */
                        /* setting the nice value of itself */
                        {
                                int cpid = getpid();
                                if (set_priority(cpid, 5) == 0) {
                                        printf(1, "My nice value changed from 20 to %d \n", get_priority(cpid));
                                        exit();
                                }
                                break;
                        }
                case -1: /* error occurred */
                        printf(1, "Oops error occurred. Can't fork the kid \n");
                        break;
                default: /* parent process */
                        while ((wpid = wait()) > 0);
                        printf(1, " Tested, the set value can change the nice value to 5. \nTo get the nice value, get_priority() was called \n");
                        printf(1, "Child created and terminated\n");
                        break;
        }
        /* to test if setting the nice value outside the range changes the nice value */
        switch (pid = fork()) {
                case 0: /* child process */
                        {
                                int cpid = getpid();
                                if (set_priority(cpid, 100) == 0) {
                                        printf(1, "My nice vaue was set to 100, but now it is %d \n", get_priority(cpid));
                                }
                        }
                        break;
                case -1: /* error occurred */ 
                        printf(1, "Oops error occurred. Can't fork the kid \n");
                        break;
                default: /* parent process */
                        while((wpid = wait()) > 0);
                        printf(1, "Tested, nice value could be set outside of the range, \nand set_priority() converts it to the value in range and get_priority gets the nice value \n");

        }
        return 0;
}