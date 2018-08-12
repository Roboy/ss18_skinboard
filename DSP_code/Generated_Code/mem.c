/** ###################################################################
**
**     (c) Freescale Semiconductor, Inc.
**     2004 All Rights Reserved
**
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/

/* File: memory.c */

#include "port.h"
#include "mem.h"
#include "arch.h"
#include "assert.h"
#include <string.h>
#include <stdio.h>

#ifdef MEM_THREADED_OS
#include "pthread.h"
#endif

/*******************************************************
* memory Package
*******************************************************/

#define ADDRESSING_8

bool        bMemInitialized = false;
mem_sPool   InternalMemoryPool;
mem_sPool   ExternalMemoryPool;
mem_sState  InitialState;
static void Initialize (void);


/*******************************************************
*
* Method: memMallocIM
*
* Description: This function allocates dynamic memory
*              of the specified size from the memory
*              partitions. The function memMallocIM
*              first tries to allocate the memory from
*              the internal memory partition. However,
*              if not enough space exists in the internal
*              memory partition to satisfy the dynamic
*              memory allocation, memMallocIM then tries
*              the allocation from the external memory partition.
*
* Arguments:
*       size - the size of the memory buffer to be
*              allocated in internal memory
*
* Return:      If memory is insufficient to satisfy the request
*              from either partition, memMallocIM returns NULL
*
*******************************************************/
void *  memMallocIM (size_t size)
{
  void * pMem;

  pMem=memMalloc(&InternalMemoryPool, size);
  if(pMem == NULL){
    pMem=memMalloc(&ExternalMemoryPool, size);
  }
  return pMem;
}


/*******************************************************
*
* Method: memCallocIM
*
* Description: This function dynamically allocates an array
*              with elements initialized to zero.
*              The memCallocIM function first tries to
*              reallocate the memory from the internal
*              memory partition. However,
*              if not enough space exists in the internal
*              memory partition to satisfy the dynamic
*              memory allocation, memMallocIM then tries
*              the allocation from the external memory partition.
*
* Arguments:
*       num  - the number of elements
*       size - the size of the memory buffer to be
*              allocated in internal memory
*
* Return:      If memory is insufficient to satisfy the request
*              from either partition, memCallocIM returns NULL
*
*******************************************************/
void *  memCallocIM (size_t num, size_t size)
{
  void * pMem;

  pMem=memCalloc(&InternalMemoryPool, num, size);
  if(pMem == NULL){
    pMem=memCalloc(&ExternalMemoryPool, num, size);
  }
  return pMem;
}


/*******************************************************
*
* Method: memReallocIM
*
* Description: This function dynamically reallocates and
*              resizes a memory buffer to the specified
*              size from the memory partitions. The function
*              memReallocIM first tries to reallocate
*              the memory from the internal memory partition.
*              However, if not enough space exists in
*              the internal memory partition to satisfy
*              the dynamic memory allocation, memReallocIM
*              then tries the allocation from the external
*              memory partition
*
* Arguments:
*   memblock - the address of the existing memory block
*              to reallocate
*       size - the new size of the memory buffer to be
*              allocated in internal memory
*
* Return:      If memory is insufficient to satisfy the request
*              from either partition, memReallocIM returns NULL
*
*******************************************************/
void * memReallocIM ( void *memblock, size_t size )
{
  void * pMem;

  pMem=memRealloc(&InternalMemoryPool, memblock, size);
  if(pMem == NULL){
    pMem=memRealloc(&ExternalMemoryPool, memblock, size);
  }
  return pMem;
}


/*******************************************************
*
* Method: memMallocAlignedIM
*
* Description: This function allocates dynamic memory
*              of the specified size from the memory
*              partitions and aligns the memory properly
*              to use modulo addressing. The function
*              memMallocAlignedIM first tries to allocate
*              the memory, properly aligned, from
*              the internal memory partition. However,
*              if not enough space exists in the internal
*              memory partition to satisfy the dynamic
*              memory allocation, or if the memory request
*              cannot be properly aligned, memMallocAlignedIM
*              then tries the allocation from the external
*              memory partition. If memMallocAlignedIM
*              cannot allocate an aligned buffer from
*              either partition, it calls memMallocIM
*              to try to allocate a buffer of the correct
*              size without the proper alignment.
*
* Arguments:
*       size - the new size of the memory buffer to be
*              allocated in internal memory
*
* Return:      If memory is insufficient to satisfy the request
*              from either partition, memMallocAlignedIM returns NULL
*
*******************************************************/
void *  memMallocAlignedIM (size_t size)
{
  void * pMem;

  pMem=memMallocAligned(&InternalMemoryPool, size);
  if(pMem == NULL){
    pMem=memMallocAligned(&ExternalMemoryPool, size);
    if(pMem == NULL){
      pMem=memMallocIM(size);
    }
  }
  return pMem;
}


/*******************************************************
*
* Method: memFreeIM
*
* Description: This function deallocates a memory block
*              in internal memory that previously had
*              been dynamically allocated with
*              the routine memMallocIM.
*
* Arguments:
*   memblock - pointer to previously allocated memory
*
* Return:      None
*
*******************************************************/
void memFreeIM (void * memblock)
{
  if(memIsIM(memblock)){
    memFree(&InternalMemoryPool, memblock);
  } else {
    memFree(&ExternalMemoryPool, memblock);
  }
}


