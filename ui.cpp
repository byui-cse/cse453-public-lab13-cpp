/********************************************************************
 * Program:
 *    Lab 13: Create a cipher
 * Author:
 *    Br. Helfrich, Br. Phillips
 * Summary:
 *    This program will be able to encrypt and decrypt text using a
 *    cipher.
 *********************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "cipher.h"   // Defines base cipher class
#include "example.h"  // Example caesar cipher
#include "cipher01.h" // Your cipher goes here

using namespace std;

/************************************************************
 * GET REPORT
 * generates the report for the selected cipher
 ************************************************************/
void getReport(Cipher& cipher)
{
   string plaintext;
   string password;

   // get the text
   cout << "Please enter the text: ";
   getline(cin, plaintext);
   if (plaintext.compare("") == 0)
      plaintext = "I am just \"plain\" text ~ 12345.";

   // get the password
   cout << "Please enter the password: ";
   getline(cin, password);
   if (password.compare("") == 0)
   {
      password = "P@55w0rd!";
      cout << "Default password: " << password << endl;
   }

   string encrypted = cipher.encrypt(plaintext, password);
   string decrypted = cipher.decrypt(encrypted, password);
   cout << "==================================="
        << "===================================\n";
   cout << "Cipher Name:     "
        << cipher.getCipherName() << endl;
   cout << "Cipher Author:   "
        << cipher.getAuthor() << endl;
   cout << "==================================="
        << "===================================\n";
   cout << "Citation:\n"
        << cipher.getCipherCitation() << endl;
   cout << "==================================="
        << "===================================\n";
   cout << "Plain text:    " << plaintext << endl;
   cout << "Cipher text:   " << encrypted << endl;
   cout << "Decipher text: " << decrypted << endl;
   cout << "==================================="
        << "===================================\n";
   cout << "Pseudocode:\n"
        << cipher.getPseudocode() << endl;
}

/********************************************************************
 * MAIN
 * drives the UI class
 ********************************************************************/
int main()
{
   Cipher* cipher = new Example; // TODO: Replace with your cipher

   getReport(*cipher); // generate the report

   delete cipher;
   return 0;
}