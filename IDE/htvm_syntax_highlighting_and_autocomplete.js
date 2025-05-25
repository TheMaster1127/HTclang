// Define the custom "ht" language for Ace Editor with AHK rules
ace.define("ace/mode/ht", ["require", "exports", "module", "ace/lib/oop", "ace/mode/text", "ace/mode/text_highlight_rules"], function (require, exports, module) {
  var oop = require("ace/lib/oop");
  var TextMode = require("ace/mode/text").Mode;
  var TextHighlightRules = require("ace/mode/text_highlight_rules").TextHighlightRules;

  var HTHighlightRules = function () {
    this.$rules = {
      start: [
{ token: "comment", regex: ";.*$" },
              { token: "keywords", regex: "\\b(if|else if|else|struct|prop|crew|alliance|proc|while|Loop|Loop,|Loop, Parse,|continue|break|func|const|return)\\b" },
              { token: "command", regex: "\\b(StringTrimLeft|StringTrimRight|Random|Sleep|FileRead|FileAppend|FileDelete|Sort|MsgBox)(?=\\,)" },
              { token: "functions", regex: "\\b(printf|sizeof|malloc|realloc|LoopParseFunc|LoopParseFunc|print|print|print|STR|INT|FLOAT|STR|INT|FLOAT|INT|STR|FLOAT|InStr|Random|Sleep|input|FileRead|FileAppend|FileDelete|StrLen|Asc|Abs|ACos|ASin|ATan|Ceil|Cos|Exp|Ln|Log|Round|Sin|Sqrt|Tan|SubStr|Trim|StrReplace|StringTrimLeft|StringTrimRight|StrLower|StrSplit|Chr|Mod|Floor|Sort|getDataFromAPI|FileCreateDir|FileRemoveDir|FileExist|isWindows|GetParams|BuildInVars|RegExReplace|RunCMD|RegExMatch|ExitApp|InStr|InStr|Random|Random|Sleep|Sleep|input|input|FileAppendJs|FileDelete|FileAppend|FileRead|StrLen|StrLen|Chr|Chr|Asc|Abs|ACos|ASin|ATan|Ceil|Cos|Exp|Ln|Log|Round|Sin|Sqrt|Tan|Asc|Abs|ACos|ASin|ATan|Ceil|Cos|Exp|Ln|Log|Round|Sin|Sqrt|Tan|SubStr|SubStr|Trim|StrReplace|StringTrimLeft|StringTrimRight|StrLower|StrSplit|Mod|Floor|Trim|StrReplace|StringTrimLeft|StringTrimRight|StrLower|StrSplit|Mod|Floor|Sort|getDataFromAPI|FileCreateDir|FileRemoveDir|FileExist|isWindows|GetParams|BuildInVars|RegExReplace|RunCMD|RegExMatch|ExitApp|Sort|getDataFromAPI|getUrlParams|BuildInVars|RegExReplace|RegExMatch|MsgBox|Gui_Show|Gui_Update|Gui_Button|Gui_Edit|Gui_Text|Gui_Size|Gui_Font|Gui_Font_Id|Gui_Size_Id|GuiControl|Gui_DropDownList|Gui_Hide|Gui_Move|Gui_Color|Gui_Image|Gui_Toggle|Gui_CheckBox|MakeHotKey|sortArr|sortArr|sortArr|countChars|countChars|countChars|StrTitleCase|StrTitleCase|StrTitleCase|free|strcpy|strcat|strlen|freeLoop|isalnum|isalpha|isblank|iscntrl|isdigit|isgraph|islower|isprint|ispunct|isspace|isupper|isxdigit|tolower|toupper|clearerr|fclose|feof|ferror|fflush|fgetc|fgetpos|fgets|fopen|fprintf|fputc|fputs|fread|freopen|fscanf|fseek|fsetpos|ftell|fwrite|getc|getchar|gets|perror|printf|putc|putchar|puts|remove|rename|rewind|scanf|setbuf|setvbuf|snprintf|sprintf|sscanf|tmpfile|tmpnam|ungetc|vfprintf|vprintf|vsnprintf|vsprintf|abort|abs|atexit|atof|atoi|atol|atoll|bsearch|calloc|div|exit|free|getenv|labs|ldiv|llabs|lldiv|malloc|mblen|mbstowcs|mbtowc|qsort|rand|realloc|srand|strtod|strtol|strtoul|strtoll|strtoull|system|wcstombs|wctomb|memchr|memcmp|memcpy|memmove|memset|strcat|strchr|strcmp|strcoll|strcpy|strcspn|strerror|strlen|strncat|strncmp|strncpy|strpbrk|strrchr|strspn|strstr|strtok|strxfrm|StrReplaceBoundaries|strdup)(?=\\()" },
              { token: "BuildInFunc", regex: "\\b(A_Index|A_LoopField)\\b" },
              { token: "static_types", regex: "\\b(int|str|char|void|bool|float|int8|int16|int32|int64|size_t)\\b" },
              { token: "operators", regex: " && | or | and | && " },
              { token: "trueANDfalse", regex: "\\b(true|false|null)\\b" },
              { token: "variables", regex: "\\b[a-zA-Z_][a-zA-Z0-9_]*\\b" },
              { token: "constant.numeric", regex: "\\b[0-9]+\\b" },
              { token: "braces_Open", regex: "\\{" },
              { token: "braces_Close", regex: "\\}" },
              { token: "string", regex: '".*?"' },
              // Multi-line comments
              {
                token: "comment.block", // Token for multi-line comments
                regex: /'''1/, // Start of multi-line comment
                next: "comment_block",
              },
            ],
            comment_block: [
              {
                token: "comment.block",
                regex: /.*?'''2/, // End of multi-line comment
                next: "start", // Go back to the start state
              },
              {
                token: "comment.block",
                regex: /.*/, // Any other content within the comment
              },
            ],
          };
        };

  oop.inherits(HTHighlightRules, TextHighlightRules);

  var HTMode = function () {
    this.HighlightRules = HTHighlightRules;
  };
  oop.inherits(HTMode, TextMode);

  exports.Mode = HTMode;
});