/*******************************************************
*
* Method: memMallocEM
*
* Description: This function allocates dynamic memory
*              of the specified size from the memory
*              partitions. The function memMallocEM
*              first tries to allocate the memory from
*              the external memory partition. However,
*              if not enough space exists in the external
*              memory partition to satisfy the dynamic
*              memory allocation, memMallocEM then tries
*              the allocation from the internal memory partition.
*
* Arguments:
*       size - the size of the memory buffer to be
*              allocated in external memory
*
* Return:      If memory is insufficient to satisfy the request
*              from either partition, memMallocIM returns NULL
*
*******************************************************/
void *  memMallocEM (size_t size)
{
  void * pMem;

  pMem = memMalloc (&ExternalMemoryPool, size);
  if (pMem == NULL){
    pMem = memMalloc (&InternalMemoryPool, size);
  }
  return pMem;
}


/*******************************************************
*
* Method: memCallocEM
*
* Description: This function dynamically allocates an array
*              with elements initialized to zero.
*              The memCallocEM function first tries to
*              reallocate the memory from the external
*              memory partition. However,
*              if not enough space exists in the external
*              memory partition to satisfy the dynamic
*              memory allocation, memCallocEM then tries
*              the allocation from the internal memory partition.
*
* Arguments:
*       num  - the number of elements
*       size - the size of the memory buffer to be
*              allocated in external memory
*
* Return:      If memory is insufficient to satisfy the request
*              from either partition, memCallocIM returns NULL
*
*******************************************************/
void *  memCallocEM (size_t num, size_t size)
{
  void * pMem;

  pMem = memCalloc (&ExternalMemoryPool, num, size);
  if (pMem == NULL) {
    pMem = memCalloc (&InternalMemoryPool, num, size);
  }
  return pMem;
}


/*******************************************************
*
* Method: memReallocEM
*
* Description: This function dynamically reallocates and
*              resizes a memory buffer to the specified
*              size from the memory partitions. The function
*              memReallocEM first tries to reallocate
*              the memory from the external memory partition.
*              However, if not enough space exists in
*              the external memory partition to satisfy
*              the dynamic memory allocation, memReallocEM
*              then tries the allocation from the internal
*              memory partition
*
* Arguments:
*   memblock - the address of the existing memory block
*              to reallocate
*       size - the new size of the memory buffer to be
*              allocated in internal memory
*
* Return:      If memory is insufficient to satisfy the request
*              from either partition, memReallocIM returns NULL
*
*******************************************************/
void * memReallocEM ( void *memblock, size_t size )
{
  void * pMem;

  pMem = memRealloc (&ExternalMemoryPool, memblock, size);
  if (pMem == NULL) {
    pMem = memRealloc (&InternalMemoryPool, memblock, size);
  }
  return pMem;
}


/*******************************************************
*
* Method: memMallocAlignedEM
*
* Description: This function allocates dynamic memory
*              of the specified size from the memory
*              partitions and aligns the memory properly
*              to use modulo addressing. The function
*              memMallocAlignedEM first tries to allocate
*              the memory, properly aligned, from
*              the external memory partition. However,
*              if not enough space exists in the external
*              memory partition to satisfy the dynamic
*              memory allocation, or if the memory request
*              cannot be properly aligned, memMallocAlignedEM
*              then tries the allocation from the internal
*              memory partition. If memMallocAlignedEM
*              cannot allocate an aligned buffer from
*              either partition, it calls memMallocEM
*              to try to allocate a buffer of the correct
*              size without the proper alignment.
*
* Arguments:
*       size - the new size of the memory buffer to be
*              allocated in internal memory
*
* Return:      If memory is insufficient to satisfy the request
*              from either partition, memMallocAlignedIM returns NULL
*
*******************************************************/
void *  memMallocAlignedEM (size_t size)
{
  void * pMem;

  pMem = memMallocAligned (&ExternalMemoryPool, size);
  if (pMem == NULL) {
    pMem = memMallocAligned (&InternalMemoryPool, size);
    if (pMem == NULL) {
      pMem = memMallocEM (size);
    }
  }
  return pMem;
}


/*******************************************************
*
* Method: memFreeEM
*
* Description: This function deallocates a memory block
*              in external memory that previously had
*              been dynamically allocated with
*              the routine memMallocEM.
*
* Arguments:
*   memblock - pointer to previously allocated memory
*
* Return:      None
*
*******************************************************/
void    memFreeEM   (void * memblock)
{
  if (memIsEM(memblock)) {
    memFree (&ExternalMemoryPool, memblock);
  }
  else {
    memFree (&InternalMemoryPool, memblock);
  }
}


/*******************************************************
*
* Method: memIsAligned
*
* Description: This function checks the address of
*              a memory block to determine whether
*              it is properly aligned to use modulo
*              addressing.
*
* Arguments:
*   memblock - the address of the memory block
*              to check alignment for modulo addressing
*       size - the size to which the block should
*              be aligned for modulo addressing
*
* Return:      The function memIsAligned returns true
*              if the address is aligned so that modulo
*              addressing can be used; otherwise, it
*              returns false.
*
*******************************************************/
bool    memIsAligned (void * memblock, size_t size)
{
  UInt16 Modulo;                       /* Modulo of the defined memory size */
  UInt16 ModuloMask;                   /* Bits mask of the modulo size */

  Modulo = 1;                          /* Set minimal modulo */
  while(size > Modulo){
    Modulo=Modulo << 1;                /* Set modulo to a double modulo (2,4,8,16, ...) */
  }
  ModuloMask = Modulo - 1;             /* Set bits mask of the modulo */
  return (((UInt16)memblock & ModuloMask) == 0); /* TRUE  - memblock mod Modulo = 0 */
                                       /* FALSE - memblock mod Modulo > 0 */
}


