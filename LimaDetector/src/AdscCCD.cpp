static const char *RcsId = "$Id:  $";
//+=============================================================================
//
// file :         AdscCCD.cpp
//
// description :  C++ source for the AdscCCD and its commands. 
//                The class is derived from Device. It represents the
//                CORBA servant object which will be accessed from the
//                network. All commands which can be executed on the
//                AdscCCD are implemented in this file.
//
// project :      TANGO Device Server
//
// $Author:  $
//
// $Revision:  $
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
// copyleft :    Synchrotron SOLEIL 
//               L'Orme des merisiers - Saint Aubin
//               BP48 - 91192 Gif sur Yvette
//               FRANCE
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================



//===================================================================
//
//	The following table gives the correspondence
//	between commands and method name.
//
//  Command name         |  Method name
//	----------------------------------------
//  State                |  dev_state()
//  Status               |  dev_status()
//  SetHeaderParameters  |  set_header_parameters()
//
//===================================================================

#ifdef WIN32
#include "tango.h"
#include <PogoHelper.h>
#endif

#include <AdscCCD.h>
#include <AdscCCDClass.h>

#ifndef WIN32
#include "tango.h"
#include <PogoHelper.h>
#endif

namespace AdscCCD_ns
{

//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::AdscCCD(string &s)
// 
// description : 	constructor for simulated AdscCCD
//
// in : - cl : Pointer to the DeviceClass object
//      - s : Device name 
//
//-----------------------------------------------------------------------------
AdscCCD::AdscCCD(Tango::DeviceClass *cl,string &s)
:Tango::Device_4Impl(cl,s.c_str())
{
	init_device();
}

AdscCCD::AdscCCD(Tango::DeviceClass *cl,const char *s)
:Tango::Device_4Impl(cl,s)
{
	init_device();
}

AdscCCD::AdscCCD(Tango::DeviceClass *cl,const char *s,const char *d)
:Tango::Device_4Impl(cl,s,d)
{
	init_device();
}
//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::delete_device()
// 
// description : 	will be called at device destruction or at init command.
//
//-----------------------------------------------------------------------------
void AdscCCD::delete_device()
{
    DELETE_DEVSTRING_ATTRIBUTE(attr_imagePath_read);
    DELETE_DEVSTRING_ATTRIBUTE(attr_fileName_read);   
    DELETE_SCALAR_ATTRIBUTE(attr_useStoredImageDark_read);
    DELETE_SCALAR_ATTRIBUTE(attr_imageKind_read);
    DELETE_SCALAR_ATTRIBUTE(attr_isLastImage_read);        
    //	Delete device allocated objects
    //!!!! ONLY LimaDetector device can do this !!!!
    //if(m_ct!=0)
    //{
    //    ControlFactory::instance().reset("AdscCCD");
    //    m_ct = 0;
    //}
}

//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::init_device()
// 
// description : 	will be called at device initialization.
//
//-----------------------------------------------------------------------------
void AdscCCD::init_device()
{
	INFO_STREAM << "AdscCCD::AdscCCD() create device " << device_name << endl;

	// Initialise variables to default values
	//--------------------------------------------
	get_device_property();

    CREATE_DEVSTRING_ATTRIBUTE(attr_imagePath_read,MAX_ATTRIBUTE_STRING_LENGTH);
    CREATE_DEVSTRING_ATTRIBUTE(attr_fileName_read,MAX_ATTRIBUTE_STRING_LENGTH);
    CREATE_SCALAR_ATTRIBUTE(attr_useStoredImageDark_read);
    CREATE_SCALAR_ATTRIBUTE(attr_imageKind_read);
    CREATE_SCALAR_ATTRIBUTE(attr_isLastImage_read);    
	m_is_device_initialized = false;
	m_status_message.str("");
    set_state(Tango::INIT);

  try
  {
      //- get the main object used to pilot the lima framework
      //in fact LimaDetector is create the singleton control objet
      //so this call, will only return existing object, no need to give it the ip !!
      m_ct = ControlFactory::instance().get_control("AdscCCD");
      
      //- get interface to specific camera
      m_hw = dynamic_cast<Adsc::Interface*>(m_ct->hwInterface());
      if(m_hw==0)
      {
          INFO_STREAM<<"Initialization Failed : Unable to get the interface of camera plugin "<<"("<<"AdscCCD"<<") !"<< endl;
          m_status_message <<"Initialization Failed : Unable to get the interface of camera plugin "<<"("<<"AdscCCD"<<") !"<< endl;
          m_is_device_initialized = false;
          set_state(Tango::FAULT);
          return;
      }
  }
  catch(Exception& e)
  {
      INFO_STREAM<<"Initialization Failed : "<<e.getErrMsg()<<endl;
      m_status_message <<"Initialization Failed : "<<e.getErrMsg( )<< endl;
      m_is_device_initialized = false;
      set_state(Tango::FAULT);
      return;
  }
  catch(...)
  {
      INFO_STREAM<<"Initialization Failed : UNKNOWN"<<endl;
      m_status_message <<"Initialization Failed : UNKNOWN"<< endl;
      set_state(Tango::FAULT);
      m_is_device_initialized = false;
      return;
  }
  m_is_device_initialized = true;
  set_state(Tango::STANDBY);
  this->dev_state();
}


//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::get_device_property()
// 
// description : 	Read the device properties from database.
//
//-----------------------------------------------------------------------------
void AdscCCD::get_device_property()
{
	//	Initialize your default values here (if not done with  POGO).
	//------------------------------------------------------------------

	//	Read device properties from database.(Automatic code generation)
	//------------------------------------------------------------------
	Tango::DbData	dev_prop;
	dev_prop.push_back(Tango::DbDatum("ReaderTimeout"));
	dev_prop.push_back(Tango::DbDatum("UseReader"));

	//	Call database and extract values
	//--------------------------------------------
	if (Tango::Util::instance()->_UseDb==true)
		get_db_device()->get_property(dev_prop);
	Tango::DbDatum	def_prop, cl_prop;
	AdscCCDClass	*ds_class =
		(static_cast<AdscCCDClass *>(get_device_class()));
	int	i = -1;

	//	Try to initialize ReaderTimeout from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  readerTimeout;
	else {
		//	Try to initialize ReaderTimeout from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  readerTimeout;
	}
	//	And try to extract ReaderTimeout value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  readerTimeout;

	//	Try to initialize UseReader from class property
	cl_prop = ds_class->get_class_property(dev_prop[++i].name);
	if (cl_prop.is_empty()==false)	cl_prop  >>  useReader;
	else {
		//	Try to initialize UseReader from default device value
		def_prop = ds_class->get_default_device_property(dev_prop[i].name);
		if (def_prop.is_empty()==false)	def_prop  >>  useReader;
	}
	//	And try to extract UseReader value from database
	if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  useReader;



	//	End of Automatic code generation
	//------------------------------------------------------------------
	create_property_if_empty(dev_prop,"1000","ReaderTimeout");
    create_property_if_empty(dev_prop,"true","UseReader");
}
//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::always_executed_hook()
// 
// description : 	method always executed before any command is executed
//
//-----------------------------------------------------------------------------
void AdscCCD::always_executed_hook()
{
	DEBUG_STREAM << "AdscCCD::always_executed_hook() entering... "<< endl;
	try
	{
	    m_status_message.str("");
		//- get the singleton control objet used to pilot the lima framework
		m_ct = ControlFactory::instance().get_control("AdscCCD");

		//- get interface to specific detector
		if(m_ct!=0)
			m_hw = dynamic_cast<Adsc::Interface*>(m_ct->hwInterface());

	}
	catch(Exception& e)
	{
		ERROR_STREAM << e.getErrMsg() << endl;
		m_status_message <<"Initialization Failed : "<<e.getErrMsg( )<< endl;
		//- throw exception
		set_state(Tango::FAULT);
		m_is_device_initialized = false;
		return;
	}
	catch(...)
	{
		ERROR_STREAM<<"Initialization Failed : UNKNOWN"<<endl;
		m_status_message <<"Initialization Failed : UNKNOWN"<< endl;
		//- throw exception
		set_state(Tango::FAULT);
		m_is_device_initialized = false;
		return;
	}
}
//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::read_attr_hardware
// 
// description : 	Hardware acquisition for attributes.
//
//-----------------------------------------------------------------------------
void AdscCCD::read_attr_hardware(vector<long> &attr_list)
{
	DEBUG_STREAM << "AdscCCD::read_attr_hardware(vector<long> &attr_list) entering... "<< endl;
	//	Add your own code here
}
//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::read_useStoredImageDark
// 
// description : 	Extract real attribute values for useStoredImageDark acquisition result.
//
//-----------------------------------------------------------------------------
void AdscCCD::read_useStoredImageDark(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdscCCD::read_useStoredImageDark(Tango::Attribute &attr) entering... "<< endl;
    try
    {
        
        *attr_useStoredImageDark_read = m_hw->getStoredImageDark();
        attr.set_value(attr_useStoredImageDark_read);
    }
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                    static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                    static_cast<const char*> (string(df.errors[0].desc).c_str()),
                    static_cast<const char*> ("AdscCCD::read_useStoredImageDark"));
    }	
}

