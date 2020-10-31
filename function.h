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
char *period_paragrah(char, char);
int quantity_letters(char *);
int quantity_of_words(char *);
int quantity_of_lines(char *);
char *changeUpper(char *cadena);
int strlen_words(char *pointer);
char *highest_strlen_word(char *);
char *lower_strlen_word(char *);
char *most_frequenty_word(char *);
int frequency_word(char *, char *);

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
    // printf("I'm here!!\n");
    int total = quantity_of_students(file_name);
    char *values = (char *)malloc(sizeof(char) * (total + 1));
    fread(values, sizeof(char) * quantity_of_students(file_name), 1, file);
    //strcat(values, "hola");
    //printf("%s", values);
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
    //printf("This is loop \n");
    //printf("%s\n", main_pointer);
    //fflush(stdin);
    temp = strtok(main_pointer, "\n"); //locates in the first space Hello , it's me
    //printf("This is temp %sokay\n", temp);
    //fflush(stdin);
    //printf("Temp before de if statements%s\n", temp);
    while (temp)
    {
        //printf("%s\n", temp);
        puntuation = (char *)malloc(sizeof(char) * strlen(temp) + 1);
        strcpy(puntuation, temp);
        if (temp)
        {
            //set spaces at the beginging
            //add the function to check for the first condition;

            //printf("This is punctiation %s", puntuation);
            if (counter == -1)
            {
                //printf("This is punctiation %s", puntuation);
                puntuation = changeUpper(puntuation);
                //printf("This is punctiation %s", puntuation);
                strcpy(original, puntuation);
                strcat(original, "\n");
                printf("This is original in counter -1 %s\n", original);
                counter = 0;
            }
            else if (counter == 0)
            {
                strcat(original, "    ");
                strcat(original, temp);
                counter = 1;
                //strcat(original, " ");
                before = original;
            }
            else if (counter > 0)
            {
                //printf("Jesus take the wheel\n");
                //printf("This is the value of temp -1 %c\n", temp - 1);
                //strcpy(puntuation, temp);
                //printf("Jesus take the wheel\n");
                if (*(puntuation + 0) == ',') //|| strchr(temp, ';') != NULL)
                {
                    //printf("Hey im0 %s\n", puntuation);
                    //puntuation = ", ";
                    //puntuation = strtok(puntuation, ","); //+ 1;
                    strcat(original, ","); //puntuation++);
                    //printf("Hey im1 %s\n", puntuation);
                    strcat(original, " ");
                    puntuation++;
                    //puntuation = temp;
                    //puntuation = strtok(puntuation, NULL);
                    //printf("Hey im1 4 %s\n", puntuation);
                    strcat(original, puntuation);
                    //printf("Hey im3 %s\n", original);
                    //--temp;
                }
                else if (*(puntuation + 0) == ';') //|| strchr(temp, ';') != NULL)
                {
                    //printf("Hey im0 %s\n", puntuation);
                    //puntuation = ", ";
                    //puntuation = strtok(puntuation, ","); //+ 1;
                    strcat(original, ";"); //puntuation++);
                    //printf("Hey im1 %s\n", puntuation);
                    strcat(original, " ");
                    puntuation++;
                    //puntuation = temp;
                    //puntuation = strtok(puntuation, NULL);
                    //printf("Hey im1 4 %s\n", puntuation);
                    strcat(original, puntuation);
                    //printf("Hey im3 %s\n", original);
                }
                else if (strchr(puntuation, '.'))
                {
                    int trye = quantity_letters(puntuation);
                    printf("This is punctuation strtok %s2\n", puntuation + strlen(puntuation) - 1);
                    strncat(original, puntuation, trye + 1);
                    strcat(original, "  ");
                    puntuation = strchr(puntuation, '.');
                    //printf("This is punctuation strtok %s2\n", puntuation);
                    puntuation++;
                    //printf("This is punctuation strtok %s2\n", puntuation);
                    strcat(original, puntuation);
                }
                else
                {
                    //printf("Jesus take the wheel\n");
                    strcat(original, temp);
                    before = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
                    strcpy(before, temp);
                }
            }
            //strcpy(puntuation, NULL);
        }
        temp = strtok(NULL, " ");
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
        //printf("This is temp outside if%s\n", temp);
        //printf("%s1\n", original);
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

char *changeUpper(char *cadena)
{
    //convertir a mayuscula.
    //printf("This is cadena%s\n", cadena);
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
    //printf("This is temp %s and quantity %d", temp, quantity_of_words);
    while ((temp = strtok(NULL, delimiter)) != NULL)
    {
        ++quantity_words;
        //printf("This is temp %s and quantity %d", temp, quantity_of_words);
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

int strlen_words(char *pointer)
{
    char *temp, *temp2, *temp3, *temp4;
    int quantity_lines = 0, quantity_letters = 0;
    quantity_letters = strlen(pointer) + 1;
    temp2 = (char *)malloc(sizeof(char) * quantity_letters);
    temp3 = (char *)malloc(sizeof(char) * quantity_letters);
    strcpy(temp2, pointer);
    strcpy(temp3, pointer);
    //temp = (char *)malloc(sizeof(char) * strlen(strtok(temp2, " ")));
    temp = strtok(temp2, " ");
    printf("This is lenght %s %d\n", temp, strlen(temp));
    //quantity_lines++;
    temp3 = strtok(temp2, "\n");
    while ((temp3 = strtok(NULL, "\n")) != NULL)
    {
        while ((temp = strtok(NULL, " ")) != NULL)
        {
            printf("This is lenght %s %d\n", temp, strlen(temp));
            //temp = (char *)malloc(sizeof(char) * strlen(strtok(NULL, " ")));
        }
    }
    return 9;
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
    char *temp, *temp2, *main_pointer, *result;
    strcpy(temp2, " ");
    main_pointer = (char *)malloc(sizeof(char) * (strlen(pointer) + 1));
    strcpy(main_pointer, pointer);
    temp = strtok(main_pointer, " ");
    temp2 = strtok(main_pointer, " ");
    while (temp)
    {
        if (strlen(temp) < strlen(temp2))
        {
            //result = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
            temp2 = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
            strcpy(temp2, temp);
        }
        temp = strtok(NULL, " ");
    }

    return temp2;
}

char *most_frequenty_word(char *main_pointer)
{
    char *temp, *temp_return, *main_pointer_temp, *result, *result_number;
    int max_repeat_word = 0, result_function = 0;
    main_pointer_temp = (char *)malloc(sizeof(char) * (strlen(main_pointer) + 1));
    strcpy(main_pointer_temp, main_pointer);
    temp = strtok(main_pointer, " ");
    //temp2 = strtok(main_pointer, " ");
    while (temp)
    {
        result_function = frequency_word(temp, main_pointer_temp);
        if (max_repeat_word < result_function)
        {
            temp_return = (char *)malloc(sizeof(char) * (strlen(temp) + 5));
            strcpy(temp_return, temp);
            sprintf(result_number, "%d", result_function);
            strcat(temp_return, result_number);
            max_repeat_word = result_function;
            //printf("This is the max %d\n", max_repeat_word);
        }
        temp = strtok(NULL, " ");
    }
}

int frequency_word(char *pointer_word, char *main_pointer)
{
    char *temp_word, *temp_main;
    int counter_frequency = 0;
    temp_main = (char *)malloc(sizeof(char) * (strlen(main_pointer) + 1));
    strcpy(temp_main, main_pointer);
    temp_word = (char *)malloc(sizeof(char) * (strlen(pointer_word) + 1));
    //strcpy(temp_word, pointer_word);
    temp_word = strstr(temp_main, pointer_word);
    while (temp_word)
    {
        ++counter_frequency;
        temp_word = strstr(NULL, pointer_word);
    }
    return counter_frequency;
}
/*
char *check_punctuation(char temp_pointer, char temp_pointer_One)
{
    if (temp_pointer == ' ' && temp_pointer == ',')
    {
        return temp_pointer_One;
    }
    else if (temp_pointer == ' ' && temp_pointer == ';')
    {
        return temp_pointer_One;
    }
    else
    {
        return;
    }
}

char *period_paragrah(char temp_pointer, char temp_pointer_One)
{
    //
    char *value;
    if (temp_pointer_One == '.' && temp_pointer_One != NULL && temp_pointer_One != ' ')
    {
        *value = toupper(temp_pointer_One);
    }
    return value;
}*/
#endif /* !FUNCTION_H_ */
