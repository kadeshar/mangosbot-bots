#include "botpch.h"
#include "../../playerbot.h"
#include "DruidActions.h"
#include "DruidAiObjectContext.h"
#include "BearTankDruidStrategy.h"
#include "CatDpsDruidStrategy.h"
#include "CasterDruidStrategy.h"
#include "GenericDruidNonCombatStrategy.h"
#include "DruidReactionStrategy.h"
#include "../NamedObjectContext.h"
#include "DruidTriggers.h"
#include "HealDruidStrategy.h"
#include "MeleeDruidStrategy.h"
#include "../generic/PullStrategy.h"

using namespace ai;

namespace ai
{
    namespace druid
    {
        using namespace ai;

        class StrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
            StrategyFactoryInternal()
            {
                creators["nc"] = &druid::StrategyFactoryInternal::nc;
                creators["react"] = &druid::StrategyFactoryInternal::react;
                creators["cat aoe"] = &druid::StrategyFactoryInternal::cat_aoe;
                creators["caster aoe"] = &druid::StrategyFactoryInternal::caster_aoe;
                creators["caster debuff"] = &druid::StrategyFactoryInternal::caster_debuff;
                creators["dps debuff"] = &druid::StrategyFactoryInternal::caster_debuff;
                creators["cure"] = &druid::StrategyFactoryInternal::cure;
                creators["melee"] = &druid::StrategyFactoryInternal::melee;
                creators["buff"] = &druid::StrategyFactoryInternal::buff;
                creators["boost"] = &druid::StrategyFactoryInternal::boost;
                creators["cc"] = &druid::StrategyFactoryInternal::cc;
                creators["pull"] = &druid::StrategyFactoryInternal::pull;
            }

        private:
            static Strategy* nc(PlayerbotAI* ai) { return new GenericDruidNonCombatStrategy(ai); }
            static Strategy* react(PlayerbotAI* ai) { return new DruidReactionStrategy(ai); }
            static Strategy* cat_aoe(PlayerbotAI* ai) { return new CatAoeDruidStrategy(ai); }
            static Strategy* caster_aoe(PlayerbotAI* ai) { return new CasterDruidAoeStrategy(ai); }
            static Strategy* caster_debuff(PlayerbotAI* ai) { return new CasterDruidDebuffStrategy(ai); }
            static Strategy* cure(PlayerbotAI* ai) { return new DruidCureStrategy(ai); }
            static Strategy* melee(PlayerbotAI* ai) { return new MeleeDruidStrategy(ai); }
            static Strategy* buff(PlayerbotAI* ai) { return new GenericDruidBuffStrategy(ai); }
            static Strategy* boost(PlayerbotAI* ai) { return new DruidBoostStrategy(ai); }
            static Strategy* cc(PlayerbotAI* ai) { return new DruidCcStrategy(ai); }
            static Strategy* pull(PlayerbotAI* ai) { return new PullStrategy(ai, "faerie fire" , "dire bear form"); }
        };

        class DruidStrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
            DruidStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
            {
                creators["bear"] = &druid::DruidStrategyFactoryInternal::bear;
                creators["tank"] = &druid::DruidStrategyFactoryInternal::bear;
                creators["cat"] = &druid::DruidStrategyFactoryInternal::cat;
                creators["caster"] = &druid::DruidStrategyFactoryInternal::caster;
                creators["dps"] = &druid::DruidStrategyFactoryInternal::cat;
                creators["heal"] = &druid::DruidStrategyFactoryInternal::heal;
            }

        private:
            static Strategy* bear(PlayerbotAI* ai) { return new BearTankDruidStrategy(ai); }
            static Strategy* cat(PlayerbotAI* ai) { return new CatDpsDruidStrategy(ai); }
            static Strategy* caster(PlayerbotAI* ai) { return new CasterDruidStrategy(ai); }
            static Strategy* heal(PlayerbotAI* ai) { return new HealDruidStrategy(ai); }
        };
    };
};

namespace ai
{
    namespace druid
    {
        using namespace ai;

