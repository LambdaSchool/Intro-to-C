// #include <stdio.h>
// int main(void) {
//     //! showArray(word, cursors[i])
//     char word[51]; //arrray of characters (string)
//     printf("Please enter a word with 50 letters: ");
//     scanf("%s", word);
//     printf("The word read is: %s.\n", word);
//     printf("The characters are: <%c> <%c> <%c> <%c>\n", word[0], word[1], word[2], word[3]);
//     word[1] = 'a';
//     printf("The new word is %s\n", word);
//     return 0;
// }

// Your program should first read the total number of names (an integer) in order to know how many index cards need to be processed altogether. Next,  for each index card, your program should read a patron's first name and last name and then display these names correctly, that is on one line, the last name followed by one space, followed by the first name.  Your program should print the reversed name immediately after reading the patron's names (ie, it should not wait until it has read all of the index cards to begin printing).
#include <stdio.h>
int main(void)
{
    int num, i;
    char first[101], last[101];
    scanf("%d", &num);
    for (i = 0; i < num; i++)
    {
        scanf("%s", &first);
        scanf("%s", &last);
        printf("%s %s\n", last, first);
    }
    return 0;
}

// Find the length of a string
#include <stdio.h>
int main(void)
{
    //! showArray(word, cursors=[i])
    char word[30];
    int i = 0;
    printf("Please enter a word: ");
    scanf("%s", word);
    while (word[i] != '\0')
        i++;
    printf("%s has word length %d.\n", word, i);
    return 0;
}

// even or odd number of letters in a word
// student names are less than 50 characters long and contain no spaces. Your program should output an integer value (1 or 2) depending on whether the fan should join line 1 (name has even number of letters) or line 2 (name has odd number of letters).
#include <stdio.h>
int main(void)
{
    int i = 0;
    char first[50];
    scanf("%s", &first);
    while (first[i] != '\0')
    {
        i++;
    }
    if (i % 2 == 0)
    {
        printf("%d", 1);
    }
    else
    {
        printf("%d", 2);
    }
    return 0;
}
// int main(void) {
//     char name[51];
//     int i=0;

//     scanf("%s", name);
//     while(name[i] != '\0')
//         i++;

//     if (i%2 == 0)
//         printf("1");
//     else
//         printf("2");

//     return 0;
// }