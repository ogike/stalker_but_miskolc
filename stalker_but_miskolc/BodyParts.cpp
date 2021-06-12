//Created by: Geri
//Date: 2021-06-07
//Edited: 2021-06-07 By: Geri
#include "BodyParts.h"



BodyPart::BodyPart(float cH, float mH): curHealth(cH), maxHealth(mH)
{
    if(curHealth > maxHealth)
    {
        maxHealth = curHealth;
    }
} 

void BodyPart::ModifyCurHealth(float diff)
{
    curHealth = std::max(std::min(curHealth + diff,maxHealth),(float)0); //magik harvard ugyileg, tudni illik, created by Zsolt
}

float BodyPart::GetCurHealth()const
{
    return curHealth;
}

float BodyPart::GetMaxHealth()const
{
    return maxHealth;
}

void BodyPart::AddCondition(Conditions cond)
{
    if(std::count(conditions.begin(),conditions.end(),cond) == 0)
    {
        conditions.push_back(cond);
    }
}

bool BodyPart::RemCondition(Conditions cond)
{
	//akarunk mi ilyen furcsa beepitett c++ dolgokat??
    if(std::count( conditions.begin(), conditions.end(), cond ) == 1)
    {
        conditions.erase(std::find( conditions.begin(), conditions.end(), cond ) );
    	return true;
    }
	return false;
}

std::vector<BodyPart::Conditions> BodyPart::GetConditions()const
{
    return conditions;
}

void BodyPart::ClearConditions()
{
    conditions.clear();
}

Head::Head(float cH, float mH) : BodyPart(cH,mH){}
Thorax::Thorax(float cH, float mH) : BodyPart(cH,mH){}
Arm::Arm(float cH, float mH) : BodyPart(cH,mH){}
Leg::Leg(float cH, float mH) : BodyPart(cH,mH){}
