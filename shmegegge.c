#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main(){
  //ftok
  key_t key = ftok("/Systems/MKS65C-shmegegge/keyfile", 'R');
  //creating the segment and connecting
  int shmid = shmget(key, 200, 0700);
  //getting a pointer to the segment
  char * data = shmat(shmid, (void *)0, 0);
  printf("segment created\n");
  printf("do you want to change the segment? (y/n)\n");
  char buf[100];
  fgets(buf, 100, stdin);
  buf[strlen(buf)-1] = 0;
  if (strcmp(buf,"y") == 0) {
    printf("enter your edits:\n");
    /*char edit[200];
    fgets(edit, 200, stdin);
    strcpy(data, edit);*/
    //fgets(data, 200, stdin);
    //printf("data: %s\n", data);
    printf("methods shown in documentation dont actually work :(\n");
  }
  //else {
    printf("press enter to delete the segment");
    fgets(buf, 100, stdin);
    //detach from segment
    shmdt(data);
    //delete segment
    shmctl(shmid, IPC_RMID, NULL);
  //}

/*
  int i = 1;
  while (i){
    printf("do you want to change the segment? (y/n)\n");
    char ans[16];
    fgets(ans, 16, stdin);
    ans[strlen(ans)-1] = 0;
    if (strcmp(ans,"y") == 0){
      printf("enter your edits:\n");
      char buf[200];
      fgets(buf, 200, stdin);
      strcpy(data, buf);
      printf("data: %s\n", data);
    }
    if (strcmp(ans,"n") == 0){
      i = 0;
      printf("do you want to delete the segment? (y/n)\n");
      char ans2[16];
      fgets(ans2, 16, stdin);
      ans2[strlen(ans2)-1] = 0;
      if (strcmp(ans2,"y") == 0){
        //detach from segment
        shmdt(data);
        //delete segment
        shmctl(shmid, IPC_RMID, NULL);
      }
      else {
        i = 1;
      }
    }
  }
*/
  return 0;
}
