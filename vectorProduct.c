/***  
Vector Product Calculator
By: Al240 & stereoscoped
12/19/2024
***/
#include <stdio.h>
#include <stdbool.h>

int dotProduct(double v1[3], double v2[3]) {
    double dProduct = ((v1[0]*v2[0])+(v1[1]*v2[1])+(v1[2]*v2[2])); // (a1b1)+(a2b2)+(a3b3)
    printf("A • B = %.3f\n\n", dProduct); // Display final dot product
}

int crossProduct(double v1[3], double v2[3]) {
    double cProduct[3] = {(v1[1]*v2[2]-v1[2]*v2[1]), (v1[2]*v2[0]-v1[0]*v2[2]), (v1[0]*v2[1]-v1[1]*v2[0])}; //<a2b3-a3b2,a3b1-a1b3,a1b2-a2b1>
    printf("\nWork Shown:\n"); // Display 2 steps in detail
    printf("A x B = <(%.3f)(%.3f) - (%.3f)(%.3f), (%.3f)(%.3f) - (%.3f)(%.3f), (%.3f)(%.3f) - (%.3f)(%.3f)>", // 1. plug in values
        v1[1], v2[2], v1[2], v2[1], // x: (a2b3)-(a3b2)
        v1[2], v2[0], v1[0], v2[2], // y: (a3b1)-(a1b3)
        v1[0], v2[1], v1[1], v2[0]); // z: (a1b2)-(a2b1)
    printf("\nA x B = <%.3f - %.3f, %.3f - %.3f, %.3f - %.3f>\n", // 2. simplify after multiplication
        v1[1] * v2[2], v1[2] * v2[1],
        v1[2] * v2[0], v1[0] * v2[2],
        v1[0] * v2[1], v1[1] * v2[0]);
    printf("\nFinal Answer:");
    printf("\nA x B = <");
    for (int i=0; i<2; i++) {
        printf("%.3f, ", cProduct[i]); // print final x & y component
    }
    printf("%.3f>\n\n", cProduct[2]); // print final z component
}

int main(void) {
    char choice; // operation choice
    double vecA[3]; // A
    double vecB[3]; // B
    bool running = true;
    printf("Welcome to the Vector Product Calculator!\n");
    printf("If you find any errors, please report them at https://github.com/Al240/c-vector-product-calc\n");

    while (running) {
        printf("Choose (D)ot product, (C)ross product, or (Q)uit: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            // Dot Product
            case 'D': case 'd':
                printf("Define the x, y, and z components of the first vector:\n");
                for (int i=0; i<3; i++) {
                    scanf("%lf", &vecA[i]);
                }
                printf("Vector A: <%.3f, %.3f, %.3f>\n\n", vecA[0], vecA[1], vecA[2]);
                
                printf("Define the x, y, and z components of the second vector:\n");
                for (int i=0; i<3; i++) {
                    scanf("%lf", &vecB[i]);
                }
                printf("Vector B: <%.3f, %.3f, %.3f>\n\n", vecB[0], vecB[1], vecB[2]);

                dotProduct(vecA, vecB);
                break;
            // Cross Product
            case 'C': case 'c':
                printf("Define the x, y, and z components of the first vector.\n");
                printf("(Note: The vector order matters for cross product (right hand rule).)\n");
                for (int i=0; i<3; i++) {
                    scanf("%lf", &vecA[i]);
                }
                printf("Vector A: <%.3f, %.3f, %.3f>\n\n", vecA[0], vecA[1], vecA[2]);
                
                printf("Define the x, y, and z components of the second vector.\n");
                for (int i=0; i<3; i++) {
                    scanf("%lf", &vecB[i]);
                }
                printf("Vector B: <%.3f, %.3f, %.3f>\n\n", vecB[0], vecB[1], vecB[2]);

                crossProduct(vecA, vecB);
                break;
            // Quit
            case 'Q': case 'q':
                running = false;
                break;
            default:
                printf("Invalid option. Try again.\n"); // input validation
        }
    }
    return 0;
}
