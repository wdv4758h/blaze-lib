//=================================================================================================
/*!
//  \file src/mathtest/svecsveccross/VCbVCa.cpp
//  \brief Source file for the VCbVCa sparse vector/sparse vector cross product math test
//
//  Copyright (C) 2011 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. This library is free software; you can redistribute
//  it and/or modify it under the terms of the GNU General Public License as published by the
//  Free Software Foundation; either version 3, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
//  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//  See the GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along with a special
//  exception for linking and compiling against the Blaze library, the so-called "runtime
//  exception"; see the file COPYING. If not, see http://www.gnu.org/licenses/.
*/
//=================================================================================================


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <cstdlib>
#include <iostream>
#include <blaze/math/CompressedVector.h>
#include <blazetest/mathtest/Creator.h>
#include <blazetest/mathtest/svecsveccross/OperationTest.h>
#include <blazetest/system/MathTest.h>


//=================================================================================================
//
//  MAIN FUNCTION
//
//=================================================================================================

//*************************************************************************************************
int main()
{
   std::cout << "   Running 'VCbVCa'..." << std::endl;

   using blazetest::mathtest::TypeA;
   using blazetest::mathtest::TypeB;

   try
   {
      // Vector type definitions
      typedef blaze::CompressedVector<TypeB>  VCb;
      typedef blaze::CompressedVector<TypeA>  VCa;

      // Creator type definitions
      typedef blazetest::Creator<VCb>  CVCb;
      typedef blazetest::Creator<VCa>  CVCa;

      // Running tests with small vectors
      for( size_t i=0UL; i<=3UL; ++i ) {
         for( size_t j=0UL; j<=3UL; ++j ) {
            RUN_SVECSVECCROSS_OPERATION_TEST( CVCb( 3UL, i ), CVCa( 3UL, j ) );
         }
      }
   }
   catch( std::exception& ex ) {
      std::cerr << "\n\n ERROR DETECTED during sparse vector/sparse vector cross product:\n"
                << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
//*************************************************************************************************
