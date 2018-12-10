#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main(){
  //creating the segment and connecting
  int shmid = shmget(200, 0700);
  //getting a pointer to the segment
  char * data = shmat(shmid, (void *)0, 0);
  printf("segment created\n");

  int i = 1;
  while (i){
    printf("do you want to change the segment? (y/n)\n");
    char ans[16];
    fgets(ans);
    if (strcmp(ans,"y") == 0){
      printf("enter your edits:\n");
      fgets(data);
    }
    if (strcmp(ans,"n") == 0){
      i = 0;
      printf("do you want to delete the segment? (y/n)\n");
      fgets(ans);
      if (strcmp(ans,"y") == 0){
        //delete
      }
      else {
        i = 1;
      }
    }
  }
  return 0;
}
