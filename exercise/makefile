#makeコマンドはオプションなし、引数なしで実行することで、
#MakeFileを参照し、MakeFile内のデフォルトの処理を行う(大抵の場合はビルド処理)

#ディレクトリ以下の全部のファイルを一度にコンパイルできる方法はあるが、
#makeはそもそも一度コンパイルしたファイルを再度コンパイルせず、
#新しくコンパイルが必要なファイルのみをコンパイルするためにあるので、
#一度コンパイルされているファイルが全部のファイルを一度にコンパイルされるタイミングで
#再度コンパイルされる必要はない。

#タブでインデント

CC := gcc #コンパイラ
CFLAGS=-I -Wall -Werror -O2 -march=native -c #コンパイルオプション
INCS=
OBJS=test.c #ソースファイル
LIBS=
TARGET=./test #実行ファイル
OBJDIR=./obj #オブジェクトファイル保存フォルダ
INCLUDE=

#all: $(TARGET) #実行ファイル

#%.o: %.c $(INCS)
#	$(CC) $(CFLAGS) -c -o $@ $<

#$(TARGET): $(OBJS)
#	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

#上の2つと同じように実行できる
#実行ファイル作成
$(TARGET): $(OBJS) $(LIBS)
	$(CC) -o $@ $^ $(LDFLAGS)

#ソースファイルをコンパイル
$(OBJDIR)/*.o: *.c
	@if [ ! -d $(OBJDIR) ];\
	then echo "mkdir -p $(OBJDIR)";mkdir -p $(OBJDIR);\
	fi
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $< $(LIBS)

#make clean で削除してから新しくmakeする
clean:
	rm -rf $(TARGET) *.o

#make euclid で実行できる
euclid: euclid.o main.o input.o output.o
	gcc euclid.o main.o input.o output.o -o euclid

euclid.o: euclid.c euclid.h
	gcc -c euclid.c

main.o: main.c euclid.h
	gcc -c main.c euclid.h

input.o: input.c
	gcc -c input.c

output.o: output.c
	gcc -c output.c
