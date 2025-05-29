/*!
 *  \file       sequential_string.h
 *  \brief
 *
 */


#pragma once

#include "../pre_defines.h"
/*!
 *  \brief  Abstract Data Type : Sequential String
 *
 */


#define MAX_STR_LEN   0xFF
typedef unsigned char SString[MAX_STR_LEN + 1];

Status StrAssign(SString T, const char* str);
void StrCopy(SString target, SString source);
Status StrEmpty(SString S);
int StrCompare(SString S, SString T);
int StrLength(SString S);
void ClearString(SString S);
#define DestroyString ClearString
Status StrConcat(SString target, SString src1, SString src2);
Status SubString(SString sub, SString src, int pos, int len);
int Index(SString src, SString sub, int pos);
Status StrInsert(SString src, int pos, SString sub);
void StrPrint(SString s);