        class TriggerFactoryInternal : public NamedObjectContext<Trigger>
        {
        public:
            TriggerFactoryInternal()
            {
                creators["omen of clarity"] = &TriggerFactoryInternal::omen_of_clarity;
                creators["thorns"] = &TriggerFactoryInternal::thorns;
                creators["thorns on party"] = &TriggerFactoryInternal::thorns_on_party;
                creators["bash"] = &TriggerFactoryInternal::bash;
                creators["faerie fire (feral)"] = &TriggerFactoryInternal::faerie_fire_feral;
                creators["faerie fire"] = &TriggerFactoryInternal::faerie_fire;
                creators["insect swarm"] = &TriggerFactoryInternal::insect_swarm;
                creators["moonfire"] = &TriggerFactoryInternal::moonfire;
                creators["nature's grasp"] = &TriggerFactoryInternal::natures_grasp;
                creators["tiger's fury"] = &TriggerFactoryInternal::tigers_fury;
                creators["rake"] = &TriggerFactoryInternal::rake;
                creators["mark of the wild"] = &TriggerFactoryInternal::mark_of_the_wild;
                creators["mark of the wild on party"] = &TriggerFactoryInternal::mark_of_the_wild_on_party;
                creators["gift of the wild on party"] = &TriggerFactoryInternal::gift_of_the_wild_on_party;
                creators["cure poison"] = &TriggerFactoryInternal::cure_poison;
                creators["party member cure poison"] = &TriggerFactoryInternal::party_member_cure_poison;
                creators["remove curse"] = &TriggerFactoryInternal::remove_curse;
                creators["party member remove curse"] = &TriggerFactoryInternal::party_member_remove_curse;
                creators["entangling roots"] = &TriggerFactoryInternal::entangling_roots;
                creators["entangling roots kite"] = &TriggerFactoryInternal::entangling_roots_kite;
                creators["entangling roots snare"] = &TriggerFactoryInternal::entangling_roots_snare;
                creators["hibernate"] = &TriggerFactoryInternal::hibernate;
                creators["bear form"] = &TriggerFactoryInternal::bear_form;
                creators["cat form"] = &TriggerFactoryInternal::cat_form;
                creators["tree form"] = &TriggerFactoryInternal::tree_form;
                creators["eclipse (solar)"] = &TriggerFactoryInternal::eclipse_solar;
                creators["eclipse (lunar)"] = &TriggerFactoryInternal::eclipse_lunar;
                creators["bash on enemy healer"] = &TriggerFactoryInternal::bash_on_enemy_healer;
                creators["nature's swiftness"] = &TriggerFactoryInternal::natures_swiftness;
                creators["ferocious bite"] = &TriggerFactoryInternal::ferocious_bite;
                creators["claw"] = &TriggerFactoryInternal::claw;
                creators["rip"] = &TriggerFactoryInternal::rip;
            }

