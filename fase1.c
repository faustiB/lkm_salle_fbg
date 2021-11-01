#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/fs.h>
#include <linux/uaccess.h>


MODULE_LICENSE("FBG");


static unsigned int gpioLED1=23; //Hardcode del pin del led1
static unsigned int gpioLED2=24; //Hardcode del pin del led3

static bool led1On=0; //Bool para determinar si estaencendido o no. Se usa como apagado por defecto. 
static bool led2On=0; //Bool para determinar si estaencendido o no. Se usa como apagado por defecto. 

static unsigned int gpioBUT1=22; //Hardcode del pin del boton1
static unsigned int gpioBUT2=27; //Hardcode del pin del boton2
static unsigned int gpioBUT3=5; //Hardcode del pin del boton3
static unsigned int gpioBUT4=6; //Hardcode del pin del boton4

static int __init my_init(void) {
	//Inicializacion + check de los pines de los leds. 	
	printk(KERN_INFO "FASE 1 : Initializing Fase 1 LKM \n");
	if(!gpio_is_valid(gpioLED1) || !gpio_is_valid(gpioLED2) ||
 	   !gpio_is_valid(gpioBUT1) || !gpio_is_valid(gpioBUT2) ||
 	   !gpio_is_valid(gpioBUT3) || !gpio_is_valid(gpioBUT4) ){
		printk(KERN_INFO "FASE 1 :One of the LEDs Hardcoded it is not correct. Please check.  \n");
	}


	return 0;
}

static void __exit my_exit(void) {
	return ;
}

module_init(my_init);
module_exit(my_exit);
