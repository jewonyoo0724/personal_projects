#include <stdio.h>
#include <string.h>

char *getCycle(char** cycles, int index, int card);
char *groupCalc(char **cycles, char *comp, char *result);

int main (int argc, char **argv){

    int numCycle, card, maxLength;
    char *result, *comp;
    char **cycles;

    //Sn -> get n
    printf("Cardinality of symmetric group: ");
    scanf("%i", &card);
    printf("\n");

    maxLength = 3 * card;

    //num of cycles in Sn
    printf("Enter number of cycles: ");
    scanf("%i", &numCycle);
    printf("\n");

    //array of strings. size numCycle. strings cannot be more than n (excluding parantheses)
    cycles = malloc(numCycle * maxLength * sizeof(char)); //refine

    //get cycles
    for (int i = 0; i < numCycle; i++){
        cycles[i] = getCycles(cycles, i, maxLength);
    }

    char *result = malloc(sizeof(char)); // dont know maxLength yet
    char *comp = malloc(numCycle * sizeof(char));

    printf("Enter composition order (e.g. c1c2c3): ");
    scanf("%s", comp);

    groupCalc(cycles, comp, result);

    for (int i = 0; i < numCycle; i++){
        free(cycles[i]);
    }
    free(comp);
    free(cycles);
}

//function gets cycle input
char *getCycle(char**cycles, int index, int maxLength){

    cycles[index] = malloc(maxLength * sizeof(char));

    printf("Cycle (omit if trivial; no commas) c%i= ", index+1);
    fgets(cycles[index], maxLength * sizeof(char), stdin); //(1)...(n) max

    if (cycles[index] == NULL) cycles[index] = 'i'; //for identity as it is fully trivial

    return cycles[index];
}

char *groupCalc(char **cycles, char *comp, char *result){

    int length = strlen(comp);
    int index;

    for (int i = 0; i < length; i++)
    {
        if (comp[i] == 'c') continue;

        index = comp[length-i-1] - '0';
        for (int j = 0, k = strlen(cycles[index]); j < k; j++){

            if (cycles[comp[length-i-1] - '0'][j] == '('
                || cycles[comp[length-i-1] - '0'][j] == ')') continue;

            result = str
        }
        result[i] = cycles[length-i-1]
    }
}