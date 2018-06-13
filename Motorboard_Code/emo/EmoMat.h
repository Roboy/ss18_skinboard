/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **********************************************************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* See Mat.c */

#ifndef MAT_H
#define MAT_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "tle_device.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Function-like macro to multiply two fixed-point factors to get a standard fixed-point product */
#define Mat_FixMul(Factor1, Factor2) ((((sint32)(Factor1)) * ((sint32)(Factor2))) >> MAT_FIX_SHIFT)

/* Function-like macro to multiply two fixed-point factors to get a fixed-point product with scaling
 * e.g. scale = 1: shift result left by Scale */
#define Mat_FixMulScale(Factor1, Factor2, Scale) ((((sint32)(Factor1)) * ((sint32)(Factor2))) >> ((uint32)((sint32)MAT_FIX_SHIFT - (Scale))))

/* Shift value for fixed-point format */
#define MAT_FIX_SHIFT (15u)

/* Saturation bit for fixed-point format */
#define MAT_FIX_SAT (16u)

/* (1 / sqrt(3)) in fixed-point format */
#define MAT_ONE_OVER_SQRT_3 (18919u)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/** \brief PI status */
typedef struct
{
  sint32 IOut;     /**< \brief I output */
  sint16 Kp;       /**< \brief Proportional parameter */
  sint16 Ki;       /**< \brief Integral parameter */
  sint16 IMin;     /**< \brief Minimum for I output */
  sint16 IMax;     /**< \brief Maximum for I output */
  sint16 PiMin;    /**< \brief Minimum for PI output */
  sint16 PiMax;    /**< \brief Maximum for PI output */
}TMat_Pi;


/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

__STATIC_INLINE sint16 Mat_ExePi(TMat_Pi *pPi, sint16 Error);
__STATIC_INLINE uint16 Mat_ExeSimpleLp(uint32 *pOutput, uint16 Input, uint16 Fac);


/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
/** \brief Performs PI control algorithm.
 *
 * \param[inout] pPi Pointer to PI status
 * \param[in] Error Difference between reference and actual value
 *
 * \return PI output
 * \ingroup mat_api
 */
__STATIC_INLINE sint16 Mat_ExePi(TMat_Pi *pPi, sint16 Error)
{
  sint32 IOut;
  sint32 PiOut;
  sint32 Min;
  sint32 Max;
  sint32 Temp;

  /* I output = old output + error * I parameter */
  IOut = pPi->IOut + ((sint32)Error * (sint32)pPi->Ki);
  
  /* Limit I output */
  Min = ((sint32)(pPi->IMin)) << 15u;
  if (IOut < Min)
  {
    IOut = Min;
  }  
  else
  {
    Max = ((sint32)(pPi->IMax)) << 15u;
    if (IOut > Max)
    {
      IOut = Max;
    }  
  }    
  /* Store I output */
  pPi->IOut = IOut;

  /* PI output = upper half of (I output + saturate(error * P parameter) * 64) */
  Temp = __SSAT(Error * ((sint32)pPi->Kp), 31u - 6u);
  PiOut = (IOut + (Temp << 6u)) >> 15u;
  
  /* Limit PI output */
  Min = (sint32)(pPi->PiMin);
  if (PiOut < Min)
  {
    PiOut = Min;
  }  
  else
  {
    Max = (sint32)(pPi->PiMax);
    if (PiOut > Max)
    {
      PiOut = Max;
    }  
  }    
  return (sint16)PiOut;

} /* End of Mat_ExePi */


/** \brief Performs simple low-pass filter algorithm.
 *
 * \param[inout] pOutput Pointer to low-pass filter status
 * \param[in] Input Input
 * \param[in] Fac Factor (1..65535, time constant = sample period * 65536/Fac)
 *
 * \return Low-pass filter output (0..65535)
 * \ingroup mat_api
 */
uint16 Mat_ExeSimpleLp(uint32 *pOutput, uint16 Input, uint16 Fac)
{
    uint32 NegFac;
    uint32 Out;
    
    Out = *pOutput;
    
    /* Output = output - output * factor */
    NegFac = 0x10000u - (uint32)Fac;
    Out = (((Out & 0xFFFFu) * NegFac) >> 16u) + ((Out >> 16u) * NegFac);
    
    /* Output += input * factor */
    Out += (uint32)Input * (uint32)Fac;
    
    /* Store output */
    *pOutput = Out;
    
    /* Return upper rounded part */
    return (uint16)((Out + 0x8000u) >> 16u);
}


#endif /* MAT.H */
