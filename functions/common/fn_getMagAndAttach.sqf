params ["_weapon"];
_value = [];

//magazines =====================================================================
_magazines = getArray (configFile / "CfgWeapons" / _weapon / "magazines");
_magazine = selectRandom _magazines;

//muzzle attachments ===================================================================
_cfg = (configFile >> "CfgWeapons" >> _weapon >> "WeaponSlotsInfo" >> "MuzzleSlot" >> "compatibleItems");
_allMuzzleItems = getArray _cfg;

//RHS is stupid
if (count _allMuzzleItems == 0) then {
	_attributes = configProperties [_cfg, "true", true];
	{
		_str = str (_x);
		_strArray = _str splitString "/";
		_attachmentName = _strArray select ((count _strArray) - 1);
		if ((getNumber (configFile >> "CfgWeapons" >> _weapon >> "WeaponSlotsInfo" >> "MuzzleSlot" >> "compatibleItems" >> _attachmentName)) == 1) then {
			_allMuzzleItems pushBack _attachmentName;
		};
	} forEach _attributes;
};

if (count _allMuzzleItems == 0) then {
	_muzzleItem = "EMPTY";
} else {
	_muzzleItem = selectRandom _allMuzzleItems;
};

//scopes ===================================================================
_cfg = (configFile >> "CfgWeapons" >> _weapon >> "WeaponSlotsInfo" >> "CowsSlot" >> "compatibleItems");
_attributes = configProperties [_cfg, "true", true];
_compatibleScopes = [];
{
	_str = str (_x);
	_strArray = _str splitString "/";
	_scopeName = _strArray select ((count _strArray) -1);
	_compatibleScopes pushBack _scopeName;
} forEach _attributes;

if (count _compatibleScopes == 0) then {
	_compatibleScopes = getArray (configFile >> "CfgWeapons" >> _weapon >> "WeaponSlotsInfo" >> "CowsSlot" >> "compatibleItems");
	if (count _compatibleScopes == 0) then {
		_scope = "EMPTY";
	};

} else {
	_scopeFound = false;
	for [{_i=0}, {_i<50}, {_i=_i+1}] do {
		_randomID = round (random ((count _compatibleScopes) - 1));
		_scope = _compatibleScopes select _randomID;
		_scopeFound = _scope in _standartScopes;

		if (_scopeFound) exitWith {};
		_compatibleScopes deleteAt _randomID;
		if (count _compatibleScopes == 0) exitWith {};
	};
	
	if !(_scopeFound) then {
		_scope = "EMPTY";
	};
};

_value pushBack ["_magazine", "_muzzleItem", "_scope"];
_value;