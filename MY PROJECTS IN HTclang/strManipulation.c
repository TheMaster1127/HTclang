#include <stdint.h>
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
    int len = strlen(string);
    for (size_t A_Index3 = 0; A_Index3 < len + 0; A_Index3++) {
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
    for (size_t A_Index8 = 0; A_Index8 < len - lenWhat + 1 + 0; A_Index8++) {
        if (strncmp(&string[A_Index8], what, lenWhat) == 0) {
            return A_Index8 + 1;
        }
    }
}
char *SubStr(char *string, size_t num1, size_t num2) {
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
char *StrReplace(char *string, char *find, char *replace) {
    size_t len = strlen(string);
    size_t lenFind = strlen(find);
    size_t lenReplace = strlen(replace);
    size_t count = 0;
    for (size_t A_Index9 = 0; A_Index9 < len - lenFind + 1 + 0; A_Index9++) {
        if (strncmp(&string[A_Index9], find, lenFind) == 0) {
            count++;
        }
    }
    //printf("%d`n", count)
    size_t outLen = len + count * (lenReplace - lenFind);
    char *out = malloc(outLen + 1);
    size_t doWeAppend = 0;
    size_t diff = 0;
    for (size_t A_Index10 = 0; A_Index10 < outLen + 0; A_Index10++) {
        if ((A_Index10 + diff) < len && strncmp(&string[A_Index10 + diff], find, lenFind) == 0 && doWeAppend == 0) {
            doWeAppend = lenReplace;
        }
        if (doWeAppend > 0) {
            out[A_Index10] = replace[lenReplace - doWeAppend];
            doWeAppend--;
            if (doWeAppend == 0) {
                diff += lenFind - lenReplace;
            }
        } else {
            out[A_Index10] = string[A_Index10 + diff];
        }
    }
    out[outLen] = (char)0;
    return out;
}

int is_word_boundary_char(char c) {
    return c == '\0' || !(isalnum((unsigned char)c) || c == '_');
}
char* StrReplaceBoundaries(const char* input, const char* target, const char* replacement) {
    // 1. Validate input parameters
    if (input == NULL) {
        // fprintf(stderr, "Error: input string is NULL.\n");
        return NULL;
    }
    if (target == NULL) {
        // fprintf(stderr, "Error: target string is NULL.\n");
        // Alternatively, could strdup(input) if NULL target means "find nothing".
        // For strictness, treating as an error.
        return NULL;
    }
    if (replacement == NULL) {
        // fprintf(stderr, "Error: replacement string is NULL.\n");
        return NULL;
    }
    size_t in_len = strlen(input);
    size_t target_len = strlen(target);
    size_t repl_len = strlen(replacement);
    // 2. Handle empty target string: usually means "do nothing" or "insert everywhere".
    // Common behavior for "find and replace" with empty find is to return original.
    if (target_len == 0) {
        char* copy = strdup(input); // strdup allocates memory
        // if (copy == NULL) { perror("strdup failed for empty target case"); }
        return copy; // Returns NULL if strdup fails
    }
    // 3. Initial allocation for output string
    // Start with enough for the original string; realloc will grow if needed.
    size_t out_cap = in_len + 1; // +1 for null terminator
    char* output = malloc(out_cap);
    if (output == NULL) {
        // perror("Initial malloc failed for output string");
        return NULL;
    }
    size_t out_len = 0;
    // 4. Iterate through the input string
    for (size_t i = 0; i < in_len;) {
        // Check for a match at word boundaries
        // Condition: (left_boundary) AND (target fits AND matches) AND (right_boundary)
        if (
            (i == 0 || is_word_boundary_char(input[i - 1])) && // Left boundary
            (i + target_len <= in_len) && // Ensure target can fit within remaining input
            strncmp(&input[i], target, target_len) == 0 &&       // Target matches
            is_word_boundary_char(input[i + target_len])    // Right boundary
                                                                 // (input[in_len] is '\0', handled by is_word_boundary_char)
        ) {
            // --- Match found: append replacement ---
            // Calculate space needed for the replacement
            // Check for overflow: out_len + repl_len
            if (out_len > SIZE_MAX - repl_len) {
                free(output); return NULL; // Overflow in calculating new length
            }
            size_t needed_content_len = out_len + repl_len;
            // Check for overflow: needed_content_len + 1 (for null terminator)
            if (needed_content_len > SIZE_MAX - 1) {
                free(output); return NULL; // Overflow for buffer size
            }
            size_t required_buffer_size = needed_content_len + 1;
            // Reallocate if current capacity is insufficient
            if (required_buffer_size > out_cap) {
                size_t new_cap = out_cap;
                // Double capacity until sufficient, with overflow checks
                while (new_cap < required_buffer_size) {
                    if (new_cap > SIZE_MAX / 2) { // Check before doubling
                        new_cap = SIZE_MAX; // Try to allocate max possible
                        break;
                    }
                    new_cap *= 2;
                }
                // If doubling still wasn't enough (e.g. new_cap hit SIZE_MAX but still too small)
                if (new_cap < required_buffer_size) {
                    free(output); return NULL; // Cannot allocate enough
                }
                char* temp = realloc(output, new_cap);
                if (temp == NULL) {
                    free(output); // Original output is still valid but unneeded
                    return NULL;  // Realloc failed
                }
                output = temp;
                out_cap = new_cap;
            }
            if (repl_len > 0) { // memcpy with 0 length is a no-op but explicit check is fine
                memcpy(&output[out_len], replacement, repl_len);
            }
            out_len += repl_len;
            i += target_len; // Move past the matched target in input
        } else {
            // --- No match: copy one character from input ---
            // Calculate space needed for one more character
            // Check for overflow: out_len + 1
            if (out_len > SIZE_MAX - 1) {
                free(output); return NULL; // Overflow in calculating new length
            }
            size_t needed_content_len = out_len + 1;
            // Check for overflow: needed_content_len + 1 (for null terminator)
            if (needed_content_len > SIZE_MAX - 1) {
                free(output); return NULL; // Overflow for buffer size
            }
            size_t required_buffer_size = needed_content_len + 1;
            // Reallocate if current capacity is insufficient
            if (required_buffer_size > out_cap) {
                size_t new_cap = out_cap;
                while (new_cap < required_buffer_size) {
                    if (new_cap > SIZE_MAX / 2) {
                        new_cap = SIZE_MAX;
                        break;
                    }
                    new_cap *= 2;
                }
                if (new_cap < required_buffer_size) {
                    free(output); return NULL;
                }
                char* temp = realloc(output, new_cap);
                if (temp == NULL) {
                    free(output);
                    return NULL;
                }
                output = temp;
                out_cap = new_cap;
            }
            
            // The loop condition `i < in_len` ensures input[i] is valid.
            output[out_len++] = input[i++];
        }
    }
    // 5. Null-terminate the output string
    // Capacity for this was ensured by `required_buffer_size = ... + 1`
    output[out_len] = '\0';
    // Optional: Trim excess capacity. Can sometimes fail.
    // If it fails, the slightly larger buffer is still valid.
    // char* trimmed_output = realloc(output, out_len + 1);
    // if (trimmed_output != NULL) {
    //     output = trimmed_output;
    // } // Else, use the existing output buffer
    return output;
}
char **arrSplit(char *string, char del, size_t countARR) {
    size_t totalLen = strlen(string);
    size_t totalMem = countARR * sizeof(char *) + totalLen + 1;
    char *block = malloc(totalMem);
    char **ARR = (char **)block;
    char *strData = (char *)(block + countARR * sizeof(char *));
    size_t strIndex = 0;
    size_t writePos = 0;
    for (size_t A_Index11 = 0; A_Index11 < countARR + 0; A_Index11++) {
        size_t start = strIndex;
        size_t len = 0;
        // Find length of next substring
        while (string[strIndex] != 0 && string[strIndex] != del) {
            strIndex++;
            len++;
        }
        // Store pointer to current write position
        ARR[A_Index11] = strData + writePos;
        // Copy characters into result
        for (size_t A_Index12 = 0; A_Index12 < len + 0; A_Index12++) {
            strData[writePos] = string[start + A_Index12];
            writePos++;
        }
        // Null-terminate
        strData[writePos] = 0;
        writePos++;
        // Skip delimiter
        if (string[strIndex] == del) {
            strIndex++;
        }
    }
    return ARR;
}
char **resize(char **myArr, size_t *capacity) {
    size_t newCapacity = (*capacity) * 2;
    char **newArr = realloc(myArr, newCapacity * sizeof(char *));
    if (!newArr) {
        perror("realloc failed");
        // Don't return old pointer if realloc fails
        return NULL;
    }
    // Update capacity if realloc succeeded
    *capacity = newCapacity;
    return newArr;
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
    printf("%s\n", StrReplace("hello man whats up man", "man", "bro"));
    printf("%s\n", StrReplace("hello man whats up man", "man", "br"));
    printf("%s\n", StrReplace("hello man whats up man", "man", "br0o"));
    printf("%s\n", StrReplaceBoundaries("var", "var", "replaced"));
    printf("%s\n", StrReplaceBoundaries("var foo", "var", "replaced"));
    printf("%s\n", StrReplaceBoundaries("foo var", "var", "replaced"));
    printf("%s\n", StrReplaceBoundaries("foo var bar", "var", "replaced"));
    printf("%s\n", StrReplaceBoundaries("foobar", "var", "replaced"));
    printf("%s\n", StrReplaceBoundaries("my_var", "var", "replaced"));
    printf("%s\n", StrReplaceBoundaries("var123", "var", "replaced"));
    printf("%s\n", StrReplaceBoundaries("123 var_abc 456", "var", "replaced"));
    printf("%s\n", StrReplaceBoundaries("_var_", "var", "replaced"));
    printf("%s\n", StrReplaceBoundaries("var,var.var;var", "var", "replaced"));
    printf("%s\n", StrReplaceBoundaries("(var)", "var", "replaced"));
    printf("%s\n", StrReplaceBoundaries("func(var)", "var", "replaced"));
    printf("%s\n", StrReplaceBoundaries("(var+var)", "var", "replaced"));
    printf("%s\n", StrReplaceBoundaries("var()", "var", "replaced"));
    printf("%s\n", StrReplaceBoundaries("(123)var(456)", "var", "replaced"));
    printf("%s\n", StrReplaceBoundaries("func(var1, var2)", "var1", "R1"));
    printf("%s\n", StrReplaceBoundaries("func(var1, var2)", "var2", "R2"));
    printf("%s\n", StrReplaceBoundaries("var;var.var,var(var)", "var", "R"));
    printf("%s\n", StrReplaceBoundaries("var(var(var))", "var", "R"));
    printf("%s\n", StrReplaceBoundaries("((var))", "var", "replaced"));
    char var1[] = "hello man whats up";
    // add +1 since there are 3 spaces but 4 words — that makes sense.
    size_t loopLen = countChars(var1, ' ') + 1;
    // we need to pass the len
    char **arr = arrSplit(var1, ' ', loopLen);
    // back to normal
    printf("|%s|\n", var1);
    printf("%d\n", loopLen);
    for (size_t A_Index13 = 0; A_Index13 < loopLen + 0; A_Index13++) {
        printf("%s\n", arr[A_Index13]);
        printf("%d\n", A_Index13);
    }
    // back to normal
    printf("|%s|\n", var1);
    free(arr);
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
    //;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    //;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    //;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    //;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    char *var11 = strdup("hello man whats up");
    if (!var11) {
        perror("malloc failed");
        return -1;
    }
    // equivalent to StringTrimLeft
    memmove(var11, &var11[6], strlen(&var11[6]) + 1);
    // equivalent to StringTrimRight
    var11[strlen(var11) - 3] = 0;
    // will have "man whats"
    printf("|%s|\n", var11);
    free(var11);
    //;;;;;;;;;;;;;;;;;;;;;;;;;;; try resize
    size_t arr1_s = 5;
    size_t arr1_i = 0;
    char **arr1 = malloc(arr1_s * sizeof(char *));
    arr1[arr1_i++] = strdup("hello");
    arr1[arr1_i++] = strdup("man");
    arr1[arr1_i++] = strdup("whats");
    arr1[arr1_i++] = strdup("up");
    arr1 = resize(arr1, &arr1_s);
    arr1[arr1_i++] = strdup("hello");
    arr1[arr1_i++] = strdup("man");
    arr1[arr1_i++] = strdup("whats");
    arr1[arr1_i++] = strdup("up");
    for (size_t A_Index14 = 0; A_Index14 < arr1_i + 0; A_Index14++) {
        printf("%s\n", arr1[A_Index14]);
    }
    // free arr1
    for (size_t A_Index15 = 0; A_Index15 < arr1_i + 0; A_Index15++) {
        free(arr1[A_Index15]);
    }
    free(arr1);
    //;;;;;;;;;;;;;;;;;;;;;;
    char *var12 = strdup("hello\nman\n\n\nwhats\nup");
    // add +1 since there are 3 spaces but 4 words — that makes sense.
    size_t loopLen2 = countChars(var12, (char)10) + 1;
    // we need to pass len
    char **arr2 = arrSplit(var12, (char)10, loopLen2);
    // back to normal
    printf("|%s|\n", var12);
    printf("%zu\n", loopLen2);
    printf("--------------------------------------\n");
    for (size_t A_Index16 = 0; A_Index16 < loopLen2 + 0; A_Index16++) {
        printf("||||||%d||||||\n", strlen(arr2[A_Index16]));
        if (strlen(arr2[A_Index16]) > 0) {
            printf("%zu %s\n", A_Index16, arr2[A_Index16]);
        }
    }
    // back to normal
    printf("|%s|\n", var12);
    free(var12);
    free(arr2);
    return 0;
}