/*******************************************************
* Mem
*
* Description:
*   General-purpose ANSI C-compliant memory pool manager.
*
* Author:
*   Mark Glenn
*
* Design:
*   These routines manage a memory buffer that you specify, internally
*   called the pool.  Blocks of memory are allocated from and returned
*   to this pool.
*
*   The first UInt32 of every block is the size of the block
*   in bytes, inclusive.  This value is positive if the block is free,
*   negative if the block is in use, and zero if this is the last block
*   of the pool.
*******************************************************/

/* The header for each memory block in a pool. */
#pragma warn_padding off
typedef struct {
  /* The size of the block. This includes the size of this sBlockHead. */
  Int32 Size;
} sBlockHead;

/* sPool -- Holds the state of a memory pool. */
typedef struct {
  /* Points to the first block of the pool. */
  sBlockHead * pFirst;
  /* Points to the last block of the pool. */
  sBlockHead * pLast;
  /* Points to a block within the pool.  It is used
  // to remain "close" to memory most likely to be free.  We could just
  // start from the beginning of the pool each time, but then we would
  // very likely have to skip over many in-use blocks, especially as
  // memory is allocated from a fresh pool.  We wrap to pFirst if
  // there isn't enough memory between pCurrent and the end of the pool,
  // to satisfy the request. */
  sBlockHead * pCurrent;
  /* If set, aborts the program when the memory pool is
  // exhausted.  Otherwise, behave as ANSI requires. */
  bool Assert;
  /* True if we are to mutex-protect the pool. */
  bool Protect;
} sPool;
#pragma warn_padding reset


/*******************************************************
*
* Method: memProtect
*
* Description: This function set memory protection.
*
* Arguments:
*   pMemPool - pointer to the memory pool
*
* Return:      None
*
*******************************************************/
extern void memProtect(mem_sPool * pMemPool)
{
  sPool * pPool=(sPool *)pMemPool;

  pPool -> Protect=true;
}


/*******************************************************
*
* Method: memCleanUp
*
* Description: This function cleans memory.
*              Starting from the beginning of the pool,
*              merge blocks that are not in use.
*              Stop at the first in-use block.
*
* Arguments:
*   pMemPool - pointer to the memory pool
*
* Return:      Size of the free memory
*
*******************************************************/
extern size_t memCleanUp(mem_sPool * pMemPool)
{
  bool            bSatMode;
  sPool         * pPool       = (sPool *) pMemPool;
  sBlockHead    * pBlock      = pPool -> pFirst;
  sBlockHead    * pFirstBlock = pBlock;
  Int32           TotalSize   = 0;
  Int32           Size;

  bSatMode = archGetSetSaturationMode(false);
  pPool -> pCurrent = pBlock;
  while (Size = pBlock -> Size, Size != 0) {
    if (Size < 0) break;
    TotalSize += Size;
    pBlock = (sBlockHead *) (((char *) pBlock) + Size);
  }
  pFirstBlock -> Size = TotalSize;
  archGetSetSaturationMode(bSatMode);
  return (size_t)TotalSize;
}


/*******************************************************
*
* Method: MergeFree
*
* Description: This function assumes that pBlock points to a block not in-use.
*              Checks the block following to determine its state.  If it is not in-use,
*              merge it to the current block.  pBlock will not change, but the
*              size of the block to which it points may increase.
*
* Arguments:
*      pPool - pointer to the memory pool
*     pBlock - pointer to the memory pool
* SizeNeeded - size of the memory block
*
* Return:      None
*
*******************************************************/
static Int32 MergeFree(sPool* pPool, sBlockHead * pBlock, Int32 SizeNeeded)
{
  bool  bSatMode;
  Int32 CurrentSize = pBlock -> Size;

  bSatMode = archGetSetSaturationMode(false);
  assert ((((UWord16)pBlock) & 0x0001) == 0); /* Ensure that pBlock is double-word aligned */
  while (true) {
    sBlockHead * pNext;
    Int32        NextSize;

    /* Get a pointer to the next block and retrieve it's size. */
    pNext = ((sBlockHead *)(((char *) pBlock) + CurrentSize));
    assert ((((UWord16)pNext) & 0x0001) == 0); /* Ensure that pNext is double-word aligned */
    NextSize  = pNext -> Size;
    assert ((NextSize & 0x0003) == 0); /* Ensure that NextSize is double-word aligned */
    /* If the next block is in use or is the last block (Size == 0), return. */
    if (NextSize <= 0) {
      assert ((CurrentSize & 0x0003) == 0); /* Ensure that NextSize is double-word aligned */
      pBlock -> Size = CurrentSize;
      archGetSetSaturationMode (bSatMode);
      return CurrentSize;
    }
    /* Increment the known size of the current block.  We won't store it
    // until we are about to leave the routine. */
    CurrentSize += NextSize;
    /* If pCurrent happens to point to the block that we are about
    // to combine, reset it to point to the beginning of the merged block. */
    if (pNext == pPool -> pCurrent)
      pPool -> pCurrent = pBlock;

    /* Optimized to get out as soon as we know we can satisfy the request. */
    if (CurrentSize >= SizeNeeded) {
      assert ((CurrentSize & 0x0003) == 0); /* Ensure that NextSize is double-word aligned */
      pBlock -> Size = CurrentSize;
      archGetSetSaturationMode (bSatMode);
      return CurrentSize;
    }
  }
}

