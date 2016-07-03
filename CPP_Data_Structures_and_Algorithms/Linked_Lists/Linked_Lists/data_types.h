/*************************************************************************************************
 * File name    : data_types.h
 * Description  : Study all basic data types and their sizes.
 * Creator      : Frederick Hsu
 * Creation date: Thur. 30 June, 2016
 * Copyright(C) 2016    All rights reserved.
 *
 *************************************************************************************************/

#ifndef DATA_TYPES_H
#define DATA_TYPES_H

    void checkSizeOfAllBasicDataTypes(void);

    typedef struct stType
    {
        char cNum;          // 1 byte   memory alignment to 4 bytes
        short sNum;         // 2 bytes  memory alignment to 4 bytes
        int iNum;           // 4 bytes
        float fNum;         // 4 bytes
        double dNum;        // 8 bytes
        long lNum;          // 8 bytes
        long long llNum;    // 8 bytes
        
        long lNumArray[10]; // 8 * 10 = 80 bytes
        
#if !defined (POINTER_TYPE_MEMBER)
        char *pcNum;        // 8 bytes
        short *psNum;       // 8 bytes
        int *piNum;         // 8 bytes
        float *pfNum;       // 8 bytes
        double *pdNum;      // 8 byts
        long *plNum;        // 8 bytes
        long long *pllNum;  // 8 bytes
        
        long *plNumArray[10];   // 8 * 10 = 80 bytes
#endif  /* POINTER_TYPE_MEMBER */
        
#if !defined (MEMBER_FUNCTION_POINTER)
        void *initMemberList(void);         // member function pointer doesn't occupy the memory bytes
        int *checkRangeOfMembers(void);
        
        long calculateMembersProduct(void); // member function also neither occupy the meory bytes
#endif  /* MEMBER_FUNCTION_POINTER */
        
#if !defined (COMPLEX_DATA_STRUCTURE)
        struct stType *next;    // 8 bytes
        struct stType *prev;    // 8 bytes
#endif  /* COMPLEX_DATA_STRUCTURE */
    }
    STType, *PtrSTType;

    typedef union unType
    {
        char cNum;              // 1 byte
        int iNum;               // 4 bytes
        float fNum;             // 4 bytes
        long lNum;              // 8 bytes
        int iNumArray[10];      // 4 * 10 = 40 bytes
        
        int *piNum;             // 8 bytes
        float *pfNum;           // 8 bytes
        long *plNum;            // 8 bytes
        long *plNumArray[10];   // 8 * 10 = 80 bytes
    }
    UNType, *PtrUNType;     /* union type shared the biggest 1 member's memory bytes */

    typedef struct stunType
    {
        int iNum;                   // 4 bytes
        union
        {
            char *pcNum;            // 8 bytes
            long lNumArray[10];     // 8 * 10 = 80 bytes
        } unNum;                    // Commonly 80 bytes
        
        struct stunType *next;      // 8 bytes
    }
    STUNType,   *PtrSTUNType;

#endif  /* DATA_TYPES_H */