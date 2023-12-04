#include <stdio.h>
#include <string.h>
#include <ctype.h>

int arrLength;
int k = 2;

int main()
{
    FILE  *pInput = fopen("input 1.txt", "r");
    FILE  *pOutput = fopen("output.txt", "w");

    FILE  *pOutput2 = fopen("input 2.txt", "r");
    FILE  *pOutput3 = fopen("output2.txt", "w");

    char Cipher[255];
    char DeCipher[255];
    int select;
    
    printf("Cipher(1),DeCipher(2)");
    scanf("%d",&select);



    if(select == 1)
    {
        while(fgets(Cipher, 255, pInput) != NULL )
        {

            int arrLength = strlen(Cipher);

            for(int i=0;i<arrLength;i++)
            {
                if(isalpha(Cipher[i]))
                {
                    Cipher[i] = tolower(Cipher[i]);
                    Cipher[i] -= 'a';
                    Cipher[i] += k;
                    Cipher[i] %= 26;
                    Cipher[i] += 'a';
                }
                else
                {
                    Cipher[i] = Cipher[i];
                }
            }
            fputs(Cipher,pOutput);
        }
        printf("Sifreleme Tamamlandi");
    }
    else if(select == 2)
    {
        while(fgets(DeCipher, 255, pOutput2) != NULL )
        {

            int arrLength = strlen(DeCipher);

            for(int i=0;i<arrLength;i++)
            {
                if(isalpha(DeCipher[i]))
                {
                    DeCipher[i] = tolower(DeCipher[i]);
                    DeCipher[i] -= 'a';
                    DeCipher[i] -= k;
                    DeCipher[i] %= 26;
                    DeCipher[i] += 'a';
                }
                else
                {
                    DeCipher[i] = DeCipher[i];
                }
            }
            fputs(DeCipher,pOutput3);
        }
        printf("Sifre Cozme Tamamlandi");
    }
    else
    {
        printf("Enter a Valid Number!");
    }
    
    fclose(pOutput);
    fclose(pInput);
    fclose(pOutput2);
    fclose(pOutput3);
    
    return 0;
}