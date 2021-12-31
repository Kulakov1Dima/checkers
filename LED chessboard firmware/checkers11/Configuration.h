/**
 * LED Chessboard Firmware
 * conceived in 2019
 * 
 * Based on a microcontroller NodeMCU 1.0(ESP-12E Module)
 * Kulakov Dmitry Alekseevich
 * 
 * This firmware is designed for the chess board microcontroller
 * The LED panel polls the web server,
 * receiving user commands,
 * that were given by voice to the skill of Yandex Alice
 * 
 * This is the 11th version of 2021
 */

#define CONFIGURATION_H_VERSION             2021011

/*..................Configuration Connected....................*/

#define NETWORK_NAME                        "TP-Link_EFF4" 
//#define NETWORK_NAME_1                    "*********"
//#define NETWORK_NAME_2                    "*********" 

#define NETWORK_PASSWORD                    "13197421"
//#define NETWORK_PASSWORD_1                "*******"
//#define NETWORK_PASSWORD_2                "*******"

#define TIME_INTERVAL_CONNECTED_WIFI        70
#define TIME_INTERVAL_CHECK_WIFI            1000
#define CHECK_WIFI

#define INDICATOR_OF_NETWORK_STATUS         2
#define INVERT_INDICATOR_OF_NETWORK_STATUS

/*...........Update firmware into wifi configuration...........*/

#define OTAUSER                             ""
#define OTAPASSWORD                         ""
#define OTAPATH                             "/firmware"
#define SUBFOLDERDATA                       "/data"
#define SERVERPORT                          80

/*......................Server configuration..................*/

#define TIME_HOST                           2500

/*......................Matrix configuration..................*/

#define matrixLed                           D2