/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2011 LeafLabs, LLC.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/

#include <stdint.h>
#include "../sysdep.h"

#ifndef _USB_REG_MAP_H_
#define _USB_REG_MAP_H_

/* TODO:
 * - Pick one of "endp", "ep" "endpt"
 */

/*
 * Register map and base pointer
 */

#define USB_NR_EP_REGS                  8

/** USB register map type */
typedef struct usb_reg_map {
    volatile uint32_t EP[USB_NR_EP_REGS]; /**< Endpoint registers */
    const uint32_t RESERVED[8];       /**< Reserved */
    volatile uint32_t CNTR;               /**< Control register */
    volatile uint32_t ISTR;               /**< Interrupt status register */
    volatile uint32_t FNR;                /**< Frame number register */
    volatile uint32_t DADDR;              /**< Device address */
    volatile uint32_t BTABLE;             /**< @brief Buffer table address
                                     *
                                     * Address offset within the USB
                                     * packet memory area which points
                                     * to the base of the buffer
                                     * descriptor table.  Must be
                                     * aligned to an 8 byte boundary.
                                     */
} usb_reg_map;

/** USB register map base pointer */
#define USB_BASE                        ((struct usb_reg_map*)0x40005C00)

/*
 * Register bit definitions
 */

/* Endpoint registers (USB_EPnR) */

#define USB_EP_CTR_RX_BIT              15
#define USB_EP_DTOG_RX_BIT             14
#define USB_EP_SETUP_BIT               11
#define USB_EP_EP_KIND_BIT             8
#define USB_EP_CTR_TX_BIT              7
#define USB_EP_DTOG_TX_BIT             6

#define USB_EP_CTR_RX                  BIT(USB_EP_CTR_RX_BIT)
#define USB_EP_DTOG_RX                 BIT(USB_EP_DTOG_RX_BIT)
#define USB_EP_STAT_RX                 (0x3 << 12)
#define USB_EP_STAT_RX_DISABLED        (0x0 << 12)
#define USB_EP_STAT_RX_STALL           (0x1 << 12)
#define USB_EP_STAT_RX_NAK             (0x2 << 12)
#define USB_EP_STAT_RX_VALID           (0x3 << 12)
#define USB_EP_SETUP                   BIT(USB_EP_SETUP_BIT)
#define USB_EP_EP_TYPE                 (0x3 << 9)
#define USB_EP_EP_TYPE_BULK            (0x0 << 9)
#define USB_EP_EP_TYPE_CONTROL         (0x1 << 9)
#define USB_EP_EP_TYPE_ISO             (0x2 << 9)
#define USB_EP_EP_TYPE_INTERRUPT       (0x3 << 9)
#define USB_EP_EP_KIND                 BIT(USB_EP_EP_KIND_BIT)
#define USB_EP_CTR_TX                  BIT(USB_EP_CTR_TX_BIT)
#define USB_EP_DTOG_TX                 BIT(USB_EP_DTOG_TX_BIT)
#define USB_EP_STAT_TX                 (0x3 << 4)
#define USB_EP_STAT_TX_DISABLED        (0x0 << 4)
#define USB_EP_STAT_TX_STALL           (0x1 << 4)
#define USB_EP_STAT_TX_NAK             (0x2 << 4)
#define USB_EP_STAT_TX_VALID           (0x3 << 4)
#define USB_EP_EA                      0xF

/* Control register (USB_CNTR) */

#define USB_CNTR_CTRM_BIT              15
#define USB_CNTR_PMAOVERM_BIT          14
#define USB_CNTR_ERRM_BIT              13
#define USB_CNTR_WKUPM_BIT             12
#define USB_CNTR_SUSPM_BIT             11
#define USB_CNTR_RESETM_BIT            10
#define USB_CNTR_SOFM_BIT              9
#define USB_CNTR_ESOFM_BIT             8
#define USB_CNTR_RESUME_BIT            4
#define USB_CNTR_FSUSP_BIT             3
#define USB_CNTR_LP_MODE_BIT           2
#define USB_CNTR_PDWN_BIT              1
#define USB_CNTR_FRES_BIT              0