        private:
            static Trigger* rip(PlayerbotAI* ai) { return new RipTrigger(ai, 3); }
            static Trigger* ferocious_bite(PlayerbotAI* ai) { return new ComboPointsAvailableTrigger(ai, 3); }
            static Trigger* natures_swiftness(PlayerbotAI* ai) { return new NaturesSwiftnessTrigger(ai); }
            static Trigger* eclipse_solar(PlayerbotAI* ai) { return new EclipseSolarTrigger(ai); }
            static Trigger* eclipse_lunar(PlayerbotAI* ai) { return new EclipseLunarTrigger(ai); }
            static Trigger* thorns(PlayerbotAI* ai) { return new ThornsTrigger(ai); }
            static Trigger* thorns_on_party(PlayerbotAI* ai) { return new ThornsOnPartyTrigger(ai); }
            static Trigger* bash(PlayerbotAI* ai) { return new BashInterruptSpellTrigger(ai); }
            static Trigger* faerie_fire_feral(PlayerbotAI* ai) { return new FaerieFireFeralTrigger(ai); }
            static Trigger* insect_swarm(PlayerbotAI* ai) { return new InsectSwarmTrigger(ai); }
            static Trigger* moonfire(PlayerbotAI* ai) { return new MoonfireTrigger(ai); }
            static Trigger* faerie_fire(PlayerbotAI* ai) { return new FaerieFireTrigger(ai); }
            static Trigger* natures_grasp(PlayerbotAI* ai) { return new NaturesGraspTrigger(ai); }
            static Trigger* tigers_fury(PlayerbotAI* ai) { return new TigersFuryTrigger(ai); }
            static Trigger* rake(PlayerbotAI* ai) { return new RakeTrigger(ai); }
            static Trigger* claw(PlayerbotAI* ai) { return new SpellCanBeCastTrigger(ai, "claw"); }
            static Trigger* mark_of_the_wild(PlayerbotAI* ai) { return new MarkOfTheWildTrigger(ai); }
            static Trigger* mark_of_the_wild_on_party(PlayerbotAI* ai) { return new MarkOfTheWildOnPartyTrigger(ai); }
            static Trigger* gift_of_the_wild_on_party(PlayerbotAI* ai) { return new GiftOfTheWildOnPartyTrigger(ai); }
            static Trigger* cure_poison(PlayerbotAI* ai) { return new CurePoisonTrigger(ai); }
            static Trigger* party_member_cure_poison(PlayerbotAI* ai) { return new PartyMemberCurePoisonTrigger(ai); }
            static Trigger* remove_curse(PlayerbotAI* ai) { return new RemoveCurseTrigger(ai); }
            static Trigger* party_member_remove_curse(PlayerbotAI* ai) { return new RemoveCurseOnPartyTrigger(ai); }
            static Trigger* entangling_roots(PlayerbotAI* ai) { return new EntanglingRootsTrigger(ai); }
            static Trigger* entangling_roots_kite(PlayerbotAI* ai) { return new EntanglingRootsKiteTrigger(ai); }
            static Trigger* entangling_roots_snare(PlayerbotAI* ai) { return new EntanglingRootsSnareTrigger(ai); }
            static Trigger* hibernate(PlayerbotAI* ai) { return new HibernateTrigger(ai); }
            static Trigger* bear_form(PlayerbotAI* ai) { return new BearFormTrigger(ai); }
            static Trigger* cat_form(PlayerbotAI* ai) { return new CatFormTrigger(ai); }
            static Trigger* tree_form(PlayerbotAI* ai) { return new TreeFormTrigger(ai); }
            static Trigger* bash_on_enemy_healer(PlayerbotAI* ai) { return new BashInterruptEnemyHealerSpellTrigger(ai); }
            static Trigger* omen_of_clarity(PlayerbotAI* ai) { return new OmenOfClarityTrigger(ai); }
        };
    };
};

namespace ai
{
    namespace druid
    {
        using namespace ai;

