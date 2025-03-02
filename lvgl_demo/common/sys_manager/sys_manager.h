#ifndef _SYS_MANAGER_H
#define _SYS_MANAGER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../../conf/dev_conf.h"
#include <stdint.h>
#include <stdbool.h>

extern const char * sys_config_path;
extern const char * city_adcode_path;

typedef struct {
    char city[36];
    char adcode[16]; // 'gao de' Amap adcode
} LocationInfo_t;

typedef struct {
    int year;                       // system time year             (need store)
    int month;                      // system time month            (need store)
    int day;                        // system time day              (need store)
    int hour;                       // system time hour             (need store)
    int minute;                     // system time minute           (need store)
    uint16_t brightness;            // system brightness            (need store)
    uint16_t sound;                 // system sound volume(0-30)    (need store)
    bool wifi_connected;            // wifi connected or not
    bool auto_time;                 // auto update time or not      (need store)
    bool auto_location;             // auto update location or not  (need store)
    LocationInfo_t location;        // location info                (need store)
    char gaode_api_key[33];         // gaode api key for amap api   (need store)
}system_para_t;

// 设置LCD背光亮度（0-100之间）
int sys_set_lcd_brightness(int brightness);

// 获取LCD背光亮度
int sys_get_lcd_brightness(void);

// 设置系统音量（0到100之间）
int sys_set_volume(int level);

// 获取系统音量
int sys_get_volume(void);

// 设置系统时间
int sys_set_time(int year, int month, int day, int hour, int minute, int second);

// 获取系统时间
void sys_get_time(int *year, int *month, int *day, int *hour, int *minute, int *second);

// 获取指定日期是星期几
int sys_get_day_of_week(int year, int month, int day);

// 获取wifi连接状态
bool sys_get_wifi_status(void);

// 获取city name by adcode
const char* sys_get_city_name_by_adcode(const char *filepath, const char *target_adcode);

// 通过IP获取自动定位信息
int sys_get_auto_location_by_ip(LocationInfo_t* location, const char *api_key);

// 保存系统参数到文件
int sys_save_system_parameters(const char *filepath, const system_para_t *params);

// 从文件加载系统参数
int sys_load_system_parameters(const char *filepath, system_para_t *params);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif