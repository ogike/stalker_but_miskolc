//Created by: Geri
//Date: 2021-06-07
//Edited: 2021-06-09 By: Geri
#pragma once
#include <vector>
#include <algorithm>
#include <ostream>

class BodyPart
{
    public:
        enum Conditions
        {
            WOUND,MAJOR_WOUND,INFECTION
        };
        void ModifyCurHealth(float diff);
        float GetCurHealth()const;
        float GetMaxHealth()const;
        void AddCondition(Conditions cond);
        void RemCondition(Conditions cond);
        std::vector<Conditions> GetConditions()const;
        void ClearConditions();
       

    protected:
    
        float curHealth;
        float maxHealth;
        std::vector<Conditions> conditions;
        BodyPart(float cH, float mH);

    friend std::ostream& operator<< (std::ostream& o, BodyPart& b)
    {
        o << "Health: " << b.curHealth << std::endl;
        o << "\t\tConditions: ";
        for (int i = 0; i < b.conditions.size(); i++)
        {
            o << b.conditions[i] << " " ;
        }
        o << std::endl;
        

        return o;
    }
    friend std::ostream& operator<< (std::ostream& o, Conditions& c)
    {
        switch (c)
        {
        case WOUND:
            o << "WOUND";
            break;

        case INFECTION:
            o << "INFECTION";
            break;
        
        case MAJOR_WOUND:
            o << "MAJOR WOUND";
            break;
        
        default:
            o << "konkretan mi a fasz";
            break;
        }

        return o;
    }
};

class Arm : public BodyPart
{
    public:
        Arm(float cH, float mH);
    private:
        enum Bones
        {
            HUMERUS,ULNA,RADIUS,ELBOW,WRIST
        };
};

class Leg : public BodyPart
{
    public:
        Leg(float cH, float mH);
    private:
        enum Bones
        {
            FEMUR,TIBIA,FIBULA,ANKLE,KNEE
        };
};

class Thorax : public BodyPart
{
    public:
        Thorax(float cH, float mH);
    private:
        enum Bones
        {
            RIBS,SPINE,SHOULDER,PELVIS
        };
};
class Head : public BodyPart
{
    public:
        Head(float cH, float mH);
    private:
        enum Bones
        {
            SKULL,JAW
        };
};
