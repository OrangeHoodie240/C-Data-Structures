#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *swap_type(char *line, char *type_name, char num_of_char){
    short line_length = strlen(line);
    char *start = strstr(line, "car");
    if(start == NULL){
        return start;
    }

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

void copy_file(char *new_filename, char *template_filename, char *type_name, char *path){
    char num_of_char = strlen(type_name) + 1;
    char temp_filename[50] =  "temporary39292.c"; 
    FILE *tmp = tmpfile(); 
    tmp = fopen(temp_filename, "w");
    FILE *input = fopen(template_filename, "r"); 

    int next = fgetc(input);
    while(next != EOF){
        fputc(next, tmp);
        next = fgetc(input);
    }

    fclose(input);
    fclose(tmp);



    tmp = fopen(temp_filename, "r");

    FILE *output = fopen(new_filename, "w");
    char include_header[strlen(type_name) + 12];
 
 /* 
    REMOVE PATH FROM INCLUDE HEADER

    ADD PATH TO THE NEW FILES 






*/ 
 
    strcpy(include_header, "#include\"");
    strcat(include_header, type_name);
    strcat(include_header, ".h\"\n");
    fprintf(output, include_header);


    char *line = malloc(sizeof(char) * 300); 
    char *new_line;

    while(fgets(line, 299, tmp) != NULL){
        new_line=swap_type(line, type_name, num_of_char);
        while(new_line != NULL){
            strcpy(line, new_line);
            free(new_line);
            new_line = swap_type(line, type_name, num_of_char);

        }
        fprintf(output, line);
    }
    fclose(tmp);
    fclose(output);

    remove(temp_filename);
}

// $ ./output.exe sll_example/sll_example
int main(int argc,  char *argv[]){
    char *path_to_header = argv[1];
    char *path = malloc(sizeof(char) * strlen(path_to_header));

    char *type_name = malloc(sizeof(char) * strlen(path_to_header));
    char *sub = strstr(path_to_header, "/");
    if(sub == NULL){
        strcpy(type_name, sub);
        path[0] = '\0';
    }
    else{
        char temp_length = (strlen(path_to_header) + 1) - strlen(sub); 
        strncpy(path, path_to_header, temp_length);
        path[temp_length + 1] = '\0';
    }
    while(sub != NULL){
        sub++; 
        strcpy(type_name, sub);
        sub = strstr(sub, "/");
    }
    strncpy(type_name, type_name, strlen(type_name) - 2);
    type_name[strlen(type_name) - 2] = '\0';


    char *new_filename = malloc(sizeof(char) * 300);
    strcpy(new_filename, path);
    strcat(new_filename, "sll_"); 
    strcat(new_filename, type_name); 



// 

    char *template_filename = "sll_template/sll_template_clone.c";
    strcat(new_filename, ".c");
    printf("\n %s \n", new_filename);
    copy_file(new_filename, template_filename, type_name, path);
    
    new_filename[strlen(new_filename) - 1] = 'h';
    template_filename = "sll_template/sll_template_clone.h";
    copy_file(new_filename, template_filename, type_name, path);
    printf("\n %s \n", new_filename);

}