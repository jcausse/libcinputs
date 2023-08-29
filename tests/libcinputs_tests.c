//
// Created by Juan Causse on 12/07/2023.
//

#include "../src/libcinputs.h"
#include <assert.h>

const char *getBuild() { //Get current architecture, detectx nearly every architecture. Coded by Freak
    #if defined(__x86_64__) || defined(_M_X64)
    return "x86_64";
    #elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
    return "x86_32";
    #elif defined(__ARM_ARCH_2__)
    return "ARM2";
    #elif defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)
    return "ARM3";
    #elif defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T)
    return "ARM4T";
    #elif defined(__ARM_ARCH_5_) || defined(__ARM_ARCH_5E_)
    return "ARM5"
    #elif defined(__ARM_ARCH_6T2_) || defined(__ARM_ARCH_6T2_)
    return "ARM6T2";
    #elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__)
    return "ARM6";
    #elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
    return "ARM7";
    #elif defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
    return "ARM7A";
    #elif defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
    return "ARM7R";
    #elif defined(__ARM_ARCH_7M__)
    return "ARM7M";
    #elif defined(__ARM_ARCH_7S__)
    return "ARM7S";
    #elif defined(__aarch64__) || defined(_M_ARM64)
    return "ARM64";
    #elif defined(mips) || defined(__mips__) || defined(__mips)
    return "MIPS";
    #elif defined(__sh__)
    return "SUPERH";
    #elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__PPC__) || defined(_ARCH_PPC)
    return "POWERPC";
    #elif defined(__PPC64__) || defined(__ppc64__) || defined(_ARCH_PPC64)
    return "POWERPC64";
    #elif defined(__sparc__) || defined(__sparc)
    return "SPARC";
    #elif defined(__m68k__)
    return "M68K";
    #else
    return "UNKNOWN";
    #endif
}

void parse_short_tests();
void parse_int_tests();
void parse_long_tests();

void get_short_tests();
void get_int_tests();
void get_long_tests();

void parse_float_tests();
void parse_double_tests();
void parse_long_double_tests();

void get_float_tests();
void get_double_tests();

void compare_float_tests();
void compare_double_tests();



int main(){
    printf("LIB C INPUTS version %s tests\n", LIBCINPUTS_VERSION);
    printf("Compiled: %s, %s. Platform: %s\n", __DATE__, __TIME__, getBuild());
    puts("Created by Juan Ignacio Causse\n\n");

    parse_short_tests();
    parse_int_tests();
    parse_long_tests();

    get_short_tests();
    get_int_tests();
    get_long_tests();

    parse_float_tests();
    parse_double_tests();
    parse_long_double_tests();

    get_float_tests();
    get_double_tests();

    compare_float_tests();
    compare_double_tests();

    puts("************* ALL TESTS PASSED *************");

    return 0;
}

/************************************* INTEGERS *************************************/

void parse_short_tests(){
    puts("*** parse_short ***");
    int i = 0;

    /*** PARSING TESTS ***/

    assert(parse_short("0", 0) == 0);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_short("32767", 0) == SHRT_MAX);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_short("-32768", 0) == SHRT_MIN);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);




    /*** INVALID STRING TESTS ***/

    assert(parse_short(NULL, 0) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_short("", 0) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_short("This is a test", 0) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_short("abc123", 0) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_short("--2", 0) == 0); //Double opposite sign
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);




    /*** NUMBER OUT OF RANGE TESTS ***/

    assert(parse_short("32768", 0) == 0);   // SHRT_MAX + 1 test
    assert(errno == ERANGE);
    printf("Test %02d passed\n", ++i);

    assert(parse_short("-32769", 0) == 0);  // SHRT_MIN - 1 test
    assert(errno == ERANGE);
    printf("Test %02d passed\n", ++i);




    /*** INVALID RADIX TESTS ***/

    assert(parse_short("12345", -1) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_short("12345", 1) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_short("12345", 37) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_short("12345", -120) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_short("12345", 135) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    puts("*** All parse_short tests passed ***\n");
}

