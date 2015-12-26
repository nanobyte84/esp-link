#include "ets_sys.h"
#include "driver/uart.h"
#include "i2c/i2c.h"
#include "osapi.h"
#include "os_type.h"
#include "config.h"
#include "user_interface.h"

#include "user_main.h"
#include "user_display.h"
#include "user_buttons.h"
#include "user_network.h"

#define user_procTaskPrio        1
#define user_procTaskQueueLen    1

os_event_t    user_procTaskQueue[user_procTaskQueueLen];

void user_procTask(os_event_t *events);

void ICACHE_FLASH_ATTR
user_procTask(os_event_t *events)
{
    os_printf("USER task\n\r");
}

//void user_init(void)
void app_init(void)
{
//    char ssid[32] = SSID;
//    char password[64] = SSID_PASSWORD;
//    struct station_config stationConf;

//    system_timer_reinit();
//    uart_init(BIT_RATE_115200, BIT_RATE_115200);

//    os_memcpy(&stationConf.ssid, ssid, 32);
//    os_memcpy(&stationConf.password, password, 32);

    //Setup wifi
//    wifi_set_opmode( 0x1 );
//    wifi_set_phy_mode(PHY_MODE_11N);
//    wifi_station_set_config(&stationConf);

//    network_init();
//    display_init();
//    buttons_init();
    
    os_printf("USER start\n");

	system_os_task(user_procTask, user_procTaskPrio,user_procTaskQueue, user_procTaskQueueLen);
}


void user_function1(void)
{
	 os_printf("USER function1\n");
}

void user_function2(int8_t user1,int8_t user2)
{
	 os_printf("USER function2 1=%d  2=%d\n",user1,user2);
}

