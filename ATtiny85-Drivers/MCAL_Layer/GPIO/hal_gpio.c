/*
 * hal_gpio.c
 *
 * Created: 10/5/2023 1:49:42 PM
 *  Author: Abdallah magdy
 */ 


#include "GPIO/hal_gpio.h"
#if(PIN_CONFIGURATION  == CONFIGURATION_ENABLE)
Std_ReturnType gpio_pin_direction_initialize(const pin_config_t *_pin_config) {
	Std_ReturnType ret_val = E_OK ;
	if((NULL == _pin_config) || (_pin_config->pin_index > PIN_MAX_INDEX)){
		ret_val = E_NOT_OK ;
	}
	else{
		switch (_pin_config->direction){
			case GPIO_DIRECTION_INPUT :
				CLEAR_BIT(DDRB, _pin_config->pin_index) ;
				break ;
			case GPIO_DIRECTION_OUTPUT :
				SET_BIT(DDRB, _pin_config->pin_index) ;
				break;
			default: ret_val = E_NOT_OK ; break ;
		}
	}
	return ret_val ;
}
#endif


#if(PIN_CONFIGURATION  == CONFIGURATION_ENABLE)
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status){
	Std_ReturnType ret_val = E_OK ;
	if((NULL == _pin_config) || (NULL == direction_status) ||(_pin_config->pin_index > PIN_MAX_INDEX)){
		ret_val = E_NOT_OK ;
	}
	else{
		*direction_status = READ_BIT(DDRB,_pin_config->pin_index ) ;
	}
	return ret_val ;
}
#endif


#if(PIN_CONFIGURATION  == CONFIGURATION_ENABLE)
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config, logic_t logic){
	Std_ReturnType ret_val = E_OK ;
	if((NULL == _pin_config) || (_pin_config->pin_index > PIN_MAX_INDEX)){
		ret_val = E_NOT_OK ;
	}
	else{
		switch (logic){
			case GPIO_LOGIC_LOW:
			CLEAR_BIT(PORTB, _pin_config->pin_index) ;
			break ;
			case GPIO_LOGIC_HIGH :
			SET_BIT(PORTB, _pin_config->pin_index) ;
			break;
			default: ret_val = E_NOT_OK ; break ;
		}
	}
	return ret_val ;
}
#endif


#if(PIN_CONFIGURATION  == CONFIGURATION_ENABLE)
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config, logic_t *logic){
	Std_ReturnType ret_val = E_OK ;
	if((NULL == _pin_config) || (NULL == logic) ||(_pin_config->pin_index > PIN_MAX_INDEX)){
		ret_val = E_NOT_OK ;
	}
	else{
		*logic = READ_BIT(PINB, _pin_config->pin_index) ;

	}
	return ret_val ;
}
#endif


#if(PIN_CONFIGURATION  == CONFIGURATION_ENABLE)
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config){
	Std_ReturnType ret_val = E_OK ;
	if((NULL == _pin_config) || (_pin_config->pin_index > PIN_MAX_INDEX)){
		ret_val = E_NOT_OK ;
	}
	else{
		TOGGLE_BIT(PORTB, _pin_config->pin_index);
	}
	return ret_val ;
}
#endif


#if(PIN_CONFIGURATION  == CONFIGURATION_ENABLE)
Std_ReturnType gpio_pin_initialize(const pin_config_t *_pin_config){
	Std_ReturnType ret_val = E_OK ;
	if((NULL == _pin_config) || (_pin_config->pin_index > PIN_MAX_INDEX)){
		ret_val = E_NOT_OK ;
	}
	else{
		ret_val = gpio_pin_direction_initialize(_pin_config);
		ret_val = gpio_pin_write_logic(_pin_config, _pin_config->logic);
	}
	return ret_val ;
}
#endif



#if(PORT_CONFIGURATION  == CONFIGURATION_ENABLE)
Std_ReturnType gpio_port_direction_initialize (uint8 direction_status){
	Std_ReturnType ret_val = E_OK ;
	if(direction_status > 0xFF){
		ret_val = E_NOT_OK ;
	}
	else{
		DDRB = direction_status ;
	}
	return ret_val ;
}
#endif


#if(PORT_CONFIGURATION  == CONFIGURATION_ENABLE)
Std_ReturnType gpio_port_get_direction_status(uint8 *direction_status){
	Std_ReturnType ret_val = E_OK ;
	if(NULL == direction_status ){
		ret_val = E_NOT_OK ;
	}
	else{
		*direction_status = DDRB ;
	}
	return ret_val ;
}
#endif


#if(PORT_CONFIGURATION  == CONFIGURATION_ENABLE)
Std_ReturnType gpio_port_write_logic(uint8 logic){
	Std_ReturnType ret_val = E_OK ;
	if(logic > 0xFF){
		ret_val = E_NOT_OK ;
	}
	else{
		PORTB = logic ;
	}
	return ret_val ;	
}
#endif


#if(PORT_CONFIGURATION  == CONFIGURATION_ENABLE)
Std_ReturnType gpio_port_read_logic(uint8 *logic){
	Std_ReturnType ret_val = E_OK ;
	if(NULL == logic ){
		ret_val = E_NOT_OK ;
	}
	else{
		*logic = PINB ;
	}
	return ret_val ;
}
#endif	


#if(PORT_CONFIGURATION  == CONFIGURATION_ENABLE)
Std_ReturnType gpio_port_toggle_logic(void){
	Std_ReturnType ret_val = E_OK ;
	PORTB ^= PORT_MASK ;
	return ret_val ;
}
#endif
