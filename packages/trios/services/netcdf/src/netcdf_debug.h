/*-------------------------------------------------------------------------*/
/**
 *   @file netcdf_debug.h
 *
 *   @author Ron Oldfield (raoldfi\@sandia.gov)
 *   $Revision: 1640 $
 *   $Date: 2007-11-28 11:59:53 -0700 (Wed, 28 Nov 2007) $
 *
 */

#ifndef _NETCDF_DEBUG_H_
#define _NETCDF_DEBUG_H_

#include "Trios_logger.h"

#ifdef __cplusplus
extern "C" {
#endif

    extern log_level netcdf_debug_level;

///* Check for netcdf 4, if not, define some constants */
//#ifdef NC4_FIRST_ERROR
//
//#define USING_NETCDF4 1
//
//#else

#define NC_ENOTNC4  (-111)
#define NC_ENOGRP   (-125)

//#endif


#if defined(__STDC__) || defined(__cplusplus)

#else /* K&R C */

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif
