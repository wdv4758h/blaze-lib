//=================================================================================================
/*!
//  \file src/mathtest/dmatdmatmult/M5x5aMDa.cpp
//  \brief Source file for the M5x5aMDa dense matrix/dense matrix multiplication math test
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
#include <blaze/math/DynamicMatrix.h>
#include <blaze/math/StaticMatrix.h>
#include <blazetest/mathtest/Creator.h>
#include <blazetest/mathtest/dmatdmatmult/OperationTest.h>
#include <blazetest/system/MathTest.h>


//=================================================================================================
//
//  MAIN FUNCTION
//
//=================================================================================================

//*************************************************************************************************
int main()
{
   std::cout << "   Running 'M5x5aMDa'..." << std::endl;

   using blazetest::mathtest::TypeA;

   try
   {
      // Matrix type definitions
      typedef blaze::StaticMatrix<TypeA,5UL,5UL>  M5x5a;
      typedef blaze::DynamicMatrix<TypeA>         MDa;

      // Creator type definitions
      typedef blazetest::Creator<M5x5a>  CM5x5a;
      typedef blazetest::Creator<MDa>    CMDa;

      // Running the tests
      for( size_t i=0UL; i<=8UL; ++i ) {
         RUN_DMATDMATMULT_OPERATION_TEST( CM5x5a(), CMDa( 5UL, i ) );
      }
   }
   catch( std::exception& ex ) {
      std::cerr << "\n\n ERROR DETECTED during dense matrix/dense matrix multiplication:\n"
                << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
//*************************************************************************************************