/*******************************************************
*
* Method: SplitBlock
*
* Description: Assumes that pBlock points to a block larger than SizeNeeded.
*              If the block is large enough to contain SizeNeeded plus another block,
*              the block is split.  The area returned to the user is the user
*              portion of the first block.  The remainder in its entirety will
*              be set to describe a not-in-use block.
*
* Arguments:
*      pPool - pointer to the memory pool
*     pBlock - pointer to the memory pool
* SizeNeeded - size of the memory block
*
* Return:      None
*
*******************************************************/
#pragma warn_unusedarg off
static void * SplitBlock(sPool * pPool, sBlockHead * pBlock, Int32 SizeNeeded)
{
  bool           bSatMode;
  Int32          Remainder;
  sBlockHead   * pUser     = pBlock + 1;
  Int32          BlockSize = pBlock -> Size;

  bSatMode = archGetSetSaturationMode(false);
  assert ((((UWord16)pBlock) & 0x0001) == 0); /* Ensure that pBlock is double-word aligned */
  #ifdef ADDRESSING_8
  /* Allocate in 4 8-bit units only. */
  SizeNeeded = (SizeNeeded + 3) & ~3;
  #endif
  if ((Remainder = BlockSize - SizeNeeded) > sizeof(sBlockHead)) {
    assert ((Remainder & 0x0003) == 0); /* Ensure that Remainder is double-word aligned */
    assert ((SizeNeeded & 0x0003) == 0); /* Ensure that Remainder is double-word aligned */
    /* Set the size of the first part of the split. */
    pBlock -> Size = -SizeNeeded;
    /* Point to the next block of the split. */
    pBlock = (sBlockHead *) ((char *) pBlock + SizeNeeded);
    assert ((((UWord16)pBlock) & 0x0001) == 0); /* Ensure that pBlock is double-word aligned */
    pBlock -> Size  = Remainder;
  }
  else {
    /* Don't split block. */
    pBlock -> Size = -BlockSize;
    pBlock         = (sBlockHead *) ((char *) pBlock + BlockSize);
    assert ((((UWord16)pBlock) & 0x0001) == 0); /* Ensure that pBlock is double-word aligned */
  }

  /* Store a pointer to a likely candidate block. */
  pPool -> pCurrent = pBlock;
  archGetSetSaturationMode(bSatMode);
  return pUser;
}
#pragma warn_unusedarg reset

/*******************************************************
*
* Method: SplitBlockRev
*
* Description: Assumes that pBlock points to a block larger than SizeNeeded.
*              If the block is large enough to contain SizeNeeded plus another block,
*              the block is split.  The area returned is the
*              portion of the end of the block.  The remainder in its entirety will
*              be set to describe a not-in-use block.
*
* Arguments:
*      pPool - pointer to the memory pool
*     pBlock - pointer to the memory pool
* SizeNeeded - size of the memory block
*
* Return:      None
*
*******************************************************/
#pragma warn_unusedarg off
static void * SplitBlockRev(sPool * pPool, sBlockHead * pBlock, UInt32 SizeNeeded)
{
  bool           bSatMode;
  sBlockHead   * pUser;
  Int32          BlockSize = pBlock -> Size;

  bSatMode  = archGetSetSaturationMode(false);
  assert ((((UWord16)pBlock) & 0x0001) == 0); /* Ensure that pBlock is double-word aligned */
  #ifdef ADDRESSING_8
  /* Allocate in 4 8-bit units only. */
  SizeNeeded &= ~3;
  #endif
  if (SizeNeeded >= sizeof(sBlockHead)) {
    /* Set the size of the user part of the split. */
    pUser = (sBlockHead *)(((char *)pBlock) + SizeNeeded);
    assert ((((UWord16)pUser) & 0x0001) == 0); /* Ensure that pBlock is double-word aligned */
    assert (((BlockSize - SizeNeeded) & 0x0003) == 0); /* Ensure that Remainder is double-word aligned */
    pUser -> Size  = (Int32) (BlockSize - SizeNeeded);
    assert ((pUser -> Size & 0x0003) == 0); /* Ensure that pUser -> Size is double-word aligned */
    assert ((SizeNeeded & 0x0003) == 0); /* Ensure that Remainder is double-word aligned */
    pBlock -> Size = (Int32) SizeNeeded;
    assert ((pBlock -> Size & 0x0003) == 0); /* Ensure that pUser -> Size is double-word aligned */
  }
  else {
    pUser = pBlock;
  }
  /* Store a pointer to a likely candidate block. */
  archGetSetSaturationMode(bSatMode);
  return pUser;
}
#pragma warn_unusedarg reset


