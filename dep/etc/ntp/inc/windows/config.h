/* config.h.in.  Generated from configure.ac by autoheader.  */

#define SYS_WINNT 1

/* Define if building universal (internal helper macro) */
#undef AC_APPLE_UNIVERSAL_BUILD

/* Is adjtime() accurate? */
#undef ADJTIME_IS_ACCURATE

/* CHU audio/decoder? */
#undef AUDIO_CHU

/* Declare char *sys_errlist array */
#undef CHAR_SYS_ERRLIST

/* ACTS modem service */
#undef CLOCK_ACTS

/* Arbiter 1088A/B GPS receiver */
#undef CLOCK_ARBITER

/* ARCRON support? */
#undef CLOCK_ARCRON_MSF

/* Austron 2200A/2201A GPS receiver? */
#undef CLOCK_AS2201

/* PPS interface? */
#undef CLOCK_ATOM

/* Datum/Bancomm bc635/VME interface? */
#undef CLOCK_BANC

/* Chronolog K-series WWVB receiver? */
#undef CLOCK_CHRONOLOG

/* CHU modem/decoder */
#undef CLOCK_CHU

/* Diems Computime Radio Clock? */
#undef CLOCK_COMPUTIME

/* Datum Programmable Time System? */
#undef CLOCK_DATUM

/* ELV/DCF7000 clock? */
#undef CLOCK_DCF7000

/* Dumb generic hh:mm:ss local clock? */
#undef CLOCK_DUMBCLOCK

/* Forum Graphic GPS datating station driver? */
#undef CLOCK_FG

/* TrueTime GPS receiver/VME interface? */
#undef CLOCK_GPSVME

/* Heath GC-1000 WWV/WWVH receiver? */
#undef CLOCK_HEATH

/* HOPF 6021 clock? */
#undef CLOCK_HOPF6021

/* HOPF PCI clock device? */
#undef CLOCK_HOPF_PCI

/* HOPF serial clock device? */
#undef CLOCK_HOPF_SERIAL

/* HP 58503A GPS receiver? */
#undef CLOCK_HPGPS

/* IRIG audio decoder? */
#undef CLOCK_IRIG

/* JJY receiver? */
#undef CLOCK_JJY

/* Rockwell Jupiter GPS clock? */
#undef CLOCK_JUPITER

/* Leitch CSD 5300 Master Clock System Driver? */
#undef CLOCK_LEITCH

/* local clock reference? */
#undef CLOCK_LOCAL

/* Meinberg clocks */
#undef CLOCK_MEINBERG

/* Magnavox MX4200 GPS receiver */
#undef CLOCK_MX4200

/* NeoClock4X */
#undef CLOCK_NEOCLOCK4X

/* NMEA GPS receiver */
#undef CLOCK_NMEA

/* Motorola UT Oncore GPS */
#undef CLOCK_ONCORE

/* Palisade clock */
#undef CLOCK_PALISADE

/* PARSE driver interface */
#undef CLOCK_PARSE

/* Conrad parallel port radio clock */
#undef CLOCK_PCF

/* PCL 720 clock support */
#undef CLOCK_PPS720

/* PST/Traconex 1020 WWV/WWVH receiver */
#undef CLOCK_PST

/* DCF77 raw time code */
#undef CLOCK_RAWDCF

/* RCC 8000 clock */
#undef CLOCK_RCC8000

/* RIPE NCC Trimble clock */
#undef CLOCK_RIPENCC

/* Schmid DCF77 clock */
#undef CLOCK_SCHMID

/* clock thru shared memory */
#undef CLOCK_SHM

/* Spectracom 8170/Netclock/2 WWVB receiver */
#undef CLOCK_SPECTRACOM

/* KSI/Odetics TPRO/S GPS receiver/IRIG interface */
#undef CLOCK_TPRO

/* Trimble GPS receiver/TAIP protocol */
#undef CLOCK_TRIMTAIP

/* Trimble GPS receiver/TSIP protocol */
#undef CLOCK_TRIMTSIP

/* Kinemetrics/TrueTime receivers */
#undef CLOCK_TRUETIME

/* TrueTime 560 IRIG-B decoder? */
#undef CLOCK_TT560

/* Ultralink M320 WWVB receiver? */
#undef CLOCK_ULINK

/* VARITEXT protocol */
#undef CLOCK_VARITEXT

/* WHARTON 400A Series protocol */
#undef CLOCK_WHARTON_400A

/* WWV audio driver */
#undef CLOCK_WWV

/* Zyfer GPStarplus */
#undef CLOCK_ZYFER

/* Enable ntpd debugging code? */
#undef DEBUG

/* Enable processing time debugging? */
#undef DEBUG_TIMING

/* Declaration style */
#undef DECL_ADJTIME_0

/* Declaration style */
#undef DECL_BCOPY_0

/* Declaration style */
#undef DECL_BZERO_0

/* Declaration style */
#undef DECL_CFSETISPEED_0

/* Declare errno? */
#undef DECL_ERRNO

/* Declaration style */
#undef DECL_HSTRERROR_0

/* Declare h_errno? */
#undef DECL_H_ERRNO

/* Declaration style */
#undef DECL_INET_NTOA_0

/* Declaration style */
#undef DECL_IOCTL_0

/* Declaration style */
#undef DECL_IPC_0

