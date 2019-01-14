#include "readconfig.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void set_config_val(CONFIG *config, const char *key, int val) {
	if (config == NULL)
		return;
	if (strcmp(key, "xdim") == 0)
		config->xdim = val;
	else if (strcmp(key, "ydim") == 0)
		config->ydim = val;
	else
		;
}

void read_config(CONFIG *config, FILE *f) {
	char str[MAX];
	char *token;
	const char *delim = "=\n";

	while (fgets(str, MAX, f) != NULL) {
		if (strchr(str, ";"))
			;
		else if (strchr(str, "=")) {
			char varname[MAX];
			int value;

			token = strtok(str, delim);
			strcpy(varname, token);

			token = strtok(NULL, delim);
			value = atoi(token);

			set_config_val(config, varname, value);
		}
	}
	fclose(f);
	return;
}

