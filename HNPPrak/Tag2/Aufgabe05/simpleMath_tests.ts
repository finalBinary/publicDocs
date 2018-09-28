#include "simpleMath.h"

// checkmk simpleMath_tests.ts > simpleMath_tests.c
// gcc simpleMath.c simpleMath_tests.c -o tests -Wall -lm -lpthread -lrt -lcheck -Wall -std=c99 -g
// alternativ:
// gcc simpleMath.c simpleMath_tests.c -o tests -Wall -lm -lpthread -lrt -lcheck -lsubunit -Wall -std=c99 -g
// dann: ./tests

// use ck_assert_int_eq for integer comparison
// use ck_assert_str_eq for string comparison

#test is_negative_positive
    int test_num = 1;
    int result = is_negative(test_num);
    ck_assert_int_eq(0, result);
    
#test is_negative_negative
    int test_num = -1;
    int result = is_negative(test_num);
    ck_assert_int_eq(1, result);  
    
#test is_negative_zero
    int test_num = 0;
    int result = is_negative(test_num);
    ck_assert_int_eq(0, result);      

#test add_absolute_neg_neg
    int test_num_1 = -10;
    int test_num_2 = -13;
    int result = absolute_add(test_num_1, test_num_2);
    ck_assert_int_eq(23, result);
    
#test add_absolute_neg_pos
    int test_num_1 = -10;
    int test_num_2 = 15;
    int result = absolute_add(test_num_1, test_num_2);
    ck_assert_int_eq(25, result);    

#test add_absolute_pos_neg
    int test_num_1 = 9;
    int test_num_2 = -13;
    int result = absolute_add(test_num_1, test_num_2);
    ck_assert_int_eq(22, result);

#test add_absolute_pos_pos
    int test_num_1 = 10;
    int test_num_2 = 10;
    int result = absolute_add(test_num_1, test_num_2);
    ck_assert_int_eq(20, result);    

#test absolute_neg
    int test_num = -10;
    int result = absolute(test_num);
    ck_assert_int_eq(10, result); 

#test absolute_pos
    int test_num = 5;
    int result = absolute(test_num);
    ck_assert_int_eq(5, result); 
    
#test absolute_zero
    int test_num = 0;
    int result = absolute(test_num);
    ck_assert_int_eq(0, result);     
