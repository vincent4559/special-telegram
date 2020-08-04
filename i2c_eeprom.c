/*
 * "Copyright (c) 2008 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
 * All rights reserved.
 * (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
 * (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
 * (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the authors appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS"
 * HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 *
 * Please maintain this header in its entirety when copying/modifying
 * these files.
 *
 *
 */
#include "pic24_all.h"
#include <stdio.h>

/** \file
 Simple I2C exercises using an LC515 EEPROM
*/

#define EEPROM 0xAA  //LC515 address assuming both address pins tied low.

uint8_t readOneByteCurrentAddress(void);
uint8_t readOneByteSpecificAddress(uint16_t u16_address);
void writeOneByteSpecificAddress(uint16_t u16_address, uint8_t u8_byte);


uint16_t getAddress() {
  char buf[16];
  uint16_t u16_val;
  outString("Enter an address in hex (format @@@@): ");
  inStringEcho(buf,16);
  sscanf(buf,"%x",&u16_val);
  return(u16_val);
}

uint8_t getByte() {
  char buf[16];
  uint16_t u16_val;
  outString("Enter a byte in hex (format @@): ");
  inStringEcho(buf,16);
  sscanf(buf,"%x",&u16_val);
  return(u16_val & 0xFF);
}

uint8_t readOneByteCurrentAddress(void) {
  uint8_t val;
  startI2C1();             //start the I2C transaction
  putI2C1(EEPROM | 0x01);    //send the I2C device address; set the LSb so that this is a READ
  val = getI2C1(1);        //read the back, send a NAK to indicate finish reading; NAK==1, ACK==0
  stopI2C1();              //end the transaction
  return(val);             //return the byte that was read
}

//returns the byte read
uint8_t  readOneByteSpecificAddress(uint16_t u16_address) {
    
    uint8_t val;
    
    uint8_t BLK = 0x00;
    if (u16_address >= 0x8000){
        BLK = 0x08;
    }
    
    
    startI2C1();
    putI2C1(EEPROM | 0x00 | BLK);
    putI2C1(u16_address >> 8);
    putI2C1(u16_address & 0x00FF);
    
    rstartI2C1();
    putI2C1(EEPROM | 0x01 | BLK);
    val = getI2C1(1);
    
    stopI2C1();
    return(val);
 
}

void writeOneByteSpecificAddress(uint16_t u16_address, uint8_t u8_byte) {
    uint8_t BLK = 0x00;
    if (u16_address >= 0x8000){
        BLK = 0x08;
    }
    startI2C1();
    putI2C1(EEPROM | 0x00 | BLK);
    putI2C1(u16_address >> 8);
    putI2C1(u16_address & 0x00FF);
    putI2C1(u8_byte);
    stopI2C1();
 

}

int main (void) {
  configBasic(HELLO_MSG);
  char c;
  uint16_t u16_address;
  uint8_t u8_byte,u8_byte2;
 

  CONFIG_RB14_AS_DIG_OUTPUT();
  configI2C1(400);            //configure I2C for 400 KHz
  //print menu
  while (1) {
    outString("1. Read 1 byte from current address\n");
    outString("2. Read 1 byte from specific address\n");
    outString("3. Write (and verify) 1 byte from specific address\n");
    outString("Enter menu choice: ");
    c = inCharEcho();
    outChar('\n');
    if (c == '1') {
      u8_byte = readOneByteCurrentAddress();
      printf("\nThe byte read from the current address is 0x%02x ('%c')\n", u8_byte, u8_byte);
    } else if (c == '2') {
      u16_address = getAddress();
      u8_byte = readOneByteSpecificAddress(u16_address);
      printf("\nThe byte read from address: 0x%04x is 0x%02x ('%c')\n", u16_address,u8_byte,u8_byte);
    } else if (c == '3') {
      u16_address = getAddress();
      u8_byte = getByte();
      writeOneByteSpecificAddress(u16_address,u8_byte);
      DELAY_MS(20); //delay to ensure that write finishes
      u8_byte2 = readOneByteSpecificAddress(u16_address);
      if (u8_byte == u8_byte2) {
        printf("\nThe write of byte 0x%02x ('%c') to address: 0x%04x succeeded!\n",u8_byte,u8_byte, u16_address);
      } else  {
        printf("\nThe write of byte 0x%02x ('%c') to address: 0x%04x FAILED, read byte: 0x%02x ('%c') after write!\n",u8_byte,u8_byte, u16_address,u8_byte2,u8_byte2);
      }
    }


  }

  return 0;
}//end main
