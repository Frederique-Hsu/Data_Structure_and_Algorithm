/**************************************************************************************************
 * Project name : TextQuery
 * Description  : This project is dedicatedly reserved for the testig purpose on module TextQuery.
 * ================================================================================================
 * File name    : main.cpp
 * Description  : This file implements the main() entry function for current project.
 * Creator      : Frederique Hsu
 * Creation date: Sat.  17 Aug. 2019
 * Copyright(C) 2019    All rights reserved.
 *
 **************************************************************************************************/

#include <QCoreApplication>
#include "testing.h"

int main(int argc, char *argv[])
{
#if 0
    QCoreApplication a(argc, argv);

    return a.exec();
#else
    return executeTextQuery(argc, argv);
#endif
}
