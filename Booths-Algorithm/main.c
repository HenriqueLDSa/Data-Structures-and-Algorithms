#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int binaryToDecimal(char *binary) 
{
    if(binary == NULL)
        return -0;

    int result = 0;

    for(int i = strlen(binary)-1; i >= 0; i--)
    {
        if(binary[i] == '1')
            result += pow(2, i);
    }

    return result;
}

char *decimalToBinary(int input) 
{
    int decimal = input;
    char *buffer;
    int length = 0;

    for(int i = 0; decimal != 0; i++)
    {
        decimal /= 2;
        length++;
    }

    decimal = input;
    buffer = malloc(sizeof(char) * (length + 1));

    for(int i = 0; decimal != 0; i++)
    {
        if(decimal % 2 == 0)
        {
            decimal /= 2;
            buffer[i] = '0';
        }
        else if(decimal % 2 == 1)
        {
            decimal /= 2;
            buffer[i] = '1';
        }
    }

    char *binary = malloc(sizeof(char) * (length));

    int j = 0;
    for(int i = length-1; i >= 0; i--)
    {
        binary[j] = buffer[i];
        j++;
    }

    binary[length] = '\0';

    free(buffer);

    return binary;
}

char *take2sComplement(char *input) 
{
    if(input == NULL)
        return NULL;

    int carry = 1;
    char *twosComplement = malloc(sizeof(char) * (strlen(input) + 1));
    char *onesComplement = malloc(sizeof(char) * (strlen(input) + 1));

    for(int i = 0; i < strlen(input); i++)
    {
        if(input[i] == '0')
            onesComplement[i] = '1';
        
        if(input[i] == '1')
            onesComplement[i] = '0';
    }

    onesComplement[strlen(input)] = '\0';

    for(int i = strlen(input) - 1; i >= 0; i--)
    {
        if(onesComplement[i] == '1' && carry == 1)
        {
            twosComplement[i] = 0;
        }
        else if(onesComplement[i] == '0' && carry == 1)
        {
            twosComplement[i] = '1';
            carry = 0;
        }
        else
            twosComplement[i] = onesComplement[i];
    }

    free(onesComplement);

    twosComplement[strlen(twosComplement)] = '\0';

    return twosComplement;
}

