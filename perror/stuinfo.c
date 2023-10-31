#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 학생 정보를 저장하는 구조체
struct Student {
    char name[100];
    int midTermScore;
    int finalScore;
    struct Student* left;
    struct Student* right;
};

// 학생 정보를 트리에 삽입하는 함수
struct Student* insertStudent(struct Student* root, const char* name, int midTermScore, int finalScore) {
    if (root == NULL) {
        // 새로운 노드를 생성하고 데이터를 채웁니다.
        struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
        strcpy(newStudent->name, name);
        newStudent->midTermScore = midTermScore;
        newStudent->finalScore = finalScore;
        newStudent->left = NULL;
        newStudent->right = NULL;
        return newStudent;
    }

    // 이름을 기준으로 노드를 삽입합니다.
    if (strcmp(name, root->name) < 0) {
        root->left = insertStudent(root->left, name, midTermScore, finalScore);
    } else {
        root->right = insertStudent(root->right, name, midTermScore, finalScore);
    }

    return root;
}

// 학생 정보를 검색하고 출력하는 함수
void searchAndPrint(struct Student* root, const char* name) {
    if (root == NULL) {
        printf("학생을 찾을 수 없음.\n");
        return;
    }

    if (strcmp(name, root->name) == 0) {
        printf("학생 이름: %s\n", root->name);
        printf("중간 점수: %d\n", root->midTermScore);
        printf("기말 점수: %d\n", root->finalScore);
    } else if (strcmp(name, root->name) < 0) {
        searchAndPrint(root->left, name);
    } else {
        searchAndPrint(root->right, name);
    }
}

// 트리를 순회하며 메모리 해제
void freeTree(struct Student* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int numStudents;
    printf("학생 수를 입력하세요: ");
    scanf("%d", &numStudents);

    struct Student* root = NULL;

    for (int i = 0; i < numStudents; i++) {
        char name[100];
        int midTermScore, finalScore;

        printf("학생 이름: ");
        scanf("%s", name);
        printf("중간 점수: ");
        scanf("%d", &midTermScore);
        printf("기말 점수: ");
        scanf("%d", &finalScore);

        root = insertStudent(root, name, midTermScore, finalScore);
    }

    char searchName[100];
    printf("찾을 학생 이름을 입력하세요: ");
    scanf("%s", searchName);

    searchAndPrint(root, searchName);

    // 트리의 메모리를 해제
    freeTree(root);

    return 0;
}
