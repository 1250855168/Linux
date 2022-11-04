#ifndef _HEAD_H_
#define _HEAD_H_

/**
 * @brief 判断是否是个文件和目录
 * 
 * @param name 
 */
void is_file(char *name,void (*file)(char *));

/**
 * @brief 进行回调判断是否是文件和目录
 * 
 * @param Dir 
 * @param file 
 */
void read_Dir(char *Dir);

#endif