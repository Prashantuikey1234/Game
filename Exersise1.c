#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *replaceword(const char *str, const char *oldword, const char *newWord)
{
    char *resultstring;
    int i, count = 0;
    int newWordLength = strlen(newWord);
    int oldwordLength = strlen(oldword);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (strstr(&str[i], oldword) == &str[i])
        {
            count++;
        }
    }
    resultstring = (char *)malloc(i + count * (newWordLength - oldwordLength) + 1);
    i = 0;
    while (*str)
    {
        if (strstr(str, oldword) == str)
        {
            strcpy(&resultstring[i], newWord);
            i += newWordLength;
            str += oldwordLength;
        }
        else
        {
            resultstring[i] = *str;
            i += 1;
            str += 1;
        }
    }
    resultstring[i] = '\0';
    return resultstring;
}
void main()
{
    FILE *ptr = NULL;
    FILE *ptr2 = NULL;
    ptr2 = fopen("genBill.txt", "w");
    ptr = fopen("bill.txt", "r");
    char str[200];
    fgets(str, 200, ptr);
    printf("The given bill template was: %s\n", str);
    char *newstr;
    newstr = replaceword(newstr, "{{item}}", "table fan");
    newstr = replaceword(newstr, "{{outlet}}", "Ram Lakshmi fan outlet");
    newstr = replaceword(newstr, "{{name}}", "Harry");
    printf("The actual bill generated is: %s\n", newstr);
    fprintf(ptr2, "%s", newstr);
    fclose(ptr);
    fclose(ptr2);
}