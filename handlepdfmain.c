#include "functions.c"
#include <Windows.h>

int main(int argc,char *argv[]) {
    if (argc <= 1) {
        printf("path not found.Please specify the path where .chk file locate.\n");
        return 0;
    }
    printf("starting... target path:%s\n", argv[1]);

    char targetDirectoryPath[FILENAMELENGTH];
    sprintf(targetDirectoryPath,"%s\\*",argv[1]);

    WIN32_FIND_DATA fileAttr;
    HANDLE handle = FindFirstFile(targetDirectoryPath,&fileAttr);
    if(handle == INVALID_HANDLE_VALUE) {
        printf("load folder error\n");
        return 0;
    }
    FindNextFile(handle, &fileAttr);//跳过".."目录
    FILE *file;

    while (FindNextFile(handle, &fileAttr)) {
        if (fileAttr.dwFileAttributes == 16) {
            printf("file %s is directory. %s.\n", fileAttr.cFileName, SKIPPED);
            continue;
        }
        sprintf(targetFilePath, "%s\\%s", argv[1], fileAttr.cFileName);
        file = fopen(targetFilePath, "r");
        if (file == NULL) {
            printf("file %s not found or cannot open. %s.\n", fileAttr.cFileName, SKIPPED);
            continue;
        }
        handleFileTypeCheck(file, argv[1], fileAttr.cFileName);

    }
    if (GetLastError() == ERROR_NO_MORE_FILES) {
        printf("chk convert finished!\n");
    } else {
        printf("error! error code:%lu\n",GetLastError());
    }
    FindClose(handle);
    return 0;
}