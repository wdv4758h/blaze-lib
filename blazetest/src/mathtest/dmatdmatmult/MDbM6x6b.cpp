//=================================================================================================
/*!
//  \file src/mathtest/dmatdmatmult/MDbM6x6b.cpp
//  \brief Source file for the MDbM6x6b dense matrix/dense matrix multiplication math test
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
   std::cout << "   Running 'MDbM6x6b'..." << std::endl;

   using blazetest::mathtest::TypeB;

   try
   {
      // Matrix type definitions
      typedef blaze::DynamicMatrix<TypeB>         MDb;
      typedef blaze::StaticMatrix<TypeB,6UL,6UL>  M6x6b;

      // Creator type definitions
      typedef blazetest::Creator<MDb>    CMDb;
      typedef blazetest::Creator<M6x6b>  CM6x6b;

      // Running the tests
      RUN_DMATDMATMULT_OPERATION_TEST( CMDb( 3UL, 6UL ), CM6x6b() );
      RUN_DMATDMATMULT_OPERATION_TEST( CMDb( 6UL, 6UL ), CM6x6b() );
      RUN_DMATDMATMULT_OPERATION_TEST( CMDb( 9UL, 6UL ), CM6x6b() );
   }
   catch( std::exception& ex ) {
      std::cerr << "\n\n ERROR DETECTED during dense matrix/dense matrix multiplication:\n"
                << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
//*************************************************************************************************
