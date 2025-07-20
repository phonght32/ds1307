// MIT License

// Copyright (c) 2024 phonght32

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __DS1307_H__
#define __DS1307_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "time.h"
#include "err_code.h"

#define DS1307_I2C_ADDR  		(0x68)

typedef err_code_t (*ds1307_func_i2c_send)(uint8_t reg_addr, uint8_t *buf_send, uint16_t len);
typedef err_code_t (*ds1307_func_i2c_recv)(uint8_t reg_addr, uint8_t *buf_recv, uint16_t len);

/**
 * @brief   Handle structure.
 */
typedef struct ds1307 *ds1307_handle_t;

/**
 * @brief   Configuration structure.
 */
typedef struct {
	ds1307_func_i2c_send  			i2c_send; 		/*!< I2C send function */
	ds1307_func_i2c_recv			i2c_recv;		/*!< I2C receive function */
} ds1307_cfg_t;

/*
 * @brief   Initialize DS1307 with default parameters.
 *
 * @note    This function must be called first.
 *
 * @param   None.
 *
 * @return
 *      - Handle structure: Success.
 *      - Others:           Fail.
 */
ds1307_handle_t ds1307_init(void);

/*
 * @brief   Set configuration parameters.
 *
 * @param 	handle Handle structure.
 * @param   config Configuration structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t ds1307_set_config(ds1307_handle_t handle, ds1307_cfg_t config);

/*
 * @brief   Configure DS1307 to run.
 *
 * @param 	handle Handle structure.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t ds1307_config(ds1307_handle_t handle);

/**
 * @brief   Get time.
 *
 * @param 	handle Handle structure.
 * @param   time Pointer references to the struct tm.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t ds1307_get_time(ds1307_handle_t handle, struct tm *time);

/**
 * @brief   Set time.
 *
 * @param 	handle Handle structure.
 * @param   time Struct tm.
 *
 * @return
 *      - ERR_CODE_SUCCESS: Success.
 *      - Others:           Fail.
 */
err_code_t ds1307_set_time(ds1307_handle_t handle, struct tm *time);

#ifdef __cplusplus
}
#endif

#endif /* __DS1307_H__ */