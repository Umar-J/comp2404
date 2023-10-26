
#include "DeviceArray.h"

DeviceArray::DeviceArray(){
	numDevices = 0;
	devices = new Device*[MAX_ARRAY];
}


DeviceArray::~DeviceArray(){
	delete [] devices;
}


bool DeviceArray::add(const Device* device){
	if (isFull()) return false;
	devices[numDevices] = new Device(*device);
	numDevices++;
	return true;
}

Device* DeviceArray::remove(const string& title){
	int index = 0;

	while (index < numDevices){
		if (devices[index]->equals(title)){ break; }
		++index;
	}

	if (index >= numDevices) return NULL;

	Device* goner;
	goner = devices[index];

	while (index < numDevices-1){
		devices[index] = devices[index+1];
		++index;
	}
	--numDevices;
	return goner;
}

Device* DeviceArray::remove(int i){
	if (i < 0 || i >= numDevices) return nullptr;
	Device* goner = devices[i];

	while (i < numDevices-1){
		devices[i] = devices[i+1];
		++i;
	}
	--numDevices;
	return goner;
}

Device* DeviceArray::get(const string& title) const{
	for (int i = 0; i < numDevices; ++i){
		if (devices[i]->equals(title)){
			return devices[i];
		}
	}
	return nullptr;
}

Device* DeviceArray::get(int i) const {
	if (i < 0 || i >= numDevices) return nullptr;
	return devices[i];
}

bool DeviceArray::isFull() const{
	return numDevices >= MAX_ARRAY;
}

int DeviceArray::size() const{
	return numDevices;
}

void DeviceArray::print() const{
	for (int i = 0; i < numDevices; ++i){
		cout<<i<<":"<<endl;
		devices[i]->print();
	}
}
