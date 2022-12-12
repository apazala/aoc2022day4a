#include <stdio.h>

int loadInputFile();
int nextLine(char *dst);


char line[128];
int main(){
    if(loadInputFile()<0){
        fprintf(stderr, "Can't open: input.txt\n");
        return 1;
    }

    int pairOverlap = 0;
    int ai, af, bi, bf;
    for(int len = nextLine(line); len > 0; len = nextLine(line)){
        sscanf(line, "%d-%d,%d-%d", &ai, &af, &bi, &bf);
        if((ai <= bi && af >= bf) || (bi <= ai && bf >= af)){
            pairOverlap++;
        }
    }

    printf("%d\n", pairOverlap);

}


#define BUFSIZE 1<<14

char fileBuf[BUFSIZE];
char *pbuf = fileBuf;
char *pbufend = fileBuf;

int loadInputFile() {
    FILE *pf = fopen("input.txt", "r");
    if(!pf) return -1;
	pbuf = fileBuf;
	pbufend = fileBuf + fread(fileBuf, 1, BUFSIZE, pf);
    fclose(pf);
    
    return 0;
}

int nextLine(char *dst){
    char c;
	char *orig = dst;
    

    //skip whites
    while(*pbuf<= ' ' && pbuf < pbufend ){
        pbuf++;
    }

	//read line:
	while(pbuf < pbufend && (c = *(pbuf++))> '\r'){
		*(dst++)=c;
	}
	*dst = '\0';
    //return line length
    return dst - orig;
}