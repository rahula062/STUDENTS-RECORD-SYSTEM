#include <stdio.h>
struct Students{
    char Name[30];
    int Roll;
    float Marks;
    long long mob_no;
};

void Get_Det(struct Students *s1, FILE *CSE) {
    printf("Enter Name :");
    getchar();
    scanf("%29[^\n]", s1->Name);
    fprintf(CSE, "Name : %s\t", s1->Name);

    printf("Enter Roll No. :");
    scanf("%d",&s1->Roll);
    fprintf(CSE, "|\tRoll : %d\t", s1->Roll);

    printf("Enter Marks : ");
    scanf("%f",&s1->Marks);
    fprintf(CSE, "|\tMarks : %.2f\t", s1->Marks);

    printf("Enter Mobile Number : ");
    scanf("%lld",&s1->mob_no);
    fprintf(CSE, "|\tMobile : %lld\n", s1->mob_no);
}

int main(){
    FILE *CSE;
    char ch;

    struct Students s1;
    


    char c;
    printf("WELCOME! TO {SRUDENT RECORD SYSTEM} PROJECT\n");
    printf("Enter what You want to do\ne.g-> r fpr read, w for write, a for add, s for search Student :\t");
    scanf(" %c",&c);
    if (c == 'r'){
        CSE = fopen("C:\\Users\\rahul\\OneDrive\\Documents\\Students Project (DATA HANDLING)\\CSE.txt", "r");
        if (CSE == NULL){
            printf("No Records Found!");
        }
        else{
            while((ch = fgetc(CSE)) != EOF){
                printf("%c",ch);
            }
        }
        fclose(CSE);
    }
    else if (c == 'w'){
        CSE = fopen("C:\\Users\\rahul\\OneDrive\\Documents\\Students Project (DATA HANDLING)\\CSE.txt", "w");
            Get_Det(&s1, CSE);
        fclose(CSE);
    }
    else if (c == 'a'){
        CSE = fopen("C:\\Users\\rahul\\OneDrive\\Documents\\Students Project (DATA HANDLING)\\CSE.txt", "a");
            Get_Det(&s1, CSE);
        fclose(CSE);
    }
    else if (c == 's'){
        CSE = fopen("C:\\Users\\rahul\\OneDrive\\Documents\\Students Project (DATA HANDLING)\\CSE.txt", "r");
        if (CSE == NULL){
            printf("No Records Found!");
        }
        else{
            char name[30];
            printf("Enter Name of Student to Search : ");
            getchar();
            scanf("%29[^\n]", name);
            char line[100];
            int found = 0;
            for(int i = 0; i < 100; i++){
                if (fgets(line, sizeof(line), CSE) != NULL){
                    if (name[0] == '\0'){
                        printf("%s", line);
                        found = 1;
            }
            if (!found){
                printf("Student Not Found!");
            }
        }
        fclose(CSE);
    }
}
    }
    else{
        printf("Invalid Input!");
    }
    return 0;
}