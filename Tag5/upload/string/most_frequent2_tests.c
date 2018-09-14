/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "Dateien/tag5/most_frequent2/loesung/most_frequent2_tests.ts" instead.
 */

#include <check.h>

#line 1 "Dateien/tag5/most_frequent2/loesung/most_frequent2_tests.ts"
#include "most_frequent2.h"
#include <string.h>

// checkmk most_frequent2_tests.ts > most_frequent2_tests.c
// gcc most_frequent2.c most_frequent2_tests.c -o tests -Wall -lm -lpthread -lrt -lcheck -Wall -std=c99 -g -fprofile-arcs -ftest-coverage

void check_word_array(int cnt_words, int *mycount, int *count, char mywords[][80]){
    for(int i = 0; i < cnt_words; i++){
        int word_found = 0;
        for(int j = 0; j < cnt_words; j++){
            if(strcmp(mywords[i], words[j]) == 0 ){
                word_found++;
                ck_assert_msg(count[j] == mycount[i], "Anzahl für Wort %s nicht korrekt. Ist %i, soll %i.\n", mywords[i], count[j], mycount[i]);
            }
        }
        if(word_found == 0){
            ck_abort_msg("Wort %s in words nicht gefunden!\n", mywords[i]);
        } else if (word_found > 1) {
            ck_abort_msg("Wort %s in words zu oft gefunden!\n", mywords[i]);
        }
    }
}

START_TEST(extract_and_count_without_special_chars_return_value)
{
#line 25
    char string[] = "Wort1 Wort2 wort1 Wort1 Wort1 Wort4 Wort3 Wort3";
    int count[80]; 
    ck_assert_int_eq(extract_and_count(string, count), 5);

}
END_TEST

START_TEST(extract_and_count_without_special_chars_check_arrays)
{
#line 30
    char string[] = "Wort1 Wort2 wort1 Wort1 Wort1 Wort4 Wort3 Wort3";
    char mywords[][80] = {"Wort1", "Wort2", "wort1", "Wort4", "Wort3"};
    int mycount[] = {3, 1, 1, 1, 2};
    int cnt_words = 5;
    int count[80]; 
    extract_and_count(string, count);
    check_word_array(cnt_words, mycount, count, mywords);


}
END_TEST

START_TEST(extract_and_count_with_single_special_chars_return_value)
{
#line 40
    char string[] = "Wort1! Wort2 , wort1 !Wort1 Wort1 ?Wort4 Wort3 Wort3?";
    int count[80]; 
    ck_assert_int_eq(extract_and_count(string, count), 8);

}
END_TEST

START_TEST(extract_and_count_with_single_special_chars_check_arrays)
{
#line 45
    char string[] = "Wort1! Wort2 , wort1 !Wort1! Wort1 ?Wort4 Wort3 Wort3?";
    char mywords[][80] = {"Wort1", "Wort2", "wort1", "Wort4", "Wort3", ",", "?", "!"};
    int mycount[] = {3, 1, 1, 1, 2, 1, 2, 3};
    int cnt_words = 8;
    int count[80]; 
    extract_and_count(string, count);
    check_word_array(cnt_words, mycount, count, mywords);

}
END_TEST

START_TEST(extract_and_count_with_piled_special_chars_return_value)
{
#line 54
    char string[] = "Wort1!!! Wort2  ...wort1 !Wort1. . . Wort1 ?Wort4 Wort3 Wort3?";
    int count[80]; 
    ck_assert_int_eq(extract_and_count(string, count), 8);

}
END_TEST

START_TEST(extract_and_count_with_piled_special_chars_check_arrays)
{
#line 59
    char string[] = "Wort1! Wort2 ,, , ... wort1! !Wort1! ,Wort1 ?Wort4 Wort3 Wort3?";
    char mywords[][80] = {"Wort1", "Wort2", "wort1", "Wort4", "Wort3", ",", "?", "!", "."};
    int mycount[] = {3, 1, 1, 1, 2, 4, 2, 4, 3};
    int cnt_words = 9;
    int count[80]; 
    extract_and_count(string, count);
    check_word_array(cnt_words, mycount, count, mywords);


}
END_TEST

START_TEST(get_most_frequent_word_definitive_answer)
{
#line 69
    int count[] = {2, 5, 1, 0};
    ck_assert_int_eq(get_most_frequent_word(4, count), 1);

}
END_TEST

START_TEST(get_most_frequent_word_not_definitive_answer)
{
#line 73
    int count[] = {2, 5, 1, 1, 4, 3, 1, 1, 1, 5, 1, 1, 1, 1, 1, 1, 5, 1, 1, 5};
    int pos = get_most_frequent_word(20, count);
    ck_assert( pos == 1 || pos == 9 || pos == 19);

}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, extract_and_count_without_special_chars_return_value);
    tcase_add_test(tc1_1, extract_and_count_without_special_chars_check_arrays);
    tcase_add_test(tc1_1, extract_and_count_with_single_special_chars_return_value);
    tcase_add_test(tc1_1, extract_and_count_with_single_special_chars_check_arrays);
    tcase_add_test(tc1_1, extract_and_count_with_piled_special_chars_return_value);
    tcase_add_test(tc1_1, extract_and_count_with_piled_special_chars_check_arrays);
    tcase_add_test(tc1_1, get_most_frequent_word_definitive_answer);
    tcase_add_test(tc1_1, get_most_frequent_word_not_definitive_answer);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
