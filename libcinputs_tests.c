//
// Created by Juan Causse on 12/07/2023.
//

#include "libcinputs.h"
#include <assert.h>

void parseint_tests();

int main(int argc, char** argv){
    puts("INPUTSLIB tests");
    puts("");
    parseint_tests();
    return 0;
}

void parseint_tests(){
    puts("parseint");
    errno = 0;

    assert(parseint("0") == 0);
    assert(errno == 0);
    puts("Test 1 passed");

    assert(parseint("-1523") == -1523);
    assert(errno == 0);
    puts("Test 2 passed");

    assert(parseint("1904425") == 1904425);
    assert(errno == 0);
    puts("Test 3 passed");

    assert(parseint("This is a test") == 0);
    assert(errno == EINVAL);
    puts("Test 4 passed");

    assert(parseint("abc123") == 0);
    assert(errno == EINVAL);
    puts("Test 5 passed");

    puts("");
}

