#include <stdio.h>

#pragma once
#ifndef READCONFIG_H_INCLUDED
#define READCONFIG_H_INCLUDED
#define MAX 128

typedef struct CONFIGURATION {
	unsigned int xdim;
	unsigned int ydim;
} CONFIG;
void set_config_val(CONFIG *config, const char *key, int val);
void read_config(CONFIG *config, FILE *f);

#endif