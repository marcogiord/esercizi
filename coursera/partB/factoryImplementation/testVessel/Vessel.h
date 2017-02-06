//Creator.h

# include <iostream>

#ifndef _VESSEL_H
#define _VESSEL_H

using namespace std;

enum vType{RCA,LCX,LAD};

class Vessel{
	public:
		Vessel(int id):_id(id){};
		~Vessel() {};
		virtual void info()=0;
		int getVesselID() const{return(_id);};
	protected:
		int _id;
};

// ypu mudst move all the characteristics to the parent class and leave in the child only the information on the segments 

class LCXVessel: public Vessel{
	public:	
		LCXVessel(int id, vType ctype, int segmentID): Vessel(id), _type(ctype), _segmentID(segmentID) {
			<< "Vessel ID  : " << _id << endl
			<< "Segment ID    : " << _segmentID << endl
			<< " type : " << _type << endl << endl;
		}; // constructor
		
		//Vessel* Create(){return new Vessel(*this);
		 //                 };
		//
		void info(){
			cout<<"Vessel Object " << endl
				<< "Vessel ID  : " << this->getVesselID() << endl
				<< "Segment ID    : " << this->_segmentID << endl << endl;
		}	
	private:
		int _segmentID;
		vType _type;
};
#endif






/*class VesselFactory {
	public:
		VesselFactory();
		Vessel* requestVessel();
		int getNumVessels() const;
	protected:
		virtual Vessel* createVessel() ;   // 
	private:
		
};*/

// should i implement the sub factories... not needed if the creator is not virtual 

/*class Vessel {
	public:
		Vessel(int _number, VesType _type)
		: vesselNumber(_number), vesselType(_type){};
		
		~Vessel();
		
		virtual void info();
		//{std::cout<< "This is a vessel"<<std::endl;}
		
		virtual void set_vesselNumber(const int number);
		virtual void set_vesselType(const string& type);
		
		const int get_vesselNumber(return );
		const std::string get_vesselType();
		
		virtual Vessel* createVessel(){
        return new Vessel(*this);}
	private:
	    int vesselNumber
		vType _vesselType;
		//string patientID;
		//vector <int> connection;		
};*/



/* class LAD : public Vessel {
	
	public:
		//virtual 
		void info(){ {std::cout<< "LAD"<<std::endl;}};
	
	 
};

class LCX : public Vessel {
	
	public:
		//virtual 
		void info(){ {std::cout<< "LCX"<<std::endl;}};
	
	 
}; */
