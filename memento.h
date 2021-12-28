class riverState {
public:
	float flow;
	float speed;
	float deep;
	void init(float a, float b, float c)
	{
		flow = a;
		speed = b;
		deep = c;
	}
	void get()
	{
		printf("Анализируем:\n");
		printf("%f %f %f\n", flow, speed, deep);
	}
};

class Memento {
private:
	riverState *savio;
public:
	void setRiverState(float a, float b, float c)
	{
		savio = new riverState();
		savio->init(a, b, c);
	}

	riverState *getRiverState()
	{
		return savio;
	}
};

class Memorier {
private:
	Memento *memPoint;
	riverState *memState;
public:
	void createMemPoint()
	{
		memPoint = new Memento();
		memPoint->setRiverState(memState->flow, memState->speed, memState->deep);
	}
	void resetState()
	{
		printf("Восстанавливаем точку памяти\n");
		memState = memPoint->getRiverState();
	}
	void init(float a, float b, float c)
	{
		memState = new riverState();
		memState->init(a, b, c);
	}
	void get()
	{
		memState->get();
	}
};