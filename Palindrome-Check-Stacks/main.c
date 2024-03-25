#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{

} stack;

int isPalindrome(char *str) {  
    struct stack s;  
    initialize(&s);  
    int len = strlen(str); 
    
    if (isEmpty(s) == 1)
        return 0;
    else
    {
        int i = 0;

        for (i; i < len/2; i++)
        {
            push(&s, *(str+i));
        }

        if (len % 2 == 0)
        {
            for (i; i < len; i++)   
            {
                if (pop(&s) != *(str+i))
                    return 0;  
            }
        }
        else
        {
            i++;

            for (i; i < len; i++)   
            {
                if (pop(&s) != *(str+i))
                    return 0;  
            }
        }
    } 

    return 1;
}      