let HTVM_Syntax_AutoComplete = [{ name: "if" }, { name: "else if" }, { name: "else" }, { name: "struct" }, { name: "prop" }, { name: "crew" }, { name: "alliance" }, { name: "proc" }, { name: "while" }, { name: "for" }, { name: "Loop" }, { name: "Loop," }, { name: "Loop, Parse," }, { name: "continue" }, { name: "break" }, { name: "func" }, { name: "const" }, { name: "return" }, { name: "end" }, { name: "StringTrimLeft" }, { name: "StringTrimRight" }, { name: "Random" }, { name: "Sleep" }, { name: "FileRead" }, { name: "FileAppend" }, { name: "FileDelete" }, { name: "Sort" }, { name: "MsgBox" }, { name: "LoopParseFunc" }, { name: "printf" }, { name: "malloc" }, { name: "realloc" }, { name: "STR" }, { name: "INT" }, { name: "FLOAT" }, { name: "free" }, { name: "INT" }, { name: "strcat" }, { name: "sizeof" }, { name: "strlen" }, { name: "strcpy" }, { name: "InStr" }, { name: "Random" }, { name: "Sleep" }, { name: "input" }, { name: "FileRead" }, { name: "FileAppend" }, { name: "FileDelete" }, { name: "StrLen" }, { name: "Asc" }, { name: "Abs" }, { name: "ACos" }, { name: "ASin" }, { name: "ATan" }, { name: "Ceil" }, { name: "Cos" }, { name: "Exp" }, { name: "Ln" }, { name: "Log" }, { name: "Round" }, { name: "Sin" }, { name: "Sqrt" }, { name: "Tan" }, { name: "SubStr" }, { name: "Trim" }, { name: "StrReplace" }, { name: "StringTrimLeft" }, { name: "StringTrimRight" }, { name: "StrLower" }, { name: "StrSplit" }, { name: "Mod" }, { name: "Floor" }, { name: "Sort" }, { name: "getDataFromAPI" }, { name: "FileCreateDir" }, { name: "FileRemoveDir" }, { name: "FileExist" }, { name: "isWindows" }, { name: "GetParams" }, { name: "BuildInVars" }, { name: "RegExReplace" }, { name: "RunCMD" }, { name: "RegExMatch" }, { name: "ExitApp" }, { name: "InStr" }, { name: "InStr" }, { name: "Random" }, { name: "Random" }, { name: "Sleep" }, { name: "Sleep" }, { name: "input" }, { name: "input" }, { name: "FileAppendJs" }, { name: "FileDelete" }, { name: "FileAppend" }, { name: "FileRead" }, { name: "StrLen" }, { name: "StrLen" }, { name: "Chr" }, { name: "Chr" }, { name: "Asc" }, { name: "Abs" }, { name: "ACos" }, { name: "ASin" }, { name: "ATan" }, { name: "Ceil" }, { name: "Cos" }, { name: "Exp" }, { name: "Ln" }, { name: "Log" }, { name: "Round" }, { name: "Sin" }, { name: "Sqrt" }, { name: "Tan" }, { name: "Asc" }, { name: "Abs" }, { name: "ACos" }, { name: "ASin" }, { name: "ATan" }, { name: "Ceil" }, { name: "Cos" }, { name: "Exp" }, { name: "Ln" }, { name: "Log" }, { name: "Round" }, { name: "Sin" }, { name: "Sqrt" }, { name: "Tan" }, { name: "SubStr" }, { name: "SubStr" }, { name: "Trim" }, { name: "StrReplace" }, { name: "StringTrimLeft" }, { name: "StringTrimRight" }, { name: "StrLower" }, { name: "StrSplit" }, { name: "Mod" }, { name: "Floor" }, { name: "Trim" }, { name: "StrReplace" }, { name: "StringTrimLeft" }, { name: "StringTrimRight" }, { name: "StrLower" }, { name: "StrSplit" }, { name: "Mod" }, { name: "Floor" }, { name: "Sort" }, { name: "freeLoop" }, { name: "FileCreateDir" }, { name: "FileRemoveDir" }, { name: "FileExist" }, { name: "isWindows" }, { name: "GetParams" }, { name: "BuildInVars" }, { name: "RegExReplace" }, { name: "RunCMD" }, { name: "RegExMatch" }, { name: "ExitApp" }, { name: "Sort" }, { name: "getDataFromAPI" }, { name: "getUrlParams" }, { name: "BuildInVars" }, { name: "RegExReplace" }, { name: "RegExMatch" }, { name: "sortArr" }, { name: "sortArr" }, { name: "sortArr" }, { name: "countChars" }, { name: "countChars" }, { name: "countChars" }, { name: "StrTitleCase" }, { name: "StrTitleCase" }, { name: "StrTitleCase" }, { name: "A_LoopField" }, { name: "A_Index" }, { name: "int" }, { name: "str" }, { name: "void" }, { name: "bool" }, { name: "float" }, { name: "int8" }, { name: "int16" }, { name: "int32" }, { name: "int64" }, { name: "size_t" }, { name: "isalnum" }, { name: "isalpha" }, { name: "isblank" }, { name: "iscntrl" }, { name: "isdigit" }, { name: "isgraph" }, { name: "islower" }, { name: "isprint" }, { name: "ispunct" }, { name: "isspace" }, { name: "isupper" }, { name: "isxdigit" }, { name: "tolower" }, { name: "toupper" }, { name: "clearerr" }, { name: "fclose" }, { name: "feof" }, { name: "ferror" }, { name: "fflush" }, { name: "fgetc" }, { name: "fgetpos" }, { name: "fgets" }, { name: "fopen" }, { name: "fprintf" }, { name: "fputc" }, { name: "fputs" }, { name: "fread" }, { name: "freopen" }, { name: "fscanf" }, { name: "fseek" }, { name: "fsetpos" }, { name: "ftell" }, { name: "fwrite" }, { name: "getc" }, { name: "getchar" }, { name: "gets" }, { name: "perror" }, { name: "printf" }, { name: "putc" }, { name: "putchar" }, { name: "puts" }, { name: "remove" }, { name: "rename" }, { name: "rewind" }, { name: "scanf" }, { name: "setbuf" }, { name: "setvbuf" }, { name: "snprintf" }, { name: "sprintf" }, { name: "sscanf" }, { name: "tmpfile" }, { name: "tmpnam" }, { name: "ungetc" }, { name: "vfprintf" }, { name: "vprintf" }, { name: "vsnprintf" }, { name: "vsprintf" }, { name: "abort" }, { name: "abs" }, { name: "atexit" }, { name: "atof" }, { name: "atoi" }, { name: "atol" }, { name: "atoll" }, { name: "bsearch" }, { name: "calloc" }, { name: "div" }, { name: "exit" }, { name: "free" }, { name: "getenv" }, { name: "labs" }, { name: "ldiv" }, { name: "llabs" }, { name: "lldiv" }, { name: "malloc" }, { name: "mblen" }, { name: "mbstowcs" }, { name: "mbtowc" }, { name: "qsort" }, { name: "rand" }, { name: "realloc" }, { name: "srand" }, { name: "strtod" }, { name: "strtol" }, { name: "strtoul" }, { name: "strtoll" }, { name: "strtoull" }, { name: "system" }, { name: "wcstombs" }, { name: "wctomb" }, { name: "memchr" }, { name: "memcmp" }, { name: "memcpy" }, { name: "memmove" }, { name: "memset" }, { name: "strcat" }, { name: "strchr" }, { name: "strcmp" }, { name: "strcoll" }, { name: "strcpy" }, { name: "strcspn" }, { name: "strerror" }, { name: "strlen" }, { name: "strncat" }, { name: "strncmp" }, { name: "strncpy" }, { name: "strpbrk" }, { name: "strrchr" }, { name: "strspn" }, { name: "strstr" }, { name: "strtok" }, { name: "strxfrm" }, { name: "char" }, { name: "null" }, { name: "StrReplaceBoundaries" }, { name: "strdup" }]

