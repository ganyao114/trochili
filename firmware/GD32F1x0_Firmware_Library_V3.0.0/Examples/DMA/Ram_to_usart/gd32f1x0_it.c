/*!
    \file  gd32f1x0_it.c
    \brief interrupt service routines
*/

/*
    Copyright (C) 2016 GigaDevice

    2014-12-26, V1.0.0, firmware for GD32F1x0(x=3,5)
    2016-01-15, V2.0.0, firmware for GD32F1x0(x=3,5,7,9)
    2016-04-30, V3.0.0, firmware update for GD32F1x0(x=3,5,7,9)
*/

#include "gd32f1x0_it.h"

extern __IO uint32_t transfer;

/*!
    \brief      this function handles NMI exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void NMI_Handler(void)
{
}

/*!
    \brief      this function handles HardFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void HardFault_Handler(void)
{
    /* if Hard Fault exception occurs, go to infinite loop */
    while (1);
}

/*!
    \brief      this function handles MemManage exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void MemManage_Handler(void)
{
    /* if Memory Manage exception occurs, go to infinite loop */
    while (1);
}

/*!
    \brief      this function handles BusFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void BusFault_Handler(void)
{
    /* if Bus Fault exception occurs, go to infinite loop */
    while (1);
}

/*!
    \brief      this function handles UsageFault exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void UsageFault_Handler(void)
{
    /* if Usage Fault exception occurs, go to infinite loop */
    while (1);
}

/*!
    \brief      this function handles SVC exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SVC_Handler(void)
{
}

/*!
    \brief      this function handles DebugMon exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void DebugMon_Handler(void)
{
}

/*!
    \brief      this function handles PendSV exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void PendSV_Handler(void)
{
}

/*!
    \brief      this function handles SysTick exception
    \param[in]  none
    \param[out] none
    \retval     none
*/
void SysTick_Handler(void)
{
}

#ifdef GD32F130_150

/*!
    \brief      this function handles DMA_Channel1_2_IRQHandler interrupt
    \param[in]  none
    \param[out] none
    \retval     none
*/
void DMA_Channel1_2_IRQHandler(void)
{
    if(dma_interrupt_flag_get(DMA_CH1,DMA_CHXCTL_FTFIF)){     
        transfer++;
        dma_interrupt_flag_clear(DMA_CH1,DMA_INTF_ANYIC);        
    }
}

#elif defined GD32F170_190

/*!
    \brief      this function handles DMA_Channel3_4_IRQHandler interrupt
    \param[in]  none
    \param[out] none
    \retval     none
*/
void DMA_Channel3_4_IRQHandler(void)
{
    if(dma_interrupt_flag_get(DMA_CH3,DMA_CHXCTL_FTFIF)){     
        transfer++;
        dma_interrupt_flag_clear(DMA_CH3,DMA_INTF_ANYIC);         
    }
}

#endif   /* GD32F130_150 */