//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::write_useStoredImageDark
// 
// description : 	Write useStoredImageDark attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdscCCD::write_useStoredImageDark(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdscCCD::write_useStoredImageDark(Tango::WAttribute &attr) entering... "<< endl;
    try
    {
        attr.get_write_value(attr_useStoredImageDark_write);
        m_hw->setStoredImageDark(attr_useStoredImageDark_write);
    }
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                    static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                    static_cast<const char*> (string(df.errors[0].desc).c_str()),
                    static_cast<const char*> ("AdscCCD::write_useStoredImageDark"));
    }
}

//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::read_imageKind
// 
// description : 	Extract real attribute values for imageKind acquisition result.
//
//-----------------------------------------------------------------------------
void AdscCCD::read_imageKind(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdscCCD::read_imageKind(Tango::Attribute &attr) entering... "<< endl;
    try
    {
        
        *attr_imageKind_read = m_hw->getImageKind();
        attr.set_value(attr_imageKind_read);
    }
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                    static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                    static_cast<const char*> (string(df.errors[0].desc).c_str()),
                    static_cast<const char*> ("AdscCCD::read_useStoredImageDark"));
    }		
}

//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::write_imageKind
// 
// description : 	Write imageKind attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdscCCD::write_imageKind(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdscCCD::write_imageKind(Tango::WAttribute &attr) entering... "<< endl;
    try
    {
        attr.get_write_value(attr_imageKind_write);
        m_hw->setImageKind(attr_imageKind_write);
    }
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                    static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                    static_cast<const char*> (string(df.errors[0].desc).c_str()),
                    static_cast<const char*> ("AdscCCD::write_imageKind"));
    }	
}

