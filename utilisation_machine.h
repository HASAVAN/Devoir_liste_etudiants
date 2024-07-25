typedef enum UtilMachine 
{
     NON=2,OUI=1

}UM;

/*definition de structure pour chaque etudiant*/
typedef struct MachineEtudiant
{
    char nom[200];
    int numero;
    UM um;
    char *presence ;

}ME;
//Liste les eleves
void list_student(ME *st);

//remlpissage  des verifications
void fil(FILE **file ,  char *argv);

//le fichier pris pour lister les eleves
void get_file(FILE *file ,ME *st , char *argv);

//remplir par numero
void fill_with_number(FILE *file , ME *st , int i);

//remplir par numero
void fill_with_name(FILE *file , ME *st , int i);

//remplissge des verification
void fill_data(FILE *file , ME *st);

//affichage des listes 
void display(FILE *file , ME *st ,  char *argv);