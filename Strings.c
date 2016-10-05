
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int fakestrlen(char *a){
  int length;
  while(*a){
    length++;
    a++;
  }
  return length;
}
//Working
char * fakestrcat(char *dest, char *src){
  char *point = src;
  char *srcpoint = dest;
  while(*point){
    point++;
  }
  while(*srcpoint){
    *point = *srcpoint;
    point++;
    srcpoint++;
  }
  point++;
  *(point) = 0;
  return dest;
}
//Working
char * fakestrchr(char *str, char val){
  char *pointer = str;
  while(*pointer){
    if(*pointer == val){
      return pointer;
    }else{
      pointer++;
    }
  }
  return NULL;
}
//Working
char * fakestrcpy(char *dest,char *src){
  char *destpoint = dest;
  while(*src){
    *destpoint = *src;
    destpoint++;
    src++;
  }
  *(destpoint) = 0;
  return dest;
}

int fakestrcmp(char *a,char *b){
  char *p = a;
  char *q = b;
  
  while(*p && *q){
    int diff = *p - *q;
    if (*(p+1)&&*(q+1)){
      if(diff){
	return diff;
      }else{
	p++;
	q++;
      }
    }else{
      return *(p+1) - *(q+1);
    }
  }  
}

char * fakestrncpy(char *dest, char *src,int n){
  char *destpoint = dest;
  char *srcpoint = src;
  while(n && *src){
    *destpoint = *srcpoint;
    destpoint++;
    srcpoint++;
    n--;
  }
  *(destpoint) = 0;
  return dest;
}


int main(){
  //Strlen Test:
  char str[] = "hello";
  int n = fakestrlen(str);
  printf("Length of Imagine = %d\n",strlen(str));
  printf("My Length of Imagine = %d\n",n);
  
  char i = 'i';

  // Strchr Test:
  // Built in function
  char *ans1 = strchr(str,i);
  printf("\nBuilt-in strchr = %p\n",ans1);
  // My function
  char *ans2 = fakestrchr(str,i);
  printf("My strchr = %p\n\n",ans2);
  
  // Strcat Test:
  char c[15] = "Imagine";
  char d[15] = " that";
  // Built in function  
  char *ans3 = strcat(c,d);
  printf("strcat(\"Imagine\",\"that\") = %s\n",c);
  strcpy(c,"Imagine"); 
  // My function
  char *ans4 = fakestrcat(d,c);
  printf("My strcat(\"Imagine\",\"that\") = %s\n\n",c);
  
  // Strcpy and Strncpy Test:
  // Built in function
  char *ans5 = strncpy(str,c,3);
  printf("Copy the first three bytes of Imagine = %s\n",c);
  strcpy(c,"hello");
  // My function
  char *ans6 = fakestrncpy(c,"Imagine",3);
  printf("My strncpy  = %s\n\n",c);
  strcpy(c,"hello");
  printf("Before strcpy = %s\n",c);
  printf("Built in strcpy = %s\n",strcpy(c,"woah"));
  strcpy(c,"hello");
  printf("Before My Strcpy = %s\n",c);
  char *point = fakestrcpy(c,"woah");
  printf("After My Strcpy = %s\n\n",point);

  // Strcmp Test:
  char *Stringa = "imagine";
  char *Stringb = "imagbne";
  int p = strcmp(Stringa,Stringb);
  printf("Strcmp(%s,%s) = %d\n",Stringa,Stringb,p);  
  // My function
  int q = fakestrcmp(Stringa,Stringb);
  printf("MyStrcmp(%s,%s) = %d\n",Stringa,Stringb,q);
	 
  

//printf("%s\n",fakestrcat(tht,img));
  //int j = len(arr);
  //printf("length of arr = %d\n",j);
  return 0;
}