/* Declaration style */
#undef DECL_MEMMOVE_0

/* Declaration style */
#undef DECL_MKSTEMP_0

/* Declaration style */
#undef DECL_MKTEMP_0

/* Declaration style */
#undef DECL_NLIST_0

/* Declaration style */
#undef DECL_PLOCK_0

/* Declaration style */
#undef DECL_RENAME_0

/* Declaration style */
#undef DECL_SELECT_0

/* Declaration style */
#undef DECL_SETITIMER_0

/* Declaration style */
#undef DECL_SETPRIORITY_0

/* Declaration style */
#undef DECL_SETPRIORITY_1

/* Declaration style */
#undef DECL_SIGVEC_0

/* Declaration style */
#undef DECL_STDIO_0

/* Declaration style */
#undef DECL_STIME_0

/* Declaration style */
#undef DECL_STIME_1

/* Declaration style */
#undef DECL_STRERROR_0

/* Declaration style */
#undef DECL_STRTOL_0

/* Declare syscall()? */
#undef DECL_SYSCALL

/* Declaration style */
#undef DECL_SYSLOG_0

/* Declaration style */
#undef DECL_TIMEOFDAY_0

/* Declaration style */
#undef DECL_TIME_0

/* Declaration style */
#undef DECL_TOLOWER_0

/* Declaration style */
#undef DECL_TOUPPER_0

/* What is the fallback value for HZ? */
#undef DEFAULT_HZ

/* Directory separator character, usually / or \\ */
#undef DIR_SEP

/* use old autokey session key behavior? */
#undef DISABLE_BUG1243_FIX

/* synch TODR hourly? */
#undef DOSYNCTODR

/* The number of minutes in a DST adjustment */
#undef DSTMINUTES

/* fopen(3) accepts a 'b' in the mode flag */
#undef FOPEN_BINARY_FLAG

/* fopen(3) accepts a 't' in the mode flag */
#undef FOPEN_TEXT_FLAG

/* Force deferred DNS lookups? */
#undef FORCE_DEFER_DNS

/* force ntpdate to step the clock if !defined(STEP_SLEW) ? */
#undef FORCE_NTPDATE_STEP

/* What is getsockname()'s socklen type? */
#undef GETSOCKNAME_SOCKLEN_TYPE

/* Do we have a routing socket (struct rt_msghdr)? */
#undef HAS_ROUTING_SOCKET

/* Define to 1 if you have the <arpa/nameser.h> header file. */
#undef HAVE_ARPA_NAMESER_H

/* Do we have audio support? */
#undef HAVE_AUDIO

/* Define to 1 if you have the <bstring.h> header file. */
#undef HAVE_BSTRING_H

/* Define to 1 if you have the `canonicalize_file_name' function. */
#undef HAVE_CANONICALIZE_FILE_NAME

/* Do we have the CIOGETEV ioctl (SunOS, Linux)? */
#undef HAVE_CIOGETEV

/* Define to 1 if you have the `clock_gettime' function. */
#undef HAVE_CLOCK_GETTIME

/* Define to 1 if you have the `clock_settime' function. */
#undef HAVE_CLOCK_SETTIME

/* Define to 1 if you have the `daemon' function. */
#undef HAVE_DAEMON

/* Define this if /dev/zero is readable device */
#undef HAVE_DEV_ZERO

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'.
   */
#undef HAVE_DIRENT_H

/* Define to 1 if you have the <dlfcn.h> header file. */
#undef HAVE_DLFCN_H

/* Use Rendezvous/DNS-SD registration */
#undef HAVE_DNSREGISTRATION

/* Define to 1 if you don't have `vprintf' but do have `_doprnt.' */
#undef HAVE_DOPRNT

/* Can we drop root privileges? */
#undef HAVE_DROPROOT

/* Define to 1 if you have the <errno.h> header file. */
#undef HAVE_ERRNO_H

/* Define to 1 if you have the <fcntl.h> header file. */
#undef HAVE_FCNTL_H

/* Define to 1 if you have the `finite' function. */
#undef HAVE_FINITE

/* Define to 1 if you have the `fork' function. */
#undef HAVE_FORK

/* Define to 1 if you have the `getbootfile' function. */
#undef HAVE_GETBOOTFILE

/* Define to 1 if you have the `getclock' function. */
#undef HAVE_GETCLOCK

/* Define to 1 if you have the `getdtablesize' function. */
#undef HAVE_GETDTABLESIZE

/* Define to 1 if you have the `getifaddrs' function. */
#undef HAVE_GETIFADDRS

/* Define to 1 if you have the `getpassphrase' function. */
#undef HAVE_GETPASSPHRASE

/* Define to 1 if you have the `getrusage' function. */
#undef HAVE_GETRUSAGE

/* Define to 1 if you have the `getuid' function. */
#undef HAVE_GETUID

/* Define to 1 if you have the <histedit.h> header file. */
#undef HAVE_HISTEDIT_H

/* Define to 1 if you have the <history.h> header file. */
#undef HAVE_HISTORY_H

/* Define to 1 if you have the `hstrerror' function. */
#undef HAVE_HSTRERROR

/* Obvious... */
#undef HAVE_HZ_IN_STRUCT_CLOCKINFO

/* Define to 1 if you have the <ieeefp.h> header file. */
#undef HAVE_IEEEFP_H