//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::read_isLastImage
// 
// description : 	Extract real attribute values for isLastImage acquisition result.
//
//-----------------------------------------------------------------------------
void AdscCCD::read_isLastImage(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdscCCD::read_isLastImage(Tango::Attribute &attr) entering... "<< endl;
    try
    {
        
        *attr_isLastImage_read = m_hw->getLastImage();
        attr.set_value(attr_isLastImage_read);
    }
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                    static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                    static_cast<const char*> (string(df.errors[0].desc).c_str()),
                    static_cast<const char*> ("AdscCCD::read_isLastImage"));
    }		
}

//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::write_isLastImage
// 
// description : 	Write isLastImage attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdscCCD::write_isLastImage(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdscCCD::write_isLastImage(Tango::WAttribute &attr) entering... "<< endl;
    try
    {
        attr.get_write_value(attr_isLastImage_write);
        m_hw->setLastImage(attr_isLastImage_write);
    }
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                    static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                    static_cast<const char*> (string(df.errors[0].desc).c_str()),
                    static_cast<const char*> ("AdscCCD::write_isLastImage"));
    }	
}

//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::read_imagePath
// 
// description : 	Extract real attribute values for imagePath acquisition result.
//
//-----------------------------------------------------------------------------
void AdscCCD::read_imagePath(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdscCCD::read_imagePath(Tango::Attribute &attr) entering... "<< endl;
    try
    {
        strcpy(*attr_imagePath_read, m_hw->getImagePath().c_str());
        attr.set_value(attr_imagePath_read);
    }
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                     static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                     static_cast<const char*> (string(df.errors[0].desc).c_str()),
                     static_cast<const char*> ("AdscCCD::read_imagePath"));
    }
    catch(Exception& e)
    {
        ERROR_STREAM << e.getErrMsg() << endl;
        //- throw exception
        Tango::Except::throw_exception(
                     static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                     static_cast<const char*> (e.getErrMsg().c_str()),
                     static_cast<const char*> ("AdscCCD::read_imagePath"));
    }  
}

