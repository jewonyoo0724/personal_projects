#include <stdio.h>

typedef struct{

};

char *groupCalc(char *cycle);

int main (int argc, char **argv){

    int numCycle;
    int card;
    char *comp = malloc(sizeof(char) * numCycle);
    char **cycles;

    //Sn -> get n
    printf("Cardinality of symmetric group: ");
    scanf("%i", &card);

    //num of cycles in Sn
    printf("Enter number of cycles: ");
    scanf("%i", &numCycle);

    //array of strings. size numCycle. strings cannot be more than n (excluding parantheses)
    cycles = malloc(numCycle * sizeof);

    for (int i = 0; i < numCycle; i++)
    {
        printf("Cycle %i: ", i+1);
        fgets(cycles[i], sizeof(cycles[i]), stdin);
    }

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

char *groupCalc(char *cycle){

}