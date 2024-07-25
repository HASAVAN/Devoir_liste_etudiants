#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilisation_machine.h"
#define nbr_of_eleve 76

/*----------------------------------------------------------------------------------------------------------------------------*/
void fil(FILE **file ,  char *argv)
{
    *file=fopen(argv,"r");
    if(*file == NULL)
    {
        perror("Error!!!");
    }
}


/*----------------------------------------------------------------------------------------------------------------------------*/
void get_file(FILE *file , ME *st , char *argv)
{
    int i = 1 , j;
    UM me ;
    char chaine[1000];
    fil(&file , argv);
    for(i=1 ; i < nbr_of_eleve ; i++)
    {
        fgets(chaine, 254, file);
        strcpy(st[i].nom ,chaine);
        st[i].numero = i;
        for(j= 0 ; j < strlen(st[i].nom) - 1 ; j++)
        {
            if(st[i].nom[j] == '\n')
                st[i].nom[j] == '\0';
                //printf("%c",st[i].nom[j] );
        }
        //printf(" no: %d\n",st[i].numero);
    }
}

/*----------------------------------------------------------------------------------------------------------------------------*/
void fill_data(FILE *file , ME *st)
{
    int i,j,k,n,c,a, opt ,tab[nbr_of_eleve];
    int temp , menu , moyen ;
    int temp2 = 0;
    int temp3[k];
    char search[100] , src[100];
    char util[50];
    file=fopen("temporary.csv" , "w+");
    printf("\n");
    printf("\t\t|1| Afficher la liste des eleves \n");
    printf("\t\t    `````````````````````````````\n");
    printf("\t\t|2| Faire la presence des eleves\n");
    printf("\t\t    ``````````````````````````````\n");
    printf("\t\t|3| Quitter\n");
    printf("\t\t    ````````\n");
    printf("\tChoisissez l'option : ");
    scanf("%d",&menu);
    
    do
        {
        while(menu != 1 &&   menu != 2  && menu != 3)
        {
            do{
            printf("Erreur!!! Veuillez bien choisir le chiffre ci_dessous\n");
            printf("Reessayer : \n");
            printf("``````````\n");
            printf("\t\t|1| Afficher la liste des eleves \n");
            printf("\t\t    ````````````````````````````\n");
            printf("\t\t|2| Faire la presence des eleves\n");
            printf("\t\t    ````````````````````````````\n");
            printf("\t\t|3| Quitter\n");
            printf("\t\t    `````````\n");
            printf("\toption : ");
            scanf("%d",&menu);
            while((a=getchar()!= '\n') && (a != EOF));
            }while(!(scanf("%d", &menu)));
        }

        switch (menu)
        {
            case 1 :
                for(i=1 ; i<nbr_of_eleve ; i++)
                    {
                        printf("-----------------------------------------------------------\n");
                        printf("|%d ,%s|\n",i, st[i].nom);
                    }
                    printf("\t\t|2| Faire la presence des eleves\n");
                    printf("\t\t    ````````````````````````````\n");
                    printf("\t\t|3| Quitter\n");
                    printf("\t\t    `````````\n");
                    printf("\t|option| : ");
                    scanf("%d",&menu);
                    if(menu == 3)
                        exit(EXIT_SUCCESS);

            case 2 :
                for(i=1 ; i < nbr_of_eleve ; i++)
                    {
                        do
                        {
                            printf("\n\n\t1)Rechercher par numero\n\t `````````````````````\n\t2)Rechercher par nom\n\t ```````````````````\n|Choisissez| : ");
                            scanf("%d",&moyen);
                            while((a=getchar()) != '\n' && a != EOF);
                        }
                        while(!scanf("%d", &moyen));
                        switch(moyen)
                        {
                            case 1 :
                              if ( i == 1)
                                {
                                        do
                                        {
                                        printf("Entrer le numero de l'etudiant  : ");
                                        scanf("%d",&temp);
                                        while((c=getchar() != '\n') && c != EOF);
                                        }while(!(scanf("%d",&temp)));
                                }
                                else if( i > 1)
                                    {
                                        do
                                        {
                                        scanf("%d",&temp);
                                        printf("````````````````````````````````````````````````````````````````````\n");
                                        while((c=getchar()) != '\n' && c != EOF);
                                        }while(!(scanf("%d",&temp)));
                                    }
                                        while(temp > 75 || temp <=0)
                                        {
                                            printf("le numero doit etre inferieur a 76 et superieur a 0 et doit etre un nombre\n");
                                            printf("````````````````````````````````````````````````````````````````````\n");
                                            printf("Retapez le numero : ");
                                            scanf("%d",&temp);
                                        }
                                    
                                    tab[i] = temp ;
                                    temp2++;
                                printf("````````````````````````````````````````\n");   
                                printf("|%s n°%d|\n",st[temp].nom ,st[temp].numero);
                                printf("````````````````````````````````````````\n");   
                                for(j=1 ; j<76 ; j++)
                                {
                                        for(k=1 ; k<temp2 ; k++)
                                        {
                                                if(tab[k] == temp)
                                                {
                                                    while(tab[k] == temp)
                                                    {
                                                        printf("Cette personne est deja verifie \n");
                                                        printf("Entrer le numero de l'etudiant : ");
                                                        scanf("%d",&temp);
                                                    }
                                                }
                                        }
                                }
                                
                                do
                                {
                                    printf("Est ce que vous utilisez la machine de MIT ?\t(OUI/NON)\n(NB: NON <=> vous utilisez votre machine personnel)\n");
                                    scanf("%s", util);
                                    if (strcmp(util,"OUI")==0)
                                        {       
                                            st[temp].um=OUI;
                                            break;
                                        }
                                        else if (strcmp(util,"NON")==0)
                                        {
                                            st[temp].um=NON;
                                            break;
                                        }
                                }while(strcmp(util,"OUI")!=0||strcmp(util,"NON")!=0);
                                printf("==> Option <==\n\n1) Quittez\n2) Continuer\n");
                                printf("opt: ");
                                scanf("%d", &opt);
                                while(opt != 1 && opt != 2)
                                {                          
                                do
                                    {
                                        printf("\nReessayer : ");
                                        scanf("%d", &opt);
                                        while(c=getchar() != '\n'  &&  c !=EOF);
                                    }while(!(scanf("%d",&opt)));
                                }
                                if(opt == 1)
                                {
                                        fprintf(file ,",%d",st[i].numero);
                                        fprintf(file ,"%d",st[i].um);
                                    break;
                                }
                                break;
                        case 2 :
                                printf("Entrer le nom a rechercher : ");
                                scanf("%s", search);
                                for(k=1 ; k < nbr_of_eleve ; k++)
                                {
                                        for(j=0 ; j < 100 ; j++)
                                        {
                                            if(st[k].nom[j] == search[0] &&  st[k].nom[j+1] == search[1] &&  st[k].nom[j+2] == search[2]  &&  st[k].nom[j+3] == search[3]  &&  st[k].nom[j+4] == search[4] &&  st[k].nom[j+5] == search[5] &&  st[k].nom[j+6] == search[6] &&  st[k].nom[j+7] == search[7])
                                            { 
                                                printf("n° : %d  %s\n", st[i].numero ,st[i].nom);
                                                tab[i] = temp ;
                                                break;
                                            }
                                            if( strstr(st[k].nom , search) != 0 )
                                            {
                                                printf("%s ",st[k].nom);
                                                tab[i] = temp ;
                                                break;     
                                            }
                                        }
                                }
                                printf("Precisez maintenant le nom de l'etudiant :");
                                scanf("%s",search);
                                for(k=1 ; k < nbr_of_eleve ; k++)
                                {
                                        for(j=0 ; j < 100 ; j++)
                                        {
                                            if( strstr(st[k].nom , search) != 0 )
                                            {
                                                printf("%s ",st[k].nom);
                                                tab[i] = temp ;
                                                break;     
                                            }
                                        }
                                }
                                temp2++;
                                for(j=1 ; j<76 ; j++)
                                {        
                                        for(k=0 ; k<temp2 ; k++)
                                        {
                                                while(tab[k] == temp)
                                                {
                                                    
                                                        printf("\n\n");
                                                        printf("Cette personne est deja verifie \n");
                                                        printf("Re-entrer le nom a rechercher : ");
                                                        scanf("%s", search);
                                                        for(k=1 ; k < nbr_of_eleve ; k++)
                                                        {
                                                                for(j=0 ; j < 100 ; j++)
                                                                {
                                                                    if(st[k].nom[j] == search[0] &&  st[k].nom[j+1] == search[1] &&  st[k].nom[j+2] == search[2]  &&  st[k].nom[j+3] == search[3]  &&  st[k].nom[j+4] == search[4] &&  st[k].nom[j+5] == search[5] &&  st[k].nom[j+6] == search[6] &&  st[k].nom[j+7] == search[7])
                                                                    { 
                                                                        printf("n° : %d  %s\n", st[i].numero ,st[i].nom);
                                                                        break;
                                                                    }
                                                                        if( strstr(st[k].nom , search) != 0 )
                                                                    {
                                                                        printf("%s ",st[k].nom);
                                                                        temp = k ;
                                                                        break;     
                                                                    }
                                                                }
                                                        }
                                                    
                                                }
                                        }
                                    }
                                do
                                {
                                    printf("n°%d : %s ",st[temp].numero ,st[temp].nom);
                                    printf("Est ce que vous utilisez la machine de MIT ?\t(OUI/NON)\n(NB: NON <=> vous utilisez votre machine personnel)\n");
                                    scanf("%s", util);
                                    if (strcmp(util,"OUI")==0)
                                        {       
                                            st[temp].um=OUI;
                                            break;
                                        }
                                        else if (strcmp(util,"NON")==0)
                                        {
                                            st[temp].um=NON;
                                            break;
                                        }
                                }while(strcmp(util,"OUI")!=0 || strcmp(util,"NON")!=0);
                                printf("presence : %d\n",st[i].um);
                                printf("==> Option <==\n\n1) Quittez\n2) Continuer\n");
                                printf("opt: ");
                                scanf("%d", &opt);
                                if(opt == 1)
                                {
                                    break;
                                }
                                        while(opt != 1 && opt != 2)
                                        {                          
                                            do
                                            {
                                                printf("\nReessayer : ");
                                                scanf("%d", &opt);
                                                while(c=getchar() != '\n'  &&  c !=EOF);
                                                }while(!(scanf("%d",&opt)));   


                                                    for(j=0 ; j < strlen(st[i].nom) - 1 ; j++ )
                                                            {
                                                                fprintf(file ,",%c",st[temp].nom[j]);
                                                            }                                    
                                                                fprintf(file ,",%d",st[tab[temp]].numero);
                                                                fprintf(file ,"%d",st[temp].um);
                                                if(opt == 1)
                                                {
                                                   break;
                                                }    
                                        }
                                                    
                        }
                    if(opt == 1)
                        {
                            for(k=0 ; k < temp2 ; k++)
                            {
                                    for(j=0 ; j < strlen(st[i].nom) - 1 ; j++ )
                                    {
                                        fprintf(file ,",%c",st[tab[k]].nom[j]);
                                    }                                    
                                        fprintf(file ,",%d",st[tab[k]].numero);
                                        fprintf(file ,"%d",st[tab[k]].um);
                            }
                            break;
                        }
                    }
                break;
                    case 3 :
                    exit(EXIT_SUCCESS);
            }
    }while(menu == 1);
}


