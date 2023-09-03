/* 
 * File:   Bit_Math.h
 *
 * Author: Mohamed Sameh
 *
 */
/* Section : Includes */

/* Section : Macro Declarations */
#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)    reg^=(1<<bit)
#define READ_BIT(reg,bit)    ((reg&(1<<bit))>>bit)
#define IS_BIT_SET(reg,bit)  (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)  !((reg&(1<<bit))>>bit)

/* Section : Macro Functions Declarations */


/* Section : Data Types Declarations  */


/* Section : Functions Declarations */



