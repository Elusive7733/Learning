#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
  char nouns[20], temp;
  char *ptr;
  int len, i;
  printf("Enter a Singular Noun\n");
  gets(nouns);
  len = strlen(nouns);
  ptr = (char*) calloc(len, len*sizeof(char) + 1);
  for (i = 0 ; i < len ; i++) {
      *(ptr+i) = nouns[i];
  }
    temp = *(ptr+len-1);
    switch (temp) {
      case 'f':
        ptr = (char*) realloc(ptr, len*sizeof(char) + 3);
        *(ptr+len-1) = 'v';
        *(ptr+len) = 'e';
        *(ptr+len+1) = 's';
        len += 2;
        break;
      case 'e':
        ptr = (char*) realloc(ptr, len*sizeof(char) + 2);
        temp = *(ptr+len-2);
        if(temp == 'f')
        {
          *(ptr+len-2) = 'v';
          *(ptr+len) = 's';
        }
        else
        {
          *(ptr+len) = 's';
        }
        len += 1;
        break;
      case 'h':
        ptr = (char*) realloc(ptr, len*sizeof(char) + 3);
        *(ptr+len) = 'e';
        *(ptr+len+1) = 's';
        len += 2;
        break;
      case 'o':
        ptr = (char*) realloc(ptr, len*sizeof(char) + 3);
        *(ptr+len) = 'e';
        *(ptr+len+1) = 's';
        len += 2;
        break;
      case 'z':
        ptr = (char*) realloc(ptr, len*sizeof(char) + 3);
        *(ptr+len) = 'e';
        *(ptr+len+1) = 's';
        len += 2;
        break;
      case 'x':
        ptr = (char*) realloc(ptr, len*sizeof(char) + 3);
        *(ptr+len) = 'e';
        *(ptr+len+1) = 's';
        len += 2;
        break;
      default:
        ptr = (char*) realloc(ptr, len*sizeof(char) + 2);
        *(ptr+len) = 's';
        len += 2;
        break;
    }
    // if(temp == 'h' || temp == 'o' || temp == 'z' ||temp == 'x'){
    //     ptr = (char*) realloc(ptr, len*sizeof(char) + 3);
    //     *(ptr+len) = 'e';
    //     *(ptr+len+1) = 's';
    //     len += 2;
    // }
    // else if(temp == 'e' && *(ptr+len-2) == 'f'){
    //   ptr = (char*) realloc(ptr, len*sizeof(char) + 2);
    //   *(ptr+len-2) = 'v';
    //   *(ptr+len) = 's';
    //   len += 1;
    // }
    // else if (temp == 'f'){
    //       ptr = (char*) realloc(ptr, len*sizeof(char) + 3);
    //       *(ptr+len-1) = 'v';
    //       *(ptr+len) = 'e';
    //       *(ptr+len+1) = 's';
    //       len += 2;
    // }
    // else{
    //       ptr = (char*) realloc(ptr, len*sizeof(char) + 2);
    //       *(ptr+len) = 's';
    //       len += 2;
    // }
    for (i = 0 ; i < len ; i++) {
        *(ptr+i) ;
        printf("%c", *(ptr+i));
    }
}
