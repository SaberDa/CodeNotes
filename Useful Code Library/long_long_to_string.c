#include <stdio.h>

int ll2str(char *s, long long value) {
    char *p;
    char aux;
    unsigned long long v;
    size_t l;

    // Generate the string representation, this method
    // produces an reversed string
    v = (value < 0) ? -value : value;
    p = s;
    do {
        *p++ = '0' + (v % 10);
        v /= 10;
    } while (v);
    if (value < 0) {
        *p++ = '-';
    }

    // Compute the length and add null term
    l = p - s;
    *p = '\0';

    // reverse the string
    p--;
    while (s < p) {
        aux = *s;
        *s = *p;
        *p = aux;
        s++;
        p--;
    }
    return l;
}

int ullstr(char *s ,unsigned long long v) {
    char *p;
    char aux;
    size_t l;

    p = s;
    do {
        *p++ = '0' + (v % 10);
        v /= 10;
    } while (v);
    
    l = p -s;
    *p++ = '\0';

    p--;
    while (s < p) {
        aux = *s;
        *s = *p;
        *p = aux;
        s++;
        p--;
    }
    return l;
}