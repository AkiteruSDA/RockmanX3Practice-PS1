#include <common.h>
#include "practice.h"

void StageSelected();

void CastleStageCheck()
{
    practice.revist = false;
    if (*((char *)0x800dabc7) == 2) // X Logo Selected
    {
        stageId = 0;
        StageSelected();
        return;
    }
    if ((buttonsHeld & PAD_SELECT))
    {
        switch (stageId)
        {
        case 1:
            stageId = 0xA;
            break;
        case 4:
            stageId = 0xB;
            break;
        case 5:
            stageId = 0xC;
            break;
        case 8:
            stageId = 0xD;
            break;
        default:
            break;
        }
    }
    if (practice.route == 0 && (buttonsHeld & PAD_R2) && stageId == 5)
    {
        practice.revist = true;
    }else{
        practice.revist = false;
    }
    
    StageSelected();
}