/*------------------------------------------------------
* Filename: [dynamic_scanf.c]
* Description: [This program tekes an unknown length string and prints it.]
* Author: [Oron Bar Hillel]
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 2 //to take one char each user type

void check_null(char *p_string){
    if(p_string == NULL){
        printf("Error in memory allocation!!\n");
    }
}


//function that takes string from user and updates the pointer to it dynamicly!
char* dyn_scanf(void){
    char ch; //each character
    int count = 0;

    char *p_string = NULL;
    printf("Enter a string of characters:\n");

    //for each character we add space in the memory
    while((ch = fgetc(stdin)) != '\n'){
        if(count == 0){
            p_string = (char*) malloc(SIZE * sizeof(char));
            *p_string = ch;
            check_null(p_string);
        }else{
            p_string = (char*) realloc(p_string, sizeof(char));
            *(p_string + count) = ch;

            check_null(p_string);
        }
        ++count;
    }
    *(p_string + count) = '\0'; //so the char will know to end.

    return p_string;
    
}


int main() {
    //Setting the variables

    char *string = dyn_scanf();
    int flag = 0;
    int counter = 0;

    //finding length of the string
    while(flag == 0){   
        if(*(string + counter) == '\0'){
            flag = 1;
        }else{
            ++counter;
        }
    }

    //making new array to print
    char string_to_print[counter];
    string_to_print[counter] = '\0';

    //setting values and printing
    for(int i = 0; i < counter; ++i){
        string_to_print[i] =  *(string + i);
    }
    printf("%s", string_to_print);
    free(string);

    return 0;
}