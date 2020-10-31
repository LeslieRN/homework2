#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "function.h"
#include <ctype.h>

//char *add_space_begining(char *);
//char *godPlease(char *);
//int quantity_letters(char *);
int main()
{
    /*char *text = "This is some text i want to change\0";
    char *anotherText = "", *var;
    int counter = 0;
    int total = strlen(text);
    anotherText = (char *)malloc(sizeof(char) * (total + 1));
    while (text != '\0')
    {
        if (*(text + counter) != 65)
        {
            *var = *(anotherText + counter);
            strcat(anotherText, var);
            //strncat(anotherText, text, counter);
            //printf("This is another text %s\n", anotherText);
        }
        counter++;
        //text++;
    }
    printf("Hey");
    printf("This is another text %s", anotherText);*/
    char *file = "text.txt", *temp, *original, buffer[100], *highest_word, *lowest_word, *most_frequent_word;
    int total_lines = 0, total_words = 0;
    //insert_data(file);
    int var = quantity_of_students(file); //, check;
    printf("This is quantity of the text %d\n", var);
    temp = show_file_data(file);
    original = loopThrough(temp);
    printf("%s\n", original);
    total_words = quantity_of_words(original);
    printf("This is the quantity of words: %d\n", total_words);
    total_lines = quantity_of_lines(original);
    printf("This is the quantity of lines: %d\n", total_words);
    highest_word = highest_strlen_word(original);
    printf("This is the highest word: %s\n", highest_word);
    lowest_word = lower_strlen_word(original);
    //printf("This is the lowest word: %s\n", lowest_word);
    //most_frequent_word = most_frequenty_word(original);

    return 0;
}

//printf("This is the highest word: %s\n", highest_word);
//printf("This is the lowest word: %s\n", lowest_word);
//printf("This is the most frequent word %s", most_frequenty_word);
/*strlen_words(hey);
    original = (char *)malloc(sizeof(char) * strlen(temp) + 10);
    val2 = strtok(temp, " ");
    hey = (char *)malloc(sizeof(char) * (strlen(val2)));
    while (val2 != NULL)
    {
        //printf("hola gu%s\n", val2);
        //hey = (char *)malloc(sizeof(char) * (strlen(val2)));
        //hey = (char *)realloc(hey, sizeof(char) * (strlen(val2)));
        strcpy(hey, val2);
        printf("hola gu%s\n", val2);
        if (strchr(hey, '.'))
        {
            //printf("Ke\n");
            printf("This is val2 %s\n", val2);
            printf("This is hey %s\n", hey);
            //check = godPlease(hey);
            //char *okay = godPlease(hey);
            //strcpy(buffer, okay);
            int trye = quantity_letters(hey);
            strncat(original, hey, trye + 1);
            printf("Hey original %s\n", original);
            strcat(original, "  ");

            hey = strchr(hey, '.');
            hey++;
            printf("This is hey %s\n", hey);
            strcat(origin/al, hey);
            //strcat(original, hey);
            printf("This is hey %s\n", hey);
            //val2 = strchr(val2, '.');
            printf("This is hey %s\n", val2);
            //printf("This is hey %s\n", hey + 1);
            //printf("This is check %d\n", check);
            //puntuation = strtok(temp, ".");
            //printf("This is temp %s\n", strchr(temp, '.'));
            //printf("This is punctuation %s\n", hey + check);
            //printf("This is hey %s\n", hey + check);
            //strcat(original, val2);
            //printf("I'm in\n");
            //printf("This is temp %c\n", *(temp + check + 2));
            //strcat(original, puntuation);
            //puntuation = ++puntuation; //strtok(puntuation + check, NULL);
            //strcat(original, ".  ");
            //strcat(original, puntuation + check);
            //printf("This is punctuation strtok %s\n", hey);
            //*(puntuation + 0) = toupper(temp + check + 1);
            //printf("This is punctuation toUpper %c\n", *(puntuation + 0));
            //strcat(original, hey + check);
            //printf("Hey original %s\n", original);
            //printf("okay\n");
            //temp = strtok(NULL, " ");
        }
        //printf("This is temp %s\n", val2);
        //temp++;
        //printf("This is temp %s\n", val2);
        val2 = strtok(NULL, " ");
        printf("This is temp %s\n", val2);
    }

    //hey = loopThrough(temp);
    //printf("\nValues 1 %c\n", *values);
    //strcat(values, "\0");
    /*printf("Values\n");
    int counter = 0;
    while (counter < (var - 1))
    {
        printf("Hello %c\n", *values); //(), counter);
        //counter++;
        if (counter == 0)
        {
            hey = (char *)malloc(sizeof(char) * 14);
            strcpy(hey, "    ");
            printf("This is hey to upper %snice\n", hey);
            *(hey + 4) = *(values);
            //char *firstLetter = (char *)tolower(*values);
            //strcpy(hey, *values);
            printf("This is hey to upper %snice\n", hey);
            //hey = strtok(++values, " ");
        }
        else
        {
            /* code */
/*      if (*(values + 1) == ',' && *values == ' ')
            {
                *val2 = *(values + 1);
                *(hey + (counter + 4)) = *(values + 1);
                printf("This is hey to upper 3 %snice\n", hey);
                values++;
            }
            else
            {
                *(hey + (counter + 4)) = *(values);
                //printf("This is hey to upper %snice\n", hey);
            }
        }
        values++;
        counter++;
    }*/

/*char *godPlease(char *pointer)
{
    char *prov;
    prov = (char *)malloc(sizeof(char) * (strlen(pointer) + 1));
    strcpy(prov, pointer);
    prov = strtok(prov, ".");
    //int s = strlen(strtok(pointer, "."));
    //printf("Okay baby\n");
    return prov;
}*/
/*
int quantity_letters(char *pointer)
{
    int counter = 0;
    while (*pointer != '.')
    {
        counter++;
        pointer++;
    }
    return counter;
}*/
/*function add speces in the begining*/
