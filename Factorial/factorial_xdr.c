/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "factorial.h"

bool_t
xdr_fact (XDR *xdrs, fact *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->numeroFactorial))
		 return FALSE;
	return TRUE;
}