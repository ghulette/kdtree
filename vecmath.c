/*
 *  vecmath.c
 *  kdtree
 *
 *  Created by Geoff Hulette on 6/6/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include <math.h>
#include "vecmath.h"

inline float vec_fmax(float f1, float f2) {
	return f1 > f2 ? f1 : f2;
}

inline float vec_fmin(float f1, float f2) {
	return f1 < f2 ? f1 : f2;
}

inline float vec_length(vec *a) {
	return sqrt(vec_dot_prod(a, a));
}

inline void vec_neg(vec *dst, vec *v) {
	int j;
	for(j=0; j < KDT_DIM; j++) {
		dst->coord[j] = -v->coord[j];
	}
}

inline void vec_add(vec *dst, vec *a, vec *b) {
	int i;
	for(i=0; i < KDT_DIM; i++) {
		dst->coord[i] = a->coord[i] + b->coord[i];
	}
}

inline void vec_sub(vec *dst, vec *a, vec *b) {
	int i;
	for(i=0; i < KDT_DIM; i++) {
		dst->coord[i] = a->coord[i] - b->coord[i];
	}
}

inline float vec_dot_prod(vec *a, vec *b) {
	int i;
	float sum = 0.0;
	for(i=0; i < KDT_DIM; i++) {
		sum += a->coord[i] * b->coord[i];
	}
	return sum;
}

inline void vec_scalar_mult(vec *dst, vec *a, float x) {
	int i;
	for(i=0; i < KDT_DIM; i++) {
		dst->coord[i] = a->coord[i] * x;
	}
}

inline void vec_copy(point *dst, point *src) {
	int i;
	for(i=0; i < KDT_DIM; i++) {
		dst->coord[i] = src->coord[i];
	}
}

inline void vec_rand_unit(vec *dst) {
	int j;
	for(j=0; j < KDT_DIM; j++) {
		dst->coord[j] = (float)(rand() % 1000)/100 - 5;
	}
	vec_scalar_mult(dst, dst, 1/vec_length(dst));
}
