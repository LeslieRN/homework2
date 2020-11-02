#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "function.h"
int main()
{

    char *file = "text.txt", *temp, *original, *highest_word, *lowest_word, *most_frequent;
    int total_lines = 0, total_words = 0, modifications = 0;

    int var = quantity_of_students(file);
    temp = show_file_data(file);
    original = loopThrough(temp);
    printf("%s\n", original);

    total_words = quantity_of_words(original);
    printf("This is the quantity of words: %d\n", total_words);

    total_lines = quantity_of_lines(original);
    printf("This is the quantity of lines: %d\n", total_lines);

    highest_word = highest_strlen_word(original);
    printf("This is the highest word: %s\n", highest_word);

    lowest_word = lower_strlen_word(original);
    printf("This is the lowest word: %s\n", lowest_word);

    most_frequent = most_frequent_word(original);
    printf("This is the most frequent word: %s\n", most_frequent);

    return 0;
}