/*!
 *  \file       sort_algorithms.h
 *  \brief      
 *  
 */


#pragma once


typedef int     DataType;


void insert_sort(DataType data[], int n);
void select_sort(DataType data[], int n);
void bubble_sort(DataType data[], int n);
void quick_sort(DataType data[], int left, int right);