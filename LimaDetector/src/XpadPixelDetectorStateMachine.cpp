static const char *RcsId = "$Id $";
//+=============================================================================
//
// file :         XpadPixelDetectorStateMachine.cpp
//
// description :  C++ source for the XpadPixelDetector and its alowed 
//                methods for commands and attributes
//
// project :      TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// SVN only:
// $HeadURL: $
//
// CVS only:
// $Source:  $
// $Log:  $
//
// copyleft :     European Synchrotron Radiation Facility
//                BP 220, Grenoble 38043
//                FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================

#include <tango.h>
#include <XpadPixelDetector.h>
#include <XpadPixelDetectorClass.h>

/*====================================================================
 *	This file contains the methods to allow commands and attributes
 * read or write execution.
 *
 * If you wand to add your own code, add it between 
 * the "End/Re-Start of Generated Code" comments.
 *
 * If you want, you can also add your own methods.
 *====================================================================
 */

namespace XpadPixelDetector_ns
{

//=================================================
//		Attributes Allowed Methods
//=================================================

//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_dacl_allowed
// 
// description : 	Read/Write allowed for dacl attribute.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_dacl_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_ithl_allowed
// 
// description : 	Read/Write allowed for ithl attribute.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_ithl_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_deadTime_allowed
// 
// description : 	Read/Write allowed for deadTime attribute.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_deadTime_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_init_allowed
// 
// description : 	Read/Write allowed for init attribute.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_init_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_shutter_allowed
// 
// description : 	Read/Write allowed for shutter attribute.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_shutter_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_ovf_allowed
// 
// description : 	Read/Write allowed for ovf attribute.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_ovf_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_mode_allowed
// 
// description : 	Read/Write allowed for mode attribute.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_mode_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_n_allowed
// 
// description : 	Read/Write allowed for n attribute.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_n_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_p_allowed
// 
// description : 	Read/Write allowed for p attribute.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_p_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_gp1_allowed
// 
// description : 	Read/Write allowed for gp1 attribute.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_gp1_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_gp2_allowed
// 
// description : 	Read/Write allowed for gp2 attribute.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_gp2_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_gp3_allowed
// 
// description : 	Read/Write allowed for gp3 attribute.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_gp3_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_gp4_allowed
// 
// description : 	Read/Write allowed for gp4 attribute.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_gp4_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}

//=================================================
//		Commands Allowed Methods
//=================================================

//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_LoadFlatConfig_allowed
// 
// description : 	Execution allowed for LoadFlatConfig command.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_LoadFlatConfig_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_LoadAllConfigG_allowed
// 
// description : 	Execution allowed for LoadAllConfigG command.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_LoadAllConfigG_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_LoadConfigG_allowed
// 
// description : 	Execution allowed for LoadConfigG command.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_LoadConfigG_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_LoadAutoTest_allowed
// 
// description : 	Execution allowed for LoadAutoTest command.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_LoadAutoTest_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		XpadPixelDetector::is_GetDacl_allowed
// 
// description : 	Execution allowed for GetDacl command.
//
//-----------------------------------------------------------------------------
bool XpadPixelDetector::is_GetDacl_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::INIT	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}

}	// namespace XpadPixelDetector_ns
