//
// Created by DELL on 2021/7/21.
//

#include "fileHeader.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SKIPPED "skipped"
/**
 * 检查文件头前BUFFERLENGTH个字节，判断文件类型是否匹配
 * @param fileHeadInfoBuffer
 * @return 0是不匹配，1是匹配
 */
char targetFilePath[FILENAMELENGTH*2];
char renameFilePath[FILENAMELENGTH*2];
int checkFileHeadHex(byte toBeCheckedFileHeadInfoBuffer[], unsigned int listIndex);
bool isSuffixChk(char *suffixString);

void handleFileTypeCheck(FILE *checkFile, char *directoryName, char *fileName) {
    if (!isSuffixChk(fileName)) {
        printf("file %s is not .chk file.%s\n", fileName, SKIPPED);
        return;
    }
    //待检查的文件头部缓存
    static byte toBeCheckedFileHeadInfoBuffer[BUFFERLENGTH];
    //读取前BUFFERLENGTH个字节
    fread(toBeCheckedFileHeadInfoBuffer, sizeof(byte),BUFFERLENGTH,checkFile);
    //（暴力）遍历检索匹配
    for (unsigned int listIndex = 0; listIndex < sizeof(checkItemHeadInfoList) / sizeof(FileHeadInfo); ++listIndex) {
        if (checkFileHeadHex(toBeCheckedFileHeadInfoBuffer, listIndex)) {
            //找到了匹配的,重命名
            fclose(checkFile);
            static char newName[FILENAMELENGTH];
            sprintf(newName,"%s",fileName);
            char *dotPosition = strrchr(newName,'.');
            *(dotPosition+1) = '\0';
            strcat(newName, checkItemHeadInfoList[listIndex].suffixName);
            sprintf(renameFilePath, "%s\\%s", directoryName, newName);
            if(rename(targetFilePath,renameFilePath) == 0) {
                printf("file %s is %s file! renamed to %s!\n", fileName,
                       checkItemHeadInfoList[listIndex].suffixName, newName);
            } else {
                printf("file %s is %s file! but rename failed!\n", fileName, checkItemHeadInfoList[listIndex].suffixName);
            }
            return;
        }
    }
    //未匹配
    printf("file %s: the type is not found,%s\n", fileName, SKIPPED);
}

int checkFileHeadHex(byte toBeCheckedFileHeadInfoBuffer[], unsigned int listIndex) {
    //用无符号4字节整数指针，一个用bytesPointer指向待检查的文件头部缓存
    //另一个用checkItemHeadBytesPointer指向检查项的头部字节数组
    unsigned int *toBeCheckedBytesPointer = toBeCheckedFileHeadInfoBuffer, *checkItemHeadBytesPointer = NULL;
    //检查项指针，用于指向FileHeadInfo的数据
    FileHeadInfo *checkItemHeadInfoPointer = &checkItemHeadInfoList[listIndex];
    checkItemHeadBytesPointer = checkItemHeadInfoPointer->fileHeadHexCode;
    int i = 0;
    for (i = 0; i < checkItemHeadInfoPointer->count/4; ++i,++toBeCheckedBytesPointer,++checkItemHeadBytesPointer) {
        //按4字节读取大部分
        if (*toBeCheckedBytesPointer != *checkItemHeadBytesPointer ){
            return 0;
        }
    }
    for (i = i*4; i < checkItemHeadInfoPointer->count; ++i) {
        //按1个字节读取剩下部分
        if (toBeCheckedFileHeadInfoBuffer[i] != checkItemHeadInfoPointer->fileHeadHexCode[i]) {
            return 0;
        }
    }
    return 1;
}

/**
 * 判断文件后缀名是否为"chr"或其包含大写字符的变形
 * @param fileName
 * @return 返回值为1说明符合，否则不符合
 */
bool isSuffixChk(char *fileName) {
    if(fileName == NULL) {
        return 0;
    }
    char *suffixString = strrchr(fileName, '.');
    if (suffixString == NULL) {
        return 0;
    }
    return (suffixString[1] == 'c'|suffixString[1] == 'C')
    &(suffixString[2] == 'h'|suffixString[2] == 'H')
    &(suffixString[3] == 'k'|suffixString[3] == 'K');
}