/**
 * @file Carpenter.h
 * @author biko
 * @date 2016-08-06
 *
 * Carpenter module public header.
 * Contains routines for patching message tables.
 */
#pragma once

/** Headers *************************************************************/
#include <ntifs.h>


/** Constants ***********************************************************/

/**
 * The default type of a message table resource.
 */
#define RT_MESSAGETABLE ((ULONG_PTR)(USHORT)11)


/** Typedefs ************************************************************/

/**
 * Handle to a patcher instance.
 */
DECLARE_HANDLE(HCARPENTER);
typedef HCARPENTER *PHCARPENTER;


/** Functions ***********************************************************/

/**
 * Creates a new patcher instance.
 *
 * @param[in]	pvImageBase	Base of the image that contains
 *							the message table.
 * @param[in]	pvType		Type of the resource that contains
 *							the message table. Usually, this is
 *							RT_MESSAGETABLE.
 * @param[in]	pvName		Name of the resource that contains
 *							the message table.
 * @param[in]	pvLanguage	Language of the resource that
 *							contains the message table.
 * @param[out]	phCarpenter	Will receive a patcher handle.
 *
 * @remark	The resource type, name and language can be
 *			either a numerical ID (USHORT-sized),
 *			or a pointer to a null-terminated Unicode string.
 *
 * @returns NTSTATUS
 */
_IRQL_requires_(PASSIVE_LEVEL)
NTSTATUS
CARPENTER_Create(
	_In_	PVOID		pvImageBase,
	_In_	ULONG_PTR	pvType,
	_In_	ULONG_PTR	pvName,
	_In_	ULONG_PTR	pvLanguage,
	_Out_	PHCARPENTER	phCarpenter
);

/**
 * Destroys a patcher instance.
 *
 * @param[in]	hCarpenter	Patcher to destroy.
 *
 * @remark	Destroying the patcher does not
 *			undo the patch!
 */
_IRQL_requires_(PASSIVE_LEVEL)
VOID
CARPENTER_Destroy(
	_In_	HCARPENTER	hCarpenter
);