#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** lastnumlines(FILE * inputfp, unsigned int num)
{
  char ** tailbuf = calloc(num, sizeof(char *));
  char ** arr = calloc(num, sizeof(char *));

  //Allocating memory to temporary array
  for(int i = 0; i < num; i++){
	  arr[i] = (char *) calloc(255, sizeof(char));
  }

  int start = 0;
  int end = 0;
  int lines = 0;

  //Assigning Values to temporary array in a cyclic fashion using modulo operator till end of file
  while(!feof(inputfp)){
	  fgets(arr[end++], 255, inputfp);
	  //printf("%d - %d - %s", lines, i, tailbuf[i]);
	  end %= num;
	  lines++;
  }
  //printf("%d\n", end);

  //If the number of lines to print is greater than the size of the file free the memory allcated and close the file else allocate memory     to tailbuf
  if(num >= lines){
	  printf("Input Value greater than the size of the file\n");
	  for(int i = 0; i < num; i++){
		  free(arr[i]);
	  }
	  free(arr);
	  free(tailbuf);
	  fclose(inputfp);
	  exit(1);
  }
  else{
	  for(int i = 0; i < num; i++){
		  tailbuf[i] = (char *) calloc(255, sizeof(char));
	  }
  }

  //Copy the input value from temporary array to tailbuf
  for(int i = end-1; i < num; i++){
	  strcpy(tailbuf[start],arr[i]);   //strcpy because by using this the value is copied from temp without changing the address that                                              tailbuf points to and if we use assignment operator we are changing the address that tailbuf 						 was initially pointing to and if we free the memory of the temporary array then tailbuf will 						   not have any address that it points to which will give us an error if we try to access that                                               memory and will also cause memory leak because we will not be able to access the original                                                 memory dynamically allocated to tailbuf using calloc.
	  start++;
  }
  for(int i = 0; i < end-1; i++){
	  strcpy(tailbuf[start],arr[i]);
	  start++;
  }

  //Free the temporary array
  for(int i = 0; i < num; i++){
	  free(arr[i]);
  }
  free(arr);
  return tailbuf;
}

int main()
{
   int n;
   printf("Enter the Input Value : ");
   scanf("%d", &n);
   if(n > 100 || n <= 0){
	   printf("Input Value out of range\n");
	   return 0;
   }
   FILE * fp = fopen("input.txt", "r");
   // Assume fp is not NULL
   char ** lastlines = lastnumlines(fp, n);

   //Printing the lastlines
   for (int i = 0; i < n; i++) {
        if (lastlines[i] != NULL) {
            printf("%s", lastlines[i]);
        }
   }

   // Code to free lastlines will come here
   for(int i = 0; i < n; i++){
	   free(lastlines[i]);
   }
   free(lastlines);
   fclose(fp);
   return 0;
}