void boothMultiply(char* n1, char* n2)
{
    printf("     Product     Q-1    M        M-1     Log\n");

    int n = strlen(n1);
    int bits = strlen(n1);
    int Q_1 = 0;
    char *M = malloc(bits + 1);
    char *M_1 = malloc(bits + 1);
    char *A = malloc(bits + 1);  
    char *product = malloc(bits*2 + 1);
    int carry = 0;

    strcpy(M, n1);    
    strcpy(M_1, take2sComplement(M));

    for(int i = 0; i < bits; i++)
        A[i] = '0';
    A[bits] = '\0';

    for(int i = 0; i < bits; i++) 
        product[i] = A[i];
    for(int i = sizeof(product)/2, j = 0; i < bits*2; i++, j++)
        product[i] = n1[j];
    product[bits] = '\0';
    
    printf("%s %d %s %s ", product, Q_1, M, M_1);
    printf("Populate Data\n");

    while(n != 0)
    {
        carry = 0;

        if((product[bits*2-1] == '0' && Q_1 == 0) || (product[bits*2-1] == '1' && Q_1 == 1))
        {
            for(int i = bits*2-1; i >= 0; i--) // Right Shift
            {
                if(i == 0)
                    product[i] = '0';
                else if(i == bits*2-1)
                {
                    if(product[bits*2-1] == '0')
                        Q_1 = 0;
                    else
                        Q_1 = 1;    
                }
                else
                    product[i] = product[i-1]; 
            }
            n--; // Decrementing n
            printf("%s %d %s %s ", product, Q_1, M, M_1);
            printf("Shift\n");
        }
        else if(product[bits*2-1] == '1' && Q_1 == 0)
        {
            for(int i = bits-1; i >= 0; i--) // A = A - M
            {
                if(A[i] == '0' && M_1[i] == '0')
                {
                    if (carry == 0)
                    {    
                        carry = 0;
                        A[i] = '0'; 
                    }
                    else if (carry == 1)
                    {    
                        carry = 0;
                        A[i] = '1'; 
                    }
                }
                else if(A[i] == '0' && M_1[i] == '1')
                {
                    if (carry == 0)
                    {    
                        carry = 0;
                        A[i] = '1'; 
                    }
                    else if (carry == 1)
                    {    
                        carry = 0;
                        A[i] = '0'; 
                    }
                }
                else if(A[i] == '1' && M_1[i] == '0')
                {
                    if (carry == 0)
                    {    
                        carry = 0;
                        A[i] = '1'; 
                    }
                    else if (carry == 1)
                    {    
                        carry = 0;
                        A[i] = '0'; 
                    }
                }
                else if(A[i] == '1' && M_1[i] == '1')
                {
                    if (carry == 0)
                    {    
                        carry = 0;
                        A[i] = '0'; 
                    }
                    else if (carry == 1)
                    {    
                        carry = 1;
                        A[i] = '0'; 
                    }
                }
            }

            for(int i = bits-1; i >= 0; i--)
                product[i] = A[i];

            printf("%s %d %s %s ", product, Q_1, M, M_1);
            printf("A = A - M\n");
            
            for(int i = bits*2-1; i >= 0; i--) // Right Shift
            {
                if(i == 0)
                    product[i] = '0';
                else if(i == bits*2-1)
                {
                    if(product[bits*2-1] == '0')
                        Q_1 = 0;
                    else
                        Q_1 = 1;    
                }
                else
                    product[i] = product[i-1]; 
            }
            
            printf("%s %d %s %s ", product, Q_1, M, M_1);
            printf("Shift\n");

            n--; // Decrementing n
        }
        else if(product[bits*2-1] == '0' && Q_1 == 1)
        {
            for(int i = bits-1; i >= 0; i--) // A = A + M
            {
                if(A[i] == '0' && M[i] == '0')
                {
                    if (carry == 0)
                    {    
                        carry = 0;
                        A[i] = '0'; 
                    }
                    else if (carry == 1)
                    {    
                        carry = 0;
                        A[i] = '1'; 
                    }
                }
                else if(A[i] == '0' && M[i] == '1')
                {
                    if (carry == 0)
                    {    
                        carry = 0;
                        A[i] = '1'; 
                    }
                    else if (carry == 1)
                    {    
                        carry = 0;
                        A[i] = '0'; 
                    }
                }
                else if(A[i] == '1' && M[i] == '0')
                {
                    if (carry == 0)
                    {    
                        carry = 0;
                        A[i] = '1'; 
                    }
                    else if (carry == 1)
                    {    
                        carry = 0;
                        A[i] = '0'; 
                    }
                }
                else if(A[i] == '1' && M[i] == '1')
                {
                    if (carry == 0)
                    {    
                        carry = 0;
                        A[i] = '0'; 
                    }
                    else if (carry == 1)
                    {    
                        carry = 1;
                        A[i] = '0'; 
                    }
                }
            }

            for(int i = bits-1; i >= 0; i--)
                product[i] = A[i];

            printf("%s %d %s %s ", product, Q_1, M, M_1);
            printf("A = A + M\n");

            for(int i = bits*2-1; i >= 0; i--) // Right Shift
            { 
                if(i == 0)
                    product[i] = '0';
                else if(i == bits*2-1)
                {
                    if(product[bits*2-1] == '0')
                        Q_1 = 0;
                    else
                        Q_1 = 1;    
                }
                else
                    product[i] = product[i-1]; 
            }
            
            printf("%s %d %s %s ", product, Q_1, M, M_1);
            printf("Shift\n");

            n--; // Decrementing n
        }
        else
            continue;
    }

    product = take2sComplement(product);

    printf("%s * %s = %s\n", n1, n2, product);
    printf("%d * %d = %d", binaryToDecimal(n1), binaryToDecimal(n2), binaryToDecimal(product));
        
    free(M);
    free(M_1);
    free(A);
    free(product);
}
 
void readMultiplicationOperation(FILE* pInfile, char** pN1, char** pN2)
{    
    int operations, bits;
    fscanf(pInfile, "%d", &operations);
    pN1 = (char**) malloc(sizeof(char*) * operations + 1);
    pN2 = (char**) malloc(sizeof(char*) * operations + 1);

    for(int i = 0; i < operations; i++)
    {   
        fscanf(pInfile, "%d", &bits);
        pN1[i] = (char*) malloc(sizeof(char) * bits);
        pN2[i] = (char*) malloc(sizeof(char) * bits);
        fscanf(pInfile, "%s", pN1[i]);
        fscanf(pInfile, "%s", pN2[i]);
        boothMultiply(pN1[i],pN2[i]);

        free(pN1[i]);
        free(pN2[i]);
    }
}

int main()
{
    printf("\n\n");
    FILE *pInfile = fopen("input.txt", "r");
    
    // char **pN1;  
    // char **pN2;

    // readMultiplicationOperation(pInfile, pN1, pN2);

    char pN1[] = "1001";
    char pN2[] = "0011";

    boothMultiply(pN1, pN2);

    fclose(pInfile);
    return 0;
}