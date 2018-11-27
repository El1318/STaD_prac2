
#include "tp4.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define log(str...)				\
  if (log_enabled()) {				\
    fprintf(stderr, "\tLOG: " str);		\
  }

const double PI=3.14;

static int do_log=0;

static inline int log_enabled() {
	return do_log;
}

void set_log(int v) {
	log("Invocation of set_log(%i)\n", v);
	do_log=v;
}

double pi() {
	log("Invocation of pi()\n");
	return PI;
}

double add_pi(double v) {
	log("Invocation of add_pi(%lg)\n", v);
	return pi()+v;
}

static int nb_created=0;
static int nb_destroyed=0;

void stats(void) {
	fprintf(stderr, "Number of created vectors : %i\n", nb_created);
	fprintf(stderr, "Number of destroyed vectors : %i\n", nb_destroyed);
}


struct _vector {
	int valid;
	double cs[3];
};

static Vector* alloc() {
	Vector *v=malloc(sizeof(Vector));
	v->valid=0xBEEF;
	nb_created++;
	return v;
}

static void desalloc(Vector *v) {
	v->valid=0;
	nb_destroyed++;
	free(v);
}

static void check(Vector *v) {
	assert(v->valid == 0xBEEF);
}

/* Create a new vector using the given 3 doubles */
Vector* Vector_create(double a, double b, double c) {
	log("Vector_create\n");
	Vector *v=alloc();
	check(v);
	v->cs[0]=a;
	v->cs[1]=b;
	v->cs[2]=c;
	return v;
}

/* Create anew vector using two others */
Vector* Vector_add(Vector *v1, Vector* v2) {
	log("Vector_add\n");
	Vector *v=alloc();
	int i;
	check(v);
	check(v1);
	check(v2);
	for(i=0; i<3; i++) {
		v->cs[i]=v1->cs[i]+v2->cs[i];
	}
	return v;	
}

/* Return coordinates of v*/
double Vector_elem(Vector *v, int coord) {
	log("Vector_elem\n");
	check(v);
	return v->cs[coord];
}

/* Return a description of vector v */
char* Vector_str(Vector *v) {
	log("Vector_str\n");
	check(v);
	int lg;
	lg=snprintf(NULL, 0, "[%lg,%lg,%lg]", v->cs[0], v->cs[1], v->cs[2]);
	char*ret=malloc(lg+1);
	snprintf(ret, lg+1, "[%lg,%lg,%lg]", v->cs[0], v->cs[1], v->cs[2]);
	return ret;
}

/* Destroy vector v */
void Vector_destroy(Vector *v) {
	log("Vector_destroy\n");
	check(v);
	desalloc(v);
}

