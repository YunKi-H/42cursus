#include <iostream>

struct Data {
	int i;
	float f;
	double d;
};

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

int main() {
	Data *data = new Data;
	data->i = 42;
	data->f = 42.42f;
	data->d = 42.4242;
	std::cout << "data i: " << data->i << std::endl;
	std::cout << "data f: " << data->f << std::endl;
	std::cout << "data d: " << data->d << std::endl;
	std::cout << std::endl;

	uintptr_t serialized = serialize(data);
	std::cout << "serialized: " << serialized << std::endl;
	// std::cout << serialized->i << std::endl;
	// std::cout << serialized->f << std::endl;
	// std::cout << serialized->d << std::endl;
	std::cout << std::endl;

	Data *newData = deserialize(serialized);
	std::cout << "newData i: " << newData->i << std::endl;
	std::cout << "newData f: " << newData->f << std::endl;
	std::cout << "newData d: " << newData->d << std::endl;
}
