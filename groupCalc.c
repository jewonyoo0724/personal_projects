#include <stdio.h>

char *getCycle(char**cycle, int index, int card);
char *groupCalc(char *cycle);

int main (int argc, char **argv){

    int numCycle;
    int card;
    int maxLength;
    char *comp = malloc(sizeof(char) * numCycle);
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
    cycles = malloc(numCycle * sizeof);

    //get cycles
    for (int i = 0; i < numCycle; i++){
        getCycles(i);
    }
    getCycles
    printf("Enter composition order: ");
    scanf("%s", comp);

    groupCalc();

    for (int i = 0; i < numCycle; i++)
    {
        free(cycle[i]);
    }

    free(comp);
    free(cycles);
}

char *getCycle(char**cycle, int index, int card, int maxLength){

    printf("Cycle %i (omit if trivial): ", index+1);
    cycle[index] = malloc(maxLength * sizeof(char));

    fgets(cycles[index], maxLength * sizeof(char), stdin); //(1)...(n) max
    if (cycles[index] == NULL)
    {

    }
    cycles[index] = malloc(sizeof();
}

char *groupCalc(char *cycle){

}