/* have iflist_sysctl? */
#undef HAVE_IFLIST_SYSCTL

/* inline keyword or macro available */
#undef HAVE_INLINE

/* Define to 1 if the system has the type `int16_t'. */
#undef HAVE_INT16_T

/* Define to 1 if the system has the type `int32_t'. */
#undef HAVE_INT32_T

/* Define to 1 if the system has the type `int8_t'. */
#undef HAVE_INT8_T

/* Define to 1 if the system has the type `intptr_t'. */
#undef HAVE_INTPTR_T

/* Define to 1 if you have the <inttypes.h> header file. */
#undef HAVE_INTTYPES_H

/* Do we have IPTOS support? */
#undef HAVE_IPTOS_SUPPORT

/* Define to 1 if you have the `isfinite' function. */
#undef HAVE_ISFINITE

/* Define to 1 if you have the <kvm.h> header file. */
#undef HAVE_KVM_H

/* Define to 1 if you have the `kvm_open' function. */
#undef HAVE_KVM_OPEN

/* Define to 1 if you have the `advapi32' library (-ladvapi32). */
#undef HAVE_LIBADVAPI32

/* Define to 1 if you have the `elf' library (-lelf). */
#undef HAVE_LIBELF

/* Define to 1 if you have the `gen' library (-lgen). */
#undef HAVE_LIBGEN

/* Define to 1 if you have the <libgen.h> header file. */
#undef HAVE_LIBGEN_H

/* Define to 1 if you have the `kvm' library (-lkvm). */
#undef HAVE_LIBKVM

/* Define to 1 if you have the `ld' library (-lld). */
#undef HAVE_LIBLD

/* Define to 1 if you have the `mld' library (-lmld). */
#undef HAVE_LIBMLD

/* Define to 1 if you have the `netsnmp' library (-lnetsnmp). */
#undef HAVE_LIBNETSNMP

/* Define to 1 if you have the `posix4' library (-lposix4). */
#undef HAVE_LIBPOSIX4

/* Define to 1 if you have the `rt' library (-lrt). */
#undef HAVE_LIBRT

/* Define to 1 if you have the <libscf.h> header file. */
#undef HAVE_LIBSCF_H

/* Define to 1 if you have the <limits.h> header file. */
#undef HAVE_LIMITS_H

/* Do we have Linux capabilities? */
#undef HAVE_LINUX_CAPABILITIES

/* Define to 1 if you have the <machine/inline.h> header file. */
#undef HAVE_MACHINE_INLINE_H

/* Define to 1 if you have the <machine/soundcard.h> header file. */
#undef HAVE_MACHINE_SOUNDCARD_H

/* Define to 1 if you have the <math.h> header file. */
#undef HAVE_MATH_H

/* Define to 1 if you have the `MD5Init' function. */
#undef HAVE_MD5INIT

/* Define to 1 if you have the <md5.h> header file. */
#undef HAVE_MD5_H

/* Define to 1 if you have the `memcpy' function. */
#undef HAVE_MEMCPY

/* Define to 1 if you have the `memlk' function. */
#undef HAVE_MEMLK

/* Define to 1 if you have the `memmove' function. */
#undef HAVE_MEMMOVE

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `memset' function. */
#undef HAVE_MEMSET

/* Define to 1 if you have the `mkstemp' function. */
#undef HAVE_MKSTEMP

/* Define to 1 if you have the `mktime' function. */
#undef HAVE_MKTIME

/* Define to 1 if you have the `mlockall' function. */
#undef HAVE_MLOCKALL

/* Define to 1 if you have the `mmap' function. */
#undef HAVE_MMAP

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
#undef HAVE_NDIR_H

/* Define to 1 if you have the <netdb.h> header file. */
#undef HAVE_NETDB_H

/* Define to 1 if you have the <netinet/in.h> header file. */
#undef HAVE_NETINET_IN_H

/* Define to 1 if you have the <netinet/in_system.h> header file. */
#undef HAVE_NETINET_IN_SYSTEM_H

/* Define to 1 if you have the <netinet/in_systm.h> header file. */
#undef HAVE_NETINET_IN_SYSTM_H

/* Define to 1 if you have the <netinet/ip.h> header file. */
#undef HAVE_NETINET_IP_H

/* NetInfo support? */
#undef HAVE_NETINFO

/* Define to 1 if you have the <netinfo/ni.h> header file. */
#undef HAVE_NETINFO_NI_H

/* Define to 1 if you have the <net/if6.h> header file. */
#undef HAVE_NET_IF6_H

/* Define to 1 if you have the <net/if.h> header file. */
#undef HAVE_NET_IF_H

/* Define to 1 if you have the <net/route.h> header file. */
#undef HAVE_NET_ROUTE_H

/* Define to 1 if you have the `nice' function. */
#define HAVE_NO_NICE 1

/* Define to 1 if you have the `nlist' function. */
#undef HAVE_NLIST

/* Define to 1 if you have the `ntp_adjtime' function. */
#undef HAVE_NTP_ADJTIME

/* Define to 1 if you have the `ntp_gettime' function. */
#undef HAVE_NTP_GETTIME

/* Do we want support for Samba's signing daemon? */
#undef HAVE_NTP_SIGND

/* Define this if pathfind(3) works */
#undef HAVE_PATHFIND

/* Define to 1 if the system has the type `pid_t'. */
#undef HAVE_PID_T

