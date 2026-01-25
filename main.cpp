#include <iostream>

class Sensor {
private:
	//static constexpr int DAYS = 7;
	//double temperatures[DAYS];
	int DAYS;
	double* temperatures;
	bool hasData;

public:
	Sensor(int d = 7) : DAYS(d), hasData(false) {
		temperatures = new double[DAYS];
		for (int i = 0; i < DAYS; i++) {
			temperatures[i] = 0;
		}
	}
	~Sensor() {
		delete[] temperatures;
	}

	void read() {
		for (int i = 0; i < DAYS; i++) {
			std::cout << "Enter temperature: ";
			std::cin >> temperatures[i];
		}
		hasData = true;
		std::cout << "Entered values: ";
		for (int i = 0; i < DAYS; i++) {
			std::cout << temperatures[i] << " ";
		}
	}

	void printMaxTemperature() const {
		if (!hasData) {
			std::cout << "No data\n";
			return;
		}

		double max = temperatures[0];
		for (int i = 0; i < DAYS; i++) {
			if (temperatures[i] > max) {
				max = temperatures[i];
			}
		}
		std::cout << "Max temperature: " << max;
	}

	void printMinTemperature() const {
		if (!hasData) {
			std::cout << "No data\n";
			return;
		}

		double min = temperatures[0];
		for (int i = 0; i < DAYS; i++) {
			if (temperatures[i] < min) {
				min = temperatures[i];
			}
		}
		std::cout << "Min temperature: " << min;
	}
	
	void printAverageTemperature() const {
		if (!hasData) {
			std::cout << "No data\n";
			return;
		}

		double sum = 0;
		for (int i = 0; i < DAYS; i++) {
			sum += temperatures[i];
		}

		double average = sum / DAYS;
		std::cout << "\nAverage temperature: " << average;
	}

	void resetData() {
		/*for (double& t : temperatures) {
			t = 0;
		}*/
		for (int i = 0; i < DAYS; i++) {
			temperatures[i] = 0;
		}
		hasData = false;
	}
};

int main() {
	int select;
	Sensor* sensor = new Sensor();
	while (true) {
		std::cout << "\n0. Exit";
		std::cout << "\n1. Read new temperatures";
		std::cout << "\n2. Print lowest temperature";
		std::cout << "\n3. Print highest temperature";
		std::cout << "\n4. Print average temperature";
		std::cout << "\n5. Reset data";
		std::cout << "\n6. Create new sensor";
		std::cout << "\nSelect: ";
		std::cin >> select;

		switch (select) {
		case 0:
			return 0;
			break;
		case 1:
			sensor->read();
			break;
		case 2:
			sensor->printMinTemperature();
			break;
		case 3:
			sensor->printMaxTemperature();
			break;
		case 4:
			sensor->printAverageTemperature();
			break;
		case 5:
			sensor->resetData();
			break;
		case 6:
			delete sensor;
			sensor = nullptr;
			sensor = new Sensor();
			break;
		default:
			std::cout << "Wrong option\n";
			break;
		}
	}
	return 0;
}