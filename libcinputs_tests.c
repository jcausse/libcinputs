//
// Created by Juan Causse on 12/07/2023.
//

#include "libcinputs.h"
#include <assert.h>

void parse_long_tests();

int main(){
    puts("LIB C INPUTS tests");
    puts("");
    parse_long_tests();
    return 0;
}

void parse_long_tests(){
    puts("parse_long");
    int i = 0;

    /*** PARSING TESTS ***/

    assert(parse_long("0", 0) == 0);
    assert(errno == 0);
    printf("Test %d passed\n", ++i);

    assert(parse_long("+0", 0) == 0);
    assert(errno == 0);
    printf("Test %d passed\n", ++i);

    assert(parse_long("-0", 0) == 0);
    assert(errno == 0);
    printf("Test %d passed\n", ++i);

    assert(parse_long("1", 0) == 1);
    assert(errno == 0);
    printf("Test %d passed\n", ++i);

    assert(parse_long("+1", 0) == 1);
    assert(errno == 0);
    printf("Test %d passed\n", ++i);

    assert(parse_long("-1523", 0) == -1523);
    assert(errno == 0);
    printf("Test %d passed\n", ++i);

    assert(parse_long("1904425", 0) == 1904425);
    assert(errno == 0);
    printf("Test %d passed\n", ++i);

    assert(parse_long("-25234563623", 0) == -25234563623);
    assert(errno == 0);
    printf("Test %d passed\n", ++i);

    assert(parse_long("+9223372036854775807", 0) == LONG_MAX); //LONG_MAX test
    assert(errno == 0);
    printf("Test %d passed\n", ++i);

    assert(parse_long("-9223372036854775808", 0) == LONG_MIN); //LONG_MIN test
    assert(errno == 0);
    printf("Test %d passed\n", ++i);

    assert(parse_long("123abc456", 0) == 123);
    assert(errno == 0);
    printf("Test %d passed\n", ++i);

    assert(parse_long("                             123abc456", 0) == 123);
    assert(errno == 0);
    printf("Test %d passed\n", ++i);

    assert(parse_long("123 456", 0) == 123);
    assert(errno == 0);
    printf("Test %d passed\n", ++i);




    /*** INVALID STRING TESTS ***/

    assert(parse_long(NULL, 0) == 0);
    assert(errno == EINVAL);
    printf("Test %d passed\n", ++i);

    assert(parse_long("", 0) == 0);
    assert(errno == EINVAL);
    printf("Test %d passed\n", ++i);

    assert(parse_long("This is a test", 0) == 0);
    assert(errno == EINVAL);
    printf("Test %d passed\n", ++i);

    assert(parse_long("abc123", 0) == 0);
    assert(errno == EINVAL);
    printf("Test %d passed\n", ++i);

    assert(parse_long("--2", 0) == 0); //Double opposite sign
    assert(errno == EINVAL);
    printf("Test %d passed\n", ++i);




    /*** NUMBER OUT OF RANGE TESTS ***/

    assert(parse_long("123456789123456789123456789", 0) == 0);
    assert(errno == ERANGE);
    printf("Test %d passed\n", ++i);

    assert(parse_long("-987654321987654321987654321", 0) == 0);
    assert(errno == ERANGE);
    printf("Test %d passed\n", ++i);

    assert(parse_long("9223372036854775808", 0) == 0); //LONG_MAX + 1 (out of range)
    assert(errno == ERANGE);
    printf("Test %d passed\n", ++i);

    assert(parse_long("-9223372036854775809", 0) == 0); //LONG_MIN - 1 (out of range)
    assert(errno == ERANGE);
    printf("Test %d passed\n", ++i);




    /*** INVALID RADIX TESTS ***/

    assert(parse_long("12345", -1) == 0);
    assert(errno == EINVAL);
    printf("Test %d passed\n", ++i);

    assert(parse_long("12345", 37) == 0);
    assert(errno == EINVAL);
    printf("Test %d passed\n", ++i);

    assert(parse_long("12345", -120) == 0);
    assert(errno == EINVAL);
    printf("Test %d passed\n", ++i);

    assert(parse_long("12345", 135) == 0);
    assert(errno == EINVAL);
    printf("Test %d passed\n", ++i);


    /*** PARSING WITH NON ZERO RADIX PARAMETER TESTS ***/ //TODO
    /*** INVALID LITERAL FOR RADIX TESTS ***/ //TODO

    puts("");
}
