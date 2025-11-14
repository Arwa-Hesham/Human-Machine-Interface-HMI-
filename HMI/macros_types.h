#ifndef MACROS_TYPES_H_ 
#define MACROS_TYPES_H_

/* Bit macros */

#define SetBit(REG,BIT)       (REG|=(1<<BIT))           /* Set a certain bit in any register */
#define ClearBit(REG,BIT)     (REG&=(~(1<<BIT)))        /* Clear a certain bit in any register */
#define BitIsSet(REG, BIT)    (REG & (1 << BIT))        /* Check if a specific bit is set in any register and return true if yes */
#define BitIsClear(REG, BIT)  (!(REG & (1 << BIT)))     /* Check if a specific bit is clear in any register and return true if yes */
#define GETBIT(REG, BIT)      (((REG) >> (BIT)) & 1)    /* Get the value of the bit  */

/* Common constants */

#ifndef NULL
#define NULL                 ((void*)0)
#endif

#define OutputPort           0xFF
#define InputPort            0x00


/* Type definitions */

typedef unsigned char         uint8;          /*           0 .. 255              */
typedef signed char           sint8;          /*        -128 .. +127             */
typedef unsigned short        uint16;         /*           0 .. 65535            */
typedef signed short          sint16;         /*      -32768 .. +32767           */
typedef unsigned long         uint32;         /*           0 .. 4294967295       */
typedef signed long           sint32;         /* -2147483648 .. +2147483647      */
typedef unsigned long long    uint64;         /*       0 .. 18446744073709551615  */
typedef signed long long      sint64;         /* -9223372036854775808 .. 9223372036854775807 */
typedef float                 float32;
typedef double                float64;

#endif /* MACROS_TYPES_H_ */


