# include "CDesOperate.h"
# include <stdio.h>
# include <stdlib.h>
int main()
{

    CDesOperate cd;
    char *pPlaintext = (char*)malloc(80);
    for(int i=0;i<79;++i)
    {
        pPlaintext[i] = 'b';
    }
    pPlaintext[79] = '\0';
    int nPlaintextLength = sizeof(pPlaintext);
    char *pCipherBuffer=(char*)malloc(80);
    int nCipherBufferLength = 80;
    char *pKey=(char*)malloc(64);
    for(int i =0;i<64;++i)
    {
        pKey[i]='a';
    }
    int nKeyLength =64;
    cd.Encry(pPlaintext,nPlaintextLength,pCipherBuffer, nCipherBufferLength, pKey,nKeyLength);
    return 0;
}