        class AiObjectContextInternal : public NamedObjectContext<Action>
        {
        public:
            AiObjectContextInternal()
            {
                creators["feral charge - bear"] = &AiObjectContextInternal::feral_charge_bear;
                creators["feral charge - cat"] = &AiObjectContextInternal::feral_charge_cat;
                creators["swipe (bear)"] = &AiObjectContextInternal::swipe_bear;
                creators["faerie fire (feral)"] = &AiObjectContextInternal::faerie_fire_feral;
                creators["faerie fire"] = &AiObjectContextInternal::faerie_fire;
                creators["bear form"] = &AiObjectContextInternal::bear_form;
                creators["dire bear form"] = &AiObjectContextInternal::dire_bear_form;
                creators["moonkin form"] = &AiObjectContextInternal::moonkin_form;
                creators["cat form"] = &AiObjectContextInternal::cat_form;
                creators["tree form"] = &AiObjectContextInternal::tree_form;
                creators["travel form"] = &AiObjectContextInternal::travel_form;
                creators["aquatic form"] = &AiObjectContextInternal::aquatic_form;
                creators["caster form"] = &AiObjectContextInternal::caster_form;
                creators["mangle (bear)"] = &AiObjectContextInternal::mangle_bear;
                creators["maul"] = &AiObjectContextInternal::maul;
                creators["bash"] = &AiObjectContextInternal::bash;
                creators["swipe"] = &AiObjectContextInternal::swipe;
                creators["growl"] = &AiObjectContextInternal::growl;
                creators["demoralizing roar"] = &AiObjectContextInternal::demoralizing_roar;
                creators["hibernate"] = &AiObjectContextInternal::hibernate;
                creators["entangling roots"] = &AiObjectContextInternal::entangling_roots;
                creators["entangling roots on cc"] = &AiObjectContextInternal::entangling_roots_on_cc;
                creators["entangling roots on snare"] = &AiObjectContextInternal::entangling_roots_on_snare;
                creators["hibernate"] = &AiObjectContextInternal::hibernate;
                creators["hibernate on cc"] = &AiObjectContextInternal::hibernate_on_cc;
                creators["wrath"] = &AiObjectContextInternal::wrath;
                creators["starfall"] = &AiObjectContextInternal::starfall;
                creators["insect swarm"] = &AiObjectContextInternal::insect_swarm;
                creators["moonfire"] = &AiObjectContextInternal::moonfire;
                creators["starfire"] = &AiObjectContextInternal::starfire;
                creators["nature's grasp"] = &AiObjectContextInternal::natures_grasp;
                creators["claw"] = &AiObjectContextInternal::claw;
                creators["mangle (cat)"] = &AiObjectContextInternal::mangle_cat;
                creators["swipe (cat)"] = &AiObjectContextInternal::swipe_cat;
                creators["rake"] = &AiObjectContextInternal::rake;
                creators["ferocious bite"] = &AiObjectContextInternal::ferocious_bite;
                creators["rip"] = &AiObjectContextInternal::rip;
                creators["cower"] = &AiObjectContextInternal::cower;
                creators["survival instincts"] = &AiObjectContextInternal::survival_instincts;
                creators["thorns"] = &AiObjectContextInternal::thorns;
                creators["thorns on party"] = &AiObjectContextInternal::thorns_on_party;
                creators["cure poison"] = &AiObjectContextInternal::cure_poison;
                creators["cure poison on party"] = &AiObjectContextInternal::cure_poison_on_party;
                creators["abolish poison"] = &AiObjectContextInternal::abolish_poison;
                creators["abolish poison on party"] = &AiObjectContextInternal::abolish_poison_on_party;
                creators["remove curse"] = &AiObjectContextInternal::remove_curse;
                creators["remove curse on party"] = &AiObjectContextInternal::remove_curse_on_party;
                creators["berserk"] = &AiObjectContextInternal::berserk;
                creators["tiger's fury"] = &AiObjectContextInternal::tigers_fury;
                creators["mark of the wild"] = &AiObjectContextInternal::mark_of_the_wild;
                creators["mark of the wild on party"] = &AiObjectContextInternal::mark_of_the_wild_on_party;
                creators["gift of the wild on party"] = &AiObjectContextInternal::gift_of_the_wild_on_party;
                creators["regrowth"] = &AiObjectContextInternal::regrowth;
                creators["rejuvenation"] = &AiObjectContextInternal::rejuvenation;
                creators["healing touch"] = &AiObjectContextInternal::healing_touch;
                creators["regrowth on party"] = &AiObjectContextInternal::regrowth_on_party;
                creators["rejuvenation on party"] = &AiObjectContextInternal::rejuvenation_on_party;
                creators["healing touch on party"] = &AiObjectContextInternal::healing_touch_on_party;
                creators["rebirth"] = &AiObjectContextInternal::rebirth;
                creators["revive"] = &AiObjectContextInternal::revive;
                creators["barskin"] = &AiObjectContextInternal::barskin;
                creators["lacerate"] = &AiObjectContextInternal::lacerate;
                creators["hurricane"] = &AiObjectContextInternal::hurricane;
                creators["innervate"] = &AiObjectContextInternal::innervate;
                creators["tranquility"] = &AiObjectContextInternal::tranquility;
                creators["bash on enemy healer"] = &AiObjectContextInternal::bash_on_enemy_healer;
                creators["omen of clarity"] = &AiObjectContextInternal::omen_of_clarity;
                creators["nature's swiftness"] = &AiObjectContextInternal::natures_swiftness;
                creators["prowl"] = &AiObjectContextInternal::prowl;
                creators["dash"] = &AiObjectContextInternal::dash;
                creators["shred"] = &AiObjectContextInternal::shred;
                creators["ravage"] = &AiObjectContextInternal::ravage;
                creators["pounce"] = &AiObjectContextInternal::pounce;
            }