/* Define to 1 if you have the `plock' function. */
#undef HAVE_PLOCK

/* Define to 1 if you have the <poll.h> header file. */
#undef HAVE_POLL_H

/* Do we have the PPS API per the Draft RFC? */
#undef HAVE_PPSAPI

/* Define to 1 if you have the `pututline' function. */
#undef HAVE_PUTUTLINE

/* Define to 1 if you have the `pututxline' function. */
#undef HAVE_PUTUTXLINE

/* Define to 1 if you have the <readline.h> header file. */
#undef HAVE_READLINE_H

/* Define if your readline library has \`add_history' */
#undef HAVE_READLINE_HISTORY

/* Define to 1 if you have the <readline/history.h> header file. */
#undef HAVE_READLINE_HISTORY_H

/* Define to 1 if you have the <readline/readline.h> header file. */
#undef HAVE_READLINE_READLINE_H

/* Define to 1 if you have the `readlink' function. */
#undef HAVE_READLINK

/* Define this if we have a functional realpath(3C) */
#undef HAVE_REALPATH

/* Define to 1 if you have the `recvmsg' function. */
#undef HAVE_RECVMSG

/* Define to 1 if you have the <resolv.h> header file. */
#undef HAVE_RESOLV_H

/* Define to 1 if you have the `res_init' function. */
#undef HAVE_RES_INIT

/* Do we have Linux routing socket? */
#undef HAVE_RTNETLINK

/* Define to 1 if you have the `rtprio' function. */
#undef HAVE_RTPRIO

/* Define to 1 if you have the <runetype.h> header file. */
#undef HAVE_RUNETYPE_H

/* Obvious... */
#undef HAVE_SA_SIGACTION_IN_STRUCT_SIGACTION

/* Define to 1 if you have the <sched.h> header file. */
#undef HAVE_SCHED_H

/* Define to 1 if you have the `sched_setscheduler' function. */
#undef HAVE_SCHED_SETSCHEDULER

/* Define to 1 if you have the <setjmp.h> header file. */
#undef HAVE_SETJMP_H

/* Define to 1 if you have the `setlinebuf' function. */
#undef HAVE_SETLINEBUF

/* Define to 1 if you have the `setpgid' function. */
#undef HAVE_SETPGID

/* define if setpgrp takes 0 arguments */
#undef HAVE_SETPGRP_0

/* Define to 1 if you have the `setpriority' function. */
#undef HAVE_SETPRIORITY

/* Define to 1 if you have the `setrlimit' function. */
#undef HAVE_SETRLIMIT

/* Define to 1 if you have the `setsid' function. */
#undef HAVE_SETSID

/* Define to 1 if you have the `settimeofday' function. */
#undef HAVE_SETTIMEOFDAY

/* Define to 1 if you have the `setvbuf' function. */
#undef HAVE_SETVBUF

/* Define to 1 if you have the <sgtty.h> header file. */
#undef HAVE_SGTTY_H

/* Define to 1 if you have the `sigaction' function. */
#undef HAVE_SIGACTION

/* Can we use SIGIO for tcp and udp IO? */
#undef HAVE_SIGNALED_IO

/* Define to 1 if you have the `sigset' function. */
#undef HAVE_SIGSET

/* Define to 1 if you have the `sigsuspend' function. */
#undef HAVE_SIGSUSPEND

/* Define to 1 if you have the `sigvec' function. */
#undef HAVE_SIGVEC

/* Define to 1 if the system has the type `size_t'. */
#undef HAVE_SIZE_T

/* Define to 1 if you have the `snprintf' function. */
#undef HAVE_SNPRINTF

/* Are Solaris privileges available? */
#undef HAVE_SOLARIS_PRIVS

/* Define to 1 if you have the <stdarg.h> header file. */
#undef HAVE_STDARG_H

/* Define to 1 if you have the <stdint.h> header file. */
#undef HAVE_STDINT_H

/* Define to 1 if you have the <stdlib.h> header file. */
#undef HAVE_STDLIB_H

/* Define to 1 if you have the `stime' function. */
#undef HAVE_STIME

/* Define to 1 if you have the `strchr' function. */
#define HAVE_STRCHR 1

/* Define to 1 if you have the `strdup' function. */
#undef HAVE_STRDUP

/* Define to 1 if you have the `strerror' function. */
#undef HAVE_STRERROR

/* Define this if strftime() works */
#undef HAVE_STRFTIME

/* Define to 1 if you have the <strings.h> header file. */
#undef HAVE_STRINGS_H

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strrchr' function. */
#undef HAVE_STRRCHR

/* Define to 1 if you have the `strsignal' function. */
#undef HAVE_STRSIGNAL

/* Define to 1 if you have the `strstr' function. */
#undef HAVE_STRSTR

/* Do we have struct ntptimeval? */
#undef HAVE_STRUCT_NTPTIMEVAL

/* Define to 1 if `time.tv_nsec' is a member of `struct ntptimeval'. */
#undef HAVE_STRUCT_NTPTIMEVAL_TIME_TV_NSEC

/* Does a system header define struct ppsclockev? */
#undef HAVE_STRUCT_PPSCLOCKEV

/* Do we have struct snd_size? */
#undef HAVE_STRUCT_SND_SIZE

