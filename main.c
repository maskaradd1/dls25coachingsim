#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TechMax 45
#define FitMax 35

struct card {
    int SPE;
    int ACC;
    int STA;
    int STR;
    int CON;
    int PAS;
    int SHO;
    int TAC;
};

void trainTechnical(struct card *c);
void trainFitness(struct card *c);

int main(void) {
    srand(time(NULL));

    int iteration = 1;
    int perfect = 0;

    while (perfect == 0) {
        struct card c = {90, 77, 90, 74, 81, 83, 74, 80};

        printf("iteration: %d\n", iteration);

        int t = 0;
        while (t != FitMax) {
            trainFitness(&c);
            t++;
        }

        t = 0;
        while (t != TechMax) {
            trainTechnical(&c);
            t++;
        }

        int count = 0;

        if (c.SPE > 90) count++;
        if (c.ACC > 90) count++;
        if (c.STA > 90) count++;
        if (c.STR > 90) count++;
        if (c.CON > 90) count++;
        if (c.PAS > 90) count++;
        if (c.SHO > 90) count++;
        if (c.TAC > 90) count++;

        if (count >= 7) {
            perfect = 1;
        }

        else {
            perfect = 0;
        }

        printf("SPE: %d\n", c.SPE);
        printf("ACC: %d\n", c.ACC);
        printf("STA: %d\n", c.STA);
        printf("STR: %d\n", c.STR);
        printf("CON: %d\n", c.CON);
        printf("PAS: %d\n", c.PAS);
        printf("SHO: %d\n", c.SHO);
        printf("TAC: %d\n", c.TAC);

        iteration++;
    }

    return 0;
}

void trainFitness(struct card *c) {
    int i = rand() % 4;

    if (i == 0 && c->SPE < 100) {
        c->SPE++;
    }
    else if (i == 1 && c->ACC < 100) {
        c->ACC++;
    }
    else if (i == 2 && c->STA < 100) {
        c->STA++;
    }
    else if (i == 3 && c->STR < 100) {
        c->STR++;
    }
    else {
        trainFitness(c);
    }
}

void trainTechnical(struct card *c) {
    int i = rand() % 4;

    if (i == 0 && c->CON < 100) {
        c->CON++;
    }
    else if (i == 1 && c->PAS < 100) {
        c->PAS++;
    }
    else if (i == 2 && c->SHO < 100) {
        c->SHO++;
    }
    else if (i == 3 && c->TAC < 100) {
        c->TAC++;
    }
    else {
        trainTechnical(c);
    }
}
