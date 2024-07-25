#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utilisation_machine.h"
#define nbr_of_eleve 76

int main(int argc , char *argv[])
{
    FILE *file=NULL;
    ME *st=NULL;
    st=(ME*)malloc(sizeof(ME)*nbr_of_eleve);
    fil(&file , argv[1]);

    get_file(file , st  , argv[1]);
    
    fill_data(file ,st);

    display(file , st , argv[2]);
    
    return 0;
}