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

/*FILE FUNCTIONS*/
FILE *open_file(char *, char *);
void close_file(FILE *);
char *show_file_data(char *);
int quantity_of_characters(char *file_name);
void insert_data(char *file_name, char *);
/*Text Funtions*/
char *loopThrough(char *);
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

int modifications;
void insert_data(char *file_name, char *data_text)
{
    FILE *file = open_file(file_name, "a+");
    fwrite(data_text, sizeof(char) * (strlen(data_text) + 1), 1, file);
    close_file(file);
}
FILE *open_file(char *name_file, char *mode)
{
    //open the file
    FILE *file = fopen(name_file, mode);
    return file;
}

void close_file(FILE *name_file)
{
    //close the file
    fclose(name_file);
}

char *show_file_data(char *file_name)
{
    FILE *file = open_file(file_name, "r");
    int total = quantity_of_characters(file_name);
    char *values = (char *)malloc(sizeof(char) * (total + 1));
    //obtains the text from the file
    fread(values, sizeof(char) * quantity_of_characters(file_name), 1, file);
    close_file(file);
    return values;
}

int quantity_of_characters(char *file_name)
{
    FILE *file = open_file(file_name, "r");
    fseek(file, 0L, SEEK_END); //move at the end of the file
    long bytes = ftell(file);  //tells the location of the cursor
    //obtains the quantity of characters
    int students = bytes / sizeof(char);
    close_file(file);
    return students;
}

char *loopThrough(char *main_pointer)
{
    int counter = -1; //counter it's like a key, it is used to determine the differents actions to do

    char *original, *temp, *puntuation, *before;
    //before it's a pointer which contains the before value of the current one
    original = (char *)malloc(sizeof(char) * strlen(main_pointer) + 100);
    before = (char *)malloc(sizeof(char));

    strcpy(before, " ");
    temp = strtok(main_pointer, "\n"); //temp it's going to be equal to the string before the first \n

    modifications = 0;
    while (temp)
    {
        puntuation = (char *)malloc(sizeof(char) * strlen(temp) + 1); //setting a temp variable
        strcpy(puntuation, temp);
        if (temp)
        {
            if (counter == -1)
            {
                //if counter == -1 means its the first lineo
                puntuation = changeUpper(puntuation);
                strcpy(original, puntuation);
                strcat(original, "\n");
                strcat(original, "\n");
                strcat(original, "\n");
                counter = 0;
            }
            else if (counter == 0)
            {
                //if counter == 0 means its the first word of the paragrah
                strcat(original, "    ");
                strcat(original, change_first_letter_upper(puntuation));
                counter = 1;
            }
            else if (counter > 0)
            {
                //if counter == 1 means its the rest of the text
                if (*(puntuation + 0) == ',')
                {
                    //when the value it's a , then we add the , and a space, to continue with the rest of the word.
                    strcat(original, ",");
                    strcat(original, " ");
                    puntuation++;
                    strcat(original, puntuation);
                    modifications++;
                }
                else if (*(puntuation + 0) == ';')
                {
                    //when the value it's a ; then we add the ; and a space, to continue with the rest of the word.
                    strcat(original, ";");
                    strcat(original, " ");
                    puntuation++;
                    strcat(original, puntuation);
                    modifications++;
                }
                else
                {
                    //in case that there is no comma or semicolon
                    strcat(original, period_paragrah(before, puntuation));
                }
            }
        }
        //setting before to the current element of temp
        before = (char *)malloc(sizeof(char) * (strlen(puntuation) + 1));
        strcpy(before, puntuation);
        //move temp to th next
        temp = strtok(NULL, " ");
        if (temp == NULL)
        {
            break;
        }
        else if ((*(temp + 0) != ',') && (*(temp + 0) != ';') && (*(temp + 0) != '.'))
        {
            //adding space in case that there are no puntuactions at the begining
            strcat(original, " ");
        }
    }
    return original;
}

int quantity_letters(char *pointer)
{
    //obtains the quantity of letters before a period
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
        if (i == 0 && pointer_word[i] >= 97 && pointer_word[i] <= 122)
        {
            //this is only for the first value, since one of the conditions is i == 0
            letter = pointer_word[i] - 32;
            strncat(temp_pointer, &letter, 1);
            modifications++;
        }
        else
        {
            letter = pointer_word[i];
            strncat(temp_pointer, &letter, 1);
        }
    }
    return temp_pointer;
}
char *changeUpper(char *cadena)
{
    //this function changes everything to uppercase
    char *temp, letter;
    temp = (char *)malloc(sizeof(char) * (strlen(cadena) + 42));
    strcpy(temp, "                                        ");
    for (int i = 0; cadena[i] != '\0'; ++i)
    {
        if (cadena[i] >= 97 && cadena[i] <= 122)
        {
            letter = cadena[i] - 32;
            strncat(temp, &letter, 1);
            modifications++;
        }
        else
        {
            letter = cadena[i];
            strncat(temp, &letter, 1);
        }
    }
    return temp;
}

