#include <stdio.h>
int main() {
    float gpa;
    char faculty;
    int id;
    printf("please enter a 3-digit integer id number: ");
    scanf("%d",&id);
    printf("please enter a faculty(for engineering e, for management m, for other faculties o): ");
    scanf(" %c",&faculty);
    printf("please enter gpa: ");
    scanf("%f",&gpa);
    if(id <= 100 || id >= 999 || gpa >= 4.0 || gpa <= 0.0){
        printf("please enter a valid id number or gpa.");
    }
    else if(faculty=='e' && gpa >= 2.80){
        printf("you can takr the cmpe444 lesson.");
    }
    else if(faculty =='m'){
        printf("management students can not take this lesson.");
    }
    else if(faculty=='o'){
        printf("only the enginnering students can take thit lesson.");
    }
    else {
        printf("please enter a valid value.");
    }

    return 0;

}
