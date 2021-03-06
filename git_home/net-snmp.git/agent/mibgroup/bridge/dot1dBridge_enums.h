/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.column_enums.conf,v 5.2 2003/02/22 04:09:25 hardaker Exp $
 */
#ifndef DOT1DBRIDGE_ENUMS_H
#define DOT1DBRIDGE_ENUMS_H

/*
 * enums for column dot1dStpPortState 
 */
#define DOT1DSTPPORTSTATE_DISABLED		1
#define DOT1DSTPPORTSTATE_BLOCKING		2
#define DOT1DSTPPORTSTATE_LISTENING		3
#define DOT1DSTPPORTSTATE_LEARNING		4
#define DOT1DSTPPORTSTATE_FORWARDING		5
#define DOT1DSTPPORTSTATE_BROKEN		6

/*
 * enums for column dot1dStpPortEnable 
 */
#define DOT1DSTPPORTENABLE_ENABLED		1
#define DOT1DSTPPORTENABLE_DISABLED		2

/*
 * enums for column dot1dTpFdbStatus 
 */
#define DOT1DTPFDBSTATUS_OTHER		1
#define DOT1DTPFDBSTATUS_INVALID		2
#define DOT1DTPFDBSTATUS_LEARNED		3
#define DOT1DTPFDBSTATUS_SELF		4
#define DOT1DTPFDBSTATUS_MGMT		5

/*
 * enums for column dot1dStaticStatus 
 */
#define DOT1DSTATICSTATUS_OTHER		1
#define DOT1DSTATICSTATUS_INVALID		2
#define DOT1DSTATICSTATUS_PERMANENT		3
#define DOT1DSTATICSTATUS_DELETEONRESET		4
#define DOT1DSTATICSTATUS_DELETEONTIMEOUT		5

#endif                          /* DOT1DBRIDGE_ENUMS_H */