/* Does a system header define struct sockaddr_storage? */
#define HAVE_STRUCT_SOCKADDR_STORAGE 1

/* Do we have struct timespec? */
#undef HAVE_STRUCT_TIMESPEC

/* Define to 1 if you have the <sun/audioio.h> header file. */
#undef HAVE_SUN_AUDIOIO_H

/* Define to 1 if you have the `sysconf' function. */
#undef HAVE_SYSCONF

/* Define to 1 if you have the `sysctl' function. */
#undef HAVE_SYSCTL

/* Define to 1 if you have the <sysexits.h> header file. */
#undef HAVE_SYSEXITS_H

/* Define to 1 if you have the <sys/audioio.h> header file. */
#undef HAVE_SYS_AUDIOIO_H

/* Define to 1 if you have the <sys/capability.h> header file. */
#undef HAVE_SYS_CAPABILITY_H

/* Define to 1 if you have the <sys/clkdefs.h> header file. */
#undef HAVE_SYS_CLKDEFS_H

/* Define to 1 if you have the <sys/clockctl.h> header file. */
#undef HAVE_SYS_CLOCKCTL_H

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'.
   */
#undef HAVE_SYS_DIR_H

/* Define to 1 if you have the <sys/file.h> header file. */
#undef HAVE_SYS_FILE_H

/* Define to 1 if you have the <sys/i8253.h> header file. */
#undef HAVE_SYS_I8253_H

/* Define to 1 if you have the <sys/ioctl.h> header file. */
#undef HAVE_SYS_IOCTL_H

/* Define to 1 if you have the <sys/ipc.h> header file. */
#undef HAVE_SYS_IPC_H

/* Define to 1 if you have the <sys/limits.h> header file. */
#undef HAVE_SYS_LIMITS_H

/* Define to 1 if you have the <sys/lock.h> header file. */
#undef HAVE_SYS_LOCK_H

/* Define to 1 if you have the <sys/mman.h> header file. */
#undef HAVE_SYS_MMAN_H

/* Define to 1 if you have the <sys/modem.h> header file. */
#undef HAVE_SYS_MODEM_H

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'.
   */
#undef HAVE_SYS_NDIR_H

/* Define to 1 if you have the <sys/param.h> header file. */
#undef HAVE_SYS_PARAM_H

/* Define to 1 if you have the <sys/pcl720.h> header file. */
#undef HAVE_SYS_PCL720_H

/* Define to 1 if you have the <sys/poll.h> header file. */
#undef HAVE_SYS_POLL_H

/* Define to 1 if you have the <sys/ppsclock.h> header file. */
#undef HAVE_SYS_PPSCLOCK_H

/* Define to 1 if you have the <sys/ppstime.h> header file. */
#undef HAVE_SYS_PPSTIME_H

/* Define to 1 if you have the <sys/prctl.h> header file. */
#undef HAVE_SYS_PRCTL_H

/* Define to 1 if you have the <sys/procset.h> header file. */
#undef HAVE_SYS_PROCSET_H

/* Define to 1 if you have the <sys/proc.h> header file. */
#undef HAVE_SYS_PROC_H

/* Define to 1 if you have the <sys/resource.h> header file. */
#undef HAVE_SYS_RESOURCE_H

/* Define to 1 if you have the <sys/sched.h> header file. */
#undef HAVE_SYS_SCHED_H

/* Define to 1 if you have the <sys/select.h> header file. */
#undef HAVE_SYS_SELECT_H

/* Define to 1 if you have the <sys/shm.h> header file. */
#undef HAVE_SYS_SHM_H

/* Define to 1 if you have the <sys/signal.h> header file. */
#undef HAVE_SYS_SIGNAL_H

/* Define to 1 if you have the <sys/sio.h> header file. */
#undef HAVE_SYS_SIO_H

/* Define to 1 if you have the <sys/socket.h> header file. */
#undef HAVE_SYS_SOCKET_H

/* Define to 1 if you have the <sys/sockio.h> header file. */
#undef HAVE_SYS_SOCKIO_H

/* Define to 1 if you have the <sys/soundcard.h> header file. */
#undef HAVE_SYS_SOUNDCARD_H

/* Define to 1 if you have the <sys/stat.h> header file. */
#undef HAVE_SYS_STAT_H

/* Define to 1 if you have the <sys/stream.h> header file. */
#undef HAVE_SYS_STREAM_H

/* Define to 1 if you have the <sys/stropts.h> header file. */
#undef HAVE_SYS_STROPTS_H

/* Define to 1 if you have the <sys/sysctl.h> header file. */
#undef HAVE_SYS_SYSCTL_H

/* Define to 1 if you have the <sys/syssgi.h> header file. */
#undef HAVE_SYS_SYSSGI_H

/* Define to 1 if you have the <sys/systune.h> header file. */
#undef HAVE_SYS_SYSTUNE_H

/* Define to 1 if you have the <sys/termios.h> header file. */
#undef HAVE_SYS_TERMIOS_H

/* Define to 1 if you have the <sys/timepps.h> header file. */
#undef HAVE_SYS_TIMEPPS_H

/* Define to 1 if you have the <sys/timers.h> header file. */
#undef HAVE_SYS_TIMERS_H

/* Define to 1 if you have the <sys/timex.h> header file. */
#undef HAVE_SYS_TIMEX_H

/* Define to 1 if you have the <sys/time.h> header file. */
#undef HAVE_SYS_TIME_H

