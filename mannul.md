### NSS(name service switch)配置
```
passwd:     files http
shadow:     files http
group:      files http
```
### NSS 模块不必实现所有的DB访问需求
 No service module is forced to have functions for all databases and all kinds to access them.
If a function is not available it is simply treated as if the function would return unavail

### 系统查询http模块的规则: /lib64/libnss_modulename.so
如:/lib64/libnss_files.so, /lib64/libnss_http.so

### 函数命名规则
getxxent: 例如:getgrent, getpwent   which means get group entries and password entries
getxxent_r: 例如:getgrent_r

### 函数解析

http://man.chinaunix.net/develop/c&c++/linux_c/function/07.html

getgrent: 返回一个指向group结构体的指针
第一次call返回第一条group记录,以此类推,知道返回null或者错误
setgrent: 使getgrent重新搜索group文件,也就是说从第一条开始
endgrent: 当group上的所有操作完成后, 关闭group文件



###setgrent()用来将getgrent()的读写地址指回组文件开头。


endgrent 关闭组文件(由getgrent打开的密码文件)

endpwent 关闭密码文件(有getpwent打开的密码文件)

fgetent  从指定的文件来读取组格式
fgetgrent()会从参数stream指定的文件读取一行数据，然后以group结构将该数据返回。参数stream所指定的文件必须和、etc/group相同的格式。group结构定义请参考getgrent()。
返回值,返回group结构数据，如果返回NULL则表示已无数据，或有错误发生。

fgetpwent（从指定的文件来读取密码格式）
fgetpwent()会从参数stream指定的文件读取一行数据，然后以passwd结构将该数据返回。参数stream所指定的文件必须和/etc/passwd相同的格式。passwd结构定义请参考getpwent()。
返回值 返回passwd结构数据，如果返回NULL则表示已无数据，或有错误发生。

getegid（取得有效的组识别码）

### 对于加_r的解释, 大概意思就是可以重入的函数,类似cursor,一次读取一条,下一次读取下一条 而不加r的函数就是一次性读取所有的数据
The functions getgrent_r() and fgetgrent_r() are the reentrant versions of getgrent(3) and fgetgrent(3).
The former reads the next group entry from the stream initialized by setgrent(3). The latter reads the next group entry from the stream fp.

