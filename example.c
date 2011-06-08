#include <stdio.h>
#include "insn_len.h"


int main() {
    int pos = 0, len, i;
    unsigned char *p = (unsigned char*)main;


    while (1) {
        len = insn_len(p);

        printf("length: %2d   position: %4x    bytes:  ", len, pos);

        for (i=0; i < len; i++)
            printf("%02x ", p[i]);
        printf("\n");

        if (*p == 0xc3) // ret
            break;

        pos += len;
        p += len;
    }
}
