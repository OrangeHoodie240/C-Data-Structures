#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *swap_type(char *line, char *type_name, char num_of_char){
    short line_length = strlen(line);
    char *start = strstr(line, "car");
    if(start == NULL){
        return start;
    }
// here
    char *new_line = malloc(sizeof(char) * 300);
    new_line[0] = '\0';

    char *cur = line; 

    int i = 0; 
    while(cur != start){
        new_line[i]=cur[0];
        new_line[i + 1]='\0';

        cur +=1; 
        i++;
    }

    strcat(new_line, type_name);

    cur += 3; 

    i += num_of_char - 1;
    while(cur < line + line_length){
        new_line[i]=cur[0];
        cur += 1;
        i+=1; 
        new_line[i]='\0';
    }
    

    char *try_another =  swap_type(new_line, type_name, num_of_char);
    int ind = strlen(new_line); 
    new_line[ind] = '\0';
    while(try_another != NULL){
        int ind = strlen(try_another); 
        try_another[ind] = '\0';
        free(new_line);
        new_line = try_another;
        try_another = swap_type(new_line, type_name, num_of_char);
    }
    return new_line;
}



int main(){

    char *filename = malloc(sizeof(char) * 100);
    filename[0] = '\0';
    strcpy(filename, "temp.c");


    char *type_name = malloc(sizeof(char) * 4); 
    strcpy(type_name,"example");
    char num_of_char = strlen(type_name) + 1; 

    FILE *input = fopen("sll_example/sll_example.c", "r");
    FILE *output = fopen("temp.c", "w");

    int next = fgetc(input);
    while(next != EOF){
        fputc(next, output);
        next = fgetc(input);
    }

    fclose(input);


    fputc(10, output);

    // build sll_type.h
    input = fopen("sll_template/sll_template.c", "r"); 

    next = fgetc(input);
    while(next != EOF){
        fputc(next, output);
        next = fgetc(input);
    }

    fclose(input);
    fclose(output);



    input = fopen("temp.c", "r");

    output = fopen("temp2.c", "w");
    char *line = malloc(sizeof(char) * 300); 
    char *new_line;

    //int is_eof = fscanf(input, "%[^\n]", line); 
    // while(is_eof != EOF){
    while(fgets(line, 299, input) != NULL){
        new_line=swap_type(line, type_name, num_of_char);
        while(new_line != NULL){
            strcpy(line, new_line);
            free(new_line);
            new_line = swap_type(line, type_name, num_of_char);

        }
        // strcat(line, "\n");
        fprintf(output, line);
        // is_eof = fscanf(input, "%[^\n]", line); 
    }
    fclose(input);
    fclose(output);
}