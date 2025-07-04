#include <string.h>
#include <stdbool.h>

bool isValidSerialization(char* preorder) {
    //raiz
    int vagas = 1;

    char* token = strtok(preorder, ",");

    while (token != NULL) {
    
        if (vagas == 0) {
            return false;
        }
        
        //numero
        if (*token != '#') {
            vagas++;
        } 
        //nulo
        else {
            vagas--;
        }

        // prox token
        token = strtok(NULL, ",");
    }

    //vagas usadas
    return vagas == 0;
}