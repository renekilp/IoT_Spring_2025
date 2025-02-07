#include <stdio.h>

#define MAX 25

int main(void)
{

    char name[MAX];
    int age;

    printf("What's your name?\n");

    //scanf("%s", name);    // < can't read empty spaces (for example Firstname Lastname)
    fgets(name, MAX, stdin);

    printf("How old are you?\n");
    scanf("%d", &age);

    printf("Hello, %s", name);
    printf("You are %d years old\n", age);
    
    return 0;
}