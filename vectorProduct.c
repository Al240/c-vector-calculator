/***  
Cross and Dot Product Calculator
By: Al240
12/19/2024
***/
#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

int dotProduct(double v1[3], double v2[3]) {
    double dProduct = ((v1[0]*v2[0])+(v1[1]*v2[1])+(v1[2]*v2[2]));
    printf("A • B = %lf\n", dProduct);
}

int crossProduct(double v1[3], double v2[3]) {
    double cProduct[3] = {(v1[1]*v2[2]-v1[2]*v2[1]), (v1[2]*v2[0]-v1[0]*v2[2]), (v1[0]*v2[1]-v1[1]*v2[0])}; //<a2b3-a3b2,a3b1-a1b3,a1b2-a2b1>
    printf("\nWork Shown:\n");
    printf("A x B = <(%lf)(%lf) - (%lf)(%lf), (%lf)(%lf) - (%lf)(%lf), (%lf)(%lf) - (%lf)(%lf)>", 
        v1[1], v2[2], v1[2], v2[1],
        v1[2], v2[0], v1[0], v2[2],
        v1[0], v2[1], v1[1], v2[0]);
    printf("\nA x B = <%lf - %lf, %lf - %lf, %lf - %lf>\n", 
        v1[1] * v2[2], v1[2] * v2[1],
        v1[2] * v2[0], v1[0] * v2[2],
        v1[0] * v2[1], v1[1] * v2[0]);
    printf("\nFinal Answer:");
    printf("\nA x B = <");
    for (int i=0; i<2; i++) {
        printf("%lf, ", cProduct[i]);
    }
    printf("%lf>\n", cProduct[2]);
}

int main(void) {
    char prodChoice;
    double vecA[3];
    double vecB[3];
    bool cont = true;
    printf("Welcome to the product calculator!\n");
    while (cont) {
        printf("Choose either (D)ot, (C)ross product, or (Q)uit: ");
        scanf(" %c", &prodChoice);

        if ((prodChoice == 'D') || (prodChoice == 'd')) {
            printf("Define the x, y, and z components of the first vector.\n");
            for (int i=0; i<3; i++) {
                scanf("%lf", &vecA[i]);
            }
            printf("Vector A: <%f, %f, %f>\n", vecA[0], vecA[1], vecA[2]);
            
            printf("Define the x, y, and z components of the second vector.\n");
            for (int i=0; i<3; i++) {
                scanf("%lf", &vecB[i]);
            }
            printf("Vector B: <%f, %f, %f>\n", vecB[0], vecB[1], vecB[2]);

            dotProduct(vecA, vecB);
        }

        else if ((prodChoice == 'C') || (prodChoice == 'c')) {
            printf("Define the x, y, and z components of the first vector.\n");
            printf("Note: The order of the 2 vectors matters in the cross product.\n");
            for (int i=0; i<3; i++) {
                scanf("%lf", &vecA[i]);
            }
            printf("Vector A: <%f, %f, %f>\n", vecA[0], vecA[1], vecA[2]);
            
            printf("Define the x, y, and z components of the second vector.\n");
            for (int i=0; i<3; i++) {
                scanf("%lf", &vecB[i]);
            }
            printf("Vector B: <%f, %f, %f>\n", vecB[0], vecB[1], vecB[2]);

            crossProduct(vecA, vecB);
        } else if ((prodChoice == 'Q') || (prodChoice == 'q')) {
            cont = false;
        }
        else {
            printf("Invalid option. Try again.\n");
        }
    }
    
    return 0;
}