//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::write_imagePath
// 
// description : 	Write imagePath attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdscCCD::write_imagePath(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdscCCD::write_imagePath(Tango::WAttribute &attr) entering... "<< endl;
    try
    {
        attr.get_write_value(attr_imagePath_write);
        m_hw->setImagePath(attr_imagePath_write);
    }
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                     static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                     static_cast<const char*> (string(df.errors[0].desc).c_str()),
                     static_cast<const char*> ("AdscCCD::write_imagePath"));
    }
    catch(Exception& e)
    {
        ERROR_STREAM << e.getErrMsg() << endl;
        //- throw exception
        Tango::Except::throw_exception(
                     static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                     static_cast<const char*> (e.getErrMsg().c_str()),
                     static_cast<const char*> ("AdscCCD::write_imagePath"));
    }   
}


//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::read_fileName
// 
// description : 	Extract real attribute values for fileName acquisition result.
//
//-----------------------------------------------------------------------------
void AdscCCD::read_fileName(Tango::Attribute &attr)
{
	DEBUG_STREAM << "AdscCCD::read_fileName(Tango::Attribute &attr) entering... "<< endl;
    try
    {
        strcpy(*attr_fileName_read, m_hw->getFileName().c_str());
        attr.set_value(attr_fileName_read);
    }
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                     static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                     static_cast<const char*> (string(df.errors[0].desc).c_str()),
                     static_cast<const char*> ("AdscCCD::read_fileName"));
    }
    catch(Exception& e)
    {
        ERROR_STREAM << e.getErrMsg() << endl;
        //- throw exception
        Tango::Except::throw_exception(
                     static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                     static_cast<const char*> (e.getErrMsg().c_str()),
                     static_cast<const char*> ("AdscCCD::read_fileName"));
    }    
}

//+----------------------------------------------------------------------------
//
// method : 		AdscCCD::write_fileName
// 
// description : 	Write fileName attribute values to hardware.
//
//-----------------------------------------------------------------------------
void AdscCCD::write_fileName(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "AdscCCD::write_fileName(Tango::WAttribute &attr) entering... "<< endl;
    try
    {
        attr.get_write_value(attr_fileName_write);
        m_hw->setFileName(attr_fileName_write);
    }
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                     static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                     static_cast<const char*> (string(df.errors[0].desc).c_str()),
                     static_cast<const char*> ("AdscCCD::write_fileName"));
    }
    catch(Exception& e)
    {
        ERROR_STREAM << e.getErrMsg() << endl;
        //- throw exception
        Tango::Except::throw_exception(
                     static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                     static_cast<const char*> (e.getErrMsg().c_str()),
                     static_cast<const char*> ("AdscCCD::write_fileName"));
    }   
}




//+------------------------------------------------------------------
/**
 *	method:	AdscCCD::dev_state
 *
 *	description:	method to execute "State"
 *	This command gets the device state (stored in its <i>device_state</i> data member) and returns it to the caller.
 *
 * @return	State Code
 *
 */
//+------------------------------------------------------------------
Tango::DevState AdscCCD::dev_state()
{
	Tango::DevState	argout = DeviceImpl::dev_state();
	DEBUG_STREAM << "AdscCCD::dev_state(): entering... !" << endl;

	//	Add your own code to control device here

    stringstream    DeviceStatus;
    DeviceStatus     << "";
    Tango::DevState DeviceState    = Tango::STANDBY;
    if(!m_is_device_initialized )
    {
        DeviceState            = Tango::FAULT;
        DeviceStatus        << m_status_message.str();
    }
    else
	{
		//state&status are retrieved from specific device
		DeviceState = ControlFactory::instance().get_state();
		DeviceStatus << ControlFactory::instance().get_status();		
    }

    set_state(DeviceState);
    set_status(DeviceStatus.str());

    argout = DeviceState;
    return argout;
}






