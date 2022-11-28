#include<stdio.h>
#include<stdlib.h>

char ** firstnumlines(FILE * inputfp, unsigned int num){
	int max = 0;
	char ** headbuf = (char **)calloc(num, sizeof(char *));

	for(int i=0;i<num;i++){
		headbuf[i] = (char * ) calloc(255, sizeof(char));
		fscanf(inputfp,"%s",headbuf[i]);
	}
	return headbuf;
}


int main() {
	int num = 10;
	FILE * fp = fopen("input.txt", "r");
	char ** firstlines = firstnumlines(fp, 10);
	for(int i = 0; i < 10; i++){
		if(firstlines[i] != NULL){
			printf("%s\n", firstlines[i]);
		}
	}
	fclose(fp);
	free(firstlines);
}	