#if 0
#define USB_CNTR_CTRM                  BIT(USB_CNTR_CTRM_BIT)
#define USB_CNTR_PMAOVERM              BIT(USB_CNTR_PMAOVERM_BIT)
#define USB_CNTR_ERRM                  BIT(USB_CNTR_ERRM_BIT)
#define USB_CNTR_WKUPM                 BIT(USB_CNTR_WKUPM_BIT)
#define USB_CNTR_SUSPM                 BIT(USB_CNTR_SUSPM_BIT)
#define USB_CNTR_RESETM                BIT(USB_CNTR_RESETM_BIT)
#define USB_CNTR_SOFM                  BIT(USB_CNTR_SOFM_BIT)
#define USB_CNTR_ESOFM                 BIT(USB_CNTR_ESOFM_BIT)
#define USB_CNTR_RESUME                BIT(USB_CNTR_RESUME_BIT)
#define USB_CNTR_FSUSP                 BIT(USB_CNTR_FSUSP_BIT)
#define USB_CNTR_LP_MODE               BIT(USB_CNTR_LP_MODE_BIT)
#define USB_CNTR_PDWN                  BIT(USB_CNTR_PDWN_BIT)
#define USB_CNTR_FRES                  BIT(USB_CNTR_FRES_BIT)
#endif

/* Interrupt status register (USB_ISTR) */

#define USB_ISTR_CTR_BIT               15
#define USB_ISTR_PMAOVR_BIT            14
#define USB_ISTR_ERR_BIT               13
#define USB_ISTR_WKUP_BIT              12
#define USB_ISTR_SUSP_BIT              11
#define USB_ISTR_RESET_BIT             10
#define USB_ISTR_SOF_BIT               9
#define USB_ISTR_ESOF_BIT              8
#define USB_ISTR_DIR_BIT               4

#if 0
#define USB_ISTR_CTR                   BIT(USB_ISTR_CTR_BIT)
#define USB_ISTR_PMAOVR                BIT(USB_ISTR_PMAOVR_BIT)
#define USB_ISTR_ERR                   BIT(USB_ISTR_ERR_BIT)
#define USB_ISTR_WKUP                  BIT(USB_ISTR_WKUP_BIT)
#define USB_ISTR_SUSP                  BIT(USB_ISTR_SUSP_BIT)
#define USB_ISTR_RESET                 BIT(USB_ISTR_RESET_BIT)
#define USB_ISTR_SOF                   BIT(USB_ISTR_SOF_BIT)
#define USB_ISTR_ESOF                  BIT(USB_ISTR_ESOF_BIT)
#define USB_ISTR_DIR                   BIT(USB_ISTR_DIR_BIT)
#define USB_ISTR_EP_ID                 0xF
#endif

/* Frame number register (USB_FNR) */

#define USB_FNR_RXDP_BIT                15
#define USB_FNR_RXDM_BIT                14
#define USB_FNR_LCK_BIT                 13

#if 0
#define USB_FNR_RXDP                    BIT(USB_FNR_RXDP_BIT)
#define USB_FNR_RXDM                    BIT(USB_FNR_RXDM_BIT)
#define USB_FNR_LCK                     BIT(USB_FNR_LCK_BIT)
#define USB_FNR_LSOF                    (0x3 << 11)
#define USB_FNR_FN                      0x7FF
#endif

/* Device address (USB_DADDR) */

#define USB_DADDR_EF_BIT                7
#define USB_DADDR_ADD6_BIT              6
#define USB_DADDR_ADD5_BIT              5
#define USB_DADDR_ADD4_BIT              4
#define USB_DADDR_ADD3_BIT              3
#define USB_DADDR_ADD2_BIT              2
#define USB_DADDR_ADD1_BIT              1
#define USB_DADDR_ADD0_BIT              0

#if 0
#define USB_DADDR_EF                    BIT(USB_DADDR_EF_BIT)
#define USB_DADDR_ADD6                  BIT(USB_DADDR_ADD6_BIT)
#define USB_DADDR_ADD5                  BIT(USB_DADDR_ADD5_BIT)
#define USB_DADDR_ADD4                  BIT(USB_DADDR_ADD4_BIT)
#define USB_DADDR_ADD3                  BIT(USB_DADDR_ADD3_BIT)
#define USB_DADDR_ADD2                  BIT(USB_DADDR_ADD2_BIT)
#define USB_DADDR_ADD1                  BIT(USB_DADDR_ADD1_BIT)
#define USB_DADDR_ADD0                  BIT(USB_DADDR_ADD0_BIT)
#endif

/* Buffer table address (USB_BTABLE) */

// #define USB_BTABLE_BTABLE               (0x1FFF << 3)

/*
 * Register convenience routines
 */

#define __EP_CTR_NOP                    (USB_EP_CTR_RX | USB_EP_CTR_TX)
#define __EP_NONTOGGLE                  (USB_EP_CTR_RX | USB_EP_SETUP |    \
                                         USB_EP_EP_TYPE | USB_EP_EP_KIND | \
                                         USB_EP_CTR_TX | USB_EP_EA)

static inline void usb_clear_ctr_rx(uint8_t ep)
{
    uint32_t epr = USB_BASE->EP[ep];
    USB_BASE->EP[ep] = epr & ~USB_EP_CTR_RX & __EP_NONTOGGLE;
}

