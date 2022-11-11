

#include"head.h"
#include <dirent.h>
#include<stdio.h>
#include<error.h>
#include<string.h>
#include <stdlib.h>

void is_file(char *name,void (*file)(char *))
{
   char path[256];
   char x[100];
   DIR * dir;
   struct dirent *sd;

   dir = opendir(name);
   if (dir == NULL)
   {
      perror("dir error");
      exit(1);
   }

   while ((sd = readdir(dir))!=NULL)
   {
      if (strcmp(sd->d_name,".")==0||strcmp(sd->d_name,"..")==0)
      {
        continue;
      }
      
      snprintf(path,256,"%s/%s",name,sd->d_name);

      (*file)(path);
   }

   closedir(dir);

   return;
   
   
   
}