/*----------------------------------------------------------------------------------------------------------------------------*/
void display(FILE *file , ME *st  ,char *argv)
{
    int i ,j ;
    char *car;    
    file=fopen(argv , "w+");
    if(file != NULL)
    {
        fprintf(file,"<HTML>\n<TIILE>\n %s",argv);
        fprintf(file,"</TIILE>\n");
        fprintf(file,"<BODY>\n ");
        fprintf(file,"<TABLE>\n" );
        fprintf(file ,"Nom ,Prenom , Numero ,<center> Machine , Presence</center><br>");
        for(i=1 ; i<76 ; i++)
        {
            if(st[i].um == OUI)
            {
               st[i].um = 1 ;
               st[i].presence ="present";
            }
            else if (st[i].um == NON)
            {
               st[i].um = 2 ;
               st[i].presence ="N/A";
            }
            else
            {
                 st[i].um = 0 ;
                 st[i].presence ="absent";
            }
            for(j=0 ; j < strlen(st[i].nom) - 1 ; j++ )
            {
                fprintf(file ,"%c",st[i].nom[j]);
            }
            fprintf(file ,"%d ,<center>%d ,%s</center>",st[i].numero ,st[i].um, st[i].presence);
            printf("___________________________________________________________________<br>");
            printf("\t|");
            for(j=0 ; j < strlen(st[i].nom) - 1 ; j++ )
            {
                printf("%c",st[i].nom[j]);
            }
            printf(", |%d| , |%d| , |%s| \n",st[i].numero , st[i].um ,st[i].presence);
            printf("___________________________________________________________________<br>");
        }
        fprintf(file,"</TABLE>\n ");
            fprintf(file ,"\n");
            fprintf(file,",Verification machine du %s %s<br>",__TIME__,__DATE__);
            fprintf(file , "Indication : <br> 1 si OUI<br> 2 si PERSO <br> 0 si Inconnue");
            fprintf(file,"</BODY>\n ");
            fprintf(file,"</HTML>\n ");
    }
}