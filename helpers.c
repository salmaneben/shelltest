#include "shell.h"

/**
 * _strlen - Calculate the length of a string.
 * @s: The string.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *s)
{
    size_t len = 0;
    while (s[len])
        len++;
    return len;
}

/**
 * _strcmp - Compare two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

/**
 * _strdup - Duplicate a string.
 * @s: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL on failure.
 */
char *_strdup(const char *s)
{
    char *dup;
    size_t len = _strlen(s) + 1;

    dup = malloc(len);
    if (dup == NULL)
        return NULL;

    memcpy(dup, s, len);
    return dup;
}

/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the destination string.
 */
char *_strcat(char *dest, const char *src)
{
    char *temp = dest;

    while (*temp)
        temp++;
    while (*src)
    {
        *temp = *src;
        temp++;
        src++;
    }
    *temp = '\0';

    return dest;
}

