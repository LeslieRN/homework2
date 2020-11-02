/*
** EPITECH PROJECT, 2020
**  
** File description:
**  
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef FUNCTION_H_
#define FUNCTION_H_

/*
** Analysis
* One line must have only one space between words (Ex: hello its  me -> hello its me)
* After some punctiation marks such as comma, period and/or semicolon there must be an space (Ex: hello;its me -> hello; its me)
* You can't have a space right before a punction mark mention above (Ex: hello ; its me -> hello; its me)
* After a period, if there is a letter you need to change the letter to Uppercase and then add two more spaces (Ex: hello.its me -> hello.  Its me)
* A paragraph must be inicialize with some spaces (this is the begining ->  This is the begining)
* The first line of code it's the tittle of the paragrah, therefore, this part needs to be Uppercase and then need to be separated from the paragrah
(hello its me ->        HELLO ITS ME)
* The page it's made of 80 columns
*/

FILE *open_file(char *, char *);
void close_file(FILE *);
char *show_file_data(char *);
int quantity_of_students(char *file_name);
void insert_data(char *file_name);
char *loopThrough(char *);
char *check_punctuation(char, char);
char *period_paragrah(char *, char *);
int quantity_letters(char *);
int quantity_of_words(char *);
int quantity_of_lines(char *);
char *changeUpper(char *cadena);
char *highest_strlen_word(char *);
char *lower_strlen_word(char *);
char *most_frequent_word(char *);
int frequency_word(char *, char *);
char *change_first_letter_upper(char *);

void insert_data(char *file_name)
{
    FILE *file = open_file(file_name, "a+");
    fwrite("Hello it's me", sizeof(char) * 14, 1, file);
    close_file(file);
}
FILE *open_file(char *name_file, char *mode)
{
    FILE *file = fopen(name_file, mode);

    return file;
}

void close_file(FILE *name_file)
{
    fclose(name_file);
}

char *show_file_data(char *file_name)
{
    FILE *file = open_file(file_name, "r");
    int total = quantity_of_students(file_name);
    char *values = (char *)malloc(sizeof(char) * (total + 1));
    fread(values, sizeof(char) * quantity_of_students(file_name), 1, file);
    close_file(file);
    return values;
}

int quantity_of_students(char *file_name)
{
    FILE *file = open_file(file_name, "r");
    fseek(file, 0L, SEEK_END); //move at the end of the file
    long bytes = ftell(file);  //tells the location of the cursor
    int students = bytes / sizeof(char);
    //printf("This is the quantity %d\n", students);
    //close file
    close_file(file);
    //rewind(file);
    return students;
}

char *loopThrough(char *main_pointer)
{
    int counter = -1, check = 0;
    char *original, *temp, *puntuation, *before, *title;
    original = (char *)malloc(sizeof(char) * strlen(main_pointer) + 100);
    before = (char *)malloc(sizeof(char));
    strcpy(before, " ");
    temp = strtok(main_pointer, "\n");
    while (temp)
    {
        puntuation = (char *)malloc(sizeof(char) * strlen(temp) + 1);
        strcpy(puntuation, temp);
        if (temp)
        {
            if (counter == -1)
            {
                puntuation = changeUpper(puntuation);
                strcpy(original, puntuation);
                strcat(original, "\n");
                strcat(original, "\n");
                strcat(original, "\n");
                //printf("I'm here 1!!\n");
                //printf("This is original in counter -1 %s\n", original);
                counter = 0;
            }
            else if (counter == 0)
            {
                strcat(original, "    ");
                strcat(original, change_first_letter_upper(puntuation));
                counter = 1;
                //printf("I'm here 2!!\n");
                //before = original;
            }
            else if (counter > 0)
            {
                if (*(puntuation + 0) == ',')
                {
                    strcat(original, ",");
                    strcat(original, " ");
                    puntuation++;
                    strcat(original, puntuation);
                    //printf("I'm here 3!!\n");
                }
                else if (*(puntuation + 0) == ';')
                {
                    strcat(original, ";");
                    strcat(original, " ");
                    puntuation++;
                    strcat(original, puntuation);
                    //printf("I'm here 4!!\n");
                }
                else
                {
                    //printf("I'm here 5!!\n");
                    strcat(original, period_paragrah(before, puntuation));
                    /*printf("I'm here 6!!\n");
                    printf("This is puntuation %s\n", puntuation);
                    printf("This is original %s\n", original);*/
                }
            }
        }
        //printf("I'm here 7!!\n");
        before = (char *)malloc(sizeof(char) * (strlen(puntuation) + 1));
        strcpy(before, puntuation);
        //printf("I'm here 7!!\n");
        temp = strtok(NULL, " ");
        //printf("I'm here 8!! %s\n", temp);
        //printf("This is temp out %s\n", temp);
        if (temp == NULL)
        {
            break;
        }
        else if ((*(temp + 0) != ',') && (*(temp + 0) != ';') && (*(temp + 0) != '.'))
        {
            strcat(original, " ");
            //  printf("This is temp out %s\n", temp);
        }
    }
    //printf("%s\n", original);
    return original;
}