//+------------------------------------------------------------------
/**
 *	method:	AdscCCD::set_header_parameters
 *
 *	description:	method to execute "SetHeaderParameters"
 *	Set crystallographic parameters reported in the image header. <br>
 *	
 *	[param_name=value]<CARRIAGE RETURN>[param_name=value]<CARRIAGE RETURN>...<br>
 *	
 *	sample :<br>
 *	DISTANCE=300\nPHI=88.5\n...\nWAVELENGTH=0.987\n\0<br>
 *	
 *	List of availables param_name :<br>
 *
 * @param	argin	
 *
 */
//+------------------------------------------------------------------
void AdscCCD::set_header_parameters(Tango::DevString argin)
{
	DEBUG_STREAM << "AdscCCD::set_header_parameters(): entering... !" << endl;

	//	Add your own code to control device here
    try
    {
        std::string str_header_parameters = argin;
        m_hw->setHeaderParameters(str_header_parameters);
    }
    catch(Tango::DevFailed& df)
    {
        ERROR_STREAM << df << endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                     static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                     static_cast<const char*> (string(df.errors[0].desc).c_str()),
                     static_cast<const char*> ("AdscCCD::set_header_parameters"));
    }
    catch(Exception& e)
    {
        ERROR_STREAM << e.getErrMsg() << endl;
        //- throw exception
        Tango::Except::throw_exception(
                     static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                     static_cast<const char*> (e.getErrMsg().c_str()),
                     static_cast<const char*> ("AdscCCD::set_header_parameters"));
    }
}


/*-------------------------------------------------------------------------
//       LimaDetector::store_value_as_property
/-------------------------------------------------------------------------*/
template <class T>
void AdscCCD::store_value_as_property (T value, string property_name)
{
    Tango::DbDatum current_value(property_name);
    current_value << value;
    Tango::DbData db_data;
    db_data.push_back(current_value);
    try
    {
        get_db_device()->put_property(db_data);
    }
    catch(Tango::DevFailed &df)
    {
        string message= "Error in storing " + property_name + " in Configuration DataBase ";
        LOG_ERROR((message));
        ERROR_STREAM<<df<<endl;
        //- rethrow exception
        Tango::Except::re_throw_exception(df,
                    static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                    static_cast<const char*> (string(df.errors[0].desc).c_str()),
                    static_cast<const char*> ("LimaDetector::store_value_as_property"));
    }

}

/*-------------------------------------------------------------------------
//       LimaDetector::create_property_if_empty
/-------------------------------------------------------------------------*/
template <class T>
void AdscCCD::create_property_if_empty(Tango::DbData& dev_prop,T value,string property_name)
{
    int iPropertyIndex = FindIndexFromPropertyName(dev_prop,property_name);
    if (iPropertyIndex == -1) return;
    if (dev_prop[iPropertyIndex].is_empty())
    {
        Tango::DbDatum current_value(dev_prop[iPropertyIndex].name);
        current_value << value;
        Tango::DbData db_data;
        db_data.push_back(current_value);

        try
        {
            get_db_device()->put_property(db_data);
        }
        catch(Tango::DevFailed &df)
        {
            string message= "Error in storing " + property_name + " in Configuration DataBase ";
            LOG_ERROR((message));
            ERROR_STREAM<<df<<endl;
            //- rethrow exception
            Tango::Except::re_throw_exception(df,
                        static_cast<const char*> ("TANGO_DEVICE_ERROR"),
                        static_cast<const char*> (string(df.errors[0].desc).c_str()),
                        static_cast<const char*> ("LimaDetector::create_property_if_empty"));
        }
    }
}

/*-------------------------------------------------------------------------
//       LimaDetector::FindIndexFromPropertyName
/-------------------------------------------------------------------------*/
int AdscCCD::FindIndexFromPropertyName(Tango::DbData& dev_prop, string property_name)
{
    size_t iNbProperties = dev_prop.size();
    unsigned int i;
    for (i=0;i<iNbProperties;i++)
    {
        string sPropertyName(dev_prop[i].name);
        if (sPropertyName == property_name) return i;
    }
    if (i == iNbProperties) return -1;
    return i;
}



















}	//	namespace
