/*!
 *  \file       sequential_string.c
 *  \brief
 *
 */


#include "sequential_string.h"

#include <string.h>
#include <stdio.h>

Status StrAssign(SString T, const char* str)
{
    unsigned len = strlen(str);
    if (len > MAX_STR_LEN)
    {
        return ERROR;
    }
    for (unsigned index = 0; index < len; ++index)
    {
        T[index] = *(str + index);
    }
    T[strlen(str)] = '\0';
    return OK;
}

void StrCopy(SString target, SString source)
{
    unsigned index = 0;
    while (source[index] != '\0')
    {
        target[index] = source[index];
        index++;
    }
    target[index] = '\0';
}

Status StrEmpty(SString S)
{
    if (S[0] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int StrLength(SString S)
{
    int index = 0;
    while (S[index] != '\0')
    {
        index++;
    }
    return index;
}

int StrCompare(SString S, SString T)
{
    int index = 0;
    while ((S[index] != '\0') && (T[index] != '\0'))
    {
        if (S[index] != T[index])
        {
            return S[index] - T[index];
        }
        index++;
    }
    return StrLength(S) - StrLength(T);
}

void StrPrint(SString s)
{
    printf("\n");
    printf("%s", s);
    printf("\n");
}

void ClearString(SString S)
{
    for (int index = 0; index < MAX_STR_LEN; ++index)
    {
        S[index] = '\0';
    }
}

Status StrConcat(SString target, SString src1, SString src2)
{
    int len1 = StrLength(src1), len2 = StrLength(src2);
    if (len1 + len2 <= MAX_STR_LEN)
    {
        int i = 0;
        for (i = 0; i < len1; ++i)
        {
            target[i] = src1[i];
        }
        for (int j = 0; j < len2; ++j)
        {
            target[i++] = src2[j];
        }
        target[i] = '\0';
        return true;
    }
    else
    {
        int i = 0;
        for (i = 0; i < len1; ++i)
        {
            target[i] = src1[i];
        }
        for (int j = 0; j < MAX_STR_LEN - len1; ++j)
        {
            target[i++] = src2[j];
        }
        target[i] = '\0';
        return false;
    }
}

Status SubString(SString sub, SString src, int pos, int len)
{
    int src_len = StrLength(src);
    if ((pos < 0) || (pos > src_len) || (len < 0) || (len > src_len - pos + 1))
    {
        return ERROR;
    }
    int index = 0;
    for (index = 0; index < len; ++index)
    {
        sub[index] = src[pos + index - 1];
    }
    sub[index] = '\0';
    return OK;
}

int Index(SString src, SString sub, int pos)
{
    bool compare_str(SString a, SString b, int len)     // C11也允许这种在函数里面再定义函数的，这也是一种形式的闭包。
    {
        for (int index = 0; index < len; index++)
        {
            if (a[index] != b[index])
            {
                return false;
            }
        }
        return true;
    }

    int src_len = StrLength(src), sub_len = StrLength(sub);

    if (0 <= pos && pos <= src_len)
    {
        for (int i = pos; i <= src_len - sub_len; ++i)
        {
            if (true == compare_str(src + i, sub, sub_len))
            {
                return i;
            }
        }
    }
    return 0;
}

Status StrInsert(SString src, int pos, SString sub)
{
    int src_len = StrLength(src), sub_len = StrLength(sub);

    if (pos < 0 || pos > src_len)
    {
        return ERROR;
    }
    if (src_len + sub_len <= MAX_STR_LEN - 1)   // complete insertion
    {
        for (int index = pos; index < src_len; ++index)
        {
            src[index + sub_len] = src[index];
        }
        for (int index = pos; index < pos + sub_len ; ++index)
        {
            src[index] = sub[index - pos];
        }
        src[src_len + sub_len] = '\0';
        return true;
    }
    else    // partially insertion
    {
        if (sub_len >= MAX_STR_LEN - 1 - pos)
        {
            for (int index = pos; index < MAX_STR_LEN - 1; ++index)
            {
                src[index] = sub[index - pos];
            }
        }
        else
        {
            for (int index = pos + sub_len; index < MAX_STR_LEN-1; ++index)
            {
                src[index] = src[index - sub_len];
            }
            for (int index = pos; index < pos + sub_len; ++index)
            {
                src[index] = sub[index - pos];
            }
        }
        src[MAX_STR_LEN-1] = '\0';
        return false;
    }
}