//{===================================================================
//! @file array.h
//! @date 2015-09-30 22:22
//! @author Korostyleva Anastasiya <koros-anastasiya@yandex.ru>
//! @version 2.00
//!
//! Allows to create and sort an array of integer.
//!
//! @par Program reads one number - length of array.
//! Returns chaotic array, and then sorted one.
//!
//}===================================================================

//----Headers------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 
//-----------------------------------------------------------------------------

//----Types--------------------------------------------------------------------
typedef int myType;

typedef struct array_t
{
  int length;
  myType *array;
} array_t;
//-----------------------------------------------------------------------------