/*******************************************************
*
* Method: memInitializePool
*
* Description: This function Initializes the memory pool to all zeroes.
*              Brackets the pool with two blocks: The last sizeof(UInt32)
*              bytes will be set to 0 to indicate the last block of the pool.
*              The first sizeof(UInt32) bytes of the pool will be set
*              to the size of the remainder of the pool.
*
* Arguments:
*   pMemPool - pointer to the memory pool
*       pMem - pointer to the memory
*       Size - size of the memory block
*    Protect - TRUE = enable protect memory
*     Assert - TRUE = enable assert
*
* Return:      None
*
*******************************************************/
extern void memInitializePool(mem_sPool * pMemPool,
                    void      * pMem,
                    size_t      Size,
                    bool        Protect,
                    bool        Assert)
{
  bool         bSatMode;
  sBlockHead * pFirst = (sBlockHead *)pMem;
  sBlockHead * pLast;
  sPool      * pPool = (sPool *) pMemPool;

  bSatMode = archGetSetSaturationMode(false);
  /* Ensure that pFirst is double-word aligned */
  assert ((((UWord16)pFirst) & 0x0001) == 0);
  /* Ensure that enough memory has been allocated */
  assert (Size >= 2 * sizeof(sBlockHead));
  /* Make sure that we've allocated enough space for the mem pool. */
  assert(sizeof(mem_sPool) >= sizeof(sPool));
  /* Clear the entire memory pool. */
  memset((void *)pFirst, 0, Size);
  /* Mark the first block with the size of the entire allocatable memory
  // pool.  The size always includes the size of the sBlockHead. */
  Size -= sizeof(*pLast);
  /* Ensure that Remainder is double-word aligned */
  assert ((Size & 0x0003) == 0);
  pFirst -> Size = (Int32)Size;
  /* Point pLast to end of the memory pool and mark the end block with a
  // zero end marker. */
  pLast = (sBlockHead *) ((char *) pFirst + Size);
  /* Ensure that pLast is double-word aligned */
  assert ((((UWord16)pLast) & 0x0001) == 0);
  pLast -> Size  = 0;
  /* If the user wants atomic access to this memory pool... */
  if (Protect) {
    memProtect((mem_sPool *) pPool);
  }
  /* Prime the memory pool. */
  pPool -> Assert      = Assert;
  pPool -> pFirst      = pFirst;
  pPool -> pLast       = pLast;
  pPool -> pCurrent    = pFirst;
  pPool -> Protect     = Protect;
  archGetSetSaturationMode(bSatMode);
}


/*******************************************************
*
* Method: memExtendPool
*
* Description: Initializes the memory pool extension to all zeroes.  Extends the
*              pool previously initialized with memInitializePool.
*
* Arguments:
*   pMemPool - pointer to the memory pool
*       pMem - pointer to the memory block
*       Size - size of the memory block
*
* Return:      None
*
*******************************************************/
void memExtendPool ( mem_sPool * pMemPool,
              void      * pMem,
              size_t      Size
              )
{
  bool         bSatMode;
  sBlockHead * pFirst = (sBlockHead *)pMem;
  sBlockHead * pLast;
  sBlockHead * pTemp;
  sBlockHead * pNext;
  sPool      * pPool  = (sPool *) pMemPool;

  bSatMode = archGetSetSaturationMode(false);
  /* Ensure that pFirst is double-word aligned */
  assert ((((UWord16)pFirst) & 0x0001) == 0);
  /* Ensure that enough memory has been allocated */
  assert (Size >= 2 * sizeof(sBlockHead));
  /* Clear the entire memory pool. */
  memset((void *)pFirst, 0, Size);
  /* Mark the first block with the size of the entire extension
  // The size always includes the size of the sBlockHead. */
  Size -= sizeof(*pLast);
  /* Ensure that Remainder is double-word aligned */
  assert ((Size & 0x0003) == 0);
  pFirst -> Size = (Int32)Size;
  /* Point pLast to end of the memory pool and mark the end block with a
  // zero end marker. */
  pLast         = (sBlockHead *) ((char *) pFirst + Size);
  assert ((((UWord16)pLast) & 0x0001) == 0); /* Ensure that pBlock is double-word aligned */
  /* Link the extension into the pool */
  if (pLast < pPool->pFirst) {
    pLast->Size   = (Int32)((UInt32)((char*)pLast) - (UInt32)((char*)(pPool->pFirst)));
    pPool->pFirst = pFirst;
  } else if (pFirst > pPool->pLast) {
    pPool->pLast->Size = (Int32)(((UInt32)((char*)(pPool->pLast))) - ((UInt32)((char*)pFirst)));
    pLast->Size  = 0;
    pPool->pLast = pLast;
  } else {
    pTemp = pPool->pFirst;
    while (true) {
      if (pTemp->Size > 0) {
        pTemp = (sBlockHead *)(((char *)pTemp) + pTemp->Size);
        /* Ensure that pBlock is double-word aligned */
        assert ((((UWord16)pTemp) & 0x0001) == 0);
      } else {
        pNext = (sBlockHead *)(((char *)pTemp) - pTemp->Size);
        /* Ensure that pBlock is double-word aligned */
        assert ((((UWord16)pNext) & 0x0001) == 0);
        if (pFirst > pTemp && pLast < pNext) {
          pTemp->Size = (Int32)((UInt32)((char*)pTemp) - (UInt32)((char*)pFirst));
          /* Ensure that Remainder is double-word aligned */
          assert ((pTemp->Size & 0x0003) == 0);
          pLast->Size = (Int32)((UInt32)((char *)pLast) - (UInt32)((char *)pNext));
          /* Ensure that Remainder is double-word aligned */
          assert ((pLast->Size & 0x0003) == 0);
          break;
        }
        pTemp = pNext;
      }
    }
  }
  archGetSetSaturationMode (bSatMode);
}

/*******************************************************
*
* Method: memFree
*
* Description: This method frees the allocated memory.
*
* Arguments:
*   pMemPool - pointer to the memory pool
*
* Return:      None
*
*******************************************************/
#pragma warn_unusedarg off
extern void memFree(mem_sPool * pMemPool, void * pData)
{
  bool         bSatMode;
  sBlockHead * pBlock = pData;

  /* The following two lines are a check to ensure that
  // dynamic memory has been enabled in the SDK application.
  // If the user has failed to either "#define INCLUDE_MEMORY"
  // in the AppConfig.h file or include a dynamic memory
  // partition list in the linker.cmd file, he will now get
  // a link error. */
  extern UInt16 memNumEMpartitions;

  bSatMode = (bool) memNumEMpartitions;
  assert (bMemInitialized);
  assert ((((UWord16)pBlock) & 0x0001) == 0); /* Ensure that pBlock is double-word aligned */
  /* If pData is NULL, return, per ANSI C. */
  if (pData == NULL)
    return;
  bSatMode = archGetSetSaturationMode(false);
  pBlock -= 1;
  if (pBlock -> Size > 0) {
    assert(!"Attempt to free memory never allocated or previously freed");
  }
  /* Make the block available. */
  /* Ensure that Remainder is double-word aligned */
  assert ((pBlock->Size & 0x0003) == 0);
  pBlock -> Size = -(pBlock -> Size);
  archGetSetSaturationMode (bSatMode);
}
#pragma warn_unusedarg reset


