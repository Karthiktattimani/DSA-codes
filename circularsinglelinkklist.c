#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct task {
    char tname[20];
    int p;
    int dur;
    struct task* next;
};

typedef struct task* NODE;

NODE getn() {
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct task));
    if (newnode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    return newnode;
}

NODE readdetails(NODE newnode) {
    printf("Enter name, priority, and duration: ");
    scanf("%s %d %d", newnode->tname, &newnode->p, &newnode->dur);
    newnode->next = NULL;
    return newnode;
}

NODE insertFront(NODE head) {
    NODE newnode = getn();
    newnode = readdetails(newnode);
    if (head == NULL) {
        newnode->next = newnode; // Point to itself for circularity
        return newnode;
    } else {
        newnode->next = head;
        NODE temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode; // Update last node's next to point to newnode
        return newnode;
    }
}

NODE insertEnd(NODE head) {
    NODE newnode = getn();
    newnode = readdetails(newnode);
    if (head == NULL) {
        newnode->next = newnode; // Point to itself for circularity
        return newnode;
    } else {
        NODE temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head; // Point back to head for circularity
        return head;
    }
}

NODE insertAtPosition(NODE head, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return head;
    }

    if (pos == 1) {
        return insertFront(head);
    }

    NODE newnode = getn();
    newnode = readdetails(newnode);
    NODE temp = head;
    int count = 1;

    while (temp->next != head && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp->next == head && count != pos - 1) {
        printf("Position out of range\n");
        return head;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

NODE deleteAtPosition(NODE head, int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (pos < 1) {
        printf("Invalid position\n");
        return head;
    }

    NODE temp = head;
    NODE prev = NULL;
    int count = 1;

    while (temp->next != head && count < pos) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp->next == head && count != pos) {
        printf("Position out of range\n");
        return head;
    }

    if (prev == NULL) {
        if (temp->next == head) {
            free(temp);
            return NULL;
        }
        NODE last = temp;
        while (last->next != head) {
            last = last->next;
        }
        last->next = temp->next;
        free(temp);
        return last->next;
    }

    prev->next = temp->next;
    free(temp);
    return head;
}

void display(NODE head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE cur = head;
    do {
        printf("%s %d %d\n", cur->tname, cur->p, cur->dur);
        cur = cur->next;
    } while (cur != head);
}

int main() {
    NODE head = NULL;
    int ch, pos;

    while (1) {
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert at any position\n");
        printf("4. Delete at any position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                head = insertFront(head);
                break;
            case 2:
                head = insertEnd(head);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insertAtPosition(head, pos);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = deleteAtPosition(head, pos);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
