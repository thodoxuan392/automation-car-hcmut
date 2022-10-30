#ifndef __BLUETOOTH_LIB_H__
#define __BLUETOOTH_LIB_H__

#include "stdint.h"
#include "SoftwareSerial.h"

#define BLUETOOTH_MAX_LENGTH         1024

typedef enum {
    BLUETOOTH_WAIT_FOR_CMD,
    BLUETOOTH_IN_PROCESS,
    BLUETOOTH_RSP_SUCCESS,
    BLUETOOTH_RSP_FAILED,
    BLUETOOTH_TIMEOUT
}bluetooth_state_e;


typedef enum {
    BLUETOOTH_OPT_READ,
    BLUETOOTH_OPT_WRITE
}bluetooth_opt_t;

// BLuetooth Result
typedef enum {
    BLUETOOTH_OK,
    BLUETOOTH_FAILED,
    BLUETOOTH_INVALID_STATUS,
    BLUETOOTH_TIMEOUT,
}bluetooth_result_t;

// Bluetooth Request
typedef enum {
    BLUETOOTH_REQ_TEST,
    BLUETOOTH_REQ_VERSION,
    BLUETOOTH_REQ_CONNECTION_STATUS,
    BLUETOOTH_REQ_SLEEP,
    BLUETOOTH_REQ_BAUREATE,

}bluetooth_req_header_t;

typedef struct {
    bluetooth_req_header_t header;
    bluetooth_opt_t opt;
    struct{
        uint8_t data[BLUETOOTH_MAX_LENGTH];
        uint16_t length;
    }data;
}bluetooth_req_t;



// Bluetooth Response
typedef enum {
    BLUETOOTH_RSP_TEST,
    BLUETOOTH_RSP_VERSION,
    BLUETOOTH_RSP_CONNECTION_STATUS,
    BLUETOOTH_RSP_SLEEP,
    BLUETOOTH_RSP_BAUREATE,
}bluetooth_rsp_header_t;

typedef struct {
    bluetooth_rsp_header_t header;
    bluetooth_opt_t opt;
    bluetooth_result_t result;
    struct{
        uint8_t data[BLUETOOTH_MAX_LENGTH];
        uint16_t length;
    }data;
}bluetooth_rsp_t;



// Function
__attribute__((weak)) void bluetooth_on_evt(bluetooth_rsp_t * evt);

/**
 * @brief Bluetooth Loop in Super Loop
 * 
 */
void bluetooth_loop();

/**
 * @brief Init Bluetooth Stack
 * 
 * @param serial Serial Stream for send and receive data from BLUETOOTH Module
 */
void bluetooth_init(SoftwareSerial *serial);



bluetooth_result_t bluetooth_test_read();

bluetooth_result_t bluetooth_test_write();

bluetooth_result_t bluetooth_version_read();

bluetooth_result_t bluetooth_connection_status_read();

bluetooth_result_t bluetooth_baudrate_read();
bluetooth_result_t bluetooth_baudrate_write();

bluetooth_result_t bluetooth_name_read();
bluetooth_result_t bluetooth_name_write();

bluetooth_result_t bluetooth_ble_name_read();
bluetooth_result_t bluetooth_ble_name_write();


bluetooth_result_t bluetooth_pin_read();
bluetooth_result_t bluetooth_pin_write();

bluetooth_result_t bluetooth_macaddr_read();
bluetooth_result_t bluetooth_macaddr_write();





