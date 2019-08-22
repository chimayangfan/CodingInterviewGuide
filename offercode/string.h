#pragma once
#ifndef __STRING_HPP__
#define __STRING_HPP__
/***************************************************************************
*   @author:    汪亮
*   @date:      2019.8
*   @remark:    字符串处理集合
*   @note:      Part1 字符串操作
*				Part2 字符串到数值类型的转换
*				Part3 字符检查
****************************************************************************/

#include<bits/stdc++.h>

using namespace std;

//字符串操作
//strcpy(p, p1) 复制字符串
//strncpy(p, p1, n) 复制指定长度字符串
//strcat(p, p1) 附加字符串
//strncat(p, p1, n) 附加指定长度字符串
//strlen(p) 取字符串长度
//strcmp(p, p1) 比较字符串
//strcasecmp忽略大小写比较字符串
//strncmp(p, p1, n) 比较指定长度字符串
//strchr(p, c) 在字符串中查找指定字符
//strrchr(p, c) 在字符串中反向查找
//strstr(p, p1) 查找字符串
//strpbrk(p, p1) 以目标字符串的所有字符作为集合，在当前字符串查找该集合的任一元素
//strspn(p, p1) 以目标字符串的所有字符作为集合，在当前字符串查找不属于该集合的任一元素的偏移
//strcspn(p, p1) 以目标字符串的所有字符作为集合，在当前字符串查找属于该集合的任一元素的偏移
//
//字符串到数值类型的转换
//strtod(p, ppend) 从字符串 p 中转换 double 类型数值，并将后续的字符串指针存储到 ppend 指向的 char* 类型存储。
//strtol(p, ppend, base) 从字符串 p 中转换 long 类型整型数值，base 显式设置转换的整型进制，设置为 0 以根据特定格式判断所用进制，0x, 0X 前缀以解释为十六进制格式整型，0    前缀以解释为八进制格式整型
//atoi(p) 字符串转换到 int 整型
//atof(p) 字符串转换到 double 符点数
//atol(p) 字符串转换到 long 整型
//
//字符检查
//isalpha() 检查是否为字母字符
//isupper() 检查是否为大写字母字符
//islower() 检查是否为小写字母字符
//isdigit() 检查是否为数字
//isxdigit() 检查是否为十六进制数字表示的有效字符
//isspace() 检查是否为空格类型字符
//iscntrl() 检查是否为控制字符
//ispunct() 检查是否为标点符号
//isalnum() 检查是否为字母和数字
//isprint() 检查是否是可打印字符
//isgraph() 检查是否是图形字符，等效于 isalnum() | ispunct()


//*************************************************************************//
//							Part1 子集问题
//*************************************************************************//
//Part1函数定义
#ifndef Part1 
#define Part1
char *strcpy(char *dest, const char *src);					//复制字符串
char *strncpy(char *dest, const char *src, size_t count);	//复制字符串
char *strcat_(char *dest, const char *src);					//字符串拼接


/// \功能：把src所指向的以 '\0'结尾的字符串复制到dest所指向的数组中(strncpy，代表只拷贝前n个)
/// \param1: char *dest 目的字符串
/// \param2: const char *src 源字符串
/// \return char * 复制后的字符串
char *strcpy(char *dest, const char *src) {
	char *ret = dest;
	assert((dest != nullptr) && (src != nullptr));
	while ((*dest++ = *src++) != '\0');
	return ret;
}

/// \功能：把src所指向的以 '\0'结尾的字符串复制到dest所指向的数组中(strncpy，代表只拷贝前n个)
/// \param1: char *dest 目的字符串
/// \param2: const char *src 源字符串
/// \param3: size_t count 拷贝字符数
/// \return char * 复制后的字符串
char *strncpy(char *dest, const char *src, size_t count){
	char *ret = dest;
	assert((dest != nullptr) && (src != nullptr));
	while (count-- && (*dest++ = *src++) != '\0');
	return ret;
}

/// \功能：把src的字符串拼接到dest末尾
/// \param char *dest 目标字符串指针
/// \param const char *src 源字符串指针
/// \return char *目标字符串作为返回值
char *strcat_(char *dest, const char *src) {
	char *ret = dest;
	assert((dest != nullptr) && (src != nullptr));
	//找到dest指向字符串的末尾 '\0'
	while (*dest != '\0') {//注意此处while 不能写成(*dest++ != '\0'),因为一个循环结束前又++操作会跳过 '\0'
		dest++;
	}

	//拷贝src指向的内容
	while ((*dest++ = *src++));

	return ret;
}

#endif


#endif