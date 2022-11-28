#include<stdio.h>
#include<stdlib.h>

char ** firstnumlines(FILE * inputfp, unsigned int num){
	char ** headbuf = (char **)calloc(num, sizeof(char *));

	for(int i=0;i<num;i++){
		headbuf[i] = (char * ) calloc(255, sizeof(char));
		fgets(headbuf[i],255,inputfp);
	}
	return headbuf;
}


int main() {
	int num;
	scanf("%d", &num);
	FILE * fp = fopen("input.txt", "r");
	char ** firstlines = firstnumlines(fp, num);
	for(int i = 0; i < num; i++){
		if(firstlines[i] != NULL){
			printf("%s", firstlines[i]);
		}
	}
	fclose(fp);
	free(firstlines);
}	
