class cfgWeapons
{
    class ItemCore;
	class HeadgearItem;
    class VestItem;
    class UniformItem;
 
    class U_Juggernaut: Uniform_Base
    {
        author = "Salbei";
        scope = 1;
        displayName = "Uniform Juggernaut";
		picture = "\A3\characters_f\data\ui\icon_U_B_CombatUniform_mcam_ca.paa";
		model = "\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"\A3\Characters_F\Common\Suitpacks\data\suitpack_soldier_blufor_co.paa"};
 
        class ItemInfo: UniformItem
        {
            containerClass = Supply40;
            mass = 40;
        };
    };
	
    class V_Juggernaut: ItemCore
    {
        author = "Salbei";
        scope = 1;
		displayName = "Vest Juggernaut";
        weaponPoolAvailable = 1;
        allowedSlots[] = {};         // This means the vest can be put into a backpack.
        picture = "\A3\characters_f_Beta\Data\UI\icon_V_I_Vest_02_ca.paa";
		model = "A3\Characters_F_Beta\INDEP\equip_ia_vest02";
		descriptionShort = "Armor Level over 9000";
        class ItemInfo: VestItem
        {
            containerClass = Supply40;
            mass = 60;
 
           class HitpointsProtectionInfo
			{
				class Neck
				{
					hitpointName	= "HitNeck"; // reference to the hit point class defined in the man base class
					armor		= 50; // addition to armor of referenced hitpoint
					passThrough	= 0.5; // multiplier of base passThrough defined in referenced hitpoint
				};
				class Arms
				{
					hitpointName	= "HitArms";
					armor		= 50;
					passThrough	= 0.5;
				};
				class Chest 
				{
					hitpointName	= "HitChest"; 
					armor		= 50; 
					passThrough	= 0.1; 
				};
				class Diaphragm
				{
					hitpointName	= "HitDiaphragm";
					armor		= 50;
					passThrough	= 0.1;
				};
				class Abdomen
				{
					hitpointName	= "HitAbdomen"; 
					armor		= 50;
					passThrough	= 0.1;
				};
				class Body
				{
					hitpointName	= "HitBody";
					passThrough	= 0.1;
				};
			};
        };
    };

    class H_Juggernaut: ItemCore {
        author = "Salbei";
        scope = 2;
        weaponPoolAvailable = 1;
        displayName = "Helmet Juggernaut";
        picture = "\A3\Characters_F_Exp\BLUFOR\Data\UI\icon_H_HelmetB_TI_tna_F_ca.paa";
		model = "\A3\Characters_F_Exp\BLUFOR\H_HelmetB_TI_tna_F.p3d";
		DLC = "Expansion";
		descriptionShort = "Armor Level over 9000";
		hiddenSelectionsTextures[] = {"\A3\Characters_F_Exp\BLUFOR\Data\H_HelmetB_TI_tna_F_co.paa"};
		hiddenSelectionsMaterials[] = {"\A3\Characters_F_Exp\BLUFOR\Data\H_HelmetB_TI_tna_F.rvmat"};
        class ItemInfo: HeadgearItem
        {
            mass = 40;
  
            class H_HelmetB: ItemCore {	
				class HitpointsProtectionInfo {
					class Head {
						hitpointName	= "HitHead"; 		// reference to the hit point class defined in the man base class
						armor			= 50;				// addition to armor of referenced hitpoint
						passThrough		= 0.2; 				// multiplier of base passThrough defined in referenced hitpoint
					};
				};
			};
		};
    };
};