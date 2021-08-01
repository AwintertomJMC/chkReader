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

#为什么会有做这个项目?

摘自https://baike.baidu.com/item/CHK/6384780?fr=aladdin
>CHK是一种文件名称，英文全名为CHecK。后缀名为CHK的文件是用户在使用“磁盘碎片整理程序”整理硬盘后所产生的“丢失簇的恢复文件”，移动存储设备在读取数据的时候遇到断电或被强行拔出通常也会产生大量的CHK文件。  

摘自https://baike.baidu.com/item/found.000/4231708?fr=aladdin
>found.000是指文件夹及.chk文件是Windows在检查到丢失的文件碎片（非法关机造成了文件的丢失）后，将这些文件碎片转换成的文件及存放这些文件的文件夹。
 found.000文件夹里面的一些后缀名为CHK的文件是在使用“磁盘碎片整理程序”整理硬盘后所产生的“丢失簇的恢复文件”。  

#借物表
常见文件文件头 https://blog.csdn.net/syj573077027/article/details/108352832  
文件头标志大全 https://wenku.baidu.com/view/c8392d28872458fb770bf78a6529647d26283405.html
文件头 https://baike.baidu.com/item/%E6%96%87%E4%BB%B6%E5%A4%B4/2695144?fr=aladdin  
Windows 下c获取文件目录 https://blog.csdn.net/weixin_34146410/article/details/91929536  
List of file signatures https://en.wikipedia.org/wiki/List_of_file_signatures