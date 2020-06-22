#include <assert.h>
#include "String.h"
#include <string.h>

void testGetLength ()
{
    char string[14+1] = "Test GetLength";
    assert (GetLength(string) == 14);

    char stringEmpty[1]= "";
    assert (GetLength(stringEmpty)==0);
}

void testIsEmpty ()
{
    char string[12+1] = "Test IsEmpty";
    assert (!IsEmpty(string));

    char stringEmpty[1]= "";
    assert (IsEmpty(stringEmpty));
}

void testPower ()
{
    int power = 4;
    char string[9+1] = "TestPower";
    assert (Power(string,power) == "TestPowerTestPowerTestPowerTestPower"); 

    int power2;
    char string2[1] = "";
    assert (Power(string,power2)== "");
}

void testCharInIt ()
{
    char string[22+1] = "Test Char Is In String";
    char charIn = 'e';
    assert (strchr(string, charIn));

    char string2[22+1] = "Test Char Is In String";
    char charIn2 = 'o';
    assert (strchr(string2,charIn2)==false);
}