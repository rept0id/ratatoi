#include <stdlib.h>
#include <stdio.h>

#include <errno.h>

#include <limits.h>

#include <string.h>

#include "ratatoi.h"

/*** * * ***/

int ratatoi(const char *aString) {
    errno = 0;

    char *strtolEndptr;

    long aLong;
    int aInt;

    /*** * * ***/

    aLong = strtol(aString, &strtolEndptr, 10);

    /*** * * ***/

    // checks

    // checks : no digits parsed
    if (strtolEndptr == aString) {
        fprintf(
            stderr,

            "ratatoi : error : couldn't parse '%s' (aborting).\n",

            aString
        );

        /*** * * ***/

        abort();
    }

    // checks : not all digits parsed
    if (*strtolEndptr != '\0') {
        fprintf(
            stderr,

            "ratatoi : error : couldn't parse all of '%s', garbage : '%s' (aborting).\n",

            aString,
            strtolEndptr
        );

        /*** * * ***/

        abort();
    }

    // checks : errno : == ERANGE
    if (errno == ERANGE) {
        fprintf(
            stderr,

            "ratatoi : error : long overflow/underflow on '%s' (aborting).\n",

            aString
        );

        /*** * * ***/

        abort();
    }

    // checks : errno : != 0
    if (errno != 0) {
        fprintf(
            stderr,

            "ratatoi: errno %d (%s) on '%s' (aborting).\n",

            errno,
            strerror(errno),
            aString
        );

        /*** * * ***/

        abort();
    }

    /*** * * ***/

    if (aLong < INT_MIN || aLong > INT_MAX) {
        fprintf(
            stderr,

            "ratatoi : error : int overflow/underflow on '%s' (aborting).\n",

            aString
        );

        /*** * * ***/

        abort();
    }

    /*** * * ***/

    aInt = (int)aLong;

    /*** * * ***/

    return aInt;
}
