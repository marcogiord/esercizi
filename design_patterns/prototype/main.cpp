#include "Record.h"
/**
 * RecordFactory is the client
 */
 
 typedef map<RECORD_TYPE_en, Record* > RecordMap;
 
class RecordFactory
{
  public :
     RecordMap m_oMapRecordReference;
    //map<RECORD_TYPE_en, Record* > m_oMapRecordReference;

  
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
};
  
int main()
{
  RecordFactory* poRecordFactory = new RecordFactory();

  
  Record* myrec = new CarRecord("Ferrari", 5678);
  CarRecord mysecrec("Ferrari", 5656);
  
  myrec->Print();
  mysecrec.Print();
  
  //RecordMap::iterator it=poRecordFactory->m_oMapRecordReference[CAR]->begin();
  // how you interate over the map ?
  
  /*Record* poRecord;
  poRecord = poRecordFactory->CreateRecord(CAR);
  poRecord->Print();
  delete poRecord;
  
  poRecord = poRecordFactory->CreateRecord(BIKE);
  poRecord->Print();
  delete poRecord;
    
  poRecord = poRecordFactory->CreateRecord(PERSON);
  poRecord->Print();
  delete poRecord;*/
  
  delete poRecordFactory;
  return 0;
}  