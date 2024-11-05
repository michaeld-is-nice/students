#pragma once

template<typename T> class Terminator
{
	T *mpT;
	
public:
	Terminator(): mpT(NULL) {};
	Terminator(T* pT) : mpT(pT) {};
	
	~Terminator() { 
		if (mpT != NULL)
			delete mpT; 
	};
	
	void operator=(T *pT) { mpT = pT; }
	T* operator->() { return mpT; }
	bool isEmpty() { return mpT == NULL; }
};

