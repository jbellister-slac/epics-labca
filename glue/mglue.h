#ifndef  MATLAB_EZCA_GLUE_H
/* $Id: mglue.h,v 1.9 2004/02/11 23:06:10 till Exp $ */

/* matlab-ezca interface utility header */

/* Author: Till Straumann <strauman@slac.stanford.edu>, 2003 */

/* LICENSE: EPICS open license, see ../LICENSE file */
#include <mex.h>
#include <matrix.h>
#include <multiEzcaCtrlC.h>

typedef struct PVs_ {
	CtrlCStateRec	ctrlc;
	int    			m;
	char 			**names;
} PVs;

#include "shareLib.h"

#ifdef __cplusplus
extern "C" {
#endif

epicsShareFunc void epicsShareAPI
releasePVs(PVs *pvs);

epicsShareFunc int epicsShareAPI
buildPVs(const mxArray *pin, PVs *pvs);

/* mexErrMsgTxt() crashes matlab14-beta (linux) - also, we don't want
 * to jump out of context
 */
#define MEXERRPRINTF mexWarnMsgTxt

/* check for 'typearg' being a string and use the
 * first character to determine the desired ezca type
 *  ezca'N'ative
 *  ezca'B'yte
 *  ezca'S'hort
 *  ezca'L'ong
 *  ezca'F'loat
 *  ezca'D'ouble
 * or 'C'har for ezcaString
 */
epicsShareFunc char epicsShareAPI
marg2ezcaType(const mxArray *typearg);

/* use 'nlhs' as an 'error' flag; (jumped out of something and
 * have already assigned 'lhs' args).
 * Clean up the lhs args and flag an error condition.
 * If everyhing's OK, the caller passes nlhs == 0.
 */
epicsShareFunc void epicsShareAPI
flagError(int nlhs, mxArray *plhs[]);

#ifdef __cplusplus
};
#endif

#endif
