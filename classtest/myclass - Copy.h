class Super
{
public:
	Super();
	virtual void SomeMethod();

protected:
	int mProtectedInt;

private:
	int mPrivateInt;
};


class Sub : public Super
{
public:
	Sub();

	virtual void SomeMethod();
	//void SomeOtherMethod();

};


