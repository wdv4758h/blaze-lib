//=================================================================================================
/*!
//  \file src/classic/Daxpy.cpp
//  \brief Source file for the classic daxpy product kernel
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

#include <iostream>
#include <blaze/util/Timing.h>
#include <blazemark/classic/Daxpy.h>
#include <blazemark/classic/init/Vector.h>
#include <blazemark/classic/Vector.h>
#include <blazemark/system/Config.h>


namespace blazemark {

namespace classic {

//=================================================================================================
//
//  KERNEL FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Classic daxpy product kernel.
//
// \param N The size of the vectors for the daxpy product.
// \param steps The number of iteration steps to perform.
// \return Minimum runtime of the kernel function.
//
// This kernel function implements the daxpy product by means of classic C++ operator overloading.
*/
double daxpy( size_t N, size_t steps )
{
   using ::blazemark::element_t;

   ::blaze::setSeed( seed );

   ::blazemark::classic::Vector<element_t> a( N ), b( N );
   ::blaze::timing::WcTimer timer;

   init( a );
   b.reset();

   for( size_t rep=0UL; rep<reps; ++rep )
   {
      timer.start();
      for( size_t step=0UL; step<steps; ++step ) {
         b += a * element_t(3);
      }
      timer.end();

      if( b.size() != N )
         std::cerr << " Line " << __LINE__ << ": ERROR detected!!!\n";

      if( timer.last() > maxtime )
         break;
   }

   const double minTime( timer.min()     );
   const double avgTime( timer.average() );

   if( minTime * ( 1.0 + deviation*0.01 ) < avgTime )
      std::cerr << " Classic kernel 'daxpy': Time deviation too large!!!\n";

   return minTime;
}
//*************************************************************************************************

} // namespace classic

} // namespace blazemark