/*******************************************************
*
* Method: memMallocWrapper
*
*******************************************************/
#pragma warn_unusedarg off
extern void * memMallocWrapper(mem_sPool * pPool, size_t Size,
                                const char *pFile, int Line)
{
  void       * pData;

  /* Call the base allocator.  We use the parenthesis to prevent the
  // preprocessor from substituting memMalloc with memMallocWrapper,
  // causing endless recursion into this routine. */
  pData = (memMalloc)(pPool, Size);
  if (pData == NULL)
    return (void *) NULL;
  return pData;
}
#pragma warn_unusedarg reset

/*******************************************************
*
*  memMalloc
*     If the size requested is 0, return NULL, per ANSI C.
*
*  LABEL:
*     WHILE we haven't yet allocated a block DO
*       Skip blocks in use.
*
*       IF we hit the tail block of the pool THEN
*         IF we have already wrapped through the pool once THEN
*           return NULL to indicate failure to allocate.
*         ELSE
*           Reset the block pointer to the first block of the pool.
*           Indicate that we have wrapped around.
*           Continue from LABEL.
*       ENDIF
*
*       Merge all contiguous free blocks from the current block to the
*         first in-use block or the end of the pool.
*       IF the consolidated block satisfies the request THEN
*         Split the block, if it is large enough and return the first block
*           of the split.
*       ENDIF
*
*       Bump the block search pointer to the next block
*     ENDWHILE
*
*******************************************************/
void * (memMalloc)(mem_sPool * pMemPool, size_t Size)
{
  bool         bSatMode;
  Int32        SizeNeeded = (Int32) Size;
  Int32        BlockSize;
  int          Wrapped;
  sBlockHead * pBlock;
  void       * pMemory    = (void *) NULL;
  sPool      * pPool      = (sPool *) pMemPool;
  /* The following two lines are a check to ensure that
  // dynamic memory has been enabled in the SDK application.
  // If the user has failed to either "#define INCLUDE_MEMORY"
  // in the AppConfig.h file or include a dynamic memory
  // partition list in the linker.cmd file, he will now get
  // a link error. */
  extern UInt16 memNumEMpartitions;

  BlockSize = memNumEMpartitions;
  if(bMemInitialized == false) {
    Initialize();
  }
  if (SizeNeeded == 0) return (void *) NULL;
  bSatMode = archGetSetSaturationMode(false);
  #ifdef ADDRESSING_8
  /* Allocate in 4 8-bit units only. */
  SizeNeeded = ((SizeNeeded + 3) & ~3);
  #endif
  SizeNeeded += sizeof(sBlockHead);
  assert ((SizeNeeded & 0x0003) == 0); /* Ensure that SizeNeeded is double-word aligned */
  pBlock  = pPool -> pCurrent;
  assert ((((UWord16)pBlock) & 0x0001) == 0); /* Ensure that pBlock is double-word aligned */
  Wrapped = false;
  while (true) {
    /* Skip blocks in use. */
    while (true) {
      BlockSize = pBlock -> Size;
      if (BlockSize >= 0) break;
      /* Typecasting required to force 32 bit operation and preserve negative BlockSize */
      pBlock = (sBlockHead *) (((UInt32)((char *)pBlock) - BlockSize)/2);
      assert ((((UWord16)pBlock) & 0x0001) == 0); /* Ensure that pBlock is double-word aligned */
    }
    /* Found a block that is not in use.  If it's the last block of the pool,
    // wrap to the beginning. If we reach the end after wrapping, then we're
    // out of memory. */
    if (BlockSize == 0) {
      if (Wrapped) break;
      pBlock  = pPool -> pFirst;
      assert ((((UWord16)pBlock) & 0x0001) == 0); /* Ensure that pBlock is double-word aligned */
      Wrapped = true;
      continue;
    }
    /* We're now at a block that is not in use.  We optimize for
    // the hopeful case, where the current blocksize is big
    // enough and we don't have to make a costly call to merge
    // free blocks.  If the block is big enough, we split it
    // and leave the loop. */
    if (BlockSize >= SizeNeeded) {
      pMemory = SplitBlock(pPool, pBlock, SizeNeeded);
      break;
    }
    /* Merge free blocks that immediately follow this one in an
    // attempt to make the current block big enough. */
    BlockSize = MergeFree(pPool, pBlock, SizeNeeded);
    /* If the (now merged) free block is big enough, we split it in two
    // if the remainder is big enough to make it worthwhile.
    //
    // If the block still isn't big enough, at least we made a bigger
    // free block that will make for faster allocations later. */
    if (BlockSize >= SizeNeeded) {
      pMemory = SplitBlock(pPool, pBlock, SizeNeeded);
      break;
    }
    /* Move to the next candidate block and loop back up to try again */
    pBlock = (sBlockHead *) ((char *) pBlock + BlockSize);
    assert ((((UWord16)pBlock) & 0x0001) == 0); /* Ensure that pBlock is double-word aligned */
  }
  if (pPool -> Assert && pMemory == NULL) {
    #ifdef MEM_VERBOSE
    memPrintAllocatedBlocks(pMemPool);
    #endif
    assert(!"Out of Memory");
  }
  archGetSetSaturationMode(bSatMode);
  if (pMemory == NULL) return (void *) NULL;
  return pMemory;
}


