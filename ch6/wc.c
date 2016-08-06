// word count using an unbalanced binary tree
#include "getword.h"
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void printtree(struct tnode *);

int main(void) {
    char word[MAXWORD];
    struct tnode *root;

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        printf("word: %s\n", word);
        if (isalpha(word[0]))
            root = addtree(root, word);
    }
    printtree(root);

    return 0;
}

struct tnode *talloc(void);

struct tnode *addtree(struct tnode *p, char *word) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(word);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(word,  p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, word);
    else
        p->right = addtree(p->right, word);
    return p;
}

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

void printtree(struct tnode *p) {
    if (p != NULL) {
        printtree(p->left);
        printf("%4d %s\n", p->count, p->word);
        printtree(p->right);
    }
}