/* Define to 1 if you have the <sys/tpro.h> header file. */
#undef HAVE_SYS_TPRO_H

/* Define to 1 if you have the <sys/types.h> header file. */
#undef HAVE_SYS_TYPES_H

/* Use sys/uio.h for struct iovec help */
#undef HAVE_SYS_UIO_H

/* Define to 1 if you have the <sys/un.h> header file. */
#undef HAVE_SYS_UN_H

/* Define to 1 if you have the <sys/wait.h> header file. */
#undef HAVE_SYS_WAIT_H

/* Define to 1 if the system has the type `s_char'. */
#undef HAVE_S_CHAR

/* Define to 1 if you have the <termios.h> header file. */
#undef HAVE_TERMIOS_H

/* Define to 1 if you have the <termio.h> header file. */
#undef HAVE_TERMIO_H

/* Obvious... */
#undef HAVE_TICKADJ_IN_STRUCT_CLOCKINFO

/* Define to 1 if you have the `timegm' function. */
#undef HAVE_TIMEGM

/* Define to 1 if you have the <timepps.h> header file. */
#undef HAVE_TIMEPPS_H

/* Define to 1 if you have the `timer_create' function. */
#undef HAVE_TIMER_CREATE

/* Define to 1 if you have the `timer_settime' function. */
#undef HAVE_TIMER_SETTIME

/* Define to 1 if you have the <timex.h> header file. */
#undef HAVE_TIMEX_H

/* Do we have the TIOCGPPSEV ioctl (Solaris)? */
#undef HAVE_TIOCGPPSEV

/* Do we have the TIOCSPPS ioctl (Solaris)? */
#undef HAVE_TIOCSPPS

/* Do we have the TIO serial stuff? */
#undef HAVE_TIO_SERIAL_STUFF

/* Does u_int64_t exist? */
#undef HAVE_TYPE_U_INT64_T

/* Does u_int8_t exist? */
#undef HAVE_TYPE_U_INT8_T

/* Define to 1 if the system has the type `uint16_t'. */
#undef HAVE_UINT16_T

/* Define to 1 if the system has the type `uint32_t'. */
#undef HAVE_UINT32_T

/* Define to 1 if the system has the type `uint8_t'. */
#undef HAVE_UINT8_T

/* Define to 1 if the system has the type `uintptr_t'. */
#undef HAVE_UINTPTR_T

/* Define to 1 if the system has the type `uint_t'. */
#undef HAVE_UINT_T

/* Define to 1 if you have the `umask' function. */
#undef HAVE_UMASK

/* Define to 1 if you have the `uname' function. */
#undef HAVE_UNAME

/* Define to 1 if you have the <unistd.h> header file. */
#undef HAVE_UNISTD_H

/* Define to 1 if you have the `updwtmp' function. */
#undef HAVE_UPDWTMP

/* Define to 1 if you have the `updwtmpx' function. */
#undef HAVE_UPDWTMPX

/* Define to 1 if you have the <utime.h> header file. */
#undef HAVE_UTIME_H

/* Define to 1 if you have the <utmpx.h> header file. */
#undef HAVE_UTMPX_H

/* Define to 1 if you have the <utmp.h> header file. */
#undef HAVE_UTMP_H

/* Define to 1 if you have the <values.h> header file. */
#undef HAVE_VALUES_H

/* Define to 1 if you have the <varargs.h> header file. */
#undef HAVE_VARARGS_H

/* Define to 1 if you have the `vfork' function. */
#undef HAVE_VFORK

/* Define to 1 if you have the <vfork.h> header file. */
#undef HAVE_VFORK_H

/* Define to 1 if you have the `vprintf' function. */
#undef HAVE_VPRINTF

/* Define to 1 if you have the `vsnprintf' function. */
#undef HAVE_VSNPRINTF

/* Define to 1 if you have the `vsprintf' function. */
#undef HAVE_VSPRINTF

/* Define to 1 if you have the <wchar.h> header file. */
#undef HAVE_WCHAR_H

/* Define to 1 if the system has the type `wchar_t'. */
#undef HAVE_WCHAR_T

/* Define to 1 if the system has the type `wint_t'. */
#undef HAVE_WINT_T

/* Define to 1 if `fork' works. */
#undef HAVE_WORKING_FORK

/* Define to 1 if `vfork' works. */
#undef HAVE_WORKING_VFORK

/* Define to 1 if you have the </sys/sync/queue.h> header file. */
#undef HAVE__SYS_SYNC_QUEUE_H

/* Define to 1 if you have the </sys/sync/sema.h> header file. */
#undef HAVE__SYS_SYNC_SEMA_H

/* Define to 1 if you have the `__adjtimex' function. */
#undef HAVE___ADJTIMEX

/* Define to 1 if you have the `__ntp_gettime' function. */
#undef HAVE___NTP_GETTIME

/* Define to 1 if you have the `__res_init' function. */
#undef HAVE___RES_INIT

/* Does struct sockaddr_storage have __ss_family? */
#undef HAVE___SS_FAMILY_IN_SS


	/* Handle sockaddr_storage.__ss_family */
	#ifdef HAVE___SS_FAMILY_IN_SS
	# define ss_family __ss_family
	#endif /* HAVE___SS_FAMILY_IN_SS */
    


