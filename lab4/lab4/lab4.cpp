#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root;

struct Node* CreateTree(struct Node* root, struct Node* r, int data) {
    if (r == NULL) {
        r = (struct Node*)malloc(sizeof(struct Node));
        if (r == NULL) {
            printf("Ошибка выделения памяти");
            exit(0);
        }

        r->left = NULL;
        r->right = NULL;
        r->data = data;
        if (root == NULL) return r;

        if (data > root->data) root->left = r;
        else root->right = r;
        return r;
    }

    if (data > r->data)
        CreateTree(r, r->left, data);
    else
        CreateTree(r, r->right, data);

    return root;
}

void print_tree(struct Node* r, int l) {
    if (r == NULL) {
        return;
    }

    print_tree(r->right, l + 1);
    for (int i = 0; i < l; i++) {
        printf(" ");
    }

    printf("%d\n", r->data);
    print_tree(r->left, l + 1);
}

struct Node* SearchTree(struct Node* r, int value) {
    if (r == NULL) {
        return NULL;
    }
    if (r->data == value) {
        return r;
    }

    struct Node* found = SearchTree(r->left, value);

    if (found != NULL) {
        return found;
    }

    return SearchTree(r->right, value);
}

int main() {
    setlocale(LC_ALL, "");
    int D, start = 1;

    root = NULL;

    while (start) {
        printf("Введите число: ");
        scanf_s("%d", &D);
        if (D == 123645) {
            printf("Построение дерева окончено\n\n");
            start = 0;
        }
        else
            root = CreateTree(root, root, D);
    }

    print_tree(root, 0);

    printf("Введите число для поиска: ");
    scanf_s("%d", &D);
    struct Node* found = SearchTree(root, D);
    if (found != NULL) {
        printf("Число %d найдено в дереве.\n", found->data);
    }
    else {
        printf("Число %d не найдено в дереве.\n", D);
    }

    return 0;
}
