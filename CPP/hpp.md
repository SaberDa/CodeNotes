.hpp 文件，本质是将cpp的实现代码混入h文件中

定义与实现都包含在同一文件，则该类的调用者只需要include该hpp文件即可，无需再将cpp加入到project中进行编译

而实现代码将直接编译到调用者的obj文件中，不再生成单独的obj

采用hpp将大幅度减少调用project中的cpp文件数与编译次数，

也不用再发布lib与dll文件

因此非常适合用来编写公用的开源库

NOTE:

1. hpp 是 header plus plus 的缩写
2. 与 .h 类似，.hpp 是 C++ 程序头文件格式
3. 是 VCL 专用的头文件，已预编译
4. 是一般模板类的头文件
5. 一般的，.h 里面只有声明，没有实现，而 .hpp 里两者都有，后者可以减少 .cpp 的数量
6. .h 中可以有 using namespace std, 而 .hpp 中则无
7. 不可包含全局对象和全局函数

由于 .hpp 本质上是作为 .h 被调用者 include 的，所以当 hpp 文件中存在全局对象或者全局函数，

并且该 hpp 文件被多个调用者 include 时，将在链接时导致符号重定义错误。

要避免这种情况，需要去除全局对象，将全局函数封装为类的静态方法