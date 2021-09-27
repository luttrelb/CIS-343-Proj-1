#include "lite_vector.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

lite_vector* lv_new_vec(size_t type_size_){
	lite_vector* lv = malloc(sizeof *lv);
	lv->type_size = type_size_;
	lv->length = 0;
	lv->max_capacity = 10;
	lv->data = malloc(sizeof((void*)*lv->max_capacity));
	return lv;
}

void lv_cleanup(lite_vector* vec){
	free(vec->data);
	free(vec);
}

bool lv_clear (lite_vector* vec){
	free(vec->data);
	vec->length = 0;
	vec->max_capacity = 10;
	vec->data = malloc(sizeof((void*) * vec->max_capacity));
	//return true if vec->data is null
}

size_t lv_get_length(lite_vector* vec){
	size_t t = vec->length;
	return t;

}

void* lv_get(lite_vector* vec, size_t index){
	int curLength = vec->length;
	for (int i = curLength; i <= curLength; i++){
		if (vec->data[i] = index){
			return vec->data[i];
		}
	}
}

static bool resize(lite_vector* vec){
	vec->max_capacity = vec->max_capacity * 10;
	vec->data = malloc(sizeof((void*)*max_capacity));
}

bool lv_append(lite_vector* vec, void* element){
	int curLength = vec->length;
	if (curLength == vec->max_capacity){
		resize(vec);
		return false;
	}
	else{
		for (int i = curLength; i <= curLength; i++){
			if(i == curLength){
				vec->data[i+1] = element;
				return true;
			}
		}
	}
}
