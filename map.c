#include "map.h"
#include "readconfig.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void print_unit(){
    int rows = 5, columns = 5;

    /* Iterate over each row */
    for(int i=1; i<=rows; i++)
    {
        /* Iterate over each column */
        for(int j=1; j<=columns; j++)
        {
            if(i==1 || i==rows || j==1 || j==columns)
            {
                /* Print star for 1st and last row, column */
                printf("*");
            }
            else
            {
                printf("X");
            }
        }
        /* Move to the next line */
        printf("\n");
    }
}


void print_map(MAP_CONFIG *config){
	int xdim = config->xdim;
	int ydim = config->ydim;
	for (int i = 0; i < xdim; i++){
		for(int j = 0; i< ydim; j++);
			print_unit();
		printf("\n");
	}
}
