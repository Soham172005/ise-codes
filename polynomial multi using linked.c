#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode {
    int coeff;       
    int exp;         
    struct PolyNode *next; 
} PolyNode;

PolyNode* createNode(int coeff, int exp) {
    PolyNode *newNode = (PolyNode *)malloc(sizeof(PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(PolyNode **poly, int coeff, int exp) {
    PolyNode *newNode = createNode(coeff, exp);
    
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
        return;
    }

    PolyNode *temp = *poly;
    while (temp->next != NULL && temp->next->exp > exp) {
        temp = temp->next;
    }

    if (temp->next != NULL && temp->next->exp == exp) {
        temp->next->coeff += coeff;
        free(newNode); 
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void displayPolynomial(PolyNode *poly) {
    PolyNode *temp = poly;
    while (temp != NULL) {
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }
        
        if (temp->next != NULL && temp->next->coeff > 0) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

PolyNode* multiplyPolynomials(PolyNode *poly1, PolyNode *poly2) {
    PolyNode *result = NULL;

    PolyNode *temp1 = poly1;
    while (temp1 != NULL) {
        PolyNode *temp2 = poly2;
        while (temp2 != NULL) {
            int newCoeff = temp1->coeff * temp2->coeff;
            int newExp = temp1->exp + temp2->exp;
            insertTerm(&result, newCoeff, newExp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return result;
}

int main() {
    PolyNode *poly1 = NULL, *poly2 = NULL, *product = NULL;
    int coeff, exp, n, i;

    printf("Enter number of terms in polynomial 1: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    printf("Enter number of terms in polynomial 2: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    product = multiplyPolynomials(poly1, poly2);

    printf("Product of the polynomials: ");
    displayPolynomial(product);

    return 0;
}
