%module mymodule

%{
/* part A */
#include "myheader.h"
%}

/* part B */
/* declaration in myheader.h */
int foo; /* global variable */
int bar(int x); /* function */