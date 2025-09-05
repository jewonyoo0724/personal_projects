#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    int number;
    struct node *next;
}node;

void getCycle(int index, int maxLength, node *root);

int main (int argc, char *argv[]){

    int order, numFunc, maxLength;

    //get cardinality of Sn (dub order)
    printf("Cardinality of symmetric group: ");
    scanf("%i", &order);
    printf("\n");

    maxLength = 3 * order;

    //get number of cycles
    printf("Enter number of functions: ");
    scanf("%i", &numFunc);
    printf("\n");

    node **root = malloc(numFunc * sizeof(node *));
    for (int i = 0; i < numFunc; i++){
        root[i] = malloc(maxLength * sizeof(node *));
    }

    //get cycles & store in linked list
    for (int i = 0; i < numFunc; i++){
        getCycle(i, maxLength, root[i]);
    }

    //calculate composition
        //recursion for composition longer than 2


    for (int i = 0; i < numFunc; i++){
        free(root[i]);
    }
    free(root);
}

void getCycle(int index, int maxLength, node *root){

    char *cycle = malloc(maxLength * sizeof(char));

    printf("Enter function %i (may omit trivial cycles)\n", index+1);
    fgets(cycle, maxLength * sizeof(char), stdin);

    int i, j = strlen(cycle), count = 0, k = 0;
    for (i = 0; i < j; i++){
        if (cycle[i] == '(') count++;
    }

    //root 0
    i = 0;
    for (int p = 0; p < count; p++){
        for (; i < j; i++){

            if (cycle[i] == '(') continue;
            else if (cycle[i] == ')'){
                node *ptr = root[index][p];
                while (ptr != NULL) ptr = ptr->next;
                ptr->next = root[index][p]; //circle back to first node -> creates cycle
                break;
            }

            root[index][p] = NULL;
            node *n = malloc(sizeof(node));

            if (n == NULL){
                free(cycle);
                return NULL;
            }

            n->number = cycle[i] - '0';
            n->next = NULL;

            n->next = root[index][p];
            root[index][p] = n;
        }
    }
    free(cycle);
}
