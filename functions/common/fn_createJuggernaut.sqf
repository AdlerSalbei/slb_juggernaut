/*
	Function: slb_juggernaut_fnc_createJuggernaut
	Author: BIS, Salbei
	SPAWNS JUGGERNAUTS
	
	Arguments(s):
	0: Side (blufor, opfor, independent) <STRING>
	1: Spawn Position <POSITION>
	2: Target Position <POSITION>
	3: Target Typ <STRING>
	4: Amount SPAWNED (default: 1) <NUMBER>
	
	Return Value:
	Group
		
	Example:
	_grp = [
		opfor,
		[0,0,0], 
		[0,0,0],
		"DESTROY",
		1
	] call slb_juggernaut_fnc_createJuggernaut;
__________________________________________________________________*/

if !(isServer) exitWith {};
params [
			["_side", "opfor"],
			["_pos", [0,0,0]],
			["_target", [0,0,0]],
			["_targetTyp", "HOLD"]
			["_amount", 1],
		];
if (_side != "blufor" && _side != "opfor" && _side != "independent") exitWith {diag_log format ["JUG: Wrong side passed to script: %1", _side];};
if (_pos isEqualTo [0,0,0]) exitWith {diag_log "JUG: No position passed to script!";};
if (_target isEqualTo [0,0,0]) then {_target = _pos};
_unit		= ""; 
_weapon		= ""; 
_uniform	= ""; 
_vest		= "";
_backpack	= "";
_helmet		= ""; 
_facewear	= "";

switch (_side) do {
	case "blufor" 	: {
						_unit		= "B_Soldier_F"; //	B_Juggernaut
						_weapon		= selectRandom ["LMG_Mk200_F", "MMG_02_black_F", "arifle_SPAR_02_blk_F", "arifle_MX_SW_Black_F"]; 
						_uniform	= "U_B_SpecopsUniform_sgg"; 
						_vest		= "V_PlateCarrierGL_rgr";
						_backpack	= "";
						_helmet		= "H_HelmetB_TI_tna_F"; 
						_facewear	= "G_Balaclava_TI_G_tna_F";
					};
	case "opfor" 	: {
						_unit		= "O_G_Soldier_F"; //	O_Juggernaut
						_weapon		= selectRandom ["LMG_Zafir_F", "arifle_CTARS_blk_F", "MMG_01_tan_F"]; 
						_uniform	= "U_O_V_Soldier_Viper_hex_F"; 
						_vest		= "V_PlateCarrierIA2_dgtl";
						_backpack	= "";
						_helmet		= "H_HelmetB_TI_tna_F"; 
						_facewear	= "G_Balaclava_TI_G_tna_F";
					};
	case "independent" 	: {
						_unit		= "I_G_Soldier_F"; //	I_Juggernaut
						_weapon		= selectRandom ["LMG_03_F"]; 
						_uniform	= "U_I_pilotCoveralls"; 
						_vest		= "V_PlateCarrierIA2_dgtl";
						_backpack	= "";
						_helmet		= "H_HelmetB_TI_tna_F"; 
						_facewear	= "G_Balaclava_TI_G_tna_F";
					};
};

_value = [_weapon] call slb_juggernaut_fnc_getMagAndAttach;
_value params ["_magazine", "_muzzleItem", "_scope"];
  
_grp = createGroup _side;
for "_i" from 1 to _amount do {
	_juggernaut = _grp createUnit [_unit, _pos, [], 0.1, "COLONEL"];
	_juggernaut setUnitLoadout [[_weapon,,,,[], [], ""], [], [ "", "", "", "", [], [], ""],[_uniform, []],[_vest, []], [_backpack, []], _helmet, _facewear,[],["","","","","",""]];
	_juggernaut addMagazines [_magazine, 10];
	if (_muzzleItem != "EMPTY") then {
		_juggernaut addPrimaryWeaponItem _muzzleItem;
	};

	if (_scope != "EMPTY") then {
		_juggernaut addPrimaryWeaponItem _scope;
	};

	_juggernaut forceWalk true;
	_juggernaut enableAimPrecision false;
	_juggernaut setUnitPos "UP";
};

_wp =_grp addWaypoint [_target, 0];
_wp setWaypointBehaviour "COMBAT";
_wp setWaypointCombatMode "YELLOW";
_wp setWaypointFormation "LINE";
_wp setWaypointSpeed "LIMITED";
_wp setWaypointType _targetTyp;
_grp;