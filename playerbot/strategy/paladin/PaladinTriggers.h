#pragma once
#include "../triggers/GenericTriggers.h"

namespace ai
{
    class NoPaladinAuraTrigger : public BuffTrigger
    {
    public:
        NoPaladinAuraTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "no paladin aura") {}
        bool IsActive() override;
    };

    BUFF_TRIGGER(ShadowResistanceAuraTrigger, "shadow resistance aura");
    BUFF_TRIGGER(FrostResistanceAuraTrigger, "frost resistance aura");
    BUFF_TRIGGER(FireResistanceAuraTrigger, "fire resistance aura");
    BUFF_TRIGGER(DevotionAuraTrigger, "devotion aura");
    BUFF_TRIGGER(RetributionAuraTrigger, "retribution aura");
    BUFF_TRIGGER(CrusaderAuraTrigger, "crusader aura");
    BUFF_TRIGGER(SanctityAuraTrigger, "sanctity aura");
    BUFF_TRIGGER(ConcentrationAuraTrigger, "concentration aura");

    BUFF_TRIGGER(HolyShieldTrigger, "holy shield");
    BUFF_TRIGGER(RighteousFuryTrigger, "righteous fury");

	class SealTrigger : public BuffTrigger
	{
	public:
		SealTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "seal of justice") {}
		virtual bool IsActive();
	};

    // judgements
    DEBUFF_TRIGGER(JudgementTrigger, "judgement");
    DEBUFF_TRIGGER(JudgementOfLightTrigger, "judgement of light");
    DEBUFF_TRIGGER(JudgementOfWisdomTrigger, "judgement of wisdom");

    DEBUFF_TRIGGER(ConsecrationTrigger, "consecration");

    // repentance triggers
    INTERRUPT_HEALER_TRIGGER(RepentanceOnHealerTrigger, "repentance on enemy healer");
    SNARE_TRIGGER(RepentanceSnareTrigger, "repentance on snare target");
    INTERRUPT_TRIGGER(RepentanceInterruptTrigger, "repentance");

    class BlessingOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        BlessingOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "blessing", 4) {}
        bool IsActive() override;
    };

    class GreaterBlessingOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        GreaterBlessingOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "greater blessing", 4) {}
        bool IsActive() override;
    };

    class BlessingOfMightOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        BlessingOfMightOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "blessing of might", 4) {}
        virtual bool IsActive() { return BuffOnPartyTrigger::IsActive() && !ai->HasAura("greater " + spell, GetTarget()); }
    };

    class GreaterBlessingOfMightOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        GreaterBlessingOfMightOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "greater blessing of might", 4) {}

        bool IsActive() override
        {
            Unit* target = GetTarget();
            if (target && target->IsPlayer())
            {
                Player* player = (Player*)target;
                if (bot->IsInGroup(player) && ai->GetBuffedCount((Player*)GetTarget(), spell) < 4)
                {
                    return BuffOnPartyTrigger::IsActive();
                }
            }

            return false;
        }
    };

    class BlessingOfWisdomOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        BlessingOfWisdomOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "blessing of wisdom", 4) {}
        virtual bool IsActive() { return BuffOnPartyTrigger::IsActive() && !ai->HasAura("greater " + spell, GetTarget()); }
    };

    class GreaterBlessingOfWisdomOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        GreaterBlessingOfWisdomOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "greater blessing of wisdom", 4) {}

        bool IsActive() override
        {
            Unit* target = GetTarget();
            if (target && target->IsPlayer())
            {
                Player* player = (Player*)target;
                if (bot->IsInGroup(player) && ai->GetBuffedCount((Player*)GetTarget(), spell) < 4)
                {
                    return BuffOnPartyTrigger::IsActive();
                }
            }

            return false;
        }
    };

    class BlessingOfKingsOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        BlessingOfKingsOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "blessing of kings", 4) {}
        virtual bool IsActive() { return BuffOnPartyTrigger::IsActive() && !ai->HasAura("greater " + spell, GetTarget()); }
    };

    class GreaterBlessingOfKingsOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        GreaterBlessingOfKingsOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "greater blessing of kings", 4) {}

        bool IsActive() override
        {
            Unit* target = GetTarget();
            if (target && target->IsPlayer())
            {
                Player* player = (Player*)target;
                if (bot->IsInGroup(player) && ai->GetBuffedCount((Player*)GetTarget(), spell) < 4)
                {
                    return BuffOnPartyTrigger::IsActive();
                }
            }

            return false;
        }
    };

    class BlessingOfLightOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        BlessingOfLightOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "blessing of light", 4) {}
        virtual bool IsActive() { return BuffOnPartyTrigger::IsActive() && !ai->HasAura("greater " + spell, GetTarget()); }
    };

    class GreaterBlessingOfLightOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        GreaterBlessingOfLightOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "greater blessing of light", 4) {}

        bool IsActive() override
        {
            Unit* target = GetTarget();
            if (target && target->IsPlayer())
            {
                Player* player = (Player*)target;
                if (bot->IsInGroup(player) && ai->GetBuffedCount((Player*)GetTarget(), spell) < 4)
                {
                    return BuffOnPartyTrigger::IsActive();
                }
            }

            return false;
        }
    };

    class BlessingOfSalvationOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        BlessingOfSalvationOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "blessing of salvation", 4) {}
        virtual bool IsActive() { return BuffOnPartyTrigger::IsActive() && !ai->HasAura("greater " + spell, GetTarget()); }
    };

    class GreaterBlessingOfSalvationOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        GreaterBlessingOfSalvationOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "greater blessing of salvation", 4) {}

        bool IsActive() override
        {
            Unit* target = GetTarget();
            if (target && target->IsPlayer())
            {
                Player* player = (Player*)target;
                if (bot->IsInGroup(player) && ai->GetBuffedCount((Player*)GetTarget(), spell) < 4)
                {
                    return BuffOnPartyTrigger::IsActive();
                }
            }

            return false;
        }
    };

    class BlessingOfSanctuaryOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        BlessingOfSanctuaryOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "blessing of sanctuary", 4) {}
        virtual bool IsActive() { return BuffOnPartyTrigger::IsActive() && !ai->HasAura("greater " + spell, GetTarget()); }
    };

    class GreaterBlessingOfSanctuaryOnPartyTrigger : public BuffOnPartyTrigger
    {
    public:
        GreaterBlessingOfSanctuaryOnPartyTrigger(PlayerbotAI* ai) : BuffOnPartyTrigger(ai, "greater blessing of sanctuary", 4) {}

        bool IsActive() override
        {
            Unit* target = GetTarget();
            if (target && target->IsPlayer())
            {
                Player* player = (Player*)target;
                if (bot->IsInGroup(player) && ai->GetBuffedCount((Player*)GetTarget(), spell) < 4)
                {
                    return BuffOnPartyTrigger::IsActive();
                }
            }

            return false;
        }
    };

    class BlessingTrigger : public BuffTrigger
    {
    public:
        BlessingTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "blessing", 2) {}
        bool IsActive() override;
    };

    class GreaterBlessingTrigger : public BuffTrigger
    {
    public:
        GreaterBlessingTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "greater blessing", 2) {}
        bool IsActive() override;
    };

    class BlessingOfMightTrigger : public BuffTrigger
    {
    public:
        BlessingOfMightTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "blessing of might", 4) {}
        virtual bool IsActive() { return BuffTrigger::IsActive() && !ai->HasAura("greater " + spell, GetTarget()); }
    };

    class GreaterBlessingOfMightTrigger : public BuffTrigger
    {
    public:
        GreaterBlessingOfMightTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "greater blessing of might", 4) {}

        bool IsActive() override
        {
            Unit* target = GetTarget();
            if (target && target->IsPlayer())
            {
                Player* player = (Player*)target;
                if (bot->IsInGroup(player) && ai->GetBuffedCount((Player*)GetTarget(), spell) < 4)
                {
                    return BuffTrigger::IsActive();
                }
            }

            return false;
        }
    };

    class BlessingOfWisdomTrigger : public BuffTrigger
    {
    public:
        BlessingOfWisdomTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "blessing of wisdom", 4) {}
        virtual bool IsActive() { return BuffTrigger::IsActive() && !ai->HasAura("greater " + spell, GetTarget()); }
    };

    class GreaterBlessingOfWisdomTrigger : public BuffTrigger
    {
    public:
        GreaterBlessingOfWisdomTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "greater blessing of wisdom", 4) {}

        bool IsActive() override
        {
            Unit* target = GetTarget();
            if (target && target->IsPlayer())
            {
                Player* player = (Player*)target;
                if (bot->IsInGroup(player) && ai->GetBuffedCount((Player*)GetTarget(), spell) < 4)
                {
                    return BuffTrigger::IsActive();
                }
            }

            return false;
        }
    };

    class BlessingOfKingsTrigger : public BuffTrigger
    {
    public:
        BlessingOfKingsTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "blessing of kings", 4) {}
        virtual bool IsActive() { return BuffTrigger::IsActive() && !ai->HasAura("greater " + spell, GetTarget()); }
    };

    class GreaterBlessingOfKingsTrigger : public BuffTrigger
    {
    public:
        GreaterBlessingOfKingsTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "greater blessing of kings", 4) {}

        bool IsActive() override
        {
            Unit* target = GetTarget();
            if (target && target->IsPlayer())
            {
                Player* player = (Player*)target;
                if (bot->IsInGroup(player) && ai->GetBuffedCount((Player*)GetTarget(), spell) < 4)
                {
                    return BuffTrigger::IsActive();
                }
            }

            return false;
        }
    };

    class BlessingOfLightTrigger : public BuffTrigger
    {
    public:
        BlessingOfLightTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "blessing of light", 4) {}
        virtual bool IsActive() { return BuffTrigger::IsActive() && !ai->HasAura("greater " + spell, GetTarget()); }
    };

    class GreaterBlessingOfLightTrigger : public BuffTrigger
    {
    public:
        GreaterBlessingOfLightTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "greater blessing of light", 4) {}

        bool IsActive() override
        {
            Unit* target = GetTarget();
            if (target && target->IsPlayer())
            {
                Player* player = (Player*)target;
                if (bot->IsInGroup(player) && ai->GetBuffedCount((Player*)GetTarget(), spell) < 4)
                {
                    return BuffTrigger::IsActive();
                }
            }

            return false;
        }
    };

    class BlessingOfSalvationTrigger : public BuffTrigger
    {
    public:
        BlessingOfSalvationTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "blessing of salvation", 4) {}
        virtual bool IsActive() { return BuffTrigger::IsActive() && !ai->HasAura("greater " + spell, GetTarget()); }
    };

    class GreaterBlessingOfSalvationTrigger : public BuffTrigger
    {
    public:
        GreaterBlessingOfSalvationTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "greater blessing of salvation", 4) {}

        bool IsActive() override
        {
            Unit* target = GetTarget();
            if (target && target->IsPlayer())
            {
                Player* player = (Player*)target;
                if (bot->IsInGroup(player) && ai->GetBuffedCount((Player*)GetTarget(), spell) < 4)
                {
                    return BuffTrigger::IsActive();
                }
            }

            return false;
        }
    };

    class BlessingOfSanctuaryTrigger : public BuffTrigger
    {
    public:
        BlessingOfSanctuaryTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "blessing of sanctuary", 4) {}
        virtual bool IsActive() { return BuffTrigger::IsActive() && !ai->HasAura("greater " + spell, GetTarget()); }
    };

    class GreaterBlessingOfSanctuaryTrigger : public BuffTrigger
    {
    public:
        GreaterBlessingOfSanctuaryTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "greater blessing of sanctuary", 4) {}

        bool IsActive() override
        {
            Unit* target = GetTarget();
            if (target && target->IsPlayer())
            {
                Player* player = (Player*)target;
                if (bot->IsInGroup(player) && ai->GetBuffedCount((Player*)GetTarget(), spell) < 4)
                {
                    return BuffTrigger::IsActive();
                }
            }

            return false;
        }
    };

    class HammerOfJusticeInterruptSpellTrigger : public InterruptSpellTrigger
    {
    public:
        HammerOfJusticeInterruptSpellTrigger(PlayerbotAI* ai) : InterruptSpellTrigger(ai, "hammer of justice") {}
    };

    class HammerOfJusticeSnareTrigger : public SnareTargetTrigger
    {
    public:
        HammerOfJusticeSnareTrigger(PlayerbotAI* ai) : SnareTargetTrigger(ai, "hammer of justice") {}
    };

    class HammerOfJusticeOnEnemyTrigger : public Trigger
    {
    public:
        HammerOfJusticeOnEnemyTrigger(PlayerbotAI* ai) : Trigger(ai, "hammer of justice on enemy") {}
        virtual bool IsActive();
    };

    class ArtOfWarTrigger : public HasAuraTrigger
    {
    public:
        ArtOfWarTrigger(PlayerbotAI* ai) : HasAuraTrigger(ai, "the art of war") {}
    };

    class CleanseCureDiseaseTrigger : public NeedCureTrigger
    {
    public:
        CleanseCureDiseaseTrigger(PlayerbotAI* ai) : NeedCureTrigger(ai, "cleanse", DISPEL_DISEASE) {}
    };

    class CleanseCurePartyMemberDiseaseTrigger : public PartyMemberNeedCureTrigger
    {
    public:
        CleanseCurePartyMemberDiseaseTrigger(PlayerbotAI* ai) : PartyMemberNeedCureTrigger(ai, "cleanse", DISPEL_DISEASE) {}
    };

    class CleanseCurePoisonTrigger : public NeedCureTrigger
    {
    public:
        CleanseCurePoisonTrigger(PlayerbotAI* ai) : NeedCureTrigger(ai, "cleanse", DISPEL_POISON) {}
    };

    class CleanseCurePartyMemberPoisonTrigger : public PartyMemberNeedCureTrigger
    {
    public:
        CleanseCurePartyMemberPoisonTrigger(PlayerbotAI* ai) : PartyMemberNeedCureTrigger(ai, "cleanse", DISPEL_POISON) {}
    };

    class CleanseCureMagicTrigger : public NeedCureTrigger
    {
    public:
        CleanseCureMagicTrigger(PlayerbotAI* ai) : NeedCureTrigger(ai, "cleanse", DISPEL_MAGIC) {}
    };

    class CleanseCurePartyMemberMagicTrigger : public PartyMemberNeedCureTrigger
    {
    public:
        CleanseCurePartyMemberMagicTrigger(PlayerbotAI* ai) : PartyMemberNeedCureTrigger(ai, "cleanse", DISPEL_MAGIC) {}
    };

    class HammerOfJusticeEnemyHealerTrigger : public InterruptEnemyHealerTrigger
    {
    public:
        HammerOfJusticeEnemyHealerTrigger(PlayerbotAI* ai) : InterruptEnemyHealerTrigger(ai, "hammer of justice") {}
    };

    class DivineFavorTrigger : public BuffTrigger
    {
    public:
        DivineFavorTrigger(PlayerbotAI* ai) : BuffTrigger(ai, "divine favor") {}
    };

    class TurnUndeadTrigger : public HasCcTargetTrigger
    {
    public:
        TurnUndeadTrigger(PlayerbotAI* ai) : HasCcTargetTrigger(ai, "turn undead") {}
    };

    class HandOfSacrificeTrigger : public PartyMemberLowHealthTrigger
    {
    public:
        HandOfSacrificeTrigger(PlayerbotAI* ai) : PartyMemberLowHealthTrigger(ai, "hand of sacrifice", sPlayerbotAIConfig.criticalHealth, 0, true) {}
    };

    class BlessingOfSacrificeTrigger : public PartyMemberLowHealthTrigger
    {
    public:
        BlessingOfSacrificeTrigger(PlayerbotAI* ai) : PartyMemberLowHealthTrigger(ai, "blessing of sacrifice", sPlayerbotAIConfig.criticalHealth, 0, true) {}
    };

    DEBUFF_TRIGGER(AvengerShieldTrigger, "avenger's shield");
    BOOST_TRIGGER(DivineIlluminationBoostTrigger, "divine illumination");

    class BeaconOfLightTrigger : public Trigger
    {
    public:
        BeaconOfLightTrigger(PlayerbotAI* ai) : Trigger(ai, "beacon of light") {}

        bool IsActive() override
        {
            // Required Beacon of Light talent
            if (bot->HasSpell(53563))
                return false;

            Group* group = bot->GetGroup();
            if (group)
            {
                for (GroupReference* gr = group->GetFirstMember(); gr; gr = gr->next())
                {
                    Player* member = gr->getSource();
                    // Check that target is tank in bot group and dont have bot beacon of light
                    if (!group->SameSubGroup((Player*)ai, member) && ai->IsTank(member) && !ai->HasAura("light's beacon", member, true))
                    {
                        return true;
                    }
                    else if (ai->IsTank(member))
                    {
                        return false;
                    }
                }
            }

            return false;
        }
    };
}
