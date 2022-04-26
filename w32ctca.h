////////////////////////////////////////////////////////////////////////////////////
//    w32ctca.h    CTCI-W32 (Channel to Channel link to Win32 TCP/IP stack)
////////////////////////////////////////////////////////////////////////////////////
// (c) Copyright "Fish" (David B. Trout), 2002-2009. Released under the Q Public License
// (http://www.hercules-390.org/herclic.html) as modifications to Hercules.
////////////////////////////////////////////////////////////////////////////////////

// $Id: w32ctca.h 5368 2009-06-02 03:58:49Z fish $
//
// $Log$
// Revision 1.16  2007/11/30 14:54:33  jmaynard
// Changed conmicro.cx to hercules-390.org or conmicro.com, as needed.
//
// Revision 1.15  2007/06/23 00:04:19  ivan
// Update copyright notices to include current year (2007)
//
// Revision 1.14  2006/12/08 09:43:32  jj
// Add CVS message log
//

#ifndef _W32CTCA_H_
#define _W32CTCA_H_

#if defined(OPTION_W32_CTCI)

#include "tt32api.h"                            // (#define TUNTAP32_DLLNAME)

#define MAX_TT32_DLLNAMELEN  (512)
#define DEF_TT32_DLLNAME     TUNTAP32_DLLNAME   // (from tt32api.h)

#ifndef   MODULESDIR
  #define MODULESDIR         "."                // (i.e. "Current Directory")
#endif

extern char   g_tt32_dllname   [MAX_TT32_DLLNAMELEN];

extern void tt32_init
(
);

extern int          tt32_open                 ( char* pszGatewayDevice, int iFlags );
extern int          tt32_read                 ( int fd, u_char* buffer, u_long size );
extern int          tt32_write                ( int fd, u_char* buffer, u_long size );
extern int          tt32_close                ( int fd );
extern int          tt32_ioctl                ( int fd, int iRequest, char* argp );
extern const char*  tt32_get_default_iface    ();

extern int  display_tt32_stats ( int fd );
extern void enable_tt32_debug_tracing( int enable );

// (boolean helper function)
extern int tt32_build_herc_iface_mac ( BYTE* out_mac, const BYTE* in_ip );

#endif // defined(OPTION_W32_CTCI)

#endif // _W32CTCA_H_