        private:
            static Action* ravage(PlayerbotAI* ai) { return new CastRavageAction(ai); }
            static Action* pounce(PlayerbotAI* ai) { return new CastPounceAction(ai); }
            static Action* prowl(PlayerbotAI* ai) { return new CastProwlAction(ai); }
            static Action* dash(PlayerbotAI* ai) { return new CastDashAction(ai); }
            static Action* shred(PlayerbotAI* ai) { return new CastShredAction(ai); }
            static Action* natures_swiftness(PlayerbotAI* ai) { return new CastNaturesSwiftnessAction(ai); }
            static Action* omen_of_clarity(PlayerbotAI* ai) { return new CastOmenOfClarityAction(ai); }
            static Action* tranquility(PlayerbotAI* ai) { return new CastTranquilityAction(ai); }
            static Action* feral_charge_bear(PlayerbotAI* ai) { return new CastFeralChargeBearAction(ai); }
            static Action* feral_charge_cat(PlayerbotAI* ai) { return new CastFeralChargeCatAction(ai); }
            static Action* swipe_bear(PlayerbotAI* ai) { return new CastSwipeBearAction(ai); }
            static Action* faerie_fire_feral(PlayerbotAI* ai) { return new CastFaerieFireFeralAction(ai); }
            static Action* faerie_fire(PlayerbotAI* ai) { return new CastFaerieFireAction(ai); }
            static Action* bear_form(PlayerbotAI* ai) { return new CastBearFormAction(ai); }
            static Action* dire_bear_form(PlayerbotAI* ai) { return new CastDireBearFormAction(ai); }
            static Action* cat_form(PlayerbotAI* ai) { return new CastCatFormAction(ai); }
            static Action* tree_form(PlayerbotAI* ai) { return new CastTreeFormAction(ai); }
            static Action* travel_form(PlayerbotAI* ai) { return new CastTravelFormAction(ai); }
            static Action* aquatic_form(PlayerbotAI* ai) { return new CastAquaticFormAction(ai); }
            static Action* caster_form(PlayerbotAI* ai) { return new CastCasterFormAction(ai); }
            static Action* mangle_bear(PlayerbotAI* ai) { return new CastMangleBearAction(ai); }
            static Action* maul(PlayerbotAI* ai) { return new CastMaulAction(ai); }
            static Action* bash(PlayerbotAI* ai) { return new CastBashAction(ai); }
            static Action* swipe(PlayerbotAI* ai) { return new CastSwipeAction(ai); }
            static Action* growl(PlayerbotAI* ai) { return new CastGrowlAction(ai); }
            static Action* demoralizing_roar(PlayerbotAI* ai) { return new CastDemoralizingRoarAction(ai); }
            static Action* moonkin_form(PlayerbotAI* ai) { return new CastMoonkinFormAction(ai); }
            static Action* hibernate(PlayerbotAI* ai) { return new CastHibernateAction(ai); }
            static Action* entangling_roots(PlayerbotAI* ai) { return new CastEntanglingRootsAction(ai); }
            static Action* entangling_roots_on_cc(PlayerbotAI* ai) { return new CastEntanglingRootsCcAction(ai); }
            static Action* entangling_roots_on_snare(PlayerbotAI* ai) { return new CastEntanglingRootsSnareAction(ai); }
            static Action* hibernate_on_cc(PlayerbotAI* ai) { return new CastHibernateCcAction(ai); }
            static Action* wrath(PlayerbotAI* ai) { return new CastWrathAction(ai); }
            static Action* starfall(PlayerbotAI* ai) { return new CastStarfallAction(ai); }
            static Action* insect_swarm(PlayerbotAI* ai) { return new CastInsectSwarmAction(ai); }
            static Action* moonfire(PlayerbotAI* ai) { return new CastMoonfireAction(ai); }
            static Action* starfire(PlayerbotAI* ai) { return new CastStarfireAction(ai); }
            static Action* natures_grasp(PlayerbotAI* ai) { return new CastNaturesGraspAction(ai); }
            static Action* claw(PlayerbotAI* ai) { return new CastClawAction(ai); }
            static Action* mangle_cat(PlayerbotAI* ai) { return new CastMangleCatAction(ai); }
            static Action* swipe_cat(PlayerbotAI* ai) { return new CastSwipeCatAction(ai); }
            static Action* rake(PlayerbotAI* ai) { return new CastRakeAction(ai); }
            static Action* ferocious_bite(PlayerbotAI* ai) { return new CastFerociousBiteAction(ai); }
            static Action* rip(PlayerbotAI* ai) { return new CastRipAction(ai); }
            static Action* cower(PlayerbotAI* ai) { return new CastCowerAction(ai); }
            static Action* survival_instincts(PlayerbotAI* ai) { return new CastSurvivalInstinctsAction(ai); }
            static Action* thorns(PlayerbotAI* ai) { return new CastThornsAction(ai); }
            static Action* thorns_on_party(PlayerbotAI* ai) { return new CastThornsOnPartyAction(ai); }
            static Action* cure_poison(PlayerbotAI* ai) { return new CastCurePoisonAction(ai); }
            static Action* cure_poison_on_party(PlayerbotAI* ai) { return new CastCurePoisonOnPartyAction(ai); }
            static Action* abolish_poison(PlayerbotAI* ai) { return new CastAbolishPoisonAction(ai); }
            static Action* abolish_poison_on_party(PlayerbotAI* ai) { return new CastAbolishPoisonOnPartyAction(ai); }
            static Action* remove_curse(PlayerbotAI* ai) { return new CastRemoveCurseAction(ai); }
            static Action* remove_curse_on_party(PlayerbotAI* ai) { return new CastRemoveCurseOnPartyAction(ai); }
            static Action* berserk(PlayerbotAI* ai) { return new CastBerserkAction(ai); }
            static Action* tigers_fury(PlayerbotAI* ai) { return new CastTigersFuryAction(ai); }
            static Action* mark_of_the_wild(PlayerbotAI* ai) { return new CastMarkOfTheWildAction(ai); }
            static Action* mark_of_the_wild_on_party(PlayerbotAI* ai) { return new CastMarkOfTheWildOnPartyAction(ai); }
            static Action* gift_of_the_wild_on_party(PlayerbotAI* ai) { return new CastGiftOfTheWildOnPartyAction(ai); }
            static Action* regrowth(PlayerbotAI* ai) { return new CastRegrowthAction(ai); }
            static Action* rejuvenation(PlayerbotAI* ai) { return new CastRejuvenationAction(ai); }
            static Action* healing_touch(PlayerbotAI* ai) { return new CastHealingTouchAction(ai); }
            static Action* regrowth_on_party(PlayerbotAI* ai) { return new CastRegrowthOnPartyAction(ai); }
            static Action* rejuvenation_on_party(PlayerbotAI* ai) { return new CastRejuvenationOnPartyAction(ai); }
            static Action* healing_touch_on_party(PlayerbotAI* ai) { return new CastHealingTouchOnPartyAction(ai); }
            static Action* rebirth(PlayerbotAI* ai) { return new CastRebirthAction(ai); }
            static Action* revive(PlayerbotAI* ai) { return new CastReviveAction(ai); }
            static Action* barskin(PlayerbotAI* ai) { return new CastBarskinAction(ai); }
            static Action* lacerate(PlayerbotAI* ai) { return new CastLacerateAction(ai); }
            static Action* hurricane(PlayerbotAI* ai) { return new CastHurricaneAction(ai); }
            static Action* innervate(PlayerbotAI* ai) { return new CastInnervateAction(ai); }
            static Action* bash_on_enemy_healer(PlayerbotAI* ai) { return new CastBashOnEnemyHealerAction(ai); }
        };
    };
};

DruidAiObjectContext::DruidAiObjectContext(PlayerbotAI* ai) : AiObjectContext(ai)
{
    strategyContexts.Add(new ai::druid::StrategyFactoryInternal());
    strategyContexts.Add(new ai::druid::DruidStrategyFactoryInternal());
    actionContexts.Add(new ai::druid::AiObjectContextInternal());
    triggerContexts.Add(new ai::druid::TriggerFactoryInternal());
}
