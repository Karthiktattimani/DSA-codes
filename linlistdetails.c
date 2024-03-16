#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct task {
    char tname[20];
    int p;
    int dur;
    struct task* next;
};

typedef struct task* NODE;

NODE getn()
{
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
    newnode->next = newnode;
    return newnode;
}

NODE deletefront(NODE head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    } else {
        NODE cur = head->next;
        while (cur->next != head)
            cur = cur->next;
        cur->next = head->next;
        NODE temp = head;
        head = head->next;
        free(temp);
    }
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

NODE insertpriority(NODE head) {
    NODE newnode = getn();
    newnode = readdetails(newnode);
    NODE cur,prev;


    if (head == NULL)
    {
        return newnode;
    }
    if (head->p > newnode->p)
     {
         cur = head;
        while (cur->next != head)
            cur = cur->next;
        cur->next = newnode;
        newnode->next = head;
        head=newnode;
        return head;
    }
    else
    {
         cur = head->next, prev = head;
        while (cur != head && cur->p >= newnode->p) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = newnode;
        newnode->next = cur;
        return head;
    }
}

NODE modify(NODE head)
 {
    int pr;
    printf("Enter the priority to be altered: ");
    scanf("%d", &pr);

    if (head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }

    if (head->p == pr)
    {
        head = deletefront(head);
    }
    else
    {
        NODE prev = NULL, cur = head;
        while (cur->next != head) {
            if (cur->p == pr) {
                prev->next = cur->next;
                free(cur);
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        if (cur->p == pr && cur->next == head) {
            prev->next = head;
            free(cur);
        }
    }

    printf("Enter the details again with the new priority\n");
    head = insertpriority(head);
    return head;
}

int main() {
    NODE head = NULL;
    int ch;
    while (1) {
        printf("1. Insert 2. Delete after execution 3. Display 4. Modify\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                head = insertpriority(head);
                break;
            case 2:
                head = deletefront(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                head = modify(head);
                break;
            default:
                exit(0);
                break;
        }
    }
}

