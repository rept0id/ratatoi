#include <stdlib.h>
#include <stdio.h>

#include <errno.h>

#include <limits.h>

#include <string.h>

#include "ratatoi.h"

/*** * * ***/

int ratatoi(const char *a) {
    errno = 0;

    char *strtolEndptr;

    long aLong;
    int aInt;

    /*** * * ***/

    aLong = strtol(a, &strtolEndptr, 10);

    /*** * * ***/

    // checks

    // checks : no digits parsed
    if (strtolEndptr == a) {
        fprintf(
            stderr,

            "badatoi : error : couldn't parse '%s' (aborting).\n",

            a
        );

        /*** * * ***/

        abort();
    }

    // checks : not all digits parsed
    if (*strtolEndptr != '\0') {
        fprintf(
            stderr,

            "badatoi : error : couldn't parse all of '%s', garbage : '%s' (aborting).\n",

            a,
            strtolEndptr
        );

        /*** * * ***/

        abort();
    }

    // checks : errno : == ERANGE
    if (errno == ERANGE) {
        fprintf(
            stderr,

            "badatoi : error : long overflow/underflow on '%s' (aborting).\n",

            a
        );

        /*** * * ***/

        abort();
    }

    // checks : errno : != 0
    if (errno != 0) {
        fprintf(
            stderr,

            "badatoi: errno %d (%s) on '%s' (aborting).\n",

            errno,
            strerror(errno),
            a
        );

        /*** * * ***/

        abort();
    }

    /*** * * ***/

    if (aLong < INT_MIN || aLong > INT_MAX) {
        fprintf(
            stderr,

            "badatoi : error : int overflow/underflow on '%s' (aborting).\n",

            a
        );

        /*** * * ***/

        abort();
    }

    /*** * * ***/

    aInt = (int)aLong;

    /*** * * ***/

    return aInt;
}
