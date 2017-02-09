#include "Record.h"
/**
 * RecordFactory is the client
 */
 
 //typedef map<RECORD_TYPE_en, Record* > RecordMap;
 
class RecordFactory
{
  public :
     //RecordMap m_oMapRecordReference;
    //map<RECORD_TYPE_en, Record* > m_oMapRecordReference;
    //map<RECORD_TYPE_en, Record* > m_oMapRecordReference::iterator it;
    typedef map<RECORD_TYPE_en, Record* > RecordMapType;
    RecordMapType m_oMapRecordReference;
  
    RecordFactory()
    {
      m_oMapRecordReference[CAR]    = new CarRecord("Ferrari", 5050);
      m_oMapRecordReference[BIKE]   = new BikeRecord("Yamaha", 2525);
      m_oMapRecordReference[PERSON] = new PersonRecord("Tom", 25);
    }
    
    ~RecordFactory()
    {
      delete m_oMapRecordReference[CAR];
      delete m_oMapRecordReference[BIKE];
      delete m_oMapRecordReference[PERSON];
    }
    
    Record* CreateRecord(RECORD_TYPE_en enType)
    {
      return m_oMapRecordReference[enType]->Clone();
    }
	
	void ShowAllRecords(){
		for(RecordMapType::iterator it = m_oMapRecordReference.begin(); it != m_oMapRecordReference.end(); it++) {
			(this->CreateRecord(it->first))->Print();
		//RecordFactory*-> CreateRecord(entype)// this is Record*
		// this is a pointer to Record that invikes Print than iit gets called the implementation in the subclass 
		}
		
	}
};
  
int main()
{
  RecordFactory* poRecordFactory = new RecordFactory();
  poRecordFactory->ShowAllRecords();
    
  Record* poRecord;
  poRecord = poRecordFactory->CreateRecord(CAR);
  poRecord->Print();
  delete poRecord;
  
  poRecord = poRecordFactory->CreateRecord(BIKE);
  poRecord->Print();
  delete poRecord;
    
  poRecord = poRecordFactory->CreateRecord(PERSON);
  poRecord->Print();
  delete poRecord;
  
  delete poRecordFactory;
  return 0;
}  