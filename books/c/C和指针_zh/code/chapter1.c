#include <stdio.h> /* 标准I/O库 */
#include <stdlib.h> /* 定义了EXIT_SUCCESS和EXIT_FAILURE符合 */
#include <string.h> /* 包含操作字符串的函数 */
#define MAX_COLS 20  /* 预处理指令；所能处理的最大列号 */
#define MAX_INPUT 1000 /* 每个输入行的最大长度 */
/* 以上为预处理指令 preprocessor directives */

/* 函数原型 function prototype,告诉编译器这些以后将要在源文件中定义的函数的特征 */
int read_column_numbers(int columns[], int max);
/* void 表示函数并不返回任何值 */
void rearrange(char *output, char const *input, int n_columns, int const columns[]);

/* 必须有main函数 */
int main(void)
{
    int n_columns;   /* 整型标量，进行处理的列表号*/
    int columns[MAX_COLS]; /* 整型数组；需要处理的列数 */
    char input[MAX_INPUT];  /* 字符数组；容纳输入行的数组 */
    char output[MAX_INPUT]; /* 容纳输出行的数组 */

    /**
     * 读取该串列标号，在c语言中，数组参数是以引用(reference)形式进行传递的，也就是传址调用，而标量和常量则是按值(value)传递的
     **/
     n_columns = read_column_numbers(columns, MAX_COLS);

     /**
      * 读取、处理和打印剩余的输入行，gets函数从标准输入读取一行文本并把它存储到参数数组中
      **/
    while(gets(input) != NULL) {
        printf("Original input: %s\n", input);
        rearrange(output, input, n_columns, columns);
        printf("Rearranged line: %s \n", output);
    }
    /* 提示程序执行成功 */
    return EXIT_SUCCESS;
}

/**
 * 读取列标号，如果超出规定范围则不予理会
 **/
 int read_column_numbers(int columns[], int max)
 {
    /*局部变量*/
    int num = 0;
    int ch; /* EOF是一个整型值，它的位数比字符类型要多，把ch声明为整型可以防止从输入读取的字符意外地被解析为EOF */

    /**
     * 取得列标号，如果所读取的数小于0则停止
     **/
    while(num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
        num += 1;
    /**
     * 确认已读取的标号为偶数个，因为他们是以对的形式出现的
     **/
    if(num % 2 != 0) {
        /* puts把指定的字符串写到标准输出并在末尾添加一个换行符*/
        puts("Last column numbers is not paired.");
        exit(EXIT_FAILURE);
    }
    /**
     *  丢弃改行中包含最后一个数字的那部分内容
     *   getchar() 从标准输入读取一个字符并返回它的值，
     *  如果输入中不再存在任何字符，函数就会返回常量EOF(stdio.h定义)，用于提示文件结尾
     **/
    while((ch = getchar()) != EOF && ch != '\n')
        ; /*空语句 emty statement*/
    return num;
 }
/**
 * 处理输入行，讲指定的字符连接在一起，输出行已NUL结尾
 **/
void rearrange(char *output, char const *input, int n_columns, int const columns[])
{
    int col; /* columns 数组的下标 */
    int output_col;  /* 输出列计数器 */
    int len; /* 输入行的长度 */

    len = strlen(input);
    output_col = 0;

    /**
     * 处理每对列表号,for(初始部分；测试部分；调整部分)
     **/
    for(col = 0; col < n_columns; col +=2) {
        int nchars = columns[col + 1] - columns[col] + 1;

        /**
         * 如果输入行结束或者输出行数组已满，就结束任务
         **/
         if(columns[col] >= len || output_col == MAX_INPUT - 1){
            break;
         }

         /**
          * 如果输出行数据空间不够，只复制可以容纳的数据
          **/
          if(output_col + nchars > MAX_INPUT - 1)
            nchars = MAX_INPUT - output_col - 1;
        /**
         * 复制相关的数据
         *  strncpy(目标字符串的地址, 源字符串的地址) 把选中的字符串从输入行复制到输出行中可用的下一位置
         **/
         strncpy(output + output_col, input + columns[col], nchars);
         output_col += nchars;
    }

    output[output_col] = '\0'; // NUL
}
