#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *StrSplit(char *string, char delimiter, int count) {
    int currentCount = 0;
    char *start = string;
    size_t len = strlen(string);
    size_t substring_len0 = 0;
    for (size_t A_Index1 = 0; A_Index1 < len + 0; A_Index1++) {
        if (string[A_Index1] == delimiter) {
            currentCount++;
            if (currentCount == count - 1) {
                substring_len0 = A_Index1 + 1;
                start = &string[A_Index1 + 1];
                break;
            }
        }
    }
    size_t substring_len = 0;
    for (size_t A_Index2 = 0; A_Index2 < len + 0; A_Index2++) {
        if (start[A_Index2] == delimiter) {
            substring_len = A_Index2;
            start[A_Index2] = (char)0;
            break;
        }
    }
    char *out = malloc(substring_len + 1);
    if (!out) {
        return NULL;
    }
    strncpy(out, start, substring_len);
    out[substring_len] = (char)0;
    string[substring_len0 + substring_len] = delimiter;
    return out;
}
int countChars(char *string, char delimiter) {
    int count = 0;
    for (size_t A_Index3 = 0; A_Index3 < strlen(string) + 0; A_Index3++) {
        if (string[A_Index3] == delimiter) {
            count++;
        }
    }
    return count;
}
char *StringTrimLeft(char *string, int count) {
    char *line = string;
    line = &string[count];
    char *out = malloc(strlen(string) + 1);
    if (!out) {
        perror("malloc failed");
        return NULL;
    }
    strcpy(out, line);
    return out;
}
char *StringTrimRight(char *string, int count) {
    size_t lenToTrim = strlen(string) - count;
    char *out = malloc(lenToTrim + 1);
    if (!out) {
        perror("malloc failed");
        return NULL;
    }
    strcpy(out, string);
    out[lenToTrim] = (char)0;
    return out;
}
char *StrLower(char *string) {
    size_t len = strlen(string);
    char *out = malloc(len + 1);
    if (!out) {
        perror("malloc failed");
        return NULL;
    }
    for (size_t A_Index4 = 0; A_Index4 < len + 0; A_Index4++) {
        out[A_Index4] = tolower(string[A_Index4]);
    }
    out[len] = (char)0;
    return out;
}
char *StrTitleCase(char *string) {
    size_t len = strlen(string);
    char *out = malloc(len + 1);
    if (!out) {
        perror("malloc failed");
        return NULL;
    }
    for (size_t A_Index5 = 0; A_Index5 < len + 0; A_Index5++) {
        if (A_Index5 == 0) {
            out[A_Index5] = toupper(string[A_Index5]);
        } else {
            if (string[A_Index5 - 1] == ' ') {
                out[A_Index5] = toupper(string[A_Index5]);
            } else {
                out[A_Index5] = tolower(string[A_Index5]);
            }
        }
    }
    out[len] = (char)0;
    return out;
}
char *Trim(char *string) {
    size_t len = strlen(string);
    char *start = string;
    size_t substring_len0 = 0;
    size_t substring_len = 0;
    int beenHere = 0;
    for (size_t A_Index6 = 0; A_Index6 < len + 0; A_Index6++) {
        if (string[A_Index6] != (char)32 && string[A_Index6] != (char)9 && string[A_Index6] != (char)10 && string[A_Index6] != (char)13 && string[A_Index6] != (char)11 && beenHere == 0) {
            beenHere = 1;
            substring_len0 = A_Index6;
            start = &string[A_Index6];
        }
    }
    //;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    beenHere = 0;
    size_t last = 0;
    size_t REALlast = 0;
    char strTemp = 0;
    for (size_t A_Index7 = 0; A_Index7 < len + 0; A_Index7++) {
        last = len - 1 - A_Index7;
        if (string[last] != (char)32 && string[last] != (char)9 && string[last] != (char)10 && string[last] != (char)13 && string[last] != (char)11 && beenHere == 0) {
            beenHere = 1;
            substring_len = last;
            strTemp = start[last];
            start[last] = (char)0;
            REALlast = last;
        }
    }
    char *out = malloc((substring_len - substring_len0) + 1);
    if (!out) {
        return NULL;
    }
    strncpy(out, start, substring_len - substring_len0);
    out[substring_len - substring_len0] = (char)0;
    string[REALlast] = strTemp;
    return out;
}
size_t InStr(char *string, char *what) {
    size_t len = strlen(string);
    size_t lenWhat = strlen(what);
    if (lenWhat == 0 || len < lenWhat) {
        return 0;
    }
    for (size_t A_Index8 = 0; A_Index8 < len - lenWhat + 0; A_Index8++) {
        if (strncmp(&string[A_Index8], what, lenWhat) == 0) {
            return A_Index8 + 1;
        }
    }
}
char *SubStr(char *string, int num1, int num2) {
    if (!string || num1 < 1 || num2 < 0) {
        return NULL;
    }
    size_t len = strlen(string);
    if ((size_t)num1 > len) {
        return NULL;
    }
    // make it 1 indexed
    num1--;
    char *line = string;
    line = &string[num1];
    char *out = malloc(num2 + 1);
    if (!out) {
        perror("malloc failed");
        return NULL;
    }
    strncpy(out, line, num2);
    out[num2] = (char)0;
    return out;
}
int main(int argc, char* argv[]) {
    //;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    char *myStr = malloc(30);
    strcpy(myStr, "HeLLo MaN whats UP");
    char *myStr2 = malloc(50);
    strcpy(myStr2, "    - hadsfouSDbkhjdsfdwaesdf");
    char *myStr3 = malloc(61);
    strcpy(myStr3, "     hadsfouSDbkhjdsfdwaesdf      ");
    printf("%d\n", countChars(myStr, ' '));
    char *res = StrSplit(myStr, ' ', 2);
    char *res2 = StringTrimLeft(myStr, 2);
    char *res3 = StringTrimRight(myStr, 4);
    char *res4 = StrLower(myStr);
    char *res5 = StrTitleCase(myStr);
    char *res6 = Trim(myStr2);
    char *res7 = Trim(myStr3);
    printf("%s\n", res);
    printf("%s\n", res2);
    printf("%s\n", res3);
    printf("%s\n", res4);
    printf("%s\n", res5);
    printf("%s\n", res6);
    printf("%s\n", res7);
    printf("%s\n", myStr);
    printf("%s\n", myStr2);
    printf("%s\n", myStr3);
    printf("%zu\n", InStr("hello man whats up", "man"));
    printf("%s\n", SubStr("hello man whats up", 1, 4));
    free(myStr);
    free(myStr2);
    free(myStr3);
    free(res);
    free(res2);
    free(res3);
    free(res4);
    free(res5);
    free(res6);
    free(res7);
    return 0;
}