int quantity_letters(char *pointer)
{
    int counter = 0;
    while (*pointer != '.')
    {
        counter++;
        pointer++;
    }
    return counter;
}

char *change_first_letter_upper(char *pointer_word)
{
    char *temp_pointer, letter;
    temp_pointer = (char *)malloc(sizeof(char) * (strlen(pointer_word) + 1));
    strcpy(temp_pointer, "");
    for (int i = 0; pointer_word[i] != '\0'; i++)
    {
        //printf("This is cadena%c2\n", cadena[i]);
        if (i == 0 && pointer_word[i] >= 97 && pointer_word[i] <= 122)
        { //minuscula a y z
            //printf("This is %c\n", cadena[i] - 32);
            letter = pointer_word[i] - 32;
            printf("This is letter%c\n", letter);
            //temp = (char *)realloc(temp, sizeof(char) + 1);
            strncat(temp_pointer, &letter, 1);
            printf("This is temp%s\n", temp_pointer);
            //fputc(cadena[i] - 32, stdout);
        }
        else
        {
            //strcat(temp, cadena[i]);
            letter = pointer_word[i];
            strncat(temp_pointer, &letter, 1);
            printf("This is temp%s\n", temp_pointer);
        }
    }
    //temp_pointer[0] = letter;
    return temp_pointer;
}
char *changeUpper(char *cadena)
{
    char *temp, letter;
    temp = (char *)malloc(sizeof(char) * (strlen(cadena) + 42));
    strcpy(temp, "                                        ");
    for (int i = 0; cadena[i] != '\0'; ++i)
    {
        //printf("This is cadena%c2\n", cadena[i]);
        if (cadena[i] >= 97 && cadena[i] <= 122)
        { //minuscula a y z
            //printf("This is temp%c\n", cadena[i] - 32);
            letter = cadena[i] - 32;
            //printf("This is letter%c\n", letter);
            //temp = (char *)realloc(temp, sizeof(char) + 1);
            strncat(temp, &letter, 1);
            //printf("This is temp%s\n", temp);
            //fputc(cadena[i] - 32, stdout);
        }
        else
        {
            //strcat(temp, cadena[i]);
            letter = cadena[i];
            strncat(temp, &letter, 1);
            //printf("This is temp%s\n", temp);
        }
    }
    return temp;
}