/* Does struct sockaddr_storage have __ss_len? */
#undef HAVE___SS_LEN_IN_SS


	/* Handle sockaddr_storage.__ss_len */
	#ifdef HAVE___SS_LEN_IN_SS
	# define ss_len __ss_len
	#endif /* HAVE___SS_LEN_IN_SS */
    


/* [Retry queries on _any_ DNS error?] */
#undef IGNORE_DNS_ERRORS

/* Should we use the IRIG sawtooth filter? */
#undef IRIG_SUCKS

/* Do we need to fix in6isaddr? */
#undef ISC_PLATFORM_FIXIN6ISADDR

/* ISC: do we have if_nametoindex()? */
#undef ISC_PLATFORM_HAVEIFNAMETOINDEX

/* have struct if_laddrconf? */
#undef ISC_PLATFORM_HAVEIF_LADDRCONF

/* have struct if_laddrreq? */
#undef ISC_PLATFORM_HAVEIF_LADDRREQ

/* have struct in6_pktinfo? */
#undef ISC_PLATFORM_HAVEIN6PKTINFO

/* have IPv6? */
#undef ISC_PLATFORM_HAVEIPV6

/* struct sockaddr has sa_len? */
#undef ISC_PLATFORM_HAVESALEN

/* have sin6_scope_id? */
#undef ISC_PLATFORM_HAVESCOPEID

/* missing in6addr_any? */
#undef ISC_PLATFORM_NEEDIN6ADDRANY

/* Do we need netinet6/in6.h? */
#undef ISC_PLATFORM_NEEDNETINET6IN6H

/* ISC: provide inet_ntop() */
#undef ISC_PLATFORM_NEEDNTOP

/* Declare in_port_t? */
#undef ISC_PLATFORM_NEEDPORTT

/* ISC: provide inet_pton() */
#undef ISC_PLATFORM_NEEDPTON

/* Does the kernel have an FLL bug? */
#undef KERNEL_FLL_BUG

/* Does the kernel support precision time discipline? */
#undef KERNEL_PLL

/* What is (probably) the name of DOSYNCTODR in the kernel? */
#undef K_DOSYNCTODR_NAME

/* What is (probably) the name of NOPRINTF in the kernel? */
#undef K_NOPRINTF_NAME

/* What is the name of TICKADJ in the kernel? */
#undef K_TICKADJ_NAME

/* What is the name of TICK in the kernel? */
#undef K_TICK_NAME

/* Should we align with the NIST lockclock scheme? */
#undef LOCKCLOCK

/* Does the kernel support multicasting IP? */
#undef MCAST

/* Should we recommend a minimum value for tickadj? */
#undef MIN_REC_TICKADJ

/* Do we need HPUX adjtime() library support? */
#undef NEED_HPUX_ADJTIME

/* Do we want the HPUX FindConfig()? */
#undef NEED_HPUX_FINDCONFIG

/* We need to provide netsnmp_daemonize() */
#undef NEED_NETSNMP_DAEMONIZE

/* Do we need the qnx adjtime call? */
#undef NEED_QNX_ADJTIME

/* Do we need extra room for SO_RCVBUF? (HPUX <8) */
#undef NEED_RCVBUF_SLOP

/* Do we need an s_char typedef? */
#undef NEED_S_CHAR_TYPEDEF

/* Might nlist() values require an extra level of indirection (AIX)? */
#undef NLIST_EXTRA_INDIRECTION

/* does struct nlist use a name union? */
#undef NLIST_NAME_UNION

/* nlist stuff */
#undef NLIST_STRUCT

/* Should we NOT read /dev/kmem? */
#undef NOKMEM

/* Define to 1 if your C compiler doesn't accept -c and -o together. */
#undef NO_MINUS_C_MINUS_O

/* Define this if optional arguments are disallowed */
#undef NO_OPTIONAL_OPT_ARGS

/* Should we avoid #warning on option name collisions? */
#undef NO_OPTION_NAME_WARNINGS

/* Is there a problem using PARENB and IGNPAR (IRIX)? */
#undef NO_PARENB_IGNPAR

/* Default location of crypto key info */
#undef NTP_KEYSDIR

/* Path to sign daemon rendezvous socket */
#undef NTP_SIGND_PATH

/* Do we have ntp_{adj,get}time in libc? */
#undef NTP_SYSCALLS_LIBC

/* Do we have ntp_{adj,get}time in the kernel? */
#undef NTP_SYSCALLS_STD

/* Do we have support for SHMEM_STATUS? */
#undef ONCORE_SHMEM_STATUS

/* Use OpenSSL? */
#undef OPENSSL

/* Should we open the broadcast socket? */
#undef OPEN_BCAST_SOCKET

/* need to recreate sockets on changed routing? */
#undef OS_MISSES_SPECIFIC_ROUTE_UPDATES

/* wildcard socket needs to set REUSEADDR when binding to interface addresses
   */
#undef OS_NEEDS_REUSEADDR_FOR_IFADDRBIND

/* Do we need to override the system's idea of HZ? */
#undef OVERRIDE_HZ

/* Name of package */
#undef PACKAGE

/* Define to the address where bug reports for this package should be sent. */
#undef PACKAGE_BUGREPORT

/* Define to the full name of this package. */
#undef PACKAGE_NAME

/* Define to the full name and version of this package. */
#undef PACKAGE_STRING