static inline void usb_clear_ctr_tx(uint8_t ep)
{
    uint32_t epr = USB_BASE->EP[ep];
    USB_BASE->EP[ep] = epr & ~USB_EP_CTR_TX & __EP_NONTOGGLE;
}

static inline void usb_set_ep_rx_stat(uint8_t ep, uint32_t status)
{
    uint32_t epr = USB_BASE->EP[ep];
    epr &= ~(USB_EP_STAT_TX | USB_EP_DTOG_RX | USB_EP_DTOG_TX);
    epr |= __EP_CTR_NOP;
    epr ^= status;
    USB_BASE->EP[ep] = epr;
}

static inline void usb_set_ep_tx_stat(uint8_t ep, uint32_t status)
{
    uint32_t epr = USB_BASE->EP[ep];
    epr &= ~(USB_EP_STAT_RX | USB_EP_DTOG_RX | USB_EP_DTOG_TX);
    epr |= __EP_CTR_NOP;
    epr ^= status;
    USB_BASE->EP[ep] = epr;
}

static inline void usb_set_ep_type(uint8_t ep, uint32_t type)
{
    uint32_t epr = USB_BASE->EP[ep];
    epr &= ~USB_EP_EP_TYPE & __EP_NONTOGGLE;
    epr |= type;
    USB_BASE->EP[ep] = epr;
}

static inline void usb_set_ep_kind(uint8_t ep, uint32_t kind)
{
    uint32_t epr = USB_BASE->EP[ep];
    epr &= ~USB_EP_EP_KIND & __EP_NONTOGGLE;
    epr |= kind;
    USB_BASE->EP[ep] = epr;
}

static inline void usb_clear_status_out(uint8_t ep)
{
    usb_set_ep_kind(ep, 0);
}

/*
 * Packet memory area (PMA) base pointer
 */

/**
 * @brief USB packet memory area (PMA) base pointer.
 *
 * The USB PMA is SRAM shared between USB and CAN.  The USB peripheral
 * accesses this memory directly via the packet buffer interface.  */
#define USB_PMA_BASE                    ((volatile void*)0x40006000)

/*
 * PMA conveniences
 */

void usb_copy_to_pma(const uint8_t * buf, uint16_t len, uint16_t pma_offset);
void usb_copy_from_pma(uint8_t * buf, uint16_t len, uint16_t pma_offset);

static inline void *usb_pma_ptr(uint32_t offset)
{
    return (void *) (USB_PMA_BASE + 2 * offset);
}

/*
 * BTABLE
 */

/* (Forward-declared) BTABLE entry.
 *
 * The BTABLE can be viewed as an array of usb_btable_ent values;
 * these vary in structure according to the configuration of the
 * endpoint.
 */
union usb_btable_ent;

/* Bidirectional endpoint BTABLE entry */
typedef struct usb_btable_bidi {
    volatile uint16_t addr_tx;
    const uint16_t PAD1;
    volatile uint16_t count_tx;
    const uint16_t PAD2;
    volatile uint16_t addr_rx;
    const uint16_t PAD3;
    volatile uint16_t count_rx;
    const uint16_t PAD4;
} usb_btable_bidi;

/* Unidirectional receive-only endpoint BTABLE entry */
typedef struct usb_btable_uni_rx {
    volatile uint16_t empty1;
    const uint16_t PAD1;
    volatile uint16_t empty2;
    const uint16_t PAD2;
    volatile uint16_t addr_rx;
    const uint16_t PAD3;
    volatile uint16_t count_rx;
    const uint16_t PAD4;
} usb_btable_uni_rx;

/* Unidirectional transmit-only endpoint BTABLE entry */
typedef struct usb_btable_uni_tx {
    volatile uint16_t addr_tx;
    const uint16_t PAD1;
    volatile uint16_t count_tx;
    const uint16_t PAD2;
    volatile uint16_t empty1;
    const uint16_t PAD3;
    volatile uint16_t empty2;
    const uint16_t PAD4;
} usb_btable_uni_tx;

/* Double-buffered transmission endpoint BTABLE entry */
typedef struct usb_btable_dbl_tx {
    volatile uint16_t addr_tx0;
    const uint16_t PAD1;
    volatile uint16_t count_tx0;
    const uint16_t PAD2;
    volatile uint16_t addr_tx1;
    const uint16_t PAD3;
    volatile uint16_t count_tx1;
    const uint16_t PAD4;
} usb_btable_dbl_tx;

