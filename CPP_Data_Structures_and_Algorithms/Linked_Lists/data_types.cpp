/*************************************************************************************************
 * File name    : data_types.cpp
 * Description  : Study all basic data types and their sizes.
 * Creator      : Frederick Hsu
 * Creation date: Thur. 30 June, 2016
 * Copyright(C) 2016    All rights reserved.
 *
 *************************************************************************************************/

#include "data_types.h"
#include <cstdio>
#include "Singly_Linked_List/intSLList.h"


void checkSizeOfAllBasicDataTypes(void)
{
    std::printf("List the size of all basic data types : \n");
    std::printf("--------------------------------------------------------\n");
    std::printf("Data type              | sizeof  (unit : 1 byte = 8 bits)     \n" );
    std::printf("--------------------------------------------------------\n");
    std::printf("int                    | %d                       \n", sizeof(int));
    std::printf("--------------------------------------------------------\n");
    std::printf("unsigned int           | %d              \n", sizeof(unsigned int));
    std::printf("--------------------------------------------------------\n");
    std::printf("short                  | %d                     \n", sizeof(short));
    std::printf("--------------------------------------------------------\n");
    std::printf("unsigned short         | %d            \n", sizeof(unsigned short));
    std::printf("--------------------------------------------------------\n");
    std::printf("char                   | %d                      \n", sizeof(char));
    std::printf("--------------------------------------------------------\n");
    std::printf("unsigned char          | %d             \n", sizeof(unsigned char));
    std::printf("--------------------------------------------------------\n");
    std::printf("bool                   | %d                      \n", sizeof(bool));
    std::printf("--------------------------------------------------------\n");
    std::printf("float                  | %d                     \n", sizeof(float));
    std::printf("--------------------------------------------------------\n");
    std::printf("double                 | %d                    \n", sizeof(double));
    std::printf("--------------------------------------------------------\n");
    std::printf("long                   | %d                      \n", sizeof(long));
    std::printf("--------------------------------------------------------\n");
    std::printf("unsigned long          | %d             \n", sizeof(unsigned long));
    std::printf("--------------------------------------------------------\n");
    std::printf("long long              | %d                 \n", sizeof(long long));
    std::printf("--------------------------------------------------------\n");
    std::printf("unsigned long long     | %d        \n", sizeof(unsigned long long));
    std::printf("--------------------------------------------------------\n");
    std::printf("char*                  | %d                     \n", sizeof(char*));
    std::printf("--------------------------------------------------------\n");
    std::printf("int*                   | %d                      \n", sizeof(int*));
    std::printf("--------------------------------------------------------\n");
    std::printf("short*                 | %d                    \n", sizeof(short*));
    std::printf("--------------------------------------------------------\n");
    std::printf("float*                 | %d                    \n", sizeof(float*));
    std::printf("--------------------------------------------------------\n");
    std::printf("double*                | %d                   \n", sizeof(double*));
    std::printf("--------------------------------------------------------\n");
    std::printf("long*                  | %d                     \n", sizeof(long*));
    std::printf("--------------------------------------------------------\n");
    std::printf("struct                 | %d             \n", sizeof(struct stType));
    std::printf("--------------------------------------------------------\n");
    std::printf("strcut*                | %d                 \n", sizeof(PtrSTType));
    std::printf("--------------------------------------------------------\n");
    std::printf("union                  | %d              \n", sizeof(union unType));
    std::printf("--------------------------------------------------------\n");
    std::printf("union*                 | %d                 \n", sizeof(PtrUNType));
    std::printf("--------------------------------------------------------\n");
    std::printf("struct union           | %d                  \n", sizeof(STUNType));
    std::printf("--------------------------------------------------------\n");
    std::printf("struct union*          | %d               \n", sizeof(PtrSTUNType));
    std::printf("--------------------------------------------------------\n");
    std::printf("class IntSLList        | %d                  \n", sizeof(IntSLList));
    std::printf("--------------------------------------------------------\n");
    std::printf("class IntSLLNode       | %d                 \n", sizeof(IntSLLNode));
    std::printf("--------------------------------------------------------\n");
    std::printf("class IntSLList*       | %d                 \n", sizeof(IntSLList*));
    std::printf("--------------------------------------------------------\n");
    return;
}
