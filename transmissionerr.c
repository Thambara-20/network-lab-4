// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // includes malloc(),free()
//Add any necessary headers here

// user-defined header files
#include "transmissionerr.h" // do not modify this file
static char* crcremainder;

void xor1(char *a, char *b,char result[]){
    int n = strlen(b);
    for(int i = 1; i < n; i++)
    {

        if (a[i] == b[i])
            result[i-1] = '0';
        else
            result[i-1] = '1';

    }
}

// put your function prototypes for additional helper functions below:
char* mod2div(char divident[], char *poly,char *crc,int pick,int n){


    int polylen= strlen(poly);
    int i=0;
    char result[strlen(poly) - 1];

    while (pick<n+1){

        char tmp[polylen];
        strncpy(tmp,&divident[i], polylen);
        tmp[polylen] = '\0';
      //  printf("\nThe original string is: %s\n",divident);

        if (tmp[0]=='0'){
            char zeros[polylen];
            for(int h=0;h<polylen;h++)
                zeros[h]='0';

            zeros[polylen]='\0';
          //  printf("tmp is: %s %s\n",tmp,zeros);
            xor1(zeros, tmp, result);
            result[polylen - 1] = '\0';
         //   printf("result is: %s\n", result);
            }
        else {
           // printf("tmp is: %s %s\n",tmp,poly);
            xor1(poly, tmp, result);
            result[strlen(poly) - 1] = '\0';
           // printf("result is: %s\n", result);
           }
        for(int x=1;x<polylen;x++){
            divident[i+x]=result[x-1];}

        i++;
        pick++;

        }

        for(int h=0;h<polylen;h++)
            crc[h]=result[h];

    }


// implementation
void generateCRC(char *sendm, char *poly, char *crc)

{   int sendmlen = strlen(sendm);
    int polylen  = strlen(poly);

    int n= sendmlen+polylen-1;

    char appended[n-1];

    for (int i=0;i<n;i++){
        if (i>= sendmlen){
            appended[i]='0';
           // printf("%c",appended[i]);
            continue;
        }
        appended[i]= sendm[i];
       // printf("%c",appended[i]);
    }
    appended[n]='\0';

    mod2div(appended, poly,crc,polylen,n);
    crcremainder=crc;
   // printf("crc is: %s\n", crcremainder);





}
int checkCRC(char* recvm, char *poly)
{
   // printf("%c\n", recvm[0]);
    int polylen= strlen(poly);
    int recvmlen=strlen(recvm);
    int n=polylen+recvmlen-1;
    for(int x=recvmlen;x<n;x++){
        recvm[x]=crcremainder[x-recvmlen];
    }
    recvm[n]='\0';
    //printf("%s\n",recvm);
    char result[polylen-1];

    mod2div(recvm, poly,result,polylen,n);
    //printf("remainder is: %s\n", result);
    //printf("%s,%s ",crcremainder,result);
    int error=0;
    for(int i=0;i<polylen-1;i++){
        if (result[i]!='0'){
            printf("%d ",1);
            error=1;

            break;
        }
    }
    if (error==0){
        printf("%d ",0);
    }


}
void generateHammingCode(char *sendm, int parity, char *output)
{
    //TODO
}
int checkMessage(char *recvm, int parity)
{
    //TODO
}
