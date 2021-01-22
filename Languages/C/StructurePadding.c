#include <stdio.h>
#include <string.h>

#pragma pack(1)
struct structure1
{
       int id1;
       int id2;
       char name;
       char c;
       float percentage;
};

struct structure2
{
       int id1;
       char name;
       int id2;
       char c;
       float percentage;
};

typedef struct d
{
    int flag1 : 1;
    int flag2 : 1;
    int flag3 : 1;
    int flag4 : 1;
    int flag5 : 1;
    int flag6 : 1;
    int flag7 : 1;
    int flag8 : 1;
    int flag9 : 1;
    int flag10 : 1;
    int flag11 : 1;
    int flag12 : 1;
    int flag13 : 1;
    int flag14 : 1;
    int flag15 : 1;
    int flag16 : 1;
    int flag17 : 1;
    int flag18 : 1;
    int flag19 : 1;
    int flag20 : 1;
    int flag21 : 1;
    int flag22 : 1;
    int flag23 : 1;
    int flag24 : 1;
    int flag25 : 1;
    int flag26 : 1;
    int flag27 : 1;
    int flag28 : 1;
    int flag29 : 1;
    int flag30 : 1;
    int flag31 : 1;
    int flag32 : 1;
    // int flag33 : 1;
    // 4 bytes hi le raha hy so there are 32 bits in 4 bytes agar 33rd bit use hogi to phir 8 bytes lega
}flag;

void main()
{
    struct structure1 a;
    struct structure2 b;
    flag c;

    printf("size of structure1 in bytes : %d\n",
                   sizeof(a));
    printf ( "\n   Address of id1        = %u", &a.id1 );
    printf ( "\n   Address of id2        = %u", &a.id2 );
    printf ( "\n   Address of name       = %u", &a.name );
    printf ( "\n   Address of c          = %u", &a.c );
    printf ( "\n   Address of percentage = %u", &a.percentage );

    printf("   \n\nsize of structure2 in bytes : %d\n", sizeof(b));
    printf ( "\n   Address of id1        = %u", &b.id1 );
    printf ( "\n   Address of name       = %u", &b.name );
    printf ( "\n   Address of id2        = %u", &b.id2 );
    printf ( "\n   Address of c          = %u", &b.c );
    printf ( "\n   Address of percentage = %u", &b.percentage );

   printf("   \n\nsize of structure3 in bytes : %d\n", sizeof(c));
   printf ( "\n   Can not get the address of bits so we wont bother\n");

}