void parse_int_tests(){
    puts("*** parse_int ***");
    int i = 0;

    /*** PARSING TESTS ***/

    assert(parse_int("0", 0) == 0);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_int("2147483647", 0) == INT_MAX);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_int("-2147483648", 0) == INT_MIN);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);




    /*** INVALID STRING TESTS ***/

    assert(parse_int(NULL, 0) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_int("", 0) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_int("This is a test", 0) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_int("abc123", 0) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_int("--2", 0) == 0); //Double opposite sign
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);




    /*** NUMBER OUT OF RANGE TESTS ***/

    assert(parse_int("2147483648", 0) == 0);   // INT_MAX + 1 test
    assert(errno == ERANGE);
    printf("Test %02d passed\n", ++i);

    assert(parse_int("-2147483649", 0) == 0);  // INT_MIN - 1 test
    assert(errno == ERANGE);
    printf("Test %02d passed\n", ++i);




    /*** INVALID RADIX TESTS ***/

    assert(parse_int("12345", -1) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_int("12345", 1) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_int("12345", 37) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_int("12345", -120) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_int("12345", 135) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    puts("*** All parse_int tests passed ***\n");
}

void parse_long_tests(){
    puts("*** parse_long ***");
    int i = 0;

    /*** PARSING TESTS ***/

    assert(parse_long("0", 0) == 0);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("+0", 0) == 0);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("-0", 0) == 0);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("1", 0) == 1);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("+1", 0) == 1);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("-1523", 0) == -1523);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("1904425", 0) == 1904425);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("-25234563623", 0) == -25234563623);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("+9223372036854775807", 0) == LONG_MAX); //LONG_MAX test
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("-9223372036854775808", 0) == LONG_MIN); //LONG_MIN test
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("123abc456", 0) == 123);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("                             123abc456", 0) == 123);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("123 456", 0) == 123);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("0x48Dcb2E", 16) == 76401454);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("0X48Dcb2E", 16) == 76401454);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("045226657", 8) == 9776559);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);




    /*** INVALID STRING TESTS ***/

    assert(parse_long(NULL, 0) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("", 0) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("This is a test", 0) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("abc123", 0) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("--2", 0) == 0); //Double opposite sign
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);




    /*** NUMBER OUT OF RANGE TESTS ***/

    assert(parse_long("123456789123456789123456789", 0) == 0);
    assert(errno == ERANGE);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("-987654321987654321987654321", 0) == 0);
    assert(errno == ERANGE);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("9223372036854775808", 0) == 0); //LONG_MAX + 1 (out of range)
    assert(errno == ERANGE);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("-9223372036854775809", 0) == 0); //LONG_MIN - 1 (out of range)
    assert(errno == ERANGE);
    printf("Test %02d passed\n", ++i);




    /*** INVALID RADIX TESTS ***/

    assert(parse_long("12345", -1) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("12345", 1) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("12345", 37) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("12345", -120) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("12345", 135) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);




    /*** PARSING WITH NON ZERO RADIX PARAMETER TESTS ***/ //TODO
    assert(parse_long("123041", 5) == 4771);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("48Dcb2E", 16) == 76401454);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(parse_long("45226657", 8) == 9776559);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    puts("*** All parse_long tests passed ***\n");
}

