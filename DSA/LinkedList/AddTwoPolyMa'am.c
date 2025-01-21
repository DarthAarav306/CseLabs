#include <stdio.h>
#include <stdlib.h>

// Define a structure for polynomial node
typedef struct polynode *polyptr;
struct polynode {
    int coef;
    int expo;
    polyptr link;
};
typedef struct polynode pnode;

// Function to compare the exponents of two polynomial terms
int compare(int pe, int qe) {
    if (pe > qe)
        return 1;
    else if (pe == qe)
        return 0;
    else
        return -1;
}

// Function to attach a new node to the polynomial
void attach(int c, int e, polyptr *ptr) {
    polyptr newnode = (polyptr)malloc(1 * sizeof(pnode));
    newnode->coef = c;
    newnode->expo = e;
    newnode->link = NULL;
    (*ptr)->link = newnode;
    *ptr = newnode;
}

// Function to add two polynomials
polyptr padd(polyptr p, polyptr q) {
    polyptr front, rear;
    rear = (polyptr)malloc(1 * sizeof(pnode));
    front = rear;
    int sum;

    while (p != NULL && q != NULL) {
        switch (compare(p->expo, q->expo)) {
            case -1:
                attach(q->coef, q->expo, &rear);
                q = q->link;
                break;
            case 1:
                attach(p->coef, p->expo, &rear);
                p = p->link;
                break;
            case 0:
                sum = p->coef + q->coef;
                if (sum)
                    attach(sum, q->expo, &rear);
                q = q->link;
                p = p->link;
                break;
        }
    }

    // Attach remaining terms
    while (p) {
        attach(p->coef, p->expo, &rear);
        p = p->link;
    }
    while (q) {
        attach(q->coef, q->expo, &rear);
        q = q->link;
    }

    // Remove temporary front node
    polyptr temp = front;
    front = front->link;
    free(temp);

    return front;
}

// Function to create a new polynomial
void createpoly(polyptr *p, int c, int e) {
    polyptr newnode = (polyptr)malloc(1 * sizeof(pnode));
    newnode->coef = c;
    newnode->expo = e;
    newnode->link = NULL;

    if (*p == NULL) {
        *p = newnode;
    } else {
        polyptr temp;
        for (temp = *p; temp->link != NULL; temp = temp->link);
        temp->link = newnode;
    }
}

// Function to display a polynomial
void display(polyptr ptr) {
    for (polyptr tr = ptr; tr != NULL; tr = tr->link) {
        if (tr->coef > 0)
            printf("%dx", tr->coef);
        else
            printf("%dx", tr->coef);
        if (tr->expo >= 0)
            printf("^%d", tr->expo);
        if (tr->link != NULL) 
            printf(" + ");
    }
}

// Function to erase a polynomial and free memory
void erase(polyptr *ptr) {
    polyptr temp;
    while (*ptr) {
        temp = *ptr;
        *ptr = (*ptr)->link;
        free(temp);
    }
}

// Main function
int main() {
    int n, i, c, e;
    polyptr p = NULL, q = NULL, r = NULL;

    // Create first polynomial
    printf("Enter the number of terms in 1st polynomial: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent in decreasing order: ");
        scanf("%d%d", &c, &e);
        createpoly(&p, c, e);
    }

    // Create second polynomial
    printf("Enter the number of terms in 2nd polynomial: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent in decreasing order: ");
        scanf("%d%d", &c, &e);
        createpoly(&q, c, e);
    }

    // Display both polynomials
    printf("First Polynomial: ");
    display(p);
    printf("\nSecond Polynomial: ");
    display(q);

    // Add the two polynomials
    r = padd(p, q);
    printf("\nResult Polynomial: ");
    display(r);

    // Erase the polynomials
    erase(&p);
    erase(&q);
    erase(&r);

    if (!p && !q && !r)
        printf("\nMemory successfully released\n");
    else
        printf("\nMemory not fully released\n");

    return 0;
}
