/********************************************************************************************************************************\
 * 
 *        FILE main.c
 *        Com. Francesco Cesare Giorgio Teseo Bosatra
 *        
 *        Issue:    https://github.com/DarthFener/Giulia/issues
 *        README:   https://github.com/DarthFener/Giulia/blob/master/README.md
 *        Licence:  https://choosealicense.com/licenses/mit/
 * 
 * 
 * *******************************************************************************************************************************/





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "main.h"
#define BUFFER 500

char * cambiaNomeStringa (char *);
char * cambiaNomeFile (char *);

void menu();
void menuStringa();


int main(int argc, char *argv[])
{
    
    
    if (argc == 2 )
        cambiaNomeStringa(argv[1]);
        
    else
        menu();
    

}

void menu()
{
    int scelta;
    printf("\nCiao, Fai una scelta tra le seguenti:\n");
    printf("1.\t: Sostituzione da stringa\n");
    printf("2.\t: Sostituzione da file\n");
    printf("3.\t: Uscita\n");
    scanf("%d", &scelta);
    getchar();

    if (scelta == 1)
        menuStringa();
    if (scelta == 2)
        cambiaNomeFile("giulia.txt");
    if (scelta == 3)
        exit(0);
    else
        menu();
    
}

void menuStringa()
{
    char buffer[BUFFER];
    char * stringa;
    int lunghezza;
    
    printf("\n\nDigita una stringa da cui sostituire il nome Giulia:\n");
    fgets(buffer, BUFFER, stdin);
    lunghezza = strlen(buffer);

    stringa = (char *)malloc(sizeof(char) * lunghezza);
    stringa = buffer;
    

    cambiaNomeStringa(stringa);
  
    return;
}




char * cambiaNomeStringa ( char* s)
{
    
    char* risultato;
    char * oldW = "Giulia";
    char* newW = "Gigliola";
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);
 
    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], oldW) == &s[i]) {
            cnt++;
 
           
            i += oldWlen - 1;
        }
    }
 
   
    risultato = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1);
 
    i = 0;
    while (*s) {
      
        if (strstr(s, oldW) == s) {
            strcpy(&risultato[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            risultato[i++] = *s++;
    }
 
    risultato[i] = '\0';
    printf("%s",risultato);
    return risultato;

}

char * cambiaNomeFile(char * file)
{
   
    FILE *fi, *fo;
    char buffer[BUFFER];
    fi = fopen("giulia.txt", "r");

    if (fi == NULL)
    {
        printf("Errore nel file di input");
        return file;
    }

    fo = fopen("output.txt", "w");
    if (fo == NULL)
    {
        printf("Errore nel file di output");
        return file;
    }

    do
    {
        fgets(buffer, BUFFER, fi);
        char * stringa = cambiaNomeStringa(buffer);
        fprintf(fo, "%s", stringa);
    } while (!feof(fi));

    fclose(fi);
    fclose(fo);
    

    return file;
    


}
