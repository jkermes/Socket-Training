#include <stdlib.h>
#include <string.h>
#include "utils.h"

char * lowerCase(char *buffer)
{
    int i = 0;
    
    do {        
        if ('A' <= buffer[i] && 'z' >= buffer[i]) {
            if ('a' > buffer[i]) {
                buffer[i] = buffer[i] + 'a' - 'A';
            }
        }
        
        i++;
    } while ('\0' != buffer[i]);
    
    return buffer;
}

int countVowel(char *buffer)
{    
    int i = 0, j, count = 0;
    int vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    
    buffer = lowerCase(buffer);
    
    do {        
        for (j = 0; j < sizeof(vowels) / sizeof(int); j++) {
            if (buffer[i] == (int) vowels[j]) {
                count++;                
            }
        }
        
        i++;
    } while ('\0' != buffer[i]);
    
    return count;
}

int countConsonants(char *buffer)
{    
    int i = 0, j, count = 0;
    int consonants[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
    
    buffer = lowerCase(buffer);
    
    do {        
        for (j = 0; j < sizeof(consonants) / sizeof(int); j++) {
            if (buffer[i] == (int) consonants[j]) {
                count++;                
            }
        }
        
        i++;
    } while ('\0' != buffer[i]);
    
    return count;
}
