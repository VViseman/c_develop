#makeコマンドはオプションなし、引数なしで実行することで、
#MakeFileを参照し、MakeFile内のデフォルトの処理を行う(大抵の場合はビルド処理)

#タブでインデント

#コンパイルオプション
CFLAGS=-I. -Wall -Werror -O2 -march=native

INCS=
OBJS=test.c
LIBS=
TARGET=test
CC := gcc

all: $(TARGET) #実行ファイル

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

#make clean で削除してから新しくmakeする
clean:
	rm -rf $(TARGET) *.o
