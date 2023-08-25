/*
 *	Module: Common Macros
 *
 * File Name: Common Macros.h
 *
 * Description: Commonly used Macros
 *
 * Author: Muhammed Alshafie
*/

#ifndef COMMON_MACROS_H  // Check if COMMON_MACROS_H is not defined
#define COMMON_MACROS_H  // If not defined, define it

/* Set a certain bit in any register */
#define SET_BIT(REG,BIT)	((REG) |= (1U << (BIT)))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG,BIT)	((REG) &= ~(1U << (BIT)))

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG,BIT) ((REG) ^= (1U << (BIT)))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num))	)

/* Read the value of a bit in a register */
#define READ_BIT(REG, BIT) (((REG) >> (BIT)) & 0x01U)

/* Check if a bit is set (1) in a register */
#define IS_BIT_SET(REG, BIT) (((REG) & (1U << (BIT))) != 0U)

/* Check if a bit is clear (0) in a register */
#define IS_BIT_CLEAR(REG, BIT) (((REG) & (1U << (BIT))) == 0U)

/*
   b. Generalized macro to read a group of bits at a given offset in a register.
   Parameters:
     - REG: The register from which to read bits.
     - OFFSET: The starting bit position of the group of bits.
     - COUNT: The number of bits to read.
   Returns:
     - The value of the specified group of bits.
*/
#define READ_BITS(REG, OFFSET, COUNT) ((REG >> OFFSET) & ((1 << COUNT) - 1))

/*
   c. Macro to write a bit in a register.
   Parameters:
     - REG: The register in which to write the bit.
     - BIT: The bit position to write (0-31).
     - VALUE: The value to write (0 or 1).
*/
#define WRITE_BIT(REG, BIT, VALUE) (REG = (REG & ~(1 << BIT)) | (VALUE << BIT))

/*
   d. Generalized macro to write a value into a group of bits at a given offset in a register.
   Parameters:
     - REG: The register in which to write the bits.
     - OFFSET: The starting bit position of the group of bits.
     - COUNT: The number of bits to write.
     - VALUE: The value to write into the specified group of bits.
*/
#define WRITE_BITS(REG, OFFSET, COUNT, VALUE) (REG = (REG & ~(((1 << COUNT) - 1) << OFFSET)) | (VALUE << OFFSET))

/*
   Multi-line macro to set or clear a bit in a register.
   Parameters:
     - REG: The register in which to set or clear the bit.
     - BIT: The bit position to set or clear (0-31).
     - VALUE: The value to set (1 to set, 0 to clear).
*/
#define SET_CLEAR_BIT(REG, BIT, VALUE) \
    do { \
        if (VALUE) { \
            REG |= (1 << BIT); /* Set the bit */ \
        } else { \
            REG &= ~(1 << BIT); /* Clear the bit */ \
        } \
    } while (0)


#endif COMMON_MACROS_H /* End of ifndef COMMON_MACROS_H */