/* Define to the one symbol short name of this package. */
#undef PACKAGE_TARNAME

/* Define to the home page for this package. */
#undef PACKAGE_URL

/* Define to the version of this package. */
#undef PACKAGE_VERSION

/* Do we have the ppsclock streams module? */
#undef PPS

/* PARSE kernel PLL PPS support */
#undef PPS_SYNC

/* Preset a value for 'tick'? */
#undef PRESET_TICK

/* Preset a value for 'tickadj'? */
#undef PRESET_TICKADJ

/* Does qsort expect to work on "void *" stuff? */
#undef QSORT_USES_VOID_P

/* Should we not IGNPAR (Linux)? */
#undef RAWDCF_NO_IGNPAR

/* Basic refclock support? */
#undef REFCLOCK

/* name of regex header file */
#undef REGEX_HEADER

/* Do we want the ReliantUNIX clock hacks? */
#undef RELIANTUNIX_CLOCK

/* Define as the return type of signal handlers (`int' or `void'). */
#undef RETSIGTYPE

/* saveconfig mechanism */
#undef SAVECONFIG

/* Do we want the SCO clock hacks? */
#undef SCO5_CLOCK

/* The size of `char*', as computed by sizeof. */
#define SIZEOF_CHARP 4

/* The size of `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of `long', as computed by sizeof. */
#define SIZEOF_LONG 4

/* The size of `short', as computed by sizeof. */
#define SIZEOF_SHORT 2

/* The size of `signed char', as computed by sizeof. */
#define SIZEOF_SIGNED_CHAR 1

/* The size of `time_t', as computed by sizeof. */
#undef SIZEOF_TIME_T

/* Does SIOCGIFCONF return size in the buffer? */
#undef SIZE_RETURNED_IN_BUFFER

/* Slew always? */
#undef SLEWALWAYS

/* *s*printf() functions are char* */
#undef SPRINTF_CHAR

/* Define to 1 if you have the ANSI C header files. */
#undef STDC_HEADERS

/* Step, then slew the clock? */
#undef STEP_SLEW

/* canonical system (cpu-vendor-os) of where we should run */
#undef STR_SYSTEM

/* Buggy syscall() (Solaris2.4)? */
#undef SYSCALL_BUG

/* Does Xettimeofday take 1 arg? */
#undef SYSV_TIMEOFDAY

/* Do we need to #define _SVID3 when we #include <termios.h>? */
#undef TERMIOS_NEEDS__SVID3

/* Is K_TICKADJ_NAME in nanoseconds? */
#undef TICKADJ_NANO

/* Is K_TICK_NAME in nanoseconds? */
#undef TICK_NANO

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#undef TIME_WITH_SYS_TIME

/* Define to 1 if your <sys/time.h> declares `struct tm'. */
#undef TM_IN_SYS_TIME

/* Do we have the tty_clk line discipline/streams module? */
#undef TTYCLK

/* Provide a typedef for uintptr_t? */
#ifndef HAVE_UINTPTR_T
typedef unsigned int	uintptr_t;
#define HAVE_UINTPTR_T	1
#endif

/* What type to use for setsockopt */
#undef TYPEOF_IP_MULTICAST_LOOP

/* Do we set process groups with -pid? */
#undef UDP_BACKWARDS_SETOWN

/* Must we have a CTTY for fsetown? */
#undef USE_FSETOWNCTTY

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# undef _ALL_SOURCE
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# undef _GNU_SOURCE
#endif
/* Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# undef _POSIX_PTHREAD_SEMANTICS
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# undef _TANDEM_SOURCE
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# undef __EXTENSIONS__
#endif


/* Can we use SIGPOLL for tty IO? */
#undef USE_TTY_SIGPOLL

/* Can we use SIGPOLL for UDP? */
#undef USE_UDP_SIGPOLL

/* Version number of package */
#undef VERSION

/* configure --enable-ipv6 */
#undef WANT_IPV6

/* Define this if a working libregex can be found */
#undef WITH_LIBREGEX

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
#  undef WORDS_BIGENDIAN
# endif
#endif

/* Define to 1 if on MINIX. */
#undef _MINIX

/* Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
#undef _POSIX_1_SOURCE

/* Define to 1 if you need to in order for `stat' and other things to work. */
#undef _POSIX_SOURCE

/* Define to 1 if type `char' is unsigned and you are not using gcc.  */
#ifndef __CHAR_UNSIGNED__
# undef __CHAR_UNSIGNED__
#endif

/* Define to empty if `const' does not conform to ANSI C. */
#undef const

/* Define to `int' if <sys/types.h> doesn't define. */
#undef gid_t

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
#undef inline
#endif

typedef unsigned char u_char;
typedef unsigned short u_short;
//typedef unsigned int u_int32;
typedef unsigned long u_long;

/* Define to `long int' if <sys/types.h> does not define. */
#undef off_t

/* Define to `int' if <sys/types.h> does not define. */
#undef pid_t

/* Define to `unsigned int' if <sys/types.h> does not define. */
#undef size_t

/* Define to `long' if <sys/types.h> does not define. */
#undef time_t

/* Define to `int' if <sys/types.h> doesn't define. */
#undef uid_t

/* Define as `fork' if `vfork' does not work. */
#undef vfork

/* Does the compiler like "volatile"? */
#undef volatile
