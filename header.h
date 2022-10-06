#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


//!----------
//!@brief finding roots of the quadratic equation
//!@param double a [in] - Coefficient before �^2
//!@param double b [in] - Coefficient before x
//!@param double c [in] - Free coefficient
//!@param double x1 [in] - First root of the quadratic equation
//!@param double x2 [in] - Second root of the quadratic equation
//!@return number of roots
//!-----------
int find_roots(double a, double b, double c, double* x1, double* x2);

//!-----------
//!@brief cleaning bufer
//!-----------
void flush();

//!-----------
//!@brief getting value for koefficients of the quadratic equation
//!@return the value of type 'double'
//!-----------
double read_num();


//!-----------
//!@brief Removes errors when working with double
//!@return value if of a
//!-----------
int is_zero(double a);

//!-----------
//!@brief solves a linear equation
//!@param double b[in] - Coefficient before x
//!@param double c [in] - Free coefficient
//!@param double* x1 [in] - the root of the equation
//!@return argument for switch
//!-----------
int linear_eq(double b,double c,double* x1);

//!----------
//!@brief checking the correctness of the program for solving the quadratic equation
//!----------
void check_quadratic_equation();

//!----------
//!@brief Variants of the number of roots of the quadratic equation
//!----------
void number_of_roots(double a, double b, double c);

int equal_or_not(double x, double test_x);

int is_equal(double x, double y);

//!----------
//!@brief Testing the quadratic equation
//!
void Test();


enum
{
  ZERO = 0,
  INF = 0xDED32,
  TWO_ROOTS = 2,
  NO_ROOTS = 0xDEAD,
  LINE_EQUATION = 0xBAD, //ONEROOT
  ONE_ROOT = 1,
};

#endif // HEADER_H_INCLUDED
