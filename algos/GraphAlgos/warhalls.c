/* Warshall's algorithm to get a transitive closure of a given graph (relation) */

#include<stdio.h>
#include<stdlib.h>

int ** warshalls (int mo[][4]) {
    int **tm = malloc(4 * sizeof(int *));

    for (int j = 0; j < 4; j++) {
        tm[j] = malloc(4 * sizeof(int));
        for (int k = 0; k < 4; k++) {
            tm[j][k] = mo[j][k];
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int m = 0; m < 4; m++) {
            for (int n = 0; n < 4; n++) {
                tm[m][n] = tm[m][n] | (tm[m][i] & tm[i][n]);
            }
        }
    }

    return tm;
}

void destroyArray (int **m) {
    for (int i = 0; i < 4; i++) {
        free(m[i]);
    }
    free(m);
}

int main () {
    int matrixSize = 4;
    int matrix[4][4] = {
        {0b0, 0b0, 0b0, 0b1},
        {0b1, 0b0, 0b1, 0b0},
        {0b0, 0b0, 0b0, 0b1},
        {0b0, 0b0, 0b1, 0b0}
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    int **transitiveClosure = warshalls(matrix);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", transitiveClosure[i][j]);
        }
        printf("\n");
    }

    destroyArray(transitiveClosure);
}