for "_i" from 0 to (count (configFile / "CfgPatches") - 1) do 
{
_cfg_entry = (configFile / "CfgPatches") select _i;

if (isClass _cfg_entry) then
{
	diag_log format ["%1", _cfg_entry];
};
};