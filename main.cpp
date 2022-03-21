# include "CDesOperate.h"
# include <stdio.h>
# include <stdlib.h>
int main()
{

    CDesOperate cd;
    char pPlaintext[] = "happynewyear!!!!!";
    int nPlaintextLength = sizeof(pPlaintext);
    char *pCipherBuffer=(char*)malloc(64);
    int nCipherBufferLength = 64;
    char *pKey=(char*)malloc(64);
    for(int i =0;i<64;++i)
    {
        pKey[i]='a';
    }
    int nKeyLength =64;
    cd.Encry(pPlaintext,nPlaintextLength,pCipherBuffer, nCipherBufferLength, pKey,nKeyLength);
    printf("%s\n",pCipherBuffer);
    return 0;
}