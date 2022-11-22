#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void SelectionSort(char *hurricanes[], int size){ 

    int i,j;
    char temp[100];


    for(i=0;i<size-1;i++){ // going through the whole char array
        for(j=i+1;j<size;j++){
            if(strcmp(hurricanes[i],hurricanes[j])>0){ // checking to see if the two next to eachother need to be switched arround
                strcpy(temp,hurricanes[i]); // setting the array to temp
                strcpy(hurricanes[i],hurricanes[j]); // switching spots
                strcpy(hurricanes[j],temp); // puttting everything back
            }
        }
    }
}

void PrintFormat(char *hurricanes[],int size){
    FILE *fileOut; // creating file pointer for output
    fileOut=fopen("Output.txt","w"); // opening file to write to
    char *name,*type,*date;

    for(int x=0;x<size;x++){ // going through the whole array
        name=strtok(hurricanes[x],","); // setting the name by splitting up the line
        strtok(NULL," "); // getting rid of unwanted word
        type=strtok(NULL," "); // setting the type by splitting up the line
        strtok(NULL,","); // getting rid of unwanted word
        date=strtok(NULL,"\n"); // setting the date by splitting up the line
        if(strcmp(name,"Florence")==0){ // formatting issues with "Florence" being too long (prints ugly)
            fprintf(fileOut,"%s\t%s\t\t%s\n",name,type,date);
        }else{
            fprintf(fileOut,"%s\t\t%s\t\t%s\n",name,type,date); // printing eveything else to the file
        }
    }
    
    fclose(fileOut); // closing the output file

}

int main(void){
    FILE* fptr=fopen("/public/lab4/hurricanes.csv","r"); // Opens the file to read from
    if(fptr==NULL){ // checks to see if the file exists
        printf("Can't find file\n");
        return(1); // returns error if file doesn't exist
    }


    char *line;
    char *hurricanes[100];
    int i=0;
    line=malloc(sizeof(char)*100); // allocating memory to line
    while(fgets(line,100,fptr)!=NULL){ // checking to see if at the end of the file
        hurricanes[i]=malloc(sizeof(char)*100); // allocating memory for this specific line in hurricanes
        strcpy(hurricanes[i],line); // putting that line into the char array
        i++; // storing the size of the char array
    }
   

    SelectionSort(hurricanes,i); // sorts the char array in order

    PrintFormat(hurricanes,i); // prints the char array to a file in proper format


    return(0);
}
