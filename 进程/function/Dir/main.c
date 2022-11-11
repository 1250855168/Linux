
#include<stdio.h>
#include"head.h"

int main(int argc ,char *argv[])
{
    if (argc==1)
    {
        read_Dir(".");
    }
    else
    {
        for (size_t i = 1; i < argc; i++)
        {
            read_Dir(argv[i]);
        }       
    }
    
}