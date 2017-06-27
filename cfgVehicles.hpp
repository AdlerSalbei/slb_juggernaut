class CfgVehicles {
	class Man;
	class CAManBase: Man
	{
		class HitPoints
		{
			class HitHead;
			class HitBody;
			class HitHands;
			class HitLegs;
		};
	};
	class JUG_CAManBase: CAManBase
	{
		armor					= 2; 
		armorStructural			= 0.4; 
		explosionShielding		= 0.04;
		minTotalDamageThreshold	= 0.001; 
		impactDamageMultiplier	= 0.05;
 
		class HitPoints
		{
			class HitFace
			{
				armor               = 1; 
				material            = -1; 
				name                = "face_hub"; 
				passThrough         = 0.1; 
				radius              = 0.08; 
				explosionShielding  = 0.1;
				minimalHit          = 0.01;
			}
			class HitNeck: HitFace
			{
				armor               = 1;
				material            = -1;
				name                = "neck";
				passThrough         = 0.1;
				radius              = 0.1;
				explosionShielding  = 0.5;
				minimalHit          = 0.01;
			}
			class HitHead: HitNeck
			{
				armor               = 1;
				material            = -1;
				name                = "head";
				passThrough         = 0.1;
				radius              = 0.2;
				explosionShielding  = 0.5;
				minimalHit          = 0.01;
				depends             = "HitFace max HitNeck";
			};
			class HitPelvis
			{
				armor               = 1;
				material            = -1;
				name                = "pelvis";
				passThrough         = 0.1;
				radius              = 0.2;
				explosionShielding  = 1;
				visual              = "injury_body";
				minimalHit          = 0.01;
			};
			class HitAbdomen: HitPelvis
			{
				armor               = 1;
				material            = -1;
				name                = "spine1";
				passThrough         = 0.1;
				radius              = 0.15;
				explosionShielding  = 1;
				visual              = "injury_body";
				minimalHit          = 0.01;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor               = 1;
				material            = -1;
				name                = "spine2";
				passThrough         = 0.1;
				radius              = 0.15;
				explosionShielding  = 6;
				visual              = "injury_body";
				minimalHit          = 0.01;
			}
			class HitChest: HitDiaphragm
			{
				armor               = 1;
				material            = -1;
				name                = "spine3";
				passThrough         = 0.1;
				radius              = 0.15;
				explosionShielding  = 6;
				visual              = "injury_body";
				minimalHit          = 0.01;
			};
			class HitBody: HitChest
			{
				armor               = 1000; // not supposed to take damage directly
				material            = -1;
				name                = "body";
				passThrough         = 0.1;
				radius              = 0.16;
				explosionShielding  = 6;
				visual              = "injury_body";
				minimalHit          = 0.01;
				depends             = "HitPelvis max HitAbdomen max HitDiaphragm max HitChest"; 
			};
			class HitArms
			{
				armor               = 1;
				material            = -1;
				name                = "arms";
				passThrough         = 1;
				radius              = 0.1;
				explosionShielding  = 1;
				visual              = "injury_hands";
				minimalHit          = 0.01;
			};
			class HitHands: HitArms
			{
				armor               = 1;
				material            = -1;
				name                = "hands";
				passThrough         = 1;
				radius              = 0.1;
				explosionShielding  = 1;
				visual              = "injury_hands";
				minimalHit          = 0.01;
				depends             = "HitArms";
			};
			class HitLegs
			{
				armor               = 1;
				material            = -1;
				name                = "legs";
				passThrough         = 1;
				radius              = 0.12;
				explosionShielding  = 1;
				visual              = "injury_legs";
				minimalHit          = 0.01;
			};
		};
	};
	
	class JuggernautWB: JUG_CAManBase;
	class B_Juggernaut: JuggernautWB {
		author = "Salbei";         											
        scope = 2;                          								
        scopeCurator = 2;
        scopeArsenal = 0;
        identityTypes[] =  {"LanguageENG_F","Head_NATO","G_NATO_default"};  
        displayName="B_Juggernaut";
        cost = 200;  
        camouflage = 3;                   									
        sensitivity = 1;                  									
        threat[] = {1, 0.3, 0.1};             								
        model = "\A3\characters_F\BLUFOR\b_soldier_02.p3d";       			
        uniformClass = "U_Juggernaut";                         				
		nakedUniform = "U_BasicBody";										
        hiddenSelections[] = {"Camo","insignia"};							
		hiddenSelectionsTextures[] = {"\a3\characters_f\blufor\data\clothing1_co.paa"};        
        canHideBodies = 0;													
		canDeactivateMines = 0;												
        engineer = false;                        							
        attendant = 0;														
        icon = "iconManMG";													
        picture = "";				              							
        backpack = "";       												
        weapons[] = {LMG_03_F, hgun_P07_F, Throw, Put};               		
        respawnWeapons[] = {LMG_03_F, hgun_P07_F, Throw, Put};        		
        Items[] = {};                										
        RespawnItems[] = {};         										
        magazines[] = {mag_5(200Rnd_556x45_Box_Tracer_Red_F)};              
        respawnMagazines[] = {mag_5(200Rnd_556x45_Box_Tracer_Red_F)};       
        linkedItems[] = {V_Juggernaut, H_Juggernaut};						
        respawnLinkedItems[] = {V_Juggernaut, H_Juggernaut};				
	};
	
	/*
	class O_Juggernaut: JuggernautWB {
		displayName="O_Juggernaut";
		vehicleClass = "Juggernauts";
		weapons[]={"Throw","Put"};
		magazines[]={};
	};
	
	class I_Juggernaut: JuggernautWB {
		displayName="I_Juggernaut";
		vehicleClass = "Juggernauts";
		weapons[]={"Throw","Put"};
		magazines[]={};
	};	
	*/
};