#这是什么项目？
一个通过读取文件头前缀来识别FoundXXX文件夹里.chk文件类型并重命名的小工具。

#怎么使用
在命令行这样输入：`chkReader.exe 目录位置`  即可执行

#注意事项
由于该小工具会直接在原来的文件基础上重命名，所以使用前请将原来的FoundXXX
文件夹备份一份到其他目录，再对备份进行使用。

<font size=5>**本工具不能代替专业数据恢复软件**</font>

#已知问题
1. 能且只能根据文件头前缀的几个字节识别，并且识别的文件种类只有16种，详见fileHeader.h。
2. 一次只能读取600-700左右文件，之后的文件会被认为“无法打开”，原因未知。
3. 目前只能读取目录，不能读取单个文件。

#为什么会有这个项目?

#借物表