int quantity_of_words(char *pointer)
{
    char *temp, *temp2, *delimiter = " \n";
    int quantity_words = 0, quantity_letters = 0;
    quantity_letters = strlen(pointer) + 1;
    temp2 = (char *)malloc(sizeof(char) * (strlen(pointer) + 1));
    strcpy(temp2, pointer);
    temp = strtok(temp2, delimiter);
    ++quantity_words;
    while ((temp = strtok(NULL, delimiter)) != NULL)
    {
        ++quantity_words;
    }
    return quantity_words;
}
int quantity_of_lines(char *pointer)
{
    char *temp, *temp2;
    int quantity_lines = 0, quantity_letters = 0;
    quantity_letters = strlen(pointer) + 1;
    temp2 = (char *)malloc(sizeof(char) * (strlen(pointer) + 1));
    strcpy(temp2, pointer);
    temp = strtok(temp2, "\n");
    quantity_lines++;
    while ((temp = strtok(NULL, "\n")) != NULL)
    {
        quantity_lines++;
    }
    return quantity_lines;
}
char *highest_strlen_word(char *pointer)
{
    char *temp, *temp2, *main_pointer, *result, *delimiter = " \n";
    strcpy(temp2, " ");
    main_pointer = (char *)malloc(sizeof(char) * (strlen(pointer) + 1));
    strcpy(main_pointer, pointer);
    temp = strtok(main_pointer, delimiter);
    while (temp)
    {
        if (strlen(temp2) < strlen(temp))
        {
            //result = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
            temp2 = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
            strcpy(temp2, temp);
        }
        temp = strtok(NULL, delimiter);
    }

    return temp2;
}

char *lower_strlen_word(char *pointer)
{
    char *temp, *temp2, *main_pointer, *result, *delimiter = " \n";
    //strcpy(temp2, " ");
    main_pointer = (char *)malloc(sizeof(char) * (strlen(pointer) + 1));
    strcpy(main_pointer, pointer);
    temp = strtok(main_pointer, delimiter);
    temp2 = strtok(NULL, delimiter);
    while (temp)
    {
        if (strlen(temp) < strlen(temp2))
        {
            temp2 = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
            strcpy(temp2, temp);
        }
        temp = strtok(NULL, delimiter);
    }

    return temp2;
}

char *most_frequent_word(char *main_pointer)
{
    char *temp, *temp_return, *main_pointer_temp, *result, *result_number;
    int max_repeat_word = 0, result_function = 0;
    main_pointer_temp = (char *)malloc(sizeof(char) * (strlen(main_pointer) + 1));
    strcpy(main_pointer_temp, main_pointer);
    temp = strtok(main_pointer_temp, " ");
    while (temp)
    {
        result_function = frequency_word(temp, main_pointer);
        if (max_repeat_word < result_function)
        {
            temp_return = (char *)malloc(sizeof(char) * (strlen(temp) + 5));
            strcpy(temp_return, temp);
            sprintf(result_number, " %d", result_function);
            strcat(temp_return, result_number);
            max_repeat_word = result_function;
        }
        temp = strtok(NULL, " ");
    }
    return temp_return;
}

int frequency_word(char *pointer_word, char *main_pointer)
{
    char *temp_word, *temp_main;
    int counter_frequency = 0;
    temp_main = (char *)malloc(sizeof(char) * (strlen(main_pointer) + 1));
    strcpy(temp_main, main_pointer);
    while ((temp_main = strstr(temp_main, pointer_word)) != NULL)
    {
        counter_frequency++;
        temp_main++;
    }
    return counter_frequency;
}
char *period_paragrah(char *before_loop, char *temp_loop)
{
    int point_end = 0;
    char *temp_word = (char *)malloc(sizeof(char) * (strlen(temp_loop) + 3));
    point_end = strlen(before_loop);
    printf("Soy before loop %s\n", before_loop);
    strcpy(temp_word, "");
    if (*(before_loop + (strlen(before_loop) - 1)) == '.')
    {
        strcat(temp_word, "  ");
        printf("Soy before -1 %s\n", temp_loop);
        strcat(temp_word, change_first_letter_upper(temp_loop));
    }
    else if (strchr(temp_loop, '.') && *(before_loop + (strlen(before_loop) - 1)) != '.')
    {
        int quantity_before_point = quantity_letters(temp_loop);
        strncat(temp_word, temp_loop, quantity_before_point + 1);
        strcat(temp_word, "  ");
        temp_loop = strchr(temp_loop, '.');
        temp_loop++;
        printf("Soy strchr %s\n", temp_loop);
        strcat(temp_word, change_first_letter_upper(temp_loop));
    }
    else
    {
        return temp_loop;
    }
    return temp_word;
}

#endif /* !FUNCTION_H_ */