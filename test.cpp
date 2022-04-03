#include <stdio.h>
#include <cstring>
#include "CDesOperate.h"
#define BUFFERSIZE 64
char strStdinBuffer[BUFFERSIZE];
char strSocketBuffer[BUFFERSIZE];
char strEncryBuffer[BUFFERSIZE];
char strDecryBuffer[BUFFERSIZE];
static ULONG8 bitmap[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
int main()
{
    char M[] = "WHITEHAT";
    char K[] = "BLACKHAT";
    ULONG8 M_[8], K_[8];
    int count;
    for (int i = 0; i < 8; ++i)
    {
        ULONG8 temp = (ULONG8)M[i];
        M_[i] = temp;
    }
    for (int i = 0; i < 8; ++i)
    {
        ULONG8 temp = (ULONG8)K[i];
        count = 0;
        for (int j = 1; j < 8; ++j)
        {
            if (temp & bitmap[j] != 0)
            {
                count++;
            }
        }
        temp <<= 1;
        if (count % 2 == 0)
        {

            temp |= bitmap[7];
        }
        K_[i] = temp;
    }
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (((ULONG8)M_[i] & bitmap[j]) == 0)
            {
                printf("0");
            }
            else
            {
                printf("1");
            }
        }
    }
    printf("\n");

    CDesOperate cDes;
    int nLen = BUFFERSIZE;
    memset(strDecryBuffer, 0, 8);
    memset(strStdinBuffer, 0, 8);
    memcpy(strStdinBuffer, M_, 8);
    for (int i = 0; i < 8; ++i)
    {
        printf("%x ", (ULONG8)M_[i]);
    }
    printf("\n");
    for (int i = 0; i < 8; ++i)
    {
        printf("%x ", (ULONG8)K_[i]);
    }
    cDes.Encry(strStdinBuffer, BUFFERSIZE, strEncryBuffer, nLen, (char *)K_, 8);
    /*for (int i = 0; i < 8; ++i)
    {
        printf("%02x ", strDecryBuffer[i]);
    }
    printf("\n\n");
    cDes.Decry(strEncryBuffer, BUFFERSIZE, strDecryBuffer, nLen, (char *)K_, 8);
    for (int i = 0; i < 8; ++i)
    {
        printf("%02x ", (ULONG8)strDecryBuffer[i]);
    }
    printf("\n");*/
}