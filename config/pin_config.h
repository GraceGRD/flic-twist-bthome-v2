#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

// $[CMU]
// [CMU]$

// $[LFXO]
// [LFXO]$

// $[PRS.ASYNCH0]
// [PRS.ASYNCH0]$

// $[PRS.ASYNCH1]
// [PRS.ASYNCH1]$

// $[PRS.ASYNCH2]
// [PRS.ASYNCH2]$

// $[PRS.ASYNCH3]
// [PRS.ASYNCH3]$

// $[PRS.ASYNCH4]
// [PRS.ASYNCH4]$

// $[PRS.ASYNCH5]
// [PRS.ASYNCH5]$

// $[PRS.ASYNCH6]
// [PRS.ASYNCH6]$

// $[PRS.ASYNCH7]
// [PRS.ASYNCH7]$

// $[PRS.ASYNCH8]
// [PRS.ASYNCH8]$

// $[PRS.ASYNCH9]
// [PRS.ASYNCH9]$

// $[PRS.ASYNCH10]
// [PRS.ASYNCH10]$

// $[PRS.ASYNCH11]
// [PRS.ASYNCH11]$

// $[PRS.SYNCH0]
// [PRS.SYNCH0]$

// $[PRS.SYNCH1]
// [PRS.SYNCH1]$

// $[PRS.SYNCH2]
// [PRS.SYNCH2]$

// $[PRS.SYNCH3]
// [PRS.SYNCH3]$

// $[GPIO]
// [GPIO]$

// $[TIMER0]
// [TIMER0]$

// $[TIMER1]
// [TIMER1]$

// $[TIMER2]
// [TIMER2]$

// $[TIMER3]
// [TIMER3]$

// $[TIMER4]
// [TIMER4]$

// $[USART0]
// USART0 RX on PC03
#ifndef USART0_RX_PORT                          
#define USART0_RX_PORT                           gpioPortC
#endif
#ifndef USART0_RX_PIN                           
#define USART0_RX_PIN                            3
#endif

// USART0 TX on PC05
#ifndef USART0_TX_PORT                          
#define USART0_TX_PORT                           gpioPortC
#endif
#ifndef USART0_TX_PIN                           
#define USART0_TX_PIN                            5
#endif

// [USART0]$

// $[USART1]
// USART1 TX on PA05
#ifndef USART1_TX_PORT                          
#define USART1_TX_PORT                           gpioPortA
#endif
#ifndef USART1_TX_PIN                           
#define USART1_TX_PIN                            5
#endif

// [USART1]$

// $[I2C1]
// [I2C1]$

// $[PDM]
// [PDM]$

// $[LETIMER0]
// [LETIMER0]$

// $[IADC0]
// [IADC0]$

// $[I2C0]
// [I2C0]$

// $[EUART0]
// [EUART0]$

// $[PTI]
// [PTI]$

// $[MODEM]
// [MODEM]$

// $[CUSTOM_PIN_NAME]
#ifndef VBAT_PORT                               
#define VBAT_PORT                                gpioPortA
#endif
#ifndef VBAT_PIN                                
#define VBAT_PIN                                 0
#endif

#ifndef _PORT                                   
#define _PORT                                    gpioPortA
#endif
#ifndef _PIN                                    
#define _PIN                                     1
#endif

#ifndef ROT_BL_PORT                             
#define ROT_BL_PORT                              gpioPortA
#endif
#ifndef ROT_BL_PIN                              
#define ROT_BL_PIN                               5
#endif

#ifndef ROT_BR_PORT                             
#define ROT_BR_PORT                              gpioPortA
#endif
#ifndef ROT_BR_PIN                              
#define ROT_BR_PIN                               6
#endif

#ifndef BUTTON_PORT                             
#define BUTTON_PORT                              gpioPortB
#endif
#ifndef BUTTON_PIN                              
#define BUTTON_PIN                               0
#endif

#ifndef COM_LED1u_TO_LED6u_PORT                 
#define COM_LED1u_TO_LED6u_PORT                  gpioPortB
#endif
#ifndef COM_LED1u_TO_LED6u_PIN                  
#define COM_LED1u_TO_LED6u_PIN                   1
#endif

#ifndef COM_LED7u_TO_LED12u_PORT                
#define COM_LED7u_TO_LED12u_PORT                 gpioPortB
#endif
#ifndef COM_LED7u_TO_LED12u_PIN                 
#define COM_LED7u_TO_LED12u_PIN                  2
#endif

#ifndef LED1u_LED7u_PORT                        
#define LED1u_LED7u_PORT                         gpioPortC
#endif
#ifndef LED1u_LED7u_PIN                         
#define LED1u_LED7u_PIN                          0
#endif

#ifndef LED2u_LED8u_PORT                        
#define LED2u_LED8u_PORT                         gpioPortC
#endif
#ifndef LED2u_LED8u_PIN                         
#define LED2u_LED8u_PIN                          1
#endif

#ifndef LED3u_LED9u_PORT                        
#define LED3u_LED9u_PORT                         gpioPortC
#endif
#ifndef LED3u_LED9u_PIN                         
#define LED3u_LED9u_PIN                          2
#endif

#ifndef LED4u_LED10u_PORT                       
#define LED4u_LED10u_PORT                        gpioPortC
#endif
#ifndef LED4u_LED10u_PIN                        
#define LED4u_LED10u_PIN                         3
#endif

#ifndef LED5u_LED12u_PORT                       
#define LED5u_LED12u_PORT                        gpioPortC
#endif
#ifndef LED5u_LED12u_PIN                        
#define LED5u_LED12u_PIN                         4
#endif

#ifndef LED12u_LED6u_PORT                       
#define LED12u_LED6u_PORT                        gpioPortC
#endif
#ifndef LED12u_LED6u_PIN                        
#define LED12u_LED6u_PIN                         5
#endif

// [CUSTOM_PIN_NAME]$

#endif // PIN_CONFIG_H