/* Double-buffered reception endpoint BTABLE entry */
typedef struct usb_btable_dbl_rx {
    volatile uint16_t addr_rx0;
    const uint16_t PAD1;
    volatile uint16_t count_rx0;
    const uint16_t PAD2;
    volatile uint16_t addr_rx1;
    const uint16_t PAD3;
    volatile uint16_t count_rx1;
    const uint16_t PAD4;
} usb_btable_dbl_rx;

/* TODO isochronous endpoint entries */

/* Definition for above forward-declared BTABLE entry. */
typedef union usb_btable_ent {
    usb_btable_bidi bidi;
    usb_btable_uni_rx u_rx;
    usb_btable_uni_tx u_tx;
    usb_btable_dbl_tx d_tx;
    usb_btable_dbl_rx d_rx;
} usb_btable_ent;

/*
 * BTABLE conveniences
 */

/* TODO (?) Convert usages of the many (and lengthily-named)
 * accessors/mutators below to just manipulating usb_btable_entry
 * values.  */

static inline uint32_t *usb_btable_ptr(uint32_t offset)
{
    return (uint32_t *) usb_pma_ptr(USB_BASE->BTABLE + offset);
}

static inline usb_btable_ent *usb_btable(void)
{
    return (usb_btable_ent *) usb_btable_ptr(0);
}

/* TX address */

static inline uint32_t *usb_ep_tx_addr_ptr(uint8_t ep)
{
    return usb_btable_ptr(ep * 8);
}

static inline uint16_t usb_get_ep_tx_addr(uint8_t ep)
{
    return (uint16_t) * usb_ep_tx_addr_ptr(ep);
}

static inline void usb_set_ep_tx_addr(uint8_t ep, uint16_t addr)
{
    uint32_t *tx_addr = usb_ep_tx_addr_ptr(ep);
    *tx_addr = addr & ~0x1;
}

/* RX address */

static inline uint32_t *usb_ep_rx_addr_ptr(uint8_t ep)
{
    return usb_btable_ptr(ep * 8 + 4);
}

static inline uint16_t usb_get_ep_rx_addr(uint8_t ep)
{
    return (uint16_t) * usb_ep_rx_addr_ptr(ep);
}

static inline void usb_set_ep_rx_addr(uint8_t ep, uint16_t addr)
{
    uint32_t *rx_addr = usb_ep_rx_addr_ptr(ep);
    *rx_addr = addr & ~0x1;
}

/* TX count (doesn't cover double-buffered and isochronous in) */

static inline uint32_t *usb_ep_tx_count_ptr(uint8_t ep)
{
    return usb_btable_ptr(ep * 8 + 2);
}

static inline uint16_t usb_get_ep_tx_count(uint8_t ep)
{
    return (uint16_t) * usb_ep_tx_count_ptr(ep);
}

static inline void usb_set_ep_tx_count(uint8_t ep, uint16_t count)
{
    uint32_t *txc = usb_ep_tx_count_ptr(ep);
    *txc = count;
}

/* RX count */

static inline uint32_t *usb_ep_rx_count_ptr(uint8_t ep)
{
    return usb_btable_ptr(ep * 8 + 6);
}

static inline uint16_t usb_get_ep_rx_count(uint8_t ep)
{
    return (uint16_t) * usb_ep_rx_count_ptr(ep) & 0x3FF;
}

void usb_set_ep_rx_count(uint8_t ep, uint16_t count);

/*
 * Misc. types
 */

typedef enum usb_ep {
    USB_EP0,
    USB_EP1,
    USB_EP2,
    USB_EP3,
    USB_EP4,
    USB_EP5,
    USB_EP6,
    USB_EP7,
} usb_ep;

typedef enum usb_ep_type {
    USB_EP_T_CTL = USB_EP_EP_TYPE_CONTROL,
    USB_EP_T_BULK = USB_EP_EP_TYPE_BULK,
    USB_EP_T_INT = USB_EP_EP_TYPE_INTERRUPT,
    USB_EP_T_ISO = USB_EP_EP_TYPE_ISO
} usb_ep_type;

typedef enum usb_ep_stat {
    USB_EP_ST_RX_DIS = USB_EP_STAT_RX_DISABLED,
    USB_EP_ST_RX_STL = USB_EP_STAT_RX_STALL,
    USB_EP_ST_RX_NAK = USB_EP_STAT_RX_NAK,
    USB_EP_ST_RX_VAL = USB_EP_STAT_RX_VALID,
    USB_EP_ST_TX_DIS = USB_EP_STAT_TX_DISABLED,
    USB_EP_ST_TX_STL = USB_EP_STAT_TX_STALL,
    USB_EP_ST_TX_NAK = USB_EP_STAT_TX_NAK,
    USB_EP_ST_TX_VAL = USB_EP_STAT_TX_VALID
} usb_ep_stat;

#endif
