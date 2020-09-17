#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *GetString();
char *StringCleanup(char *StringPtr);

int main(){
    char* String = GetString();
    printf ("%s", StringCleanup(String));
    free(String);
    return 0;
}

char *GetString()
{
    char *FullString = calloc(0,sizeof(char));
    int LastChar;
    for (int i = 0, CurrentChar; (CurrentChar = getchar()) != EOF;i++)
    {
        FullString = realloc(FullString,sizeof(char)* i + 1);
        FullString[i] = CurrentChar;
        LastChar = i + 1;
    }
    FullString = realloc(FullString,sizeof(char)* LastChar + 1);
    FullString[LastChar]= '\0';
    return FullString;
}

char *StringCleanup(char *StringPtr)
{
    char NewString[strlen(StringPtr)];
    int Tracker = 0, Spaces = 0, NewLength = 0;
    while (StringPtr[Tracker] != '\0')
    {
        if (StringPtr[Tracker] == ' ' || StringPtr[Tracker] == '\t')
        {
            Spaces++;
        }
        else
        {
            if (Spaces > 0 && StringPtr[Tracker] != '\n')
            {   
                for (int i = Tracker - Spaces; i < Tracker; i++)
                {
                    NewString[NewLength] = StringPtr[i];
                    NewLength++;
                }
            }   
            Spaces = 0;
            NewString[NewLength] = StringPtr[Tracker];
            NewLength++;
        }
        Tracker++;
    }
    strncpy(StringPtr,NewString,strlen(NewString));
    return StringPtr;
}
