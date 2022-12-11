#include <stdio.h>
// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // stdlib includes malloc() and free()
#include "string.h"
#include "math.h"
// user-defined header files
#include "transmissionerr.c"

//Any additional function prototypes if necessary

int  checkpoly(int messegelen,int polylen){
     //int p=floor(pow(2,polylen));
     while(pow(2,polylen)<messegelen+polylen+1){

        //
         polylen++;}
    return polylen;
}


int main()
{


    int selecter;
    int *array=malloc(3 * sizeof(*array));
    for(int i=0;i<3;i++){
        scanf("%d",&array[i]);}


    selecter=array[0];

    int polylen=floor(log10 (abs (array[2]))) + 1;
    int messegelen=floor(log10 (abs (array[1]))) + 1;



    char polytemp[polylen];
    sprintf(polytemp, "%d",array[2]);


    polylen=checkpoly(messegelen,polylen);
    char poly[polylen];
    int y = strlen(polytemp);
    int space=polylen-y;

    for(int i=polylen-1;i>=0;i--){
        if(i-space>=0)
            poly[i]=polytemp[i-space];
        else
            poly[i]='0';

    }
    poly[polylen]='\0';

    //printf("%s",poly);


    char sendm[messegelen];
    sprintf(sendm, "%d", array[1]);

   // printf("%d",messegelen);
    char *recvm[messegelen];
    char array_i[messegelen+polylen-1];
    int i=0;
    char s[4];

    while (i+1>0){
        fflush(stdin);
        gets(&array_i);

        if (array_i[0]=='\0'){
            break;}

        recvm[i]= (char*)malloc(messegelen * sizeof(char));
        strcpy(recvm[i],array_i);
        i++;
    }



    if (selecter==0)
        runCRC(sendm,poly,recvm);

//    else
//        runHammingCode(,parity,recvm);





    //Call any other function here

    //Free up any malloc-ed memory
    return 0;
}

void runCRC(char *sendm, char *poly, char **recvm)
{
    int polylen= strlen(poly);
    int crclen=polylen-1;

    char crc[crclen];
    generateCRC(sendm,poly,crc);

    for (int i=0;i<4;i++){
        checkCRC(recvm[i],poly);}

}

void runHammingCode(char *sendm, int parity, char **recvm)
{

}

