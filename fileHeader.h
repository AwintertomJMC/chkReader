//
// Created by DELL on 2021/7/20.
//
#define BUFFERLENGTH 16
#define SUFFIXLENGTH 16
#define FILENAMELENGTH 263
typedef unsigned char byte;
typedef struct FileHeadInfo {
    char suffixName[SUFFIXLENGTH];
    byte fileHeadHexCode[BUFFERLENGTH];
    int count;
}FileHeadInfo;

FileHeadInfo checkItemHeadInfoList[] = {
        {"pdf",{0x25,0x50,0x44,0x46,0x2D,0x31,0x2E},7},
        {"doc",{0xD0,0xCF,0x11,0xE0},4},
        {"docx",{80,75},2},
        {"rtf",{0x7B,0x5C,0x72,0x74,0x66},5},
        {"dwg",{0x41,0x43,0x31,0x30},4},
        {"zip",{0x50,0x4B},2},
        {"rar",{0x52,0x61,0x72,0x21},4},
        {"rar",{0x52,0x61},4},
        {"7z",{0x37,0x7A,0xBC,0xAF,0x27,0x1C},4},
        {"jpg",{0xFF,0xD8,0xFF},3},
//        {"jpg",{0xFF,0xD8,0xFF,0xE0},4},
//        {"jpg",{0xFF,0xD8,0xFF,0xE1},4},
//        {"jpg",{0xFF,0xD8,0xFF,0xE8},4},
//        {"png",{0x89,0x50,0x4E,0x47,0x0d,0x0a,0x1a,0x0a},8},
        {"png",{0x89,0x50,0x4E,0x47},4},
        {"png",{0x89,0x50},2},
        {"gif",{0x47,0x49,0x46,0x38},4},
        {"bmp",{0x42,0x4D},2},
        {"3gp",{0x66,0x74,0x79,0x70,0x33,0x67},6},
        {"3g2",{0x66,0x74,0x79,0x70,0x33,0x67},6},
        {"mp4",{0x66,0x74,0x79,0x70,0x69,0x73,0x6F,0x6D},8},
        {"exe",{0x4D,0x5A},2},
        {"exe",{0x5A,0x4D},2},
};
