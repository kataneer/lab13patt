class Observer {
public:
	virtual void updateIcers(int i) = 0;
};

class concreteObserver : public Observer
{
private:
	int iceState;
	void checkIcers()
	{
		if (iceState < -5)
			printf("Начало ледохода\n");
		if (iceState < -10)
			printf("Опасно: образование зажоров на участке\n");
		else if (iceState < -7)
			printf("Опасно: образование заторов на участке\n");
	}
public:
	void updateIcers(int i)
	{
		iceState = i;
		if (iceState < 0)
			checkIcers();
	}
	concreteObserver()
	{
		iceState = 0;
	}
};

class iceDrift {
protected:
	Observer *views;
public:
	void attach(Observer *a)
	{
		views = a;
	}
	void detach(Observer *a)
	{
		if (views == a)
			views = nullptr;
	}
	virtual void notify() = 0;
};

class concreteDrift : public iceDrift
{
private:
	int x;
public:
	void notify()
	{
		views->updateIcers(x);
	}
	void setState(int e)
	{
		x = e;
		notify();
	}
	int getState()
	{
		return x;
	}
};