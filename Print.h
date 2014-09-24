/*
  Print.h - Base class that provides print() and println()
  Copyright (c) 2008 David A. Mellis.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

Modified 20140420 by circulosmeos for RPi compatibility
                      circulosmeos.wordpress.com
   
*/

#ifndef Print_h
#define Print_h

#include <inttypes.h>
#include <stdio.h> // for size_t
#include <string.h>// for strlen    //<--- for RPi compatibility

//#include "WString.h"              //<--- for RPi compatibility
//#include "Printable.h"            //<--- for RPi compatibility

#include "arduPi.h"                 //<--- for RPi compatibility
/*
#define DEC 10                      //<--- for RPi compatibility
#define HEX 16                      //<--- for RPi compatibility
#define OCT 8                       //<--- for RPi compatibility
#define BIN 2                       //<--- for RPi compatibility
*/
#define DEC_Print 10                 //<--- for RPi compatibility
#define HEX_Print 16                 //<--- for RPi compatibility
#define OCT_Print 8                  //<--- for RPi compatibility
#define BIN_Print 2                  //<--- for RPi compatibility

class Print
{
  private:
    int write_error;
    size_t printNumber(unsigned long, uint8_t);
    size_t printFloat(double, uint8_t);
  protected:
    void setWriteError(int err = 1) { write_error = err; }
  public:
    Print() : write_error(0) {}
  
    int getWriteError() { return write_error; }
    void clearWriteError() { setWriteError(0); }
  
    virtual size_t write(uint8_t) = 0;
    size_t write(const char *str) { return write((const uint8_t *)str, strlen(str)); }
    virtual size_t write(const uint8_t *buffer, size_t size);
    
    //size_t print(const __FlashStringHelper *);            //<--- for RPi compatibility
    //size_t print(const String &);                         //<--- for RPi compatibility
    size_t print(const char[]);
    size_t print(char);
    size_t print(unsigned char, int = DEC_Print);
    size_t print(int, int = DEC_Print);
    size_t print(unsigned int, int = DEC_Print);
    size_t print(long, int = DEC_Print);
    size_t print(unsigned long, int = DEC_Print);
    size_t print(double, int = 2);
    //size_t print(const Printable&);                       //<--- for RPi compatibility

    //size_t println(const __FlashStringHelper *);          //<--- for RPi compatibility
    //size_t println(const String &s);                      //<--- for RPi compatibility
    size_t println(const char[]);
    size_t println(char);
    size_t println(unsigned char, int = DEC_Print);
    size_t println(int, int = DEC_Print);
    size_t println(unsigned int, int = DEC_Print);
    size_t println(long, int = DEC_Print);
    size_t println(unsigned long, int = DEC_Print);
    size_t println(double, int = 2);
    //size_t println(const Printable&);                     //<--- for RPi compatibility
    size_t println(void);
};

#endif
