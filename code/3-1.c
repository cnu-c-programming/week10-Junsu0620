#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    int score;
    struct Node* next;
};

struct Node* head = NULL;

void add(char name[], int score) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* p = head;

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = newNode;
}

void delete(char name[]) {
    struct Node* p = head;
    struct Node* previous = NULL;

    while (p != NULL) {
        if (strcmp(p->name, name) == 0) {

            if (previous == NULL) {
                head = p->next;
            } else {
                previous->next = p->next;
            }

            free(p);
            return;
        }

        previous = p;
        p = p->next;
    }
}

void print() {
    struct Node* p = head;

    while (p != NULL) {
        printf("%s %d\n", p->name, p->score);
        p = p->next;
    }
}

void freeList() {
    struct Node* p = head;

    while (p != NULL) {
        struct Node* temp = p;
        p = p->next;
        free(temp);
    }
}

int main() {
    char command[20];

    while (1) {

        scanf("%s", command);

        if (strcmp(command, "add") == 0) {

            char name[50];
            int score;

            scanf("%s %d", name, &score);

            add(name, score);
        }

        else if (strcmp(command, "delete") == 0) {

            char name[50];

            scanf("%s", name);

            delete(name);
        }

        else if (strcmp(command, "print") == 0) {
            print();
        }

        else if (strcmp(command, "quit") == 0) {
            freeList();
            break;
        }
    }

    return 0;
}