/*******************************************************
*
*  memMallocAligned
*     Allocate memory aligned so that it ends on a 2**k boundary.
*
*     If the size requested is 0, return NULL, per ANSI C.
*
*  LABEL:
*     WHILE we haven't yet allocated a block DO
*       Skip blocks in use.
*
*       IF we hit the tail block of the pool THEN
*         IF we have already wrapped through the pool once THEN
*           return NULL to indicate failure to allocate.
*         ELSE
*           Reset the block pointer to the first block of the pool.
*           Indicate that we have wrapped around.
*           Continue from LABEL.
*       ENDIF
*
*       Merge all contiguous free blocks from the current block to the
*         first in-use block or the end of the pool.
*       IF the consolidated block satisfies the request THEN
*         Split the block, if it is large enough, and return the
*           aligned block of the split.
*       ENDIF
*
*       Bump the block search pointer to the next block
*     ENDWHILE
*
*******************************************************/
void * (memMallocAligned)(mem_sPool * pMemPool, size_t Size)
{
  bool         bSatMode;
  Int32        SizeNeeded = (Int32) Size;
  Int32        BlockSize;
  int          Wrapped;
  sBlockHead * pBlock;
  void       * pMemory    = (void *) NULL;
  sPool      * pPool      = (sPool *) pMemPool;
  UInt32     Modulo;
  UInt32       ModuloMask;
  Int32        pStartOfModBuffer;
  Int32        pEndOfModBuffer;
  Int32        SpareWords;

  if(bMemInitialized == false) {
    Initialize();
  }
  if (SizeNeeded == 0)
    return (void *) NULL;
  bSatMode = archGetSetSaturationMode(false);
  Modulo = 1;
  while (SizeNeeded > Modulo)
  {
    Modulo = Modulo << 1;
  }
  ModuloMask = Modulo - 1;
  ModuloMask = ~ ModuloMask;
  #ifdef ADDRESSING_8
  /* Allocate in 4 8-bit units only. */
  SizeNeeded = ((SizeNeeded + 3) & ~3);
  #endif
  SizeNeeded += sizeof(sBlockHead);
  pBlock  = pPool -> pCurrent;
  Wrapped = false;
  while (true) {
    /* Skip blocks in use. */
    while (true) {
      BlockSize = pBlock -> Size;
      if (BlockSize >= 0)
        break;
      /* Typecasting required to force 32 bit operation and preserve negative BlockSize */
      pBlock = (sBlockHead *) (((UInt32)((char *)pBlock) - BlockSize)/2);
      assert ((((UWord16)pBlock) & 0x0001) == 0); /* Ensure that pBlock is double-word aligned */
    }
    /* Found a block that is not in use.  If it's the last block of the pool,
    // wrap to the beginning. If we reach the end after wrapping, then we're
    // out of memory. */
    if (BlockSize == 0) {
      if (Wrapped) {
        break;
      }
      pBlock  = pPool -> pFirst;
      Wrapped = true;
      continue;
    }
    /* Merge free blocks that immediately follow this one in an
    // attempt to make the current block big enough;  ask for 2 * SizeNeeded
    // in order to bracket an aligned area */
    BlockSize = MergeFree(pPool, pBlock, SizeNeeded+SizeNeeded);
    /* If the (now merged) free block is big enough, we split it in two
    // if the remainder is big enough to make it worthwhile.
    //
    // If the block still isn't big enough, at least we made a bigger
    // free block that will make for faster allocations later. */
    if (BlockSize >= SizeNeeded) {
      pStartOfModBuffer = (Int32)(((((Int32)(((char *)pBlock) + Modulo  - 1)) & ModuloMask)) - sizeof(sBlockHead));
      while (true)
      {
        SpareWords = pStartOfModBuffer - (Int32)((char *)pBlock);
                if ((SpareWords == 0) || (SpareWords >= ((Int32)sizeof(sBlockHead))))
        {
          break;
        }
        pStartOfModBuffer = (Int32) (pStartOfModBuffer + Modulo);
      }
      pEndOfModBuffer = pStartOfModBuffer + SizeNeeded - 1;
      if (pEndOfModBuffer < ((Int32)((char *)pBlock)) + BlockSize)
      {
        pMemory = SplitBlockRev(pPool,
                        pBlock,
                        (UInt32) SpareWords);
        pMemory = SplitBlock   (pPool,
                        pMemory,
                        SizeNeeded);
        break;
      }
    }
    /* Move to the next candidate block and loop back up to try again */
    pBlock = (sBlockHead *) ((char *) pBlock + BlockSize);
    assert ((((UWord16)pBlock) & 0x0001) == 0); /* Ensure that pBlock is double-word aligned */
  }
  if (pPool -> Assert && pMemory == NULL) {
    #ifdef MEM_VERBOSE
    memPrintAllocatedBlocks(pMemPool);
    #endif
    assert(!"Out of Memory");
  }
  archGetSetSaturationMode (bSatMode);
  if (pMemory == NULL)
    return (void *) NULL;
  return pMemory;
}

