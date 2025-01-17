#include <stdio.h>

// 7 # lecture materials vvv *ENABLE* terminal output in settings!

int main(){

    char name[25];  // bytes
    int age;

    printf("What's your name?\n");
    //scanf("%s", name);    // < can't read empty spaces (for example Firstname Lastname)
    fgets(name, 25, stdin);

    printf("How old are you?\n");
    scanf("%d", &age);

    printf("Hello, %s! What's up?\n", name);
    printf("You are %d years old\n", age);
    
    return 0;
}