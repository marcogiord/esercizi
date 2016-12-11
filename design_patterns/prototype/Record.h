#include <iostream>
#include <map>
#include <string>

#ifndef _RECORD_H
#define _RECORD_H

using namespace std;

enum RECORD_TYPE_en
{
	CAR,
	BIKE,
	PERSON
};

typedef unsigned int u_int32_t;

// record is the prototype

class Record
{
	public:
		Record(){}		
		~Record() {}
		
		virtual Record* Clone()=0 ;// pure virtual method this class can not be instatiated;		
		virtual void Print()=0;
		
};


// CarRevcord is the concrete protoype 

class CarRecord : public Record
{
  public :
  // constructor
    CarRecord(string _oStrCarName,u_int32_t _ui32ID) 
     : Record(), m_oStrCarName(_oStrCarName), m_ui32ID(_ui32ID)
	{
	
	}
  // copy contructor
    CarRecord(CarRecord& _oCarRecord)
    : Record()
	{
		 m_oStrCarName = _oCarRecord.m_oStrCarName;
		 m_ui32ID = _oCarRecord.m_ui32ID; 
	}
	 
	~CarRecord(){}
	  
	CarRecord* Clone()
    {
      return new CarRecord(*this);
    }
	
	void Print()
    {
      cout << "Car Record" << endl
        << "Name  : " << m_oStrCarName << endl
        << "Number: " << m_ui32ID << endl << endl;
    } 
  private :
    string m_oStrCarName;    
    u_int32_t m_ui32ID;
};

/**
 * BikeRecord is the Concrete Prototype
 */

class BikeRecord : public Record
{
  private :
    string m_oStrBikeName;
  
    u_int32_t m_ui32ID;
  
  public :
    BikeRecord(string _oStrBikeName,u_int32_t _ui32ID)
      : Record(), m_oStrBikeName(_oStrBikeName),
        m_ui32ID(_ui32ID)
    {
    }
  
    BikeRecord(BikeRecord& _oBikeRecord)
      : Record()
    {
      m_oStrBikeName = _oBikeRecord.m_oStrBikeName;
      m_ui32ID = _oBikeRecord.m_ui32ID;
    }
  
    ~BikeRecord() {}

    BikeRecord* Clone()
    {
      return new BikeRecord(*this);
    }
    
    void Print()
    {
      cout << "Bike Record" << endl
        << "Name  : " << m_oStrBikeName << endl
        << "Number: " << m_ui32ID << endl << endl;
    }
};

/**
 * PersonRecord is the Concrete Prototype
 */

class PersonRecord : public Record
{
  private :
    string m_oStrPersonName;
    
    u_int32_t m_ui32Age;
  
  public :
    PersonRecord(string _oStrPersonName, u_int32_t _ui32Age)
      : Record(), m_oStrPersonName(_oStrPersonName),
        m_ui32Age(_ui32Age)
    {
    }
  
    PersonRecord(PersonRecord& _oPersonRecord)
      : Record()
    {
      m_oStrPersonName = _oPersonRecord.m_oStrPersonName;
      m_ui32Age = _oPersonRecord.m_ui32Age;
    }
   
    ~PersonRecord() {}
    
    Record* Clone()
    {
      return new PersonRecord(*this);
    }
    
    void Print()
    {
      cout << "Person Record" << endl
        << "Name : " << m_oStrPersonName << endl
        << "Age  : " << m_ui32Age << endl << endl ;
    }
};
  
 #endif
 

  