/*******************************************************
*
* Method: memRealloc
*
* Description: This function dynamically reallocates an array
*
*******************************************************/
extern void * memRealloc(mem_sPool * pMemPool,void * pData,
                                      size_t SizeRequested)
{
  bool           bSatMode;
  Int32          OriginalSize;
  Int32          SizeNeeded;
  Int32          Size = (Int32) SizeRequested;
  sBlockHead    * pBlock = (sBlockHead *) pData;
  void          * pMem;
  sPool         * pPool = (sPool *) pMemPool;

  if(bMemInitialized == false)
  {
    Initialize();
  }
  if (Size == 0) {
    memFree(pMemPool, pData);
    return (void *) NULL;
  }
  if (pData == NULL) {
    return (memMalloc)(pMemPool, (size_t) Size);
  }
  bSatMode = archGetSetSaturationMode(false);
  /* Back up to the block's header. */
  pBlock -= 1;
  #ifdef ADDRESSING_8
  /* Allocate in 4 complete 8-bit units only. */
  SizeNeeded = ((Size + 3) & ~3);
  #else
  SizeNeeded = Size;
  #endif
  SizeNeeded += sizeof(sBlockHead);
  pBlock -> Size = -(pBlock -> Size);
    OriginalSize = (Int32)(pBlock -> Size - sizeof(sBlockHead));
  /* Merge free memory blocks immediately following the one pointed to
  // by pBlock to see if we can avoid having to copy the data. */
  if (MergeFree(pPool, pBlock, SizeNeeded) >= SizeNeeded) {
    pMem = SplitBlock(pPool, pBlock, SizeNeeded);
  }
  else {
    pMem = (void *) NULL;
    pBlock -> Size = -(pBlock -> Size);
  }
  archGetSetSaturationMode (bSatMode);
  /* If the allocation was successful, we're done. */
  if (pMem != NULL) {
    return pMem;
  }
  /* We were not able to extend the block in place.  Now we have to
  // allocate a brand new block. */
  if ((pMem = (memMalloc)(pMemPool, (size_t) Size)) == NULL)  {
    return (void *) NULL;
  }
  /* Copy the data from the old memory area to the new.  If the new
  // block is larger than the old block, copy all the original data.
  // If the new size is smaller (the user is trimming the data), only
  // copy as much old data as will fit into the new area. */
  memcpy(pMem, pData, (size_t) (Size < OriginalSize ? Size : OriginalSize));
  /* Once the original data is copied to the new memory, free the
  // original memory. */
  memFree(pMemPool, pData);
  return pMem;
}

/*******************************************************
*
* Method: memCalloc
*
* Description: This function dynamically allocates an array
*              with elements initialized to zero.
*
* Arguments:
*      pPool - memory pool
*   Elements - number of the elements
* ElementSize - size of the element
*
* Return:      None
*
*******************************************************/
extern void * memCalloc(mem_sPool * pPool, size_t Elements, size_t ElementSize)
{
  size_t      TotalSize = Elements * ElementSize;
  void      * pMemory   = (memMalloc)(pPool, TotalSize);

  if (pMemory == (void *) NULL)
    return (void *) NULL;
  memset(pMemory, 0, TotalSize);
  return pMemory;
}


static sBlockHead EmptyInternalMemoryPool[2];
static sBlockHead EmptyExternalMemoryPool[2];

/*******************************************************
*
* Method: Initialize
*
* Description: This function initializes the memory manager
*              driver.
*
* Arguments:   None
*
* Return:      None
*
*******************************************************/
static void Initialize (void)
{
  UInt16                 i;
  const mem_sPartition * pPartitionList;
  /* Initialize empty pools */
  memInitializePool (  &InternalMemoryPool,
                EmptyInternalMemoryPool,
                sizeof (EmptyInternalMemoryPool),
                false,
                false
              );
  memInitializePool (  &ExternalMemoryPool,
                EmptyExternalMemoryPool,
                sizeof (EmptyExternalMemoryPool),
                false,
                false
              );

  switch (InitialState.EXbit)
  {
    case 0:
        pPartitionList = InitialState.intPartitionList;
        for (i=0; i<InitialState.numIntPartitions; i++) {
          assert (memIsIM(pPartitionList -> partitionAddr));
          memExtendPool (&InternalMemoryPool,
                    pPartitionList -> partitionAddr,
                    pPartitionList -> partitionSize
                    );
          pPartitionList++;
        }
        pPartitionList = InitialState.extPartitionList;
        for (i=0; i<InitialState.numExtPartitions; i++) {
          assert (memIsEM(pPartitionList -> partitionAddr));
          memExtendPool (&ExternalMemoryPool,
                    pPartitionList -> partitionAddr,
                    pPartitionList -> partitionSize
                    );
          pPartitionList++;
        }
        break;
    case 1:
        /* Ensure that no internal partitions were specified with the external memory map */
        assert (InitialState.numIntPartitions == 0);
        pPartitionList = InitialState.extPartitionList;
        for (i=0; i<InitialState.numExtPartitions; i++) {
          assert (memIsEM(pPartitionList -> partitionAddr));
          memExtendPool (&ExternalMemoryPool,
                    pPartitionList -> partitionAddr,
                    pPartitionList -> partitionSize
                    );
          pPartitionList++;
        }
        break;
    default:
        assert (false);
        break;
  }
  bMemInitialized = true;
}


/*******************************************************
*
* Method: memInitialize
*
* Description: This function initializes the memory manager
*              data structure (InitialState).
*
* Arguments:
*  pMemoryState  - parametr will be copied to InitialState variable
*
* Return:      None
*
*******************************************************/
EXPORT void    memInitialize (mem_sState * pMemoryState)
{
  /* Copy MemoryState to InitialState */
  memcpy((void *)&InitialState, (const void *)pMemoryState, sizeof(mem_sState));
}