void get_short_tests(){
    puts("*** get_short ***");
    int i = 0;

    assert(get_short(NULL) == 123);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(get_short(NULL) == 456);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(get_short(NULL) == 789);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(get_short(NULL) == 32767);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(get_short(NULL) == 0);
    assert(errno == ERANGE);
    printf("Test %02d passed\n", ++i);

    assert(get_short(NULL) == -32768);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(get_short(NULL) == 0);
    assert(errno == ERANGE);
    printf("Test %02d passed\n", ++i);

    assert(get_short(NULL) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(get_short(NULL) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(get_short(NULL) == 15);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(get_short(NULL) == 0);
    assert(errno == EINVAL);
    printf("Test %02d passed\n", ++i);

    assert(get_short(NULL) == 0);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    puts("*** All get_short tests passed ***\n");
}

void get_int_tests(){
    puts("*** get_int ***");
    int i = 0;

    assert(get_int(NULL) == 123);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(get_int(NULL) == INT_MAX);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(get_int(NULL) == 0);
    assert(errno == ERANGE);
    printf("Test %02d passed\n", ++i);

    assert(get_int(NULL) == INT_MIN);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(get_int(NULL) == 0);
    assert(errno == ERANGE);
    printf("Test %02d passed\n", ++i);

    assert(get_int(NULL) == 0);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    puts("*** All get_int tests passed ***\n");
}

void get_long_tests(){
    puts("*** get_long ***");
    int i = 0;

    assert(get_long(NULL) == 123);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(get_long(NULL) == LONG_MAX);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(get_long(NULL) == 0);
    assert(errno == ERANGE);
    printf("Test %02d passed\n", ++i);

    assert(get_long(NULL) == LONG_MIN);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    assert(get_long(NULL) == 0);
    assert(errno == ERANGE);
    printf("Test %02d passed\n", ++i);

    assert(get_long(NULL) == 0);
    assert(errno == 0);
    printf("Test %02d passed\n", ++i);

    puts("*** All get_long tests passed ***\n");
}

/*TODO*/ void parse_float_tests(){
    puts("*** parse_float ***");
    int i = 0;

    puts("*** All parse_float tests passed ***\n");
}

/*TODO*/ void parse_double_tests(){
    puts("*** parse_double ***");
    int i = 0;

    puts("*** All parse_double tests passed ***\n");
}

/*TODO*/ void parse_long_double_tests(){
    puts("*** parse_long_double ***");
    int i = 0;

    puts("*** All parse_long_double tests passed ***\n");
}

/*TODO*/ void get_float_tests(){
    puts("*** get_float ***");
    int i = 0;

    puts("*** All get_float tests passed ***\n");
}

/*TODO*/ void get_double_tests(){
    puts("*** get_double ***");
    int i = 0;

    puts("*** All get_double tests passed ***\n");
}

void compare_float_tests(){
    puts("*** compare_float ***");
    int i = 0;

    assert(compare_float(1.0f, 1.0f) == 0);
    printf("Test %02d passed\n", ++i);

    assert(compare_float(0.1f, 0.1f) == 0);
    printf("Test %02d passed\n", ++i);

    assert(compare_float(2.0f, 1.0f) == 1);
    printf("Test %02d passed\n", ++i);

    assert(compare_float(1.0f, 2.0f) == -1);
    printf("Test %02d passed\n", ++i);

    assert(compare_float(0.1f + 0.2f, 0.3f) == 0);
    printf("Test %02d passed\n", ++i);

    assert(compare_float(0.000000001 + 0.000000002, 0.000000003) == 0);
    printf("Test %02d passed\n", ++i);

    assert(compare_float(0.1f + 1e-6f, 0.1f) == 1);
    printf("Test %02d passed\n", ++i);

    assert(compare_float(0.1f, 0.1f + 1e-6f) == -1);
    printf("Test %02d passed\n", ++i);

    assert(compare_float(0.1f + 1e-7f, 0.1f) == 0);
    printf("Test %02d passed\n", ++i);

    assert(compare_float(0.1f, 0.1f + 1e-7f) == 0);
    printf("Test %02d passed\n", ++i);

    puts("*** All compare_float tests passed ***\n");
}

void compare_double_tests(){
    puts("*** compare_double ***");
    int i = 0;

    assert(compare_double(1.0, 1.0) == 0);
    printf("Test %02d passed\n", ++i);

    assert(compare_double(0.1, 0.1) == 0);
    printf("Test %02d passed\n", ++i);

    assert(compare_double(2.0, 1.0) == 1);
    printf("Test %02d passed\n", ++i);

    assert(compare_double(1.0, 2.0) == -1);
    printf("Test %02d passed\n", ++i);

    assert(compare_double(0.1 + 0.2, 0.3) == 0);
    printf("Test %02d passed\n", ++i);

    assert(compare_double(0.000000000001 + 0.000000000002, 0.000000000003) == 0);
    printf("Test %02d passed\n", ++i);

    assert(compare_double(0.1 + 1e-12, 0.1) == 1);
    printf("Test %02d passed\n", ++i);

    assert(compare_double(0.1, 0.1 + 1e-12) == -1);
    printf("Test %02d passed\n", ++i);

    assert(compare_double(0.1 + 1e-13, 0.1) == 0);
    printf("Test %02d passed\n", ++i);

    assert(compare_double(0.1, 0.1 + 1e-13) == 0);
    printf("Test %02d passed\n", ++i);

    puts("*** All compare_double tests passed ***\n");
}

