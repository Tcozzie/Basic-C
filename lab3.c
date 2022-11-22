#include <stdio.h>



void calculate(FILE* fptr,int numQ,char *answers){
    char studentAnswers[numQ]; // creates an array of all students answers
    char studentChar; // grabs one answer
    float grade=0.0; // percentage grade
    int totalMissed=0; // how many questions the student missed
    int ID=0; // students ID number
    fscanf(fptr,"%d", &ID); // gets students ID number
    
    for(int i=0;i<numQ+1;i++){ // appends all students answers to array
        fscanf(fptr,"%c", &studentChar);
        studentAnswers[i]=studentChar;
    }


    for(int i=1;i<numQ+1;i++){ // checking how many answers the student got wrong
        if(answers[i]!=studentAnswers[i]){
            totalMissed+=1;
        }
    }
    
    totalMissed=numQ-totalMissed; // calculating percentage
    grade=100.0*totalMissed/numQ;

    printf("%d\t%.2f\n",ID,grade);

}


int totalMissed(int numQ,char *answers, FILE* fptr){


    int missedBy[10]={0}; // making all missed to zero
    char studentAnswers[numQ];
    char studentAnswerC;
    char garbage;

    

    for(int x=0;x<5;x++){ // for how many students
        for(int a=0;a<numQ+1;a++){ // gets the answers from each student
            fscanf(fptr,"%c", &studentAnswerC);
            studentAnswers[a]=studentAnswerC;
        }
        for(int i=1;i<numQ+1;i++){ // checking if the answers are correct
            if(answers[i]!=studentAnswers[i]){
                missedBy[i-1]+=1;
            }
        }
        for(int z=0;z<4;z++){ // resetting the next pointer to the next set of answers
            fscanf(fptr,"%c", &garbage);
        }
    }




    printf("Missed By:\t");


    for(int i=0;i<numQ;i++){ // printing the final results
        printf("%d ",missedBy[i]);
    }
    printf("\n");




    return(0);
}



int main(void){
   // declaring and open file
   FILE* fptr=fopen("/public/lab3/exam.txt","r");
   if(fptr==NULL){
        printf("Cant't find file\n");
        return(1);
    }

    int numQ=0; // number of questions in test
    fscanf(fptr,"%d", &numQ);
    char answers[numQ];// making an array for the correct answers w size numQ
    char answersC; // keeping track of right answers
    
    for(int i=0;i<numQ+1;i++){
        fscanf(fptr,"%c", &answersC);
        answers[i]=answersC; // appends the right answers into the list
    }

    printf("Question:\t");
    for(int i=0;i<numQ;i++){ // printing out the question numbers
        printf(" %d",i+1);
    }
    printf("\n");

    printf("Answers:  \t");
    for(int i=1;i<numQ+1;i++){ // printing out the answers for each question
        printf(" %c",answers[i]);
    }
    printf("\n");
    printf("ID\tGrade(%%)\n");
    
    for(int i=0;i<5;i++){
        calculate(fptr,numQ,answers); // calculate each score and all missed 
    }
    
    printf("Question: \t");
    for(int i=0;i<numQ;i++){
        printf("%d ",i+1);i // printing the number of questions
    }
    printf("\n");


    rewind(fptr); // resetting the pointer

    char garbage;

    for(int i=0;i<numQ+6;i++){ // getting pointer back to the right spot
        fscanf(fptr,"%c",&garbage);
    }  

    
    totalMissed(numQ,answers,fptr); // calculate total missed 
    


    return(0);
}
