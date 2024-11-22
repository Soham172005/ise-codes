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

PolyNode* addPolynomials(PolyNode *poly1, PolyNode *poly2) {
    PolyNode *result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0) {
                insertTerm(&result, sum, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    PolyNode *poly1 = NULL, *poly2 = NULL, *sum = NULL;
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

    sum = addPolynomials(poly1, poly2);

    printf("Sum of the polynomials: ");
    displayPolynomial(sum);

    return 0;
}