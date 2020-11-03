#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "function.h"
int main()
{

    char *file = "text.txt", *file_result = "result_text.txt", *temp, *original, *highest_word, *lowest_word, *most_frequent;
    int total_lines = 0, total_words = 0;
    modifications = 0;

    int var_letters = quantity_of_characters(file);
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

    printf("Quantity of modifications %d\n", modifications);

    insert_data(file_result, original);
    return 0;
}