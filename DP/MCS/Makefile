# 指定编译器
CC=gcc

# 目标可执行文件
TARGET=mcs

# 构建目标可执行文件
$(TARGET): mcs.o lib.o
	$(CC) mcs.o lib.o -o $(TARGET)

# 编译主程序 mcs.c 到对象文件 mcs.o
mcs.o: mcs.c
	$(CC) $(CFLAGS) -c mcs.c

# 编译库文件 lib.c 到对象文件 lib.o
lib.o: lib.c
	$(CC) $(CFLAGS) -c lib.c

# 清理编译生成的文件
clean:
	rm -f *.o $(TARGET)
