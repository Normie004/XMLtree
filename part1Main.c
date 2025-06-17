#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern char * pop();
extern void push(char *);
extern int isEmpty();

int main(int argc, char * argv[])
{
  int charac; 
  int Nextcharac;
  char * top; 
  int a;  

  while ((charac = getchar()) != EOF)
	{
    if(charac == '\n'){ 
      break;
	}
    if (!(isalpha(charac) || charac== '>' || charac== '<' || charac == '/')){ 
      continue;
	}
    if(charac== '<'){ 
      Nextcharac = getchar();
      if(Nextcharac == '/'){ 
        top = pop(); 
		a = getchar(); 
			
			if ((char) a != *top) { 
				fprintf (stderr, "Invalid.\n");
				exit (1); 
			}
		}
		else { 
			char * charStart = malloc(sizeof(char)); 
            *charStart = Nextcharac; 
            push(charStart);    
		}
	}
}

  if (isEmpty()){ 
        fprintf(stdout, "Valid.\n");
        exit(0); 
    } else {
        fprintf (stderr, "Invalid.\n");
        exit(1);
    }
  return 0;
}
