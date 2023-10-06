/*
 * hal_gpio.h
 *
 * Created: 10/5/2023 1:49:11 PM
 *  Author: Abdallah magdy
 */ 


#ifndef HAL_GPIO_H_
#define HAL_GPIO_H_
/*-------------------------- Includes Section -----------------------------*/
#include "MCAL_Layer/STD/compiler.h"
#include "MCAL_Layer/STD/device_config.h"
#include "MCAL_Layer/STD/mcal_std_types.h"
#include "avr/io.h"
#include "hal_gpio_config.h"


/*------------- User Defined Data Type Declarations Sections --------------*/
typedef enum {
	GPIO_DIRECTION_INPUT= 0 ,
	GPIO_DIRECTION_OUTPUT
}direction_t;


typedef enum {
	GPIO_LOGIC_LOW = 0 ,
	GPIO_LOGIC_HIGH
}logic_t;


typedef enum {
	GPIO_PIN0 = 0 ,
	GPIO_PIN1 ,
	GPIO_PIN2 ,
	GPIO_PIN3 ,
	GPIO_PIN4 ,
	GPIO_PIN5 
}pin_index_t;



typedef struct {
	pin_index_t pin_index : 3 ;
	direction_t direction : 1 ;
	logic_t logic : 1 ;
	uint8 reserved : 3 ;
}pin_config_t;

/*---------------------- Macro Declarations Section -----------------------*/
#define PIN_MAX_INDEX      (uint8)5
#define PIN_MAX_NUMBER     (uint8)6


#define BIT_MASK           (uint8)0x01
#define PORT_MASK          (uint8)0xFF

/*---------------------- Macro Functions Sections --------------------------*/
#define SET_BIT(REG, POS)     (REG |= (BIT_MASK << POS))
#define CLEAR_BIT(REG, POS)   (REG &= ~(BIT_MASK << POS))
#define TOGGLE_BIT(REG, POS)   (REG ^= (BIT_MASK << POS))
#define READ_BIT(REG, POS)   ((REG >> POS)& BIT_MASK)

/*------------------- Functions Declarations Section ----------------------*/
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *_pin_config) ;
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status) ;
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic) ;
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic) ;
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config) ;
Std_ReturnType gpio_pin_initialize(const pin_config_t *_pin_config) ;



Std_ReturnType gpio_port_direction_initialize (uint8 direction_status);
Std_ReturnType gpio_port_get_direction_status(uint8 *direction_status);
Std_ReturnType gpio_port_write_logic(uint8 logic) ;
Std_ReturnType gpio_port_read_logic(uint8 *logic) ;
Std_ReturnType gpio_port_toggle_logic(void) ;



#endif /* HAL_GPIO_H_ */