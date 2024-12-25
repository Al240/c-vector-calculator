/***  
Vector Calculator
By: Al240 & stereoscoped
12/19/2024

todo:
- improve getVector data validation
- support expressions for component input
- support 'pi', 'ln(val)', 'log(val)'
***/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int addSub(double v1[3], double v2[3]) {
    char opChoice;
    bool inProgress = true;
    printf("Add (+) or Subtract (-)? ");

    while (inProgress) {
        scanf(" %c%*c", &opChoice);
        switch (opChoice) {
            // Addition
            case '+' : case 'A' : case 'a' :
                printf("\nA + B = <%.3f, %.3f, %.3f>\n\n", (v1[0]+v2[0]), (v1[1]+v2[1]), (v1[2]+v2[2]));
                inProgress = false;
                break;
            // Subtraction
            case '-' : case 'S' : case 's' :
                printf("\nA - B = <%.3f, %.3f, %.3f>\n\n", (v1[0]-v2[0]), (v1[1]-v2[1]), (v1[2]-v2[2]));
                inProgress = false;
                break;

            default:
                printf("Invalid operation. Please choose + or - : "); // input validation
                while ((getchar()) != '\n') {} // clear input buffer
        }
    }
}

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
    printf("\nA x B = <%.3f, %.3f, %.3f>\n\n", cProduct[0], cProduct[1], cProduct[2]);
}

int getMagUnit(double v1[3]) {
    double vMag = sqrt((v1[0]*v1[0])+(v1[1]*v1[1])+(v1[2]*v1[2]));
    printf("Magnitude ||v||: %.3f\n", vMag);
    printf("Unit Vector v/||v||: <%.3f, %.3f, %.3f>\n\n", v1[0]/vMag, v1[1]/vMag, v1[2]/vMag);
}

int getVector(double v1[3], char vecLabel) {
    char currComp = 'x';
    printf("Define the x, y, and z components of the vector %c.\n", vecLabel);
    for (int i=0; i<3; i++) {
        int valInput = 0;
        while (!valInput) {
            printf("%c: ", currComp);
            valInput = scanf("%lf", &v1[i]);
            if (valInput) {
                currComp++; // x -> y, y -> z
                while ((getchar()) != '\n') {} // clear input buffer
                break;
            }
            else {
                printf("Invalid input, please try again. Component must be a real number.\n");
                while ((getchar()) != '\n') {} // clear input buffer
            }
        }
    }
    printf("Vector %c: <%.3f, %.3f, %.3f>\n\n", vecLabel, v1[0], v1[1], v1[2]);
}

int main(void) {
    char choice; // operation choice
    double vecA[3]; // A
    double vecB[3]; // B
    bool running = true;
    printf("Welcome to the Vector Calculator!\n");
    printf("***Calculator supports up to 3-dimensional vectors***\n");
    printf("If you find any errors, please report them at https://github.com/Al240/c-vector-calculator\n\n");

    while (running) {
        printf("-------- MAIN MENU --------\n");
        printf("(A)ddition and Subtraction\n");
        printf("(D)ot Product\n");
        printf("(C)ross Product\n");
        printf("(M)agnitude & Unit Vector\n");
        printf("(Q)uit Program\n");
        printf("\nChoose an option: ");
        scanf("%c%*c", &choice);
        printf("- VECTOR PRODUCT CALC 1.2 -\n\n");
        
        switch (choice) {
            // Add or Subtract
            case 'A': case 'a':
                getVector(vecA, 'A');
                getVector(vecB, 'B');
                addSub(vecA, vecB);
                break;
            // Dot Product
            case 'D': case 'd':
                getVector(vecA, 'A');
                getVector(vecB, 'B');
                dotProduct(vecA, vecB);
                break;
            // Cross Product
            case 'C': case 'c':
                getVector(vecA, 'A');
                getVector(vecB, 'B');
                crossProduct(vecA, vecB);
                break;
            // Magnitude and Unit Vector
            case 'M': case 'm':
                getVector(vecA, 'v');
                getMagUnit(vecA);
                break;
            // Quit
            case 'Q': case 'q':
                printf("Quitting...");
                running = false;
                break;
            default:
                printf("Invalid option. Try again.\n"); // input validation
                while ((getchar()) != '\n') {} // clear input buffer
        }
    }
}