int quantity_of_words(char *pointer)
{
    //this function obtains the quantity of words
    char *temp, *temp2, *delimiter = " \n";
    int quantity_words = 0;
    //setting enough space for the temp2 pointer
    temp2 = (char *)malloc(sizeof(char) * (strlen(pointer) + 1));
    strcpy(temp2, pointer);
    temp = strtok(temp2, delimiter); // the temp will have the value that has the delemiter coditions
    ++quantity_words;
    while ((temp = strtok(NULL, delimiter)) != NULL)
    {
        ++quantity_words;
    }
    return quantity_words;
}
int quantity_of_lines(char *pointer)
{
    //this function obtains the quantity of lines
    char *temp, *temp2;
    int quantity_lines = 0;
    //setting enough space for the temp2 pointer
    temp2 = (char *)malloc(sizeof(char) * (strlen(pointer) + 1));
    strcpy(temp2, pointer);
    temp = strtok(temp2, "\n"); // the temp will have the value that has the \n
    quantity_lines++;
    while ((temp = strtok(NULL, "\n")) != NULL)
    {
        quantity_lines++;
    }
    return quantity_lines;
}
char *highest_strlen_word(char *pointer)
{
    //this functions obtains the largest string
    char *temp, *temp2, *main_pointer, *result, *delimiter = " \n";
    strcpy(temp2, " ");
    main_pointer = (char *)malloc(sizeof(char) * (strlen(pointer) + 1));
    strcpy(main_pointer, pointer);
    temp = strtok(main_pointer, delimiter);
    while (temp)
    {
        //if temp2 < than temp then temp2 == temp
        if (strlen(temp2) < strlen(temp))
        {
            temp2 = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
            strcpy(temp2, temp);
        }
        temp = strtok(NULL, delimiter); //move the pointer accoding to the delimiter
    }

    return temp2;
}

char *lower_strlen_word(char *pointer)
{
    //this function obtains the shortest string
    char *temp, *temp2, *main_pointer, *result, *delimiter = " \n";
    main_pointer = (char *)malloc(sizeof(char) * (strlen(pointer) + 1));
    strcpy(main_pointer, pointer);
    temp = strtok(main_pointer, delimiter); //temp it's going to be equal to the first strig
    temp2 = strtok(NULL, delimiter);        //temp2 it's gin to be the second one
    while (temp)
    {
        //if temp < than temp2 then temp2 == temp
        if (strlen(temp) < strlen(temp2))
        {
            temp2 = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
            strcpy(temp2, temp);
        }
        temp = strtok(NULL, delimiter); //move the pointer temp
    }

    return temp2;
}

char *most_frequent_word(char *main_pointer)
{
    //this function obtain the most frequent word
    char *temp, *temp_return, *main_pointer_temp, *result, *result_number;
    int max_repeat_word = 0, result_function = 0;
    main_pointer_temp = (char *)malloc(sizeof(char) * (strlen(main_pointer) + 1));
    strcpy(main_pointer_temp, main_pointer);
    temp = strtok(main_pointer_temp, " "); //moves to the first string

    while (temp)
    {
        result_function = frequency_word(temp, main_pointer); //returns the quantity of that string
        if (max_repeat_word < result_function)                //if that quantity is more than max, then max == result
        {
            temp_return = (char *)malloc(sizeof(char) * (strlen(temp) + 5));
            strcpy(temp_return, temp);
            //concatenation of the word and the amount of times
            sprintf(result_number, " %d", result_function);
            strcat(temp_return, result_number);

            max_repeat_word = result_function;
        }
        temp = strtok(NULL, " "); //move pointer
    }
    return temp_return;
}

int frequency_word(char *pointer_word, char *main_pointer)
{
    char *temp_word, *temp_main;
    int counter_frequency = 0;
    temp_main = (char *)malloc(sizeof(char) * (strlen(main_pointer) + 1));
    strcpy(temp_main, main_pointer);
    //this loop will continue until there are no matches with the string
    while ((temp_main = strstr(temp_main, pointer_word)) != NULL)
    {
        counter_frequency++; //incrementation of the frequency
        temp_main++;
    }
    return counter_frequency;
}
char *period_paragrah(char *before_loop, char *temp_loop)
{
    //this functions determines whether it's necessary to make changes(period) or not
    int point_end = 0;
    char *temp_word = (char *)malloc(sizeof(char) * (strlen(temp_loop) + 3));
    point_end = strlen(before_loop);
    strcpy(temp_word, "");
    //if the period of before it's located at the end
    if (*(before_loop + (strlen(before_loop) - 1)) == '.')
    {
        //Then double space and changing the letter to Uppercase
        strcat(temp_word, "  ");
        strcat(temp_word, change_first_letter_upper(temp_loop));
        modifications++;
    }
    else if (strchr(temp_loop, '.') && *(before_loop + (strlen(before_loop) - 1)) != '.')
    {
        //if there is a period and that period it's not located at the end
        //obtains the quantity of letter before
        int quantity_before_point = quantity_letters(temp_loop);
        //add those to the pointer
        strncat(temp_word, temp_loop, quantity_before_point + 1);
        //add the two spaces
        strcat(temp_word, "  ");
        temp_loop = strchr(temp_loop, '.');                      //moves to the point character
        temp_loop++;                                             //increment by 1 so we obtains the next part of the text
        strcat(temp_word, change_first_letter_upper(temp_loop)); //add that part with Uppercase
        modifications++;
    }
    else
    {
        //if there is no period then, return the same word
        return temp_loop;
    }
    return temp_word;
}

#endif /* !FUNCTION_H_ */