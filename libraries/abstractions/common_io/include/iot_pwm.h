/*
 * Amazon FreeRTOS V1.2.3
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */

/**
 * @file    iot_pwm.h
 * @brief   This file contains all the PWM HAL API definitions
 */

#ifndef _IOT_PWM_H_
#define _IOT_PWM_H_

/**
 * @defgroup iot_pwm PWM HAL APIs
 * @{
 */

/**
 * @brief Return values used by PWM driver.
 */
#define IOT_PWM_SUCCESS                   ( 0 )
#define IOT_PWM_INVALID_VALUE             ( 1 )
#define IOT_PWM_NOT_CONFIGURED            ( 2 )
#define IOT_PWM_FUNCTION_NOT_SUPPORTED    ( 3 )


/**
 * @brief PWM configuration type.
 */
typedef struct IotPwmConfig
{
    uint32_t ulPwmFrequency; /*!< PWM frequency */
    uint8_t ucPwmDutyCycle;  /*!< PWM duty cycle */
    uint8_t ucPwmChannel;    /*!< PWM output channel.*/
} IotPwmConfig_t;

/**
 * @brief   PWM descriptor type defined in the source file.
 */
struct                      IotPwmDescriptor;

/**
 * @brief   IotPwmHandle_t type is the PWM handle returned by calling iot_pwm_open()
 *          this is initialized in open and returned to caller. Caller must pass this pointer
 *          to the rest of the APIs.
 */
typedef struct IotPwmDescriptor   * IotPwmHandle_t;

/**
 * @brief   iot_pwm_open is used to initialize the PWM driver instance.
 *          this API will configure PWM and may reset the PWM hardware.
 *
 * @param[in]   lPwmInstance   The instance of the PWM to initialize.
                                PWM is output only.
 *
 * @return Handle to PWM interface on success, or NULL on failure.
 */
IotPwmHandle_t iot_pwm_open( int32_t lPwmInstance );

/**
 * @brief   iot_pwm_set_config sets up the PWM frequency and duty cycle
 *          to generate the PWM pulses required.
 *
 * @param[in]   pxPwmHandle  Handle to PWM driver returned in
 *                          iot_pwm_open
 * @param[in]   xConfig     PWM configuration to be setup.
 *
 * @return  returns IOT_PWM_SUCCESS on success or returns
 *          one of IOT_PWM_INVALID_VALUE on error.
 */
int32_t iot_pwm_set_config( IotPwmHandle_t const pxPwmHandle,
                            const IotPwmConfig_t xConfig );

/**
 * @brief   iot_pwm_get_config returns the current PWM configuration
 *
 * @param[in]   pxPwmHandle  Handle to PWM driver returned in
 *                          iot_pwm_open
 *
 * @return  returns pointer to current PWM configuration on success,
 *          or returns NULL
 */
IotPwmConfig_t * iot_pwm_get_config( IotPwmHandle_t const pxPwmHandle );

/*!
 * @brief   Start the PWM hardware. PWM configuration must be
 *          set before PWM is started.
 *
 * @param[in]   pxPwmHandle  Handle to PWM driver returned in
 *                          iot_pwm_open
 *
 * @return  returns IOT_PWM_SUCCESS on success or returns
 *          one of IOT_PWM_INVALID_VALUE on error.
 */
int32_t iot_pwm_start( IotPwmHandle_t const pxPwmHandle );

/*!
 * @brief Stop the PWM hardware.
 *
 * @param[in]   pxPwmHandle  Handle to PWM driver returned in
 *                          iot_pwm_open
 *
 * @return  returns IOT_PWM_SUCCESS on success or returns
 *          one of IOT_PWM_INVALID_VALUE on error.
 */
int32_t iot_pwm_stop( IotPwmHandle_t const pxPwmHandle );

/**
 * @brief iot_pwm_close de-initializes the PWM.
 *
 * @param[in]   pxPwmHandle  Handle to PWM driver returned in
 *                          iot_pwm_open
 *
 * @return  returns IOT_PWM_SUCCESS on success or returns
 *          one of IOT_PWM_INVALID_VALUE on error.
 */
int32_t iot_pwm_close( IotPwmHandle_t const pxPwmHandle );

/**
 * @}
 */

#endif /* ifndef _IOT_PWM_H_ */
