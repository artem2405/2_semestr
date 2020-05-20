#ifndef _offset_h_
#define _offset_h_

typedef struct {

    enum OFF_SET_LIN {
        YES_LIN = 'Y',
        NO_LIN = 'N'
    } OFF_SET_LIN;

    enum OFF_SET_PHY {
        YES_PHY = 'Y',
        NO_PHY = 'N'
    } OFF_SET_PHY;

    enum OFF_SET_ENG {
        YES_ENG = 'Y',
        NO_ENG = 'N'
    } OFF_SET_ENG;

    enum OFF_SET_LAB {
        YES_LAB = 'Y',
        NO_LAB = 'N'
    } OFF_SET_LAB;
} offset